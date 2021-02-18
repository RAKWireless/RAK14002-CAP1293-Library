/**
 * @file Example05_DetectCurrentTouch.ino
 * @author Bernd Giesecke (bernd.giesecke@rakwireless.com)
 * @brief Detect Current Touch example for CAP1293 touch sensor IC
 * @version 0.1
 * @date 2021-02-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <Wire.h>
#include "CAP1293.h" // Click here to get the library: http://librarymanager/All#RAK14002-CAP1293-Library

CAP1293 sensor; // Initialize sensor

void setup()
{
	Wire.begin();		  // Join I2C bus
	Serial.begin(115200); // Start serial for output

	// Setup sensor
	if (sensor.begin() == false)
	{
		Serial.println("Not connected. Please check connections and read the hookup guide.");
		while (1)
			;
	}
	else
	{
		Serial.println("Connected!");
	}
}

void loop()
{
	if (sensor.isLeftTouched() == true)
	{
		Serial.println("Left");
		while (sensor.isLeftTouched() == true)
			; // Wait until user removes finger
	}

	if (sensor.isMiddleTouched() == true)
	{
		Serial.println("Middle");
		while (sensor.isMiddleTouched() == true)
			; // Wait until user removes finger
	}

	if (sensor.isRightTouched() == true)
	{
		Serial.println("Right");
		while (sensor.isRightTouched() == true)
			; // Wait until user removes finger
	}
}
