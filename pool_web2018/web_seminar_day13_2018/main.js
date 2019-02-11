(function( $ ) {
	$.fn.mygame = function (options) {
		var settings = $.extend({
			size: "800px"
		}, options);
		var gameObject = this;
		var blockSize = settings.size / 4;
		var boardSize = settings.size;
		return gameObject;
	};
    $.fn.greenify = function() {
		console.log(this);
        this.css( "background-colour", "green" );
        return this;
    };
}(jQuery));
console.log($(".game"));
$( "body" ).greenify();

$(".game").mygame();