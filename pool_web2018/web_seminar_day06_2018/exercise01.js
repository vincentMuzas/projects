module.exports = {
	drawTriangle: function(limit)   {
		var str1 = "$";
		var str2 = "";
		var count = 0;
		while (count < limit) {
			str2 = str1.concat(str2);
			console.log(str2);
			count ++;
		}
	}
}