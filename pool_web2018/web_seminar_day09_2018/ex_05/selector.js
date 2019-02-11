window.onload = function() {
	var p = document.getElementsByTagName("ul")[0];
	if (typeof p == "object") {
		p = p.getElementsByTagName("li")[0];
		if (typeof p == "object")
			p.style.display = "none";
	}
}