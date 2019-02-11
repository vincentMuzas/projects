$(document).ready(function () {
    $("button").click(function () {
        $("main").css("opacity", "1");
    });
    $("#sidebutton").click(function () {
        $("#sidebar").css("display", "block");
    });
    $("#sidebar").mouseleave(function () {
        $("#sidebar").css("display", "none");
    });
});