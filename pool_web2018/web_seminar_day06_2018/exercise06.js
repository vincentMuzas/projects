module.exports = {
	objectsDeeplyEqual: function(cmp1, cmp2)   {
		var sw = Object.keys(cmp1);
		var ret = true;
		for (i in sw) {
			if (typeof cmp1[sw[i]] == "object") {
				ret = this.objectsDeeplyEqual(cmp1[sw[i]], cmp2[sw[i]]);
				if (ret == false) {
					return (false);
				}
			}
			else if (cmp1[sw[i]] !== cmp2[sw[i]])
				return (false);
		}
		return (ret);
	}
}