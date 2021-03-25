#include <Arduino.h>
#include <NewAttinyOneWire.h>

#define BAUD 9600
#define LED PIN_PA5

void setup()
{
    Serial.begin(BAUD);
    NewAttinyOneWire::initOneWireUART();

    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
}

int incomingByte = 0; // for incoming serial data

void loop()
{
    if (Serial.available() > 0)
    {
        // Toggle LED
        PORTA.OUTTGL = LED;

        // read the incoming byte:
        incomingByte = Serial.read();

        delay(10);

        NewAttinyOneWire::disableReceiver();
        Serial.write(incomingByte);
        NewAttinyOneWire::enableReceiver();
    }
}