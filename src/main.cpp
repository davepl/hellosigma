#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN0 0
#define NUM_LEDS 32

static CRGB leds[NUM_LEDS];

void setup() 
{
      FastLED.addLeds<WS2812B, LED_PIN0, GRB>(leds, NUM_LEDS);
}

void loop() 
{
    static byte initialHue = 0;

    CHSV hsv(initialHue, 255, 240);
    for (int i = 0; i < NUM_LEDS; i++)
    {
        CRGB rgb;
        hsv2rgb_rainbow(hsv, rgb);
        leds[i] = hsv;
        hsv.hue += (256/NUM_LEDS);
    }
    initialHue += 4;
    FastLED.show();
    delay(30);
}