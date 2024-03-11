#!/usr/bin/node
const process = require('process');
let display;
if (process.argv.length === 3) {
  display = 'Argument found';
} else if (process.argv.length < 3) {
  display = 'No argument';
} else {
  display = 'Arguments found';
}
console.log(display);
