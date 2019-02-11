window.onload = function() {
	var p = document.getElementsByTagName("p");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].style.display = "none";
		i++;
	}
}