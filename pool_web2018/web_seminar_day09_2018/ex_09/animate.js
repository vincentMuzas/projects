window.onload = function() {
	var p = document.getElementsByClassName("platypus");
	var i = 0;
	while (typeof p[i] == "object") {
		p[i].onclick = magic;
		i++;
	}
}

function magic(obj)
{
	var left = parseInt(obj.target.style.marginLeft);
	if (isNaN(left))
		left = 0;
	var top = parseInt(obj.target.style.marginTop);
	if (isNaN(top))
		top = 0;
	console.log(left, top);
	obj.target.style.marginLeft = left + 150 + "px";
	obj.target.style.marginTop = top + 200 + "px";
	obj.target.style.backgroundColor = "green";
}