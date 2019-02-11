module.exports = {
	range: function(start, end, step = 1)   {
		var arr = []
		var x = start;
		if (start < end && step > 0) {
			while (x <= end) {
				arr.push(x);
				x += step;
			}
		}
		else if (start > end && step < 0) {
			while (x >= end) {
				arr.push(x);
				x += step;
			}
		}
		return (arr);
	}
}