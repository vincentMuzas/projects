module.exports = {
	arrayFiltering: function(array, test)	{
		var res = [];
		for (var i = 0; i < array.length; i++) {
			if (test(array[i]) == 1)
				res.push(array[i]);
		}
		return res;
	}
}