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
  double cm_F,cm_L,cm_R;
  double d1,d2,d3;
  int t1,t2,t3;
  double near;//initial setting is 25cm(by my calulate)
  double far;//initial setting is 30cm



  // user-accessible "public" interface
  public:

    void Sonar_Inital(); //set TrigPin, EchoPin, nearDistance, toocloseDistance
    void Set_Distance(double,double); //distance when robot near obstacle

    double Get_cmF();
    double Get_cmL();
    double Get_cmR();
    double Get_near();
    double Get_far();
    void OpenandGet_Forward();
    void OpenandGet_Left();
    void OpenandGet_Right();
    int fuzzifiter(double);
    int Rules(int,int,int);

    void StartTrig_Forward(bool);
    void StartTrig_Left(bool);
    void StartTrig_Right(bool);
    double ReadEcho_Forward();
    double ReadEcho_Left();
    double ReadEcho_Right();

    int PureDetect();  //基本避障偵測
    int TwoDetect();
    int FUZZYDetect();
};

#endif