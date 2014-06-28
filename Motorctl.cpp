/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
*/
// include core Wiring API
#include "Arduino.h"
// include this library's description file
#include "Motorctl.h"



#define Forward_move 1
#define Forward_left_move 2
#define Left_move 3
#define Backward_left_move 4
#define Backward_move 5
#define Backward_right_move 6
#define Right_move 7
#define Forward_right_move 8

#define Stop_action 9

/**
	   2   1   8
	    \  ↑  /
	3 ←    9   → 7
	    /  ↓  \
	   4   5   6

*/



void Motorctl::Motorctl_Inital(){
	pinMode(3,OUTPUT);  //back/forward control
  	pinMode(4,OUTPUT);  //back/forward control
  	pinMode(5,OUTPUT);  //left/right control
  	pinMode(6,OUTPUT);  //left/right control
  	pinMode(Photointerrup,INPUT);
  	turn_count = 0;
}

void Motorctl::F_move(){
	digitalWrite(3,LOW);
	digitalWrite(4,HIGH);
	digitalWrite(5,LOW);
	digitalWrite(6,LOW);
}
void Motorctl::B_move(){
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
	digitalWrite(5,LOW);
	digitalWrite(6,LOW);
}
void Motorctl::L_move(){
	if(Photo_Boolean() == 1){
		//delay(750);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,HIGH);
		digitalWrite(6,LOW);
	}else{
		// digitalWrite(3,HIGH);
		// digitalWrite(4,LOW);
	}

}
void Motorctl::R_move(){
	if(Photo_Boolean() == 1){
		//delay(750);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,HIGH);
	}else{
		// digitalWrite(3,HIGH);
		// digitalWrite(4,LOW);
	}
}

void Motorctl::FL_move(){
	digitalWrite(3,LOW);
	digitalWrite(4,HIGH);
	digitalWrite(5,HIGH);
	digitalWrite(6,LOW);
}
void Motorctl::BL_move(){
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
	digitalWrite(5,LOW);
	digitalWrite(6,HIGH);
}
void Motorctl::BR_move(){
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
	digitalWrite(5,HIGH);
	digitalWrite(6,LOW);
}
void Motorctl::FR_move(){
	digitalWrite(3,LOW);
	digitalWrite(4,HIGH);
	digitalWrite(6,HIGH);
	digitalWrite(5,LOW);
}

void Motorctl::Stop_move(){
	digitalWrite(3,LOW);
	digitalWrite(4,LOW);
	digitalWrite(5,LOW);
	digitalWrite(6,LOW);
}

int Motorctl::Pressure_Boolean(){
	int value = 0 ;
	// pressure = map(analogRead(pressure_pin), 0, 1023, 0, 255);
	// if(analogRead(pressure_pin)>70 || (pressure>=1 && pressure<100)){
	// 	pressure++;
	// 	value = 0;
	// }
	// if(pressure > 100 && pressure<200){
	// 	pressure++;
	// 	value = 1;
	// }
	// if (pressure > 200) pressure = 0;

	/// testcode
	if(analogRead(pressure_pin)>30){
		value = 1;
	}else{
		value = 0;
	}
	return value;
}



void Motorctl::SwitchAction(int action_receive){
	switch(action_receive){
		case Forward_move:			//1
			F_move();
			break;
		case Forward_left_move:		//2
			FL_move();
			break;
		case Left_move:				//3
			L_move();
			break;
		case Backward_left_move:	//4
			BL_move();
			break;
		case Backward_move:			//5
			B_move();
			break;
		case Backward_right_move:	//6
			BR_move();
			break;
		case Right_move:			//7
			R_move();
			break;
		case Forward_right_move:	//8
			FR_move();
			break;
		case Stop_action:			//9
			Stop_move();
			break;
	}
}

int Motorctl::Photo_Boolean(){
	return digitalRead(Photointerrup);
}
