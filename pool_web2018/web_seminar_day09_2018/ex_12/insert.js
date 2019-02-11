window.onload = function() {
	var img = document.getElementsByTagName("img");
	if (typeof img[0] == "object") {
		img[0].insertAdjacentHTML('beforebegin', "Wow, I precede the image!");
		img[0].insertAdjacentHTML('afterend', "Hey, I come in last");
	}
}
