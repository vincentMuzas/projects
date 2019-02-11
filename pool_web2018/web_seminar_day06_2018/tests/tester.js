
console.log("--Exercise 1");
const exercise01 = require("./exercise01");
exercise01.drawTriangle(6);

console.log("--Exercise 2");
const exercise02 = require("./exercise02");
console.log(exercise02.arraysAreEqual([1, 2], [1, 4]));
console.log(exercise02.arraysAreEqual([1, 2], [1, 2]));

console.log("--Exercise 3");
const exercise03 = require("./exercise03");
console.log("GgBongOURGG:", exercise03.countGs("GgBongOURGG"));

console.log("--Exercise 4--");
const exercise04 = require("./exercise04");
console.log(exercise04.fizzBuzz(20));

console.log("--Exercise 5--");
const exercise05 = require("./exercise05");
console.log(exercise05.range(1, 10, 2));
console.log(exercise05.range(19, 22));
console.log(exercise05.range(5, 2, -1));

console.log("--Exercise 6--");
const exercise06 = require("./exercise06");
var obj = {here: {is: "an"}, object: 2};
console.log(exercise06.objectsDeeplyEqual(obj, obj));
console.log(exercise06.objectsDeeplyEqual(obj, {here: 1, object: 2}));
console.log(exercise06.objectsDeeplyEqual(obj, {here: {is: "an"}, object: 2}));

console.log("--Exercise 7--");
const exercise07 = require("./exercise07");
var  toFilter = [1, 2, 3, 4, 5, 6, 7, 8, 9];
var  res = exercise07.arrayFiltering(toFilter , function (value) {
return  value % 3 === 0;
});
console.log(res);