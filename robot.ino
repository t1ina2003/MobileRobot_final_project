#include "IRremote.h" 
#include "Motorctl.h"

const int irReceiverPin = 2;          
IRrecv irrecv(irReceiverPin);            
decode_results results;
unsigned long  time_pass;
int pressure_signal;
int pressure;
Motorctl robot1;

void setup()
{
	Serial.begin(9600);                     // 開啟 Serial port, 通訊速率為 9600 bps
	irrecv.enableIRIn();                   // 啟動紅外線解碼
	robot1.Motorctl_Inital();
	robot1.Stop_move();
	pinMode(8,OUTPUT); //LED
}

void loop() 
{
	if (irrecv.decode(&results)) {
		robot1.SwitchAction(results.value);
		Serial.print("irCode: ");            
		Serial.print(results.value, DEC);    // 紅外線編碼
		Serial.print(",  bits: ");           
		Serial.println(results.bits);        // 紅外線編碼位元數
		irrecv.resume();                    // 繼續收下一組紅外線訊號      
	}
	pressure_signal = analogRead(A0);
	pressure = map(pressure_signal, 0, 1023, 1, 50); 
	
	//time_pass = millis();

	if((millis() %3000) == 0){
		Serial.println(pressure);
	}
	if(pressure>19){
		digitalWrite(8,HIGH);
	}else{
		digitalWrite(8,LOW);
	}
}

