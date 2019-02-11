module.exports = {
	countGs: function(str)   {
		var count = 0;
		var x = 0;
		while (count < str.length) {
			if ('G' === str.charAt(count))
				x ++;
			count ++;
		}
		return x;
	}
}