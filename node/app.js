// Get pixel color under the mouse.
var robot = require("robotjs");

// Get pixel color in hex format.
while(true){
	// Get mouse position.
var mouse = robot.getMousePos();
	var hex = robot.getPixelColor(mouse.x, mouse.y);
	console.log("#" + hex + " at x:" + mouse.x + " y:" + mouse.y);
}