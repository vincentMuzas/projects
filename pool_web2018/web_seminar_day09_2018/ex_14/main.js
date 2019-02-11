window.onload = function() {
	var p = document.getElementsByTagName("p");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].onmouseenter = magic;
		p[i].onmouseleave = black_magic;
		i++;
	}
}

function magic(obj) {
	obj.target.classList.add("blue");
}

function black_magic(obj) {
	obj.target.classList.remove("blue");
}