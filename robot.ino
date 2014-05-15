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
	Serial.begin(9600);                     // �}�� Serial port, �q�T�t�v�� 9600 bps
	irrecv.enableIRIn();                   // �Ұʬ��~�u�ѽX
	robot1.Motorctl_Inital();
	robot1.Stop_move();
	pinMode(8,OUTPUT); //LED
}

void loop() 
{
	if (irrecv.decode(&results)) {
		robot1.SwitchAction(results.value);
		Serial.print("irCode: ");            
		Serial.print(results.value, DEC);    // ���~�u�s�X
		Serial.print(",  bits: ");           
		Serial.println(results.bits);        // ���~�u�s�X�줸��
		irrecv.resume();                    // �~�򦬤U�@�լ��~�u�T��      
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

