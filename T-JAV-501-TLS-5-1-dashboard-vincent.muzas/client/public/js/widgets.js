var ServerConf;
var WidgetsConf;
$(document).ready(function() {
    $.getJSON(serverRoute + "/about.json", function(data) {
        ServerConf = data;
        data.server.services.forEach(element => {
            var node= $("<optgroup label=" + element.name + "></optgroup>");
            element.widgets.forEach(widget => {
                node.append("<option value=" + widget.name + " service=" + element.name + ">" + widget.name + "</option>");
            });
            $("#WidgetSelector").append(node);
        });
        // materialize
        $('select').formSelect();
    });
    $('#WidgetSelector').change(function(){
        var serviceName = $("option:selected", this).attr("service");
        $("#ServiceName").val(serviceName);
        $("#FormParameters").empty();
        ServerConf.server.services.forEach(service => {
            if (service.name == serviceName) {
                service.widgets.forEach(widget => {
                    if (widget.name == $("#WidgetSelector").val()) {
                        widget.params.forEach(param => {
                            $("#FormParameters").append("<div class=\"input-field col s12\"><input type=\"text\" name=\"params[]\" id=\"" + param.name + "\"><label for=\"" + param.name + "\">" + param.name + "</label></div>");
                        });
                        M.updateTextFields();
                    }
                });
            }
        });
    });
});
