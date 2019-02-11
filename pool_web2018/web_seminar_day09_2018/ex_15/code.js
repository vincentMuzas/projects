function ajouter() {
	var text = document.getElementById("inp").value;
	if (text == "")
		return false;
	var list = document.getElementById("list");
	var li = document.createElement("li");
	li.appendChild(document.createTextNode(text));
	list.appendChild(li);
}