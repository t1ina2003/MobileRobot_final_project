/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
  plz. use port 3,4(forward),5,6(Rotation) as
  Reference Code:
*/
// ensure this library description is only included once
	#ifndef sonar_h
	#define sonar_h
// include types & constants of Wiring core API
#include "Arduino.h"
// library interface description
class sonar
{
  double cm_F , cm_L , cm_R;
  double warning ;//initial setting 25cm(by my calulate)

  // user-accessible "public" interface
  public:

    void Sonar_Inital();
    void Set_Sonar(double x);
    void Open_Forward_Sonar(bool);
    void Open_Left_Sonar(bool);
    void Open_Right_Sonar(bool);
    double Read_Forward();
    double Read_Left();
    double Read_Right();
    int Sonar();
};

#endif