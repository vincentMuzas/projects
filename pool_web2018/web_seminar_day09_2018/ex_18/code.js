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

function chercher() {
	var value = $('input[name=class]:checked').val();
	var list = document.getElementById("list");
	var text = document.getElementById("filter").value;
	var check = document.getElementById("check").checked;
	list = list.getElementsByTagName("li");
	var i = 0;
	if (value == "no") {
		while (typeof list[i] == "object") {
			list[i].style.display = "list-item";
			i++;
		}
	} else {
		while (typeof list[i] == "object") {
			if (list[i].className.includes(value))
				list[i].style.display = "list-item";
			else
				list[i].style.display = "none";
			i++;
		}
	}
	if (check == true) {
		i = 0;
		while (typeof list[i] == "object") {
			var sw = list[i].innerHTML.includes(text);
			console.log(sw);
			if (sw === false)
				list[i].style.display = "none";
			i++;
		}
	}
}