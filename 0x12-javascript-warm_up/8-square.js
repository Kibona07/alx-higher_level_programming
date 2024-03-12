#!/usr/bin/node
const process = require('process');
const y = parseInt(process.argv[2]);
const message = 'Missing size';
if (isNaN(y)) {
  console.log(message);
} else {
  for (let j = 0; j < y; j++) {
    console.log('y'.repeat(y));
  }
}
