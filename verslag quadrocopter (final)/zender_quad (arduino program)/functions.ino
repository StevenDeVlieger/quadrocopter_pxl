
unsigned char rescaler1(float potposition){
  float rekenvar;
  unsigned char returnval;
  
  rekenvar = potposition / 675;
  returnval = rekenvar * 100;
  return returnval;
}

unsigned char rescaler2(float motorpower){
  float rekenvar;
  unsigned char returnval;
  
  rekenvar = motorpower / 100;
  returnval = rekenvar * 255;
  return returnval;
}

signed char positivecheck(signed char motorpowervar){
  if (motorpowervar < 0){
    motorpowervar = 0;
  }
  return motorpowervar;
}

