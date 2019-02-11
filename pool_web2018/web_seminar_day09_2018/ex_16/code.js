function ajouter() {
	var text = document.getElementById("inp").value;
	var classes = ["note ", "email ", "todo "];
	var classes_name = ["note", "email", "todo_"]
	var li = document.createElement("li");
	for (var i in classes)
		if (text.startsWith(classes[i])) {
			text = text.substr(classes[i].length);
			li.className = classes_name[i];
		}
	if (text == "")
		return false;
	var list = document.getElementById("list");
	li.appendChild(document.createTextNode(text));
	list.appendChild(li);
}