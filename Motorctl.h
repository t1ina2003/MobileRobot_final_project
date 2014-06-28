/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
  plz. use port 3,4(forward),5,6(Rotation) as
  Reference Code:
*/
// ensure this library description is only included once
	#ifndef Motorctl_h
	#define Motorctl_h
// include types & constants of Wiring core API
#include "Arduino.h"

//rc-100A Channel 1 code def
#define UKeyPress 1004609626
#define UKeyUp 3621003665
#define DKeyPress 1003461924
#define DKeyUp 3621003665
#define LKeyPress 2787973717
#define LKeyUp 3621003665
#define RKeyPress 1700840424
#define RKeyUp 3621003665

#define Key1Press 3039286897
#define Key1Up 3621003665
#define Key2Press 3039286897
#define Key2Up 3621003665
#define Key3Press 3039286897
#define Key3Up 3621003665
#define Key4Press 2605744107
#define Key4Up 3621003665

#define pressure_pin A0
#define Photointerrup 52

// library interface description
class Motorctl
{
  // non-user-accessible "public" interface
  private:
    int pressure ;
    int turn_count ;
    int last_time;

  // user-accessible "public" interface
  public:
  void Motorctl_Inital();
	void F_move();
	void B_move();
	void L_move();
	void R_move();
  void FL_move();
  void BL_move();
  void BR_move();
  void FR_move();
	void Stop_move();
	void SwitchAction(int );
  int Pressure_Boolean();   //intelligence pressure threshold adjust.
  int Photo_Boolean();  
};

#endif