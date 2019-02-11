window.onload = function() {
	var p = document.getElementsByTagName("p");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].onmouseenter = magic;
		p[i].onmouseleave = black_magic;
		p[i].onclick = no_magic;
		i++;
	}
}

function magic(obj) {
	obj.target.style.backgroundColor = "LightGray";
}

function black_magic(obj) {
	obj.target.style.backgroundColor = "white";
}

function no_magic(obj) {
	obj.target.innerHTML = "";
}