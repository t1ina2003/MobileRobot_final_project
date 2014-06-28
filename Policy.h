/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
  plz. use port 3,4(forward),5,6(Rotation) as
  Reference Code:
*/
// ensure this library description is only included once
	#ifndef Policy_h
	#define Policy_h
// include types & constants of Wiring core API
#include "Arduino.h"
// library interface description
class Policy
{
  // user-accessible "public" interface
  public:
  void Policy_Inital();
	int Action(int sonar,int irint10,int irint9,int irint8);
};

#endif