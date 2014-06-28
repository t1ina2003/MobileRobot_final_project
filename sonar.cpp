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
// for twodetect
#define near_F 4         		//near the forward obstacle
#define near_L 5         		//near the left obstacle
#define near_R 6         		//near the right obstacle
#define near_FL 45               
#define near_FR 46               
#define near_RL 56
#define near_FLR 456

#define far_F 7        		    //far the forward obstacle
#define far_L 8         		//far the left obstacle
#define far_R 9         		//far the right obstacle
#define far_FL 78               
#define far_FR 79               
#define far_RL 89
#define far_FLR 789
// FUZZY-RULEs
//#define nothing 0
#define nearF 101        		
#define nearL 102        		
#define nearR 103
#define farF 104      		    
#define farL 105        		
#define farR 106       		

#define nFnL 107              
#define nFfL 108               
#define fFnL 109
#define fFfL 110

#define nFnR 111              
#define nFfR 112               
#define fFnR 113
#define fFfR 114

#define nLnR 115              
#define nLfR 116               
#define fLnR 117
#define fLfR 118

#define nFnLnR 119              
#define nFnLfR 120               
#define nFfLnR 121
#define nFfLfR 122
#define fFnLnR 123              
#define fFnLfR 124               
#define fFfLnR 125
#define fFfLfR 126
//
#define nValue 2              
#define fValue 5
#define g 9
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
	near = 10;
	far = 15;
	pinMode(Forward_TrigPin, OUTPUT); //前面
	pinMode(Forward_EchoPin, INPUT); 
	pinMode(Left_TrigPin, OUTPUT);    //左邊
	pinMode(Left_EchoPin, INPUT); 
	pinMode(Right_TrigPin, OUTPUT);   //右邊
	pinMode(Right_EchoPin, INPUT); 
	
}


void sonar::Set_Distance(double n,double f)
{ near = n;	far = f; }


/*
  Distinguish whether or not visit obstacle(separate each Forward, Left, Right)
*/
int sonar::PureDetect()
{
	OpenandGet_Forward();
	OpenandGet_Left();
	OpenandGet_Right();

	if( d1 > near && d2 > near && d3 > near) return 0;
	if( d1 <= near && d2 > near && d3 > near) return 1;
	if( d1 > near && d2 <= near && d3 > near) return 2;
	if( d1 > near && d2 > near && d3 <= near) return 3;
    if( d1 <= near && d2 <= near && d3 > near) return 12;
	if( d1 <= near && d2 > near && d3 <= near) return 13;
	if( d1 > near && d2 <= near && d3 <= near) return 23;
	if( d1 <= near && d2 <= near && d3 <= near) return 123;

}

int sonar::TwoDetect()
{
	OpenandGet_Forward();
	OpenandGet_Left();
	OpenandGet_Right();

	if( d1 <= far || d2 <= far || d3 <= far)
	{
		if(d1 <= near || d2 <= near || d3 <= near)
		{
			if( d1 <= near && d2 <= near && d3 <= near) return near_FLR;
		    if( d1 <= near && d2 <= near) return near_FL;
			if( d1 <= near && d3 <= near) return near_FR;
			if( d2 <= near && d3 <= near) return near_RL;
			if( d1 <= near) return near_F;
			if( d2 <= near) return near_L;
			if(  d3 <= near) return near_R;
		}
		else
		{
			if( d1 <= far && d2 <= far && d3 <= far) return far_FLR;
		    if( d1 <= far && d2 <= far) return far_FL;
			if( d1 <= far && d3 <= far) return far_FR;
			if( d2 <= far && d3 <= far) return far_RL;
			if( d1 <= far) return far_F;
			if( d2 <= far) return far_L;
			if( d3 <= far) return far_R;
		}
	}
	else
		return nothing;

}

int sonar::FUZZYDetect()
{
	OpenandGet_Forward();
	OpenandGet_Left();
	OpenandGet_Right();

	t1 = fuzzifiter(d1);
	t2 = fuzzifiter(d2);
	t3 = fuzzifiter(d3);

	return Rules(t1,t2,t3);
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
//
double sonar::Get_cmF()
{ return cm_F; }

double sonar::Get_cmL()
{ return cm_L; }

double sonar::Get_cmR()
{ return cm_R; }

double sonar::Get_near()
{ return near; }

double sonar::Get_far()
{ return far; }

//
void sonar::OpenandGet_Forward()
{
	StartTrig_Forward(true);
	d1 = ReadEcho_Forward();
}

void sonar::OpenandGet_Left()
{
	StartTrig_Left(true);
	d2 = ReadEcho_Left();
}

void sonar::OpenandGet_Right()
{
	StartTrig_Right(true);
	d3 = ReadEcho_Right();
}
//fuzzy function
int sonar::fuzzifiter(double D)
{
	if(D > far) return g;
	if(D <= near) return nValue;
	if(near < D <= far) return fValue;
}

int sonar::Rules(int f1,int f2,int f3)
{
	if(f1 == g && f2 == g && f3 == g) return nothing; //R1

	if(f1 == nValue && f2 == g && f3 == g) return nearF;   //R2
	if(f1 == g && f2 == nValue && f3 == g) return nearL;   //R3
	if(f1 == g && f2 == g && f3 == nValue) return nearR;   //R4

	if(f1 == fValue && f2 == g && f3 == g) return farF;   //R5
	if(f1 == g && f2 == fValue && f3 == g) return farL;   //R6
	if(f1 == g && f2 == g && f3 == fValue) return farR;   //R7

	if(f1 == nValue && f2 == nValue && f3 == g) return nFnL;   //R8
	if(f1 == nValue && f2 == fValue && f3 == g) return nFfL;   //R9
	if(f1 == fValue && f2 == nValue && f3 == g) return fFnL;   //R10
	if(f1 == fValue && f2 == fValue && f3 == g) return fFfL;   //R11

	if(f1 == nValue && f2 == g && f3 == nValue) return nFnR;   //R12
	if(f1 == nValue && f2 == g && f3 == fValue) return nFfR;   //R13
	if(f1 == fValue && f2 == g && f3 == nValue) return fFnR;   //R14
	if(f1 == fValue && f2 == g && f3 == fValue) return fFfR;   //R15

	if(f1 == g && f2 == nValue && f3 == nValue) return nLnR;   //R16
	if(f1 == g && f2 == nValue && f3 == fValue) return nLfR;   //R17
	if(f1 == g && f2 == fValue && f3 == nValue) return fLnR;   //R18
	if(f1 == g && f2 == fValue && f3 == fValue) return fLfR;   //R19

	if(f1 == nValue && f2 == nValue && f3 == nValue) return nFnLnR;   //R20
	if(f1 == nValue && f2 == nValue && f3 == fValue) return nFnLfR;   //R21
	if(f1 == nValue && f2 == fValue && f3 == nValue) return nFfLnR;   //R22
	if(f1 == nValue && f2 == fValue && f3 == fValue) return nFfLfR;   //R23

	if(f1 == fValue && f2 == nValue && f3 == nValue) return fFnLnR;   //R24
	if(f1 == fValue && f2 == nValue && f3 == fValue) return fFnLfR;   //R25
	if(f1 == fValue && f2 == fValue && f3 == nValue) return fFfLnR;   //R26
	if(f1 == fValue && f2 == fValue && f3 == fValue) return fFfLfR;   //R27
}