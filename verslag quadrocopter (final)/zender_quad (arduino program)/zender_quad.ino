#include <VirtualWire.h>

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  vw_setup(2000);
}

int leftpoty;
int rightpotx;
int rightpoty;
unsigned char byteleftpoty;
unsigned char byterightpotx;
unsigned char byterightpoty;
char motor[4];
signed char rekenvar;
signed char motorvar[4]; 



void loop() {
  
  leftpoty = analogRead(A0);
  rightpotx = analogRead(A1);
  rightpoty = analogRead(A2);
  
 byteleftpoty = rescaler1(leftpoty);
 byterightpotx = rescaler1(rightpotx);
 byterightpoty = rescaler1(rightpoty);
 
 for(int i=0;i<4;i++){
   motorvar[i] = 100 - byteleftpoty;
 }
 
 if (byterightpotx > 50){
   rekenvar = byterightpotx - 50;
   motorvar[0] = motorvar[0] - rekenvar;
   motorvar[3] = motorvar[3] - rekenvar;
 }
 
 if (byterightpotx < 50){
   rekenvar = 50 - byterightpotx;
   motorvar[1] = motorvar[1] - rekenvar;
   motorvar[2] = motorvar[2] - rekenvar;
 }
 
 if (byterightpoty > 50){
   rekenvar = byterightpoty - 50;
   motorvar[2] = motorvar[2] - rekenvar;
   motorvar[3] = motorvar[3] - rekenvar;
 }
 
 if (byterightpoty < 50){
   rekenvar = 50 - byterightpoty;
   motorvar[0] = motorvar[0] - rekenvar;
   motorvar[1] = motorvar[1] - rekenvar; 
 }
 
for(int i=0;i<4;i++){
    motorvar[i] = positivecheck(motorvar[i]);
 }
 
for(int i=0;i<4;i++){
   motor[i] = rescaler2(motorvar[i]);
 }
 
 vw_send((uint8_t *)motor, strlen(motor));
 
    Serial.println(motor[0]);
    Serial.println(motor[1]);
    Serial.println(motor[2]);
    Serial.println(motor[3]);
  
}
