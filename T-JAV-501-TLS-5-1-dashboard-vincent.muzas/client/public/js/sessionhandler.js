$(document).ready(function() {

    /**
     * set the token in the inputs or redirect if absent
     */
    if (typeof $.cookie('token') === 'undefined'){
        if (window.location.pathname == "/")
            window.location = "/login";
        $("#logout_link").hide();
    }
    else {
        $("#login_link").hide();
        $("#token_input").val($.cookie('token'));
        if (window.location.pathname == "/") {

            
            $.getJSON(serverRoute + "/widgetList?token=" + $.cookie('token'), function(data) {
                WidgetsConf = data;
                data.forEach(element=> {
                    var html = "<div class=\"card col s12 m6 l4 z-depth-2\"><div class=\"card-content\"><span class=\"card-title\">"+ element.widget_name +"</span><p>";
                    html +=   "<i class=\"material-icons\" onclick=\"edit_widget(this, " + element.id + ")\" style=\"cursor: pointer\">edit</i>";
                    element.params.forEach(function(param, idx, array) {
                        html += param;
                        if (idx !== array.length - 1) {
                            html += " - "
                        }
                    });
                    html += "</p>";
                    html += "<form action=\"" + serverRoute + "/widget\" method=\"DELETE\" successlocation=\"/\">";
                    html += "<input type=\"hidden\" name=\"token\" value=\"" + $.cookie("token") + "\">";
                    html += "<input type=\"hidden\" name=\"widgetId\" value=\"" + element.id + "\">";
                    html += "<input type=\"submit\" class=\"btn red\" value=\"Delete Widget\">";
                    html += "</form>";
                    html += "<div class=\"card-action\"><p style=\"white-space: pre\">";
                    $.getJSON(serverRoute+"/widget?token=" + $.cookie('token') + "&widgetId=" + element.id, function(data) {
                        var parsed_data = parseData(element, data);
                        html = html + parsed_data;
                        html += "</p></div></div>"
                        $("#widgetContainer").append(html);
                        form_modifiers();
                    });
                });
            })
        }
    }
});

function edit_widget(caller, element) {
    WidgetsConf.forEach(widget => {
        if (widget.id == element) {
            ServerConf.server.services.forEach(service => {
                if (service.name == widget.service_name) {
                    service.widgets.forEach(serverWidget => {
                        if (serverWidget.name == widget.widget_name) {
                            var html = "<form action=\"" + serverRoute + "/widget\" method=\"PUT\" successlocation=\"/\">";
                            html += "<input type=\"hidden\" name=\"token\" value=\"" + $.cookie("token") + "\">";
                            html += "<input type=\"hidden\" name=\"widgetId\" value=\"" + element + "\">";
                            serverWidget.params.forEach(param => {
                                html += "<div class=\"input-field col s12\">";
                                html+= "<input type=\"text\" name=\"params[]\" id=\"" + param.name+element + "\">";
                                html+= "<label for=\"" + param.name+element + "\">" + param.name + "</label></div>";
                            });
                            html += "<input type=\"submit\" class=\"btn\" value=\"update\">";
                            html += "</form>";
                            var jqobject = $(html);
                            jqobject.insertAfter($(caller).parent());
                            $(caller).attr("onclick", "");
                            console.log($(caller));
                            form_modifiers();
                            return;
                        }
                    })
                }
            });
        }
    });
}

/**
 * parse the data of the widget and return html
 */
function parseData(element, data) {
    var parsed_data = JSON.stringify(data, null, " ");
    switch (element.widget_name) {
        case "loveCalculator":
            parsed_data = "<h5 class=\"red-text\">" + data.percentage + "% match</h5>";
            parsed_data += "<p>" + data.result + "</p>";
            break;
        case "weather":
            parsed_data = "<h5 class=\"red-text\">" + (data.main.temp - 275,15).toString() + "°C</h5>"
            parsed_data += "<div class=\"valign-wrapper\"><i class=\"material-icons\">cloud</i>" + data.clouds.all + "%: " + data.weather[0].description + "</div>";
            break;
        case "covid":
            parsed_data = "<h5>Today status:</h5>";
            parsed_data += "<b>" + data.response[0].cases.new + " infected</b> (" + data.response[0].cases.total + " total)<br>";
            parsed_data += "<b>" + data.response[0].deaths.new + " deaths</b> (" + data.response[0].deaths.total + " total)";
            break;
        case "historicalFacts":
            var obj_data = JSON.parse(data.body);
            parsed_data = "<h5>" + obj_data.year.toString() + "</h5>";
            parsed_data += "<p>" + obj_data.text + "</p>";
            break;
        case "deezer":
            parsed_data = "<h5>" + data.data[0].title + "</h5>";
            parsed_data += "<img class=\"materialboxed\" style=\"width: 100%\" src=\"" + data.data[0].album.cover_big + "\"</img>";
            parsed_data += "<audio controls src=\"" + data.data[0].preview + "\"> Your browser does not support the <code>audio</code> element.</audio>";
            break;
        case "joke":
            //? cant make it to work
            break;
        case "liveMatches":
            parsed_data = "<h5>Stages:</h5><ul>";
            data.Stages.forEach(match => {
                parsed_data += "<li><b>" + match.Cnm + ":</b> " + match.Sdn + "</li>";
            });
            parsed_data += "</ul>";
            break;
        case "currencyToAll":
            if (!data.success) {
                parsed_data = "Error";
                break;
            }
            parsed_data = "<h5>1 " + data.result.base + " equals:</h5><ul>";
            data.result.data.forEach(curency => {
                parsed_data += "<li>" + curency.calculatedstr + " " + curency.code + "</li>"
            });
            parsed_data += "</ul>";
            break;
        case "shortUrl":
            parsed_data = "<a href=\"" + data.result_url + "\">" + data.result_url + "</a>";
            break;
        default:
            break;
    }
    return parsed_data;
}

/**
 * Remove the token for the api
 */
function logout() {
    $.removeCookie('token', { path: '/' });
}

/**
 * used for testing basic layout
 */
function fakelogin() {
    $.cookie("token", "thisisatotalyrandomtoken");
    location.reload();
}

/**
 * add a new widget for the user
 */
function form_modifiers() {
    $("form").unbind();
    $('form').submit(function(e){
        e.preventDefault();
        var newlocation = $(this).attr('successlocation');
        var data = $(this).serializeArray();
        var params = "[";
        var data_final = [];
        data.forEach(element => {
            if (element.name == "params[]") {
                if (/^\d+$/.test(element.value))
                    params = params + element.value + ",";
                else
                    params = params + "\"" + element.value + "\","
            } else {
                data_final.push(element);
            }
        });
        params = params + "]";
        if (params.length > 2)
            data_final.push({name:"params", value:params});
        console.log(data_final);
        $.ajax({
            url: $(this).attr('action'),
            type: $(this).attr('method'),
            data: data_final,
            success:function(data, textStatus, xhr){
                console.log(data);
                $.cookie("token", data.token);
                window.location = newlocation;
            },
            error: function(xhr, textstatus) {
                alert("The server returned code " + xhr.status + "\n" + textstatus );
                location.reload();
            }
        });
    });
}
form_modifiers();