// this is the crash prevention from the Developer: Tyler Ricketts (Brayzure)
var forever = require('forever-monitor');

var child = new (forever.Monitor)('index.js', {
	silent: false,
	args: [],
	minUptime: 15000
});

child.on('exit', function () {
	console.log('Unfortually, the bot has crashed, This could be caused by a error if it is not try running it again!');
});

child.start();
