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
  int delaytime;
  double cm_F,cm_L,cm_R;
  double d1,d2,d3;
  double near;//initial setting is 25cm(by my calulate)
  double danger;//initial setting is 20cm


  // user-accessible "public" interface
  public:

    void Sonar_Inital(); //set TrigPin, EchoPin, nearDistance, toocloseDistance
    void Set_Near(double); //distance when robot near obstacle
    void Set_Danger(double); //distance when robot to close to obstacle
    void Set_DelayTime(int); //delay some time to receive ECHO signal

    void StartTrig_Forward(bool);
    void StartTrig_Left(bool);
    void StartTrig_Right(bool);
    double ReadEcho_Forward();
    double ReadEcho_Left();
    double ReadEcho_Right();

    int PureDetect();
};

#endif