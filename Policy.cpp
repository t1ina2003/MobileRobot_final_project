/*
  Created to Arduino Motor control, the release of the IRIS from IRSILAB
  Only Use in robot 
  Created by Zuo Syuan Wang, April 18, 2014.
  Released into the public domain.
*/
// include core Wiring API
#include "Arduino.h"
// include this library's description file
#include "Policy.h"



// FUZZY-RULEs
//#define nothing 0
#define nothing 0
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



void Policy::Policy_Inital(){

}

int  Policy::Action(int v_sonar){
	switch(v_sonar){
		case nothing:
				return 1; //1
				break;
		case nearF:
				return 3; //2
				break;
		case nearL:
				return 8; //3
				break;
		case nearR:
				return 2; //4
				break;
		case farF:
				return 2; //5
				break;
		case farL:
				return 1; //6
				break;
		case farR:
				return 1; //7
				break;
		case nFnL:
				return 7; //8
				break;
		case nFfL:
				return 7; //9
				break;
		case fFnL:
				return 8; //10
				break;
		case fFfL:
				return 8; //11
				break;
		case nFnR:
				return 3; //12
				break;
		case nFfR:
				return 3; //13
				break;
		case fFnR:
				return 2; //14
				break;	
		case fFfR:
				return 2; //15
				break;
		case nLnR:
				return 4; //16
				break;
		case nLfR:
				return 8; //17
				break;
		case fLnR:
				return 2; //18
				break;
		case fLfR:
				return 1; //19
				break;
		case nFnLnR:
				return 4; //20
				break;
		case nFnLfR: 
				return 7; //21
				break;
		case nFfLnR:
				return 3; //22 
				break;
		case nFfLfR:
				return 3; //23
				break;
		case fFnLnR:
				return 1; //24
				break;
		case fFnLfR:
				return 8; //25 
				break;
		case fFfLnR:
				return 2; //26 
				break;
		case fFfLfR:
				return 1; //27
				break; 
		
					}
}