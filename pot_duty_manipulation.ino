#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Rotary Encoder Pins
#define CLK 25
#define DT 26
#define SW 27

int lastCLK;
float setVoltage = 7.0;

const float minVoltage = 7.0;
const float maxVoltage = 24.0;
const float step = 0.1;

void setup()
{
    Serial.begin(115200);

    pinMode(CLK, INPUT_PULLUP);
    pinMode(DT, INPUT_PULLUP);
    pinMode(SW, INPUT_PULLUP);

    lastCLK = digitalRead(CLK);

    Wire.begin(21,22);

    if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
    {
        while(1);
    }

    display.clearDisplay();
    display.display();
}

void loop()
{
    int currentCLK = digitalRead(CLK);

    if(currentCLK != lastCLK && currentCLK == LOW)
    {
        if(digitalRead(DT) != currentCLK)
        {
            setVoltage += step;
        }
        else
        {
            setVoltage -= step;
        }

        if(setVoltage > maxVoltage)
            setVoltage = maxVoltage;

        if(setVoltage < minVoltage)
            setVoltage = minVoltage;

        updateDisplay();
    }

    lastCLK = currentCLK;

    if(digitalRead(SW) == LOW)
    {
        Serial.print("Selected Voltage = ");
        Serial.println(setVoltage);

        delay(300);
    }
}

void updateDisplay()
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setCursor(0,0);
    display.println("Buck Converter");

    display.drawLine(0,12,128,12,WHITE);

    display.setCursor(0,22);
    display.print("Set Voltage");

    display.setTextSize(2);
    display.setCursor(15,40);
    display.print(setVoltage,1);
    display.print("V");

    display.display();
}