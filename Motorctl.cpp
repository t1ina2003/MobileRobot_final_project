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
//rc-100A Channel 1 code def
#define	UKeyPress 1004609626
#define	UKeyUp 3621003665
#define	DKeyPress 1003461924
#define	DKeyUp 3621003665
#define	LKeyPress 2787973717
#define	LKeyUp 3621003665
#define	RKeyPress 1700840424
#define	RKeyUp 3621003665

#define	Key1Press 3039286897
#define	Key1Up 3621003665
#define	Key2Press 3039286897
#define	Key2Up 3621003665
#define	Key3Press 3039286897
#define	Key3Up 3621003665
#define	Key3Press 2605744107
#define	Key3Up 3621003665

void Motorctl::Motorctl_Inital(){
  pinMode(3,OUTPUT);  //back/forward control
  pinMode(4,OUTPUT);  //back/forward control
  pinMode(5,OUTPUT);  //left/right control
  pinMode(6,OUTPUT);  //left/right control
}

void Motorctl::Forward_move(){
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);
}
void Motorctl::Backward_move(){
	digitalWrite(4,HIGH);
	digitalWrite(3,LOW);
}
void Motorctl::Left_move(){
	digitalWrite(5,HIGH);
	digitalWrite(6,LOW);
}
void Motorctl::Right_move(){
	digitalWrite(6,HIGH);
	digitalWrite(5,LOW);
}
void Motorctl::Stop_move(){
	digitalWrite(3,LOW);
	digitalWrite(4,LOW);
	digitalWrite(5,LOW);
	digitalWrite(6,LOW);
}
void Motorctl::SwitchAction(unsigned long IRnumber){
	switch(IRnumber){
		case UKeyPress:
			Forward_move();
			break;
		case DKeyPress:
			Backward_move();
			break;
		case LKeyPress:
			Left_move();
			break;
		case RKeyPress:
			Right_move();
			break;
		case Key1Press:
			Stop_move();
			break;
	}
}