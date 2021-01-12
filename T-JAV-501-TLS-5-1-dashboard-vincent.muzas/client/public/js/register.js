$(document).ready(function() {
    if (typeof $.cookie('token') === 'undefined');
    else {
        window.location.href = "/";
    }

});