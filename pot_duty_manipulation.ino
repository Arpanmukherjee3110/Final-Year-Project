#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define SDA_PIN 21
#define SCL_PIN 22

#define CLK 18
#define DT 19
#define SW 5

HardwareSerial DSPSerial(2);    
int encoderValue = 7;
int lastCLKState;

void setup()
{
    Serial.begin(115200);

    DSPSerial.begin(115200, SERIAL_8N1, 16, 17);

    pinMode(CLK, INPUT_PULLUP);
    pinMode(DT, INPUT_PULLUP);
    pinMode(SW, INPUT_PULLUP);

    Wire.begin(SDA_PIN, SCL_PIN);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        while (1);
    }

    display.clearDisplay();

    lastCLKState = digitalRead(CLK);

    showValue();

    sendVoltage();
}

void loop()
{
    int currentCLK = digitalRead(CLK);

    if (currentCLK != lastCLKState)
    {
        if (currentCLK == LOW)
        {
            if (digitalRead(DT) != currentCLK)
            {
                if (encoderValue < 24)
                    encoderValue++;
            }
            else
            {
                if (encoderValue > 7)
                    encoderValue--;
            }

            showValue();

            sendVoltage();
        }
    }

    lastCLKState = currentCLK;
}

void showValue()
{
    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(10, 10);
    display.println("Output Voltage");

    display.setTextSize(2);
    display.setCursor(35, 30);
    display.print(encoderValue);
    display.print(" V");

    display.display();
}

void sendVoltage()
{
    DSPSerial.print(encoderValue);
    DSPSerial.print('\n');

    Serial.print("Sent to DSP: ");
    Serial.println(encoderValue);
}
