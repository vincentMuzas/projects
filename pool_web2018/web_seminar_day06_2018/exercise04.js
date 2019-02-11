module.exports = {
	fizzBuzz: function(limit)   {
		var index = 1;
		var final = "";
		while (index <= limit) {
			if (index % 3 == 0)
				final = final.concat("Fizz");
			if (index % 5 == 0)
				final = final.concat("Buzz");
			if (index % 5 != 0 && index % 3 != 0)
				final = final.concat(index);
			if (index < limit)
				final = final.concat(", ");
			index ++;
			}
		console.log(final);
	}
}