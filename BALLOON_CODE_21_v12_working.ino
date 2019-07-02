/* Definitions start */
#include <FastLED.h>
// Tilt Sensor code for Robojax.com
#define TILT 23
#define DATA_PIN 17
#define NUM_LEDS 38
long timeWhenPressed = 0;
boolean timerActive = false;
boolean TILTOLD = false;
CRGB leds[NUM_LEDS]; //?
bool dir = 0;
int bright = 0;
int hitcount = 0;
boolean red = false;
/* Definitons finish*/

/*Setup start*/
void setup() {
  Serial.begin(115200);
  Serial.println("setup complete");
  pinMode(TILT, INPUT); //Define data input pin input pin
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
/* Setuop finished */

/* Main program starts */
void loop() {
  int TILT_SENSED = digitalRead(TILT);// read TILT sensor
  if (TILT_SENSED != TILTOLD) {
    timeWhenPressed = millis();
    timerActive = true;
    hitcount = hitcount + 1;
    int value = 0;
    Serial.println("Turn on leds here");
    /* Patterns start */

    /////////////////////////////////////////
    if (hitcount <= 10) {
      Serial.println("HAPPY");
      Serial.println(hitcount);
      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 190, 0);
        FastLED.show();
        delay(15);
      }
      FastLED.show();

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(130, 90, 0);
        FastLED.show();
        delay(9);
      }
      FastLED.show();

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        FastLED.show();
        delay(10);
      }
      FastLED.show();

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 100, 0);
        FastLED.show();
        delay(9);
      }
      FastLED.show();

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(120, 90, 0);
        FastLED.show();
      }
      FastLED.show();

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(50, 30, 0);
        FastLED.show();
      }
      FastLED.show();



    }
    /////////////////////////////////////////

    /////////////////////////////////////////
    if (hitcount > 10 && hitcount < 20) {
      Serial.println("PEACEFUL");
      Serial.println(hitcount);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 50, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 100, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 150, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 200, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 255, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 200, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 150, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 100, 0);
        yield();
      }
      FastLED.show();
      delay(100);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 50, 0);
        yield();
      }
      FastLED.show();
      delay(100);
    }
    /////////////////////////////////////////

    /////////////////////////////////////////
    if (hitcount > 20 && hitcount < 220) {
      Serial.println("EXCITED");
      Serial.println(hitcount);
      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CHSV(random(0, 255), 255, 255);
        yield();
      }
      FastLED.show();
    }
    /////////////////////////////////////////

    /////////////////////////////////////////
    if (hitcount > 220 && hitcount < 230) {
      Serial.println("LOVE");
      Serial.println(hitcount);
      for (int i = 0; i < NUM_LEDS; i = i + 1) {


        leds[i] = CRGB(255, 0, 255);
      }
      FastLED.show();
      delay(300);

      for (int i = 0; i < NUM_LEDS; i = i + 1) {


        leds[i] = CRGB(0, 0, 0);
      }
      FastLED.show();
      delay(100);

      for (int i = 0; i < NUM_LEDS; i = i + 1) {


        leds[i] = CRGB(255, 0, 255);
      }
      FastLED.show();
      delay(300);

      for (int i = 0; i < NUM_LEDS; i = i + 1) {


        leds[i] = CRGB(0, 0, 0);
      }
      FastLED.show();
      delay(500);

      for (int s = 0; s <  NUM_LEDS; s++)
      {
        if (dir == 0) {
          bright = bright + 5;
          delay(5);
        } else if (dir == 1) {
          bright = bright - 1;
          delay(15);
        }


        for (int i = 0; i < NUM_LEDS; i = i + 1) {


          leds[i] = CRGB(bright, 0, bright);
        }

        if (bright > 180)
        {
          dir = 1;
          //delay(20);
        } else if (bright == 0) {
          //delay(300);
          //Serial.println("delay now");
          dir = 0;
        }
      }
    }
    FastLED.show();
    /////////////////////////////////////////

    /////////////////////////////////////////
    if (hitcount > 230 && hitcount < 250)
    {
      Serial.println("INSECURE");
      Serial.println(hitcount);
      for (int i = 0; i < NUM_LEDS; i = i + 1)
      {
        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
      }
      for (int i = 0; i < NUM_LEDS; i = i + 1)
      {
        leds[i] = CRGB(0, 0, 255);
        FastLED.show();
        delay(20);
        leds[i + 1] = CRGB(0, 0, 255);
        FastLED.show();
        delay(20);

        leds[i] = CRGB(0, 0, 0);
        FastLED.show();
        delay(6);

        if (i > (NUM_LEDS / 2))
        {
          leds[i - (NUM_LEDS / 2)] = CRGB(0, 0, 255);
          FastLED.show();
          delay(40);
          leds[i - ((NUM_LEDS / 2) + 1)] = CRGB(0, 0, 255);
          Serial.println(i - ((NUM_LEDS / 2) - 1));
          FastLED.show();
          delay(40);

          leds[i - (NUM_LEDS / 2) - 1] = CRGB(0, 0, 0);
          FastLED.show();
          delay(6);

        }
        else
        {
          leds[((NUM_LEDS / 2) - 1)] = CRGB(0, 0, 0);
          FastLED.show();
          delay(6);

          leds[((NUM_LEDS / 2))] = CRGB(0, 0, 0);
          FastLED.show();
          delay(6);

          leds[((NUM_LEDS / 2) + 1)] = CRGB(0, 0, 0);
          FastLED.show();
          delay(6);
        }
      }
    }


    /////////////////////////////////////////
    /////////////////////////////////////////


    if (hitcount > 250 && hitcount < 270) {
      Serial.println("ANGRY");
      Serial.println(hitcount);
      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);

      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(255, 0, 0);
        yield();
      }
      FastLED.show();
      delay(50);
    }
    ////////////////////////////
    /////////////////////////////////////////
    if (hitcount >= 270) {
      Serial.println("SHUT DOWN");
      Serial.println(hitcount);
      for (int s = 0; s < NUM_LEDS; s++)
      {
        leds [s] = CRGB(0, 0, 0);
      }
      FastLED.show();
      delay(60000);
    }
    /////////////////////////////////////////

    FastLED.show();
  }
  /* Pattern finishes */

  /* sleep code starts */
  if (millis() - timeWhenPressed > 750 && timerActive == true)
  delay(5);
  {
    leds[random(0, NUM_LEDS)] = CRGB(255, 255, 255);
    delay(80);
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i].fadeToBlackBy( 20 );
    }
    FastLED.show();
  }
  if (millis() - timeWhenPressed > 60000 && timerActive == true)
  {
    hitcount = 0;
  }
  TILTOLD = TILT_SENSED;
}
/* Main prgram finishes here */
