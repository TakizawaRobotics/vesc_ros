#include <VescUart.h>

/** Initiate VescUart class */
VescUart UART;

void setup() {

  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial1.begin(19200);
  
  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial1);
}

void loop() {
  
  /** Call the function getVescValues() to acquire data from VESC */
  if ( UART.getVescValues() ) {

    Serial.println(UART.data.rpm);
    Serial.println(UART.data.inpVoltage);
    Serial.println(UART.data.ampHours);
    Serial.println(UART.data.tachometerAbs);

  }
  else
  {
    Serial.println("Failed to get data!");
  }

  delay(50);
}
