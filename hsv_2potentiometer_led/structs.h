

float clamp(float val, float min, float max)
{
  if (val < min)
    return min;
  else if (val > max)
    return max;
  return val;
}

float modulo(float val, float div)
{
  while (val > div)
  {
    val -= div;
  }
  return val;
}

struct rgb
{
  float r;
  float g;
  float b;
  
  rgb()
  {
    r = 0;
    g = 0;
    b = 0;
  }
  
  rgb(float red, float green, float blue)
  {
    r = red;
    g = green;
    b = blue;
  }
  
  rgb(uint8_t red, uint8_t green, uint8_t blue)
  {
    r = (float)red / 256.;
    g = (float)green / 256.;
    b = (float)blue / 256.;
  }
  
  uint8_t r_int()
  {
    return 256. * r;
  }
  
  uint8_t g_int()
  {
    return 256. * g;
  }
  
  uint8_t b_int()
  {
    return 256. * b;
  }
};

struct hsv
{
  float h;
  float s;
  float v;
  
  hsv()
  {
    h = 0;
    s = 0;
    v = 0;
  }

  hsv(float hue, float saturation, float value)
  {
    h = clamp(hue, 0., 360.);
    s = clamp(saturation, 0., 1.);
    v = clamp(value, 0., 1.);
  }
};