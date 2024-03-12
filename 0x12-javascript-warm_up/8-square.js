#!/usr/bin/node
const process = require('process');
const x = parseInt(process.argv[2]);
const message = 'Missing size';
if (isNaN(x)) {
  console.log(message);
} else {
  for (let j = 0; j < x; j++) {
    console.log('x'.repeat(x));
  }
}
