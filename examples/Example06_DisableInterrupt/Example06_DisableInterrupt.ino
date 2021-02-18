/**
 * @file Example06_DisableInterrupt.ino
 * @author Bernd Giesecke (bernd.giesecke@rakwireless.com)
 * @brief Disable Interrupt example for CAP1293 touch sensor IC
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
	Wire.begin();		// Join I2C bus
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

	/* SET INTERRUPT DISABLED/ENABLED
      Interrupt is ENABLED as default.
      When the interrupt pin is DISABLED, the alert LED
      does not turn on. When the interrupt pin is ENABLED,
      the alert LED turns on when a touch is detected.
  */
	sensor.setInterruptDisabled(); // Disable Interrupt
	//sensor.setInterruptEnabled();   // Enable Interrupt

	/* IS INTERRUPT ENABLED
      Check the current status of the interrupt pin. 
      Returns true if interrupt pin is enabled and 
      false if disabled.
  */
	Serial.print("Interrupt: ");
	if (sensor.isInterruptEnabled() == true)
	{
		Serial.println("ENABLED");
	}
	else
	{
		Serial.println("DISABLED");
	}
}

void loop()
{
	if (sensor.isTouched() == true)
	{
		Serial.println("Touched!");
		while (sensor.isTouched() == true)
			;
	}
}
