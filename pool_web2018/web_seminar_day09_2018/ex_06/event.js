window.onload = function() {
	var p = document.getElementsByTagName("button");
	if (typeof p[0] == "object") {
		p[0].onclick = magic;
	}
}

function magic() {
	p = document.getElementsByTagName("p");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].style.display = "none";
		i++;
	}
}