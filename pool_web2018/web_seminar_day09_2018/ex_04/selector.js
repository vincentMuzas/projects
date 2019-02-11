window.onload = function() {
	var p = document.getElementsByTagName("a");
	var i = 0;
	while (typeof p[i] == "object") {
		if (p[i].target != "_blank") {
			p[i].style.opacity = "0.5";
		}
		i++;
	}
}