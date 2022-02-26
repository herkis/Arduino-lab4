//Importere Zumo bibliotek og deklarere variabler
#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;


void setup() {
  // put your setup code here, to run once:
buttonA.waitForButton();
lightshow();


}

//Kjører 8 talls funksjonen. Deretter delay i 2 sek så den fortsetter
//å kjøre i ring samme retning. Så endre rotasjon
void loop() {
eightfigure();
delay(2000);
motors.setSpeeds(50, 300);
delay(4000);
}

//Funksjon for kjøring i 8 tall. 
void eightfigure(){
  for (int i = 0; i <= 3; i++){

motors.setSpeeds(50, 300);
delay(2000);
motors.setSpeeds(300, 50);
delay(2000);
}
}
//funksjon for blink og buzzersekvens
void lightshow(){
for (int i = 0; i<= 3; i++){
ledYellow(1);
delay(100);
ledYellow(0);
delay(100);
buzzer.playFrequency(440, 200, 10);
}
}
