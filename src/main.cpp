#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author Mayank
 * @date 2026-01-15
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

const uint8_t LDR_PIN = A0;
int ldrValue = 0;
const int THRESHOLD = 512;

void setup() {
    Serial.begin(9600);
    while (!Serial) { ; }
    Serial.println("System initialized: LDR Light Monitor");
}

void loop() {
    ldrValue = analogRead(LDR_PIN);

    Serial.print("Raw ADC: ");
    Serial.println(ldrValue);

    int brightnessPercent = map(ldrValue, 0, 1023, 0, 100);
    const char* status = (ldrValue >= THRESHOLD) ? "Bright" : "Dark";

    Serial.print("Brightness: ");
    Serial.print(brightnessPercent);
    Serial.print("% - Status: ");
    Serial.println(status);

    delay(500);
}
