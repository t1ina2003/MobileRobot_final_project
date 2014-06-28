#include "Motorctl.h"
#include "Sonar.h"
#include "Policy.h"
#include "IRremote.h"                    

#include <LiquidCrystal.h>

int action;
int v_sonar;
sonar sonar1;
Policy policy1;
Motorctl robot1;

int irint8,irint9,irint10;
IRrecv irrecv10(2); //right            
// IRrecv irrecv9(9); //middle
// IRrecv irrecv8(8); //left
decode_results results10;                  
// decode_results results9;                  
// decode_results results8;   

LiquidCrystal lcd(32, 30, 28, 26, 24, 22);

void setup()
{
	Serial.begin(9600);                     // 開啟 Serial port, 通訊速率為 9600 
	lcd.begin(16, 2);

	sonar1.Sonar_Inital();
	sonar1.Set_Distance(15,25);
	robot1.Motorctl_Inital();
	robot1.Stop_move();

	irrecv10.enableIRIn();                   // 啟動紅外線解碼
	// irrecv9.enableIRIn();                   // 啟動紅外線解碼
	// irrecv8.enableIRIn();                   // 啟動紅外線解碼
}

void loop()
{

 	if (irrecv10.decode(&results10)) {         // 解碼成功&#65292;收到一組紅外線訊號
    // 印到 Serial port  
    Serial.print("ir10Code: ");            
    Serial.print(results10.value);    // 紅外線編碼
    Serial.print(",  bits: ");           
    Serial.println(results10.bits);        // 紅外線編碼位元數
    if(results10.value == 83577015) irint10=1;
    else irint10=0;
  	}else{
  		irint10=0;
  	}

  	// if (irrecv9.decode(&results9)) {         // 解碼成功&#65292;收到一組紅外線訊號
   //  // 印到 Serial port  
   //  Serial.print("ir9Code: ");            
   //  Serial.print(results9.value);    // 紅外線編碼
   //  Serial.print(",  bits: ");           
   //  Serial.println(results9.bits);        // 紅外線編碼位元數
   //  if(results9.value == 83577015) irint9=1;
   //  else irint9=0;
  	// }else{
  	// 	irint9=0;
  	// }

  	// if (irrecv8.decode(&results8)) {         // 解碼成功&#65292;收到一組紅外線訊號
   //  // 印到 Serial port  
   //  Serial.print("ir8Code: ");            
   //  Serial.print(results8.value);    // 紅外線編碼
   //  Serial.print(",  bits: ");           
   //  Serial.println(results8.bits);        // 紅外線編碼位元數
   //  if(results8.value == 83577015) irint8=1;
   //  else irint8=0;
  	// }else{
  	// 	irint8=0;
  	// }

  	irrecv10.resume();
  	// irrecv9.resume();
  	// irrecv8.resume();

	v_sonar = sonar1.FUZZYDetect();
	action = policy1.Action(v_sonar,irint10,irint9,irint8);
	robot1.SwitchAction(1);

	lcd.setCursor(0, 0);
	lcd.print("Sensor:");
	lcd.print(v_sonar);
	lcd.print("  ");
	lcd.setCursor(0, 1);
	lcd.print("A1:");
	lcd.print(robot1.Photo_Boolean());
	lcd.print("  ");
	lcd.setCursor(5, 1);
	lcd.print("L");
	lcd.print(irint8);
	lcd.setCursor(7, 1);
	lcd.print("M");
	lcd.print(irint9);
	lcd.setCursor(9, 1);
	lcd.print("R");
	lcd.print(irint10);
	delay(200);
}




