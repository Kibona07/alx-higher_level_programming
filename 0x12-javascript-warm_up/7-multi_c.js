#!/usr/bin/node
const process = require('process');
let numb_times = parseInt(process.argv[2]);
const message1 = 'Missing number of occurrences';
const message2 = 'C is fun';
if (isNaN(numb_times)) {
  console.log(message1);
} else {
  while (numb_times > 0) {
    console.log(message2);
    numb_times--;
  }
}
