window.onload = function() {
	var doc = document.getElementsByClassName("test");
	while (typeof doc[0] == "object")
		doc[0].remove();
	doc = document.getElementsByClassName("platypus");
	while (typeof doc[0] == "object")
		doc[0].remove();
}