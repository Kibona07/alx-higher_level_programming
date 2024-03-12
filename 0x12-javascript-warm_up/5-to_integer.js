#!/usr/bin/node
const process = require('process');
let numb;
let message = 'Not a number';
if (process.argv.length > 2) {
  numb = parseInt(process.argv[2]);
  if (!isNaN(numb)) {
    numb = String(numb);
    message = `My number: ${numb}`;
  }
}
console.log(message);
