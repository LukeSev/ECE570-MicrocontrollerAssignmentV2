/*
;-----------------------------------------------------------------------------
; Title: Basic LED Blink
;-----------------------------------------------------------------------------
; Program Detail:
------------------------------------------------------------------------------
; Purpose: Toggle an LED on and off and prints the LED status to the serial monitor.
;     It is designed to demonstrate the basic usage of the ESP8266 using PlatformIO
; Inputs: None
; Outputs: Visual indication of LED status
; Date: 2024-06-10
; Compiler: GCC
; Author: Lucas Loughner
; Versions:
;     1.0 - Initial Version
;-----------------------------------------------------------------------------
; File Dependencies:
*/
#include <Arduino.h>
/*
;-----------------------------------------------------------------------------
; Main Program:
;-----------------------------------------------------------------------------
*/

const int analogPin = A0; // Define the analog pin for ADC reading
const int chargeDischargeDelay = 60000; // 60 seconds between readings while observing battery charge/discharge
const int adcReadDelay = 1000; // 1 second delay between ADC readings while testing ADC accuracy
const int adcBatteryConversion = 2.169; // Conversion factor for ADC to battery to account for voltage divider

float adcToVoltage(int adcValue) {
  // Convert ADC value to voltage (assuming a 3.3V reference)
  return adcValue * (3.3 / 1023.0);
}

void testADCAccuracy() {
  for(int i = 0; i < 25; i++) {
    // Get ADC reading
    int rawADC = analogRead(analogPin);
    float voltage = adcToVoltage(rawADC);

    // Print in format for CSV
    Serial.print(i + 1); // Print reading number
    Serial.print(",");
    Serial.print(rawADC);
    Serial.print(",");
    Serial.println(voltage, 2); // Print voltage with 2 decimal places

    delay(adcReadDelay); // Wait 1 second before next reading
  }
}

void setup() {
  Serial.begin(9600); // Start the serial communication at 9600 baud rate
  // testADCAccuracy(); // Test ADC accuracy with 20 readings
}

int count = 0; // Counter for the number of readings taken
void loop() {

  // USED FOR TESTING ADC
  // testADCAccuracy(); // Test ADC accuracy with 20 readings

  // MAIN PROGRAM FOR MEASURING BATTERY CHARGE/DISCHARGE
  // Get ADC reading and convert to voltage
  int rawADC = analogRead(analogPin);
  float voltage = adcToVoltage(rawADC )* 2.169; // Apply conversion factor to account for voltage divider

  // Print in format for CSV
  Serial.print(count);
  Serial.print(",");
  Serial.print(rawADC);
  Serial.print(",");
  Serial.println(voltage, 2); // Print voltage with 2 decimal places
  count++;

  // Wait 60s before taking another reading
  delay(chargeDischargeDelay);

}