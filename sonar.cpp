/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
*/
// include core Wiring API
#include "Arduino.h"
// include this library's description file
#include "sonar.h"
// define basic obstacle style(6)
#define nothing 0
#define F 1         		//near the forward obstacle
#define L 2         		//near the left obstacle
#define R 3         		//near the right obstacle
#define FL 12               
#define FR 13               
#define RL 23
#define FLR 123

// 
#define Forward_TrigPin 35  	//TrigPin of forward sonar
#define Forward_EchoPin 37  	//EchoPin
#define Left_TrigPin 31     	//TrigPin of left sonar
#define Left_EchoPin 33     	//EchoPin 
#define Right_TrigPin 39    	//TrigPin of right sonar
#define Right_EchoPin 41    	//EchoPin



/*
  "BASIC" SETTING FOR USERs: 
  Start sonar with 
  <1> Inital function of sonar(including F, L, R)    @ Sonar_Inital(void) @
  <2> Set closing distance for warning               @ Set_Near(double)   @
  													 @ Set_Danger(double) @
  <3> Set delay some time to receive ECHO signal     @ Set_DelayTime(int) @
  
  "ADVANCE" SETTING FOR USERs: 
  Deaign policy by youself, you may need
  <1> Set
*/
void sonar::Sonar_Inital()
{
	delaytime = 800;
	near = 25;
	danger = 20;
	pinMode(Forward_TrigPin, OUTPUT); //前面
	pinMode(Forward_EchoPin, INPUT); 
	pinMode(Left_TrigPin, OUTPUT); //左邊
	pinMode(Left_EchoPin, INPUT); 
	pinMode(Right_TrigPin, OUTPUT); //右邊
	pinMode(Right_EchoPin, INPUT); 
}


void sonar::Set_Near(double nd)
{	near = nd;	}

void sonar::Set_Danger(double dd)
{	danger = dd;	}

void sonar::Set_DelayTime(int t)
{	delaytime = t;	}

/*
  Distinguish whether or not visit obstacle(separate each Forward, Left, Right)
*/
int sonar::PureDetect()
{
	while(1)
	{
		StartTrig_Forward(true);
		d1 = ReadEcho_Forward();
		StartTrig_Left(true);
		d2 = ReadEcho_Left();
		StartTrig_Right(true);
		d3 = ReadEcho_Right();
		
		if( d1 > near && d2 > near && d3 > near) return nothing;
		if( d1 <= near && d2 > near && d3 > near) return F;
		if( d1 > near && d2 <= near && d3 > near) return L;
		if( d1 > near && d2 > near && d3 <= near) return R;
	    if( d1 <= near && d2 <= near && d3 > near) return FL;
		if( d1 <= near && d2 > near && d3 <= near) return FR;
		if( d1 > near && d2 <= near && d3 <= near) return RL;
		if( d1 <= near && d2 <= near && d3 <= near) return FLR;

	}//the end of while Loop
}
/*
  Open sonar(separate each Forward, Left, Right)
*/
void sonar::StartTrig_Forward(bool b)
{
	if(b == true)
	{
		digitalWrite(Forward_TrigPin, LOW); //低高低電平發一個短時間脈衝Forward_TrigPin 
		delayMicroseconds(2); 
		digitalWrite(Forward_TrigPin, HIGH); 
		delayMicroseconds(10); 
		digitalWrite(Forward_TrigPin, LOW);
		//delay(delaytime); //延遲讀取echo訊號的時間
	}
	else
	{
		digitalWrite(Forward_TrigPin, LOW);  
		delayMicroseconds(2); 
		digitalWrite(Forward_TrigPin, LOW); 
		delayMicroseconds(10); 
		digitalWrite(Forward_TrigPin, LOW);
	}
}

void sonar::StartTrig_Left(bool b)
{
	if(b == true)
	{
		digitalWrite(Left_TrigPin, LOW); //低高低電平發一個短時間脈衝Left_TrigPin 
		delayMicroseconds(2); 
		digitalWrite(Left_TrigPin, HIGH); 
		delayMicroseconds(10); 
		digitalWrite(Left_TrigPin, LOW); 
		//delay(delaytime);
	}
	else
	{
		digitalWrite(Left_TrigPin, LOW);  
		delayMicroseconds(2); 
		digitalWrite(Left_TrigPin, LOW); 
		delayMicroseconds(10); 
		digitalWrite(Left_TrigPin, LOW); 
	}
}

void sonar::StartTrig_Right(bool b)
{
	if(b == true)
	{
		digitalWrite(Right_TrigPin, LOW); //低高低電平發一個短時間脈衝Right_TrigPin 
		delayMicroseconds(2); 
		digitalWrite(Right_TrigPin, HIGH); 
		delayMicroseconds(10); 
		digitalWrite(Right_TrigPin, LOW);
		//delay(delaytime);
	}
	else
	{
		digitalWrite(Right_TrigPin, LOW);  
		delayMicroseconds(2); 
		digitalWrite(Right_TrigPin, LOW); 
		delayMicroseconds(10); 
		digitalWrite(Right_TrigPin, LOW);
	}
	 	
}

/*
  Read sonar(separate each Forward, Left, Right)
*/
double sonar::ReadEcho_Forward()
{
	cm_F = pulseIn(Forward_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_F = (int(cm_F * 100.0)) / 100.0; //保留兩位小數 
	return cm_F;
}

double sonar::ReadEcho_Left()
{
	cm_L = pulseIn(Left_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_L = (int(cm_L * 100.0)) / 100.0; //保留兩位小數 
	return cm_L;
}

double sonar::ReadEcho_Right()
{
	cm_R = pulseIn(Right_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_R = (int(cm_R * 100.0)) / 100.0; //保留兩位小數 
	return cm_R;
}


