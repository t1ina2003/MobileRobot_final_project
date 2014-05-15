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
// library interface description
class Motorctl
{
  // user-accessible "public" interface
  public:
  	void Motorctl_Inital();
	void Forward_move();
	void Backward_move();
	void Left_move();
	void Right_move();
	void Stop_move();
	void SwitchAction(unsigned long);
};

#endif