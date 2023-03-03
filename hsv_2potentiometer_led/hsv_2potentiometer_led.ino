#include "structs.h"

int huePin = A0;
int brightnessPin = A2;
int hval = 0;
int bval = 0;
float hV = 0;
float bV = 0;
int rp = 11;
int gp = 10;
int bp = 9;
int dt = 3000;

rgb hsv_to_rgb(hsv colour)
{
  float C = colour.v * colour.s;
  float H1 = colour.h / 60.;
  float X = C * (1. - abs(modulo(H1, 2) - 1.));
  
  rgb output;
  if (0. <= H1 && H1 < 1.)
  {
    output.r = C;
    output.g = X;
    output.b = 0;
  }
  else if (1. <= H1 && H1 < 2.)
  {
    output.r = X;
    output.g = C;
    output.b = 0;
  }
  else if (2. <= H1 && H1 < 3.)
  {
    output.r = 0;
    output.g = C;
    output.b = X;
  }
  else if (3. <= H1 && H1 < 4.)
  {
    output.r = 0;
    output.g = X;
    output.b = C;
  }
  else if (4. <= H1 && H1 < 5.)
  {
    output.r = X;
    output.g = 0;
    output.b = C;
  }
  else if (5. <= H1 && H1 < 6.)
  {
    output.r = C;
    output.g = 0;
    output.b = X;
  }
  
  float m = colour.v - C;
  output.r += m;
  output.g += m;
  output.b += m;
  
  return output;
}


 hsv hsv_colour;
 rgb rgb_colour;

void setup() {
  // put your setup code here, to run once:
  pinMode(huePin, INPUT);
  pinMode(brightnessPin, INPUT);
  
  pinMode(rp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(bp, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  hval = analogRead(huePin);
  bval = analogRead(brightnessPin);

  hV = 5. / 1023. * hval;
  bV = 5. / 1023. * bval;

  hsv_colour.h = hV * 360. / 5.;
  hsv_colour.s = 1.;
  hsv_colour.v = bV / 5.; // / by 5 is to reduce to 0 - 1 range. Bigger scalar to reduce max value and reduce brightness

  // print hue and value
  Serial.print("hue = ");
  Serial.println(hsv_colour.h);
  Serial.print("brightness = ");
  Serial.println(hsv_colour.v);
  Serial.println("");

  rgb_colour = hsv_to_rgb(hsv_colour);


  Serial.println((String)"rgb int values: (" + rgb_colour.r_int() + ", " + rgb_colour.g_int() + ", " + rgb_colour.b_int() + ")");
  Serial.println("");
  Serial.println("");

  analogWrite(rp, rgb_colour.r_int());
  analogWrite(gp, rgb_colour.g_int());
  analogWrite(bp, rgb_colour.b_int());
  
  delay(dt);
}
