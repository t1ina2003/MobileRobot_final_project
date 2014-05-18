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
// define obstacle style(4)
#define Keep_going 1 //NO!Forward_obstacle
#define Right_turn 2 //Forward_Left_obstacle
#define Left_turn 3 //Forward_Right_obstacle
#define Back 4 //FLR_obstacle
// 
#define Forward_TrigPin 31 //前面
#define Forward_EchoPin 33 
#define Left_TrigPin 35 //左邊
#define Left_EchoPin 37 
#define Right_TrigPin 39 //右邊
#define Right_EchoPin 41 



/*
  Start setting sonar with 
  Inital function and set function for changing closing distance for warning
*/
void sonar::Sonar_Inital()
{
	pinMode(Forward_TrigPin, OUTPUT); //前面
	pinMode(Forward_EchoPin, INPUT); 
	pinMode(Left_TrigPin, OUTPUT); //左邊
	pinMode(Left_EchoPin, INPUT); 
	pinMode(Right_TrigPin, OUTPUT); //右邊
	pinMode(Right_EchoPin, INPUT); 
}


void sonar::Set_Sonar(double x)
{
	warning = x;
}

/*
  Open sonar(separate each Forward, Left, Right)
*/
  
void sonar::Open_Forward_Sonar(bool b)
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

void sonar::Open_Left_Sonar(bool b)
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

void sonar::Open_Right_Sonar(bool b)
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
  
double sonar::Read_Forward()
{
	cm_F = pulseIn(Forward_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_F = (int(cm_F * 100.0)) / 100.0; //保留兩位小數 
	return cm_F;
}

double sonar::Read_Left()
{
	cm_L = pulseIn(Left_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_L = (int(cm_L * 100.0)) / 100.0; //保留兩位小數 
	return cm_L;
}

double sonar::Read_Right()
{
	cm_R = pulseIn(Right_EchoPin, HIGH) / 58.0; //將回波時間換算成cm 
	cm_R = (int(cm_R * 100.0)) / 100.0; //保留兩位小數 
	return cm_R;
}

/*
  Distinguish whether or not visit obstacle(separate each Forward, Left, Right)
*/
  
int sonar::Sonar()
{
	while(1)
	{
		//still opening Forward sonar, Forward-non-stop!
		Open_Forward_Sonar(true);
		//Distinguish
		if( Read_Forward() <= warning)
		{
			Open_Left_Sonar(true);
			Open_Right_Sonar(true); 

			if(Read_Left() <= warning)
			{
				Open_Left_Sonar(false);
				Open_Right_Sonar(false);
				return Right_turn;
			}
			else if(Read_Right() <= warning)
			{
				Open_Left_Sonar(false);
				Open_Right_Sonar(false);
				return Left_turn;
			}
			else if(Read_Left() <= warning && Read_Right() <= warning)
			{
				Open_Left_Sonar(false);
				Open_Right_Sonar(false);
				return Back;
			}
			else
			{	
				Open_Left_Sonar(false);
				Open_Right_Sonar(false);
				//一律右轉
				return Right_turn;
			}
		}
		else
		{
			return Keep_going;
		}
	}//the end of while Loop
}
