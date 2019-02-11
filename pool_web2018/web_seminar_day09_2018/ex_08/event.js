window.onload = function() {
	var p = document.getElementsByTagName("button");
	if (typeof p[0] == "object") {
		p[0].onclick = menu;
	}
}

function menu(obj)
{
	var menu = document.getElementById("menu");
	if (menu.style.visibility == "collapse") {
		menu.style.visibility = "visible";
	}
	else
		menu.style.visibility = "collapse";
}