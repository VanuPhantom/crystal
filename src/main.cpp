#include <LiquidCrystal.h>
#include <Arduino.h>

LiquidCrystal LCD(35, 36, 37, 38, 39, 40);

void setup()
{
    LCD.begin(16, 2);
}

char BLURPS[4][3] = {{'>', 'w', '>'}, {'<', 'w', '<'}, {'>', 'w', '<'}, {'^', 'w', '^'}};

void kittyLoop()
{
    for (int i = 0; i < sizeof(BLURPS) / sizeof(BLURPS[0]); i++)
    {
        LCD.setCursor(13, 1);
        LCD.print(BLURPS[i]);
        delay(1000);
    }
}

char *MESSAGES[] = {"vanu.dev", "@VanuPhantom"};

void lowerLoop()
{
    for (int i = 0; i < sizeof(MESSAGES) / sizeof(char *); i++)
    {
        LCD.setCursor(0, 1);
        LCD.print(MESSAGES[i]);
        kittyLoop();
    }
}

void loop()
{
    LCD.clear();

    LCD.setCursor(0, 0);
    LCD.print("Tess (It/Its)");

    lowerLoop();
}