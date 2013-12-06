#include <Wire.h>
#include <VirtualWire.h>

int Sensor1Data;

char speed;
char motor = 0;
char motorspeed[4]; 

void setup() {
  #define BL_CTRL 0X52
  delay(1000);
  Wire.begin();  
  Serial.begin(9600);
     vw_set_ptt_inverted(true); 
    // Bits per sec
    vw_setup(2000);        
    // Start the receiver PLL running
    vw_rx_start();  
}


void motorsturing(char motor, char speed){
  
  Wire.beginTransmission((BL_CTRL + ( motor << 1) >>1));
  Wire.write(speed);
  Wire.endTransmission();
  
  delay(10);
}




void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
  
    if (vw_get_message(buf, &buflen)){ 
        
      for (int i = 0; i < buflen; i++){  
          motorspeed[i] = char(buf[i]);
      }
      
      motorspeed[buflen] = '\0';  
    }

    for(int y=0;y<4;y++){
      motorsturing(y, motorspeed[y]);
    }
}

  
