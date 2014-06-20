#include "IRremote.h" 
#include "Motorctl.h"
#include "Sonar.h"
#include "Policy.h"

#include <LiquidCrystal.h>       

int action,v_sonar;
sonar sonar1;
Policy policy1;
Motorctl robot1;

const int irReceiverPin = 2;             
IRrecv irrecv(irReceiverPin);            
decode_results results;                  

int plus=0;

LiquidCrystal lcd(32, 30, 28, 26, 24, 22);


void setup()
{
	Serial.begin(9600);                     // 開啟 Serial port, 通訊速率為 9600 
	lcd.begin(16, 2);
	sonar1.Sonar_Inital();
	sonar1.Set_Distance(20,30); //near, far
	robot1.Motorctl_Inital();
	robot1.Stop_move();
	irrecv.enableIRIn(); 
}

void loop()
{
	v_sonar = sonar1.PureDetect();
	action = policy1.Action(v_sonar);
	robot1.SwitchAction(3);
	
	lcd.setCursor(0, 0);
	lcd.print("Sensor:");
	lcd.print(v_sonar);
	lcd.print("  ");
	lcd.setCursor(0, 1);
	lcd.print("pre:");
	lcd.print(robot1.Pressure_Boolean());
	lcd.print("   ");
	delay(200);

}

