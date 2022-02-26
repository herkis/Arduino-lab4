#include <Zumo32U4.h>
Zumo32U4LineSensors lineSensors;
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
unsigned int lineSensorValues[5];
const uint16_t maxSpeed = 400;
int16_t lastError = 0;

void setup() { 
  lineSensors.initFiveSensors(); 
  calLightSensors(10); 
  lcd.clear(); 
  lcd.gotoXY(0,0); 
  lcd.print("Press A"); 
  lcd.gotoXY(0,1); 
  lcd.print("to Cont."); 
  buttonA.waitForButton();   
  buzzer.playFrequency(440, 200, 15); 
  lcd.clear(); 
} 

void loop() { 
lineSensors.readCalibrated(lineSensorValues); 
  displayLCD(); 
  delay(50);
  if (buttonB.isPressed()) {
    while(true){
      movement();
    }
  }
  
}

void calLightSensors(int CalTime) { 
  lcd.clear(); 
  lcd.gotoXY(0,0); 
  lcd.print("Press A"); 
  lcd.gotoXY(0,1); 
  lcd.print("to Cal"); 
  buttonA.waitForButton(); 
  buzzer.playFrequency(440, 200, 15); 
  lcd.clear(); 
  lcd.print("Cal\'ing"); 
  for (int i = 20*CalTime; i > 0; i--) {
    motors.setSpeeds(200, -200); 
    lcd.gotoXY(0, 1); 
    if(i%20==0) { 
      lcd.print(i/20); 
      lcd.print(" "); 
      buzzer.playFrequency(440, 50, 15); 
    } 
    lineSensors.calibrate(); 
    delay(20); 
  }
  motors.setSpeeds(0, 0); 
  buzzer.playFrequency(600, 200, 15); 
  lcd.clear(); 
  lcd.print("Cal Done"); 
  delay(1000); 
} 

void displayLCD () { 
  lcd.clear(); 
  lcd.gotoXY(2, 0); 
  lcd.print(lineSensorValues[1]%100); 
  lcd.gotoXY(0, 1); 
  lcd.print(lineSensorValues[0]%100); 
  lcd.gotoXY(6, 1); 
  lcd.print(lineSensorValues[4]%100);
  lcd.gotoXY(5, 0); 
  lcd.print(lineSensorValues[2]%100);
  lcd.gotoXY(3, 1); 
  lcd.print(lineSensorValues[3]%100);
} 





void movement(){
  int16_t position = lineSensors.readLine(lineSensorValues);
  if (position < 1950) {
    motors.setSpeeds(50, 400);
  }
  else if (position > 2050) {
    motors.setSpeeds(400, 50);
  }
  else{
    motors.setSpeeds(300, 300);
  }
  lcd.clear();
  lcd.print(position);
}
