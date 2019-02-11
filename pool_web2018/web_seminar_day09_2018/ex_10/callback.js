window.onload = function() {
	var p = document.getElementsByClassName("test");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].onclick = magic;
		i++;
	}
}

function magic(obj)
{
	obj.target.style.visibility = "hidden";
	alert("The paragraph is now hidden");
}