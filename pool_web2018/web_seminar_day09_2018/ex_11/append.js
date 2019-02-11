window.onload = function() {
}

function magic(obj)
{
	var div = document.createElement("div");
	div.innerHTML = document.getElementById("listItem").value;
	obj.parentNode.insertBefore(div, obj.nextSibling);
}