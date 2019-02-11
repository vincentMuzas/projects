module.exports = {
	arraysAreEqual: function(arr1 , arr2)   {
		return (JSON.stringify(arr1) === JSON.stringify(arr2))
	}
}