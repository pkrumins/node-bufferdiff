var sys = require('sys');
var eqBuf = require('bufferdiff').eqBuf;
var fs = require('fs');
var assert = require('assert');

// test 1: equal buffers
var b1 = fs.readFileSync('./databuf-1029');
var b2 = fs.readFileSync('./databuf-1029');
assert.ok(eqBuf(b1, b1), 'b1 != b1');
assert.ok(eqBuf(b1, b2), 'b1 != b2');
assert.ok(eqBuf(b2, b2), 'b2 != b2');


// test 2: 1 byte buffer
var b3 = fs.readFileSync('./databuf-1');
assert.ok(eqBuf(b3, b3), 'b3 != b3');
assert.ok(!eqBuf(b3, b1), 'b3 = b3');
assert.ok(!eqBuf(b3, b2), 'b3 = b2');
assert.ok(!eqBuf(b1, b3), 'b1 = b3');

sys.log('all tests ok');
