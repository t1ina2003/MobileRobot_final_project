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

int  Policy::Action(int v_sonar,int irint10,int irint9,int irint8){
	switch(v_sonar){
		case nothing://1
		 		if( irint10 == 1 && irint9 == 1 && irint8 == 1) return 1;
				if(irint10 == 1 && irint9 == 1 ) return 8;
				if(irint9 == 1 && irint8 == 1) return 2;
				if(irint10 == 1 && irint8 == 1) return 3;
				if(irint10 == 1) return 7;
				if(irint9 == 1) return 1;
				if(irint8 == 1) return 3;
				return 1;
				break;
		case nearF://2
				if(irint8 == 1 && irint9 == 1) return 3;
				return 7; 
				break;
		case nearL://3
				if(irint9 == 1) return 1;
				return 8; 
				break;
		case nearR://4
				if(irint8 == 1) return 1;
				return 2; 
				break;
		case farF://5
				//if(irint10 == 1 && irint9 == 1 ) return 8;
				if(irint9 == 1 && irint8 == 1) return 2;
				return 8; 
				break;
		case farL: //6
				//if(irint10 == 1 && irint9 == 1 ) return 8;
				if(irint9 == 1) return 1;
				//if(irint10 == 1) return 7;
				if(irint9 == 1 && irint8 == 1) return 2;
				return 1;
				break;
		case farR: //7
				if(irint9 == 1 && irint8 == 1) return 2;
				if(irint9 == 1) return 1;
				if(irint8 == 1) return 3;
				//if(irint10 == 1 && irint9 == 1 ) return 8;
				return 1;
				break;
		case nFnL://8
				return 7; 
				break;
		case nFfL://9
				return 7; 
				break;
		case fFnL://10
				if(irint9 == 1 && irint8 == 1) return 2;
				return 8; 
				break;
		case fFfL://11
				if(irint9 == 1) return 1;
				return 8; 
				break;
		case nFnR://12
				return 3; 
				break;
		case nFfR://13
				return 3; 
				break;
		case fFnR://14
				if(irint8 == 1) return 3;
				return 2;
				break;	
		case fFfR://15
				if(irint8 == 1) return 3;
				return 2;
				break;
		case nLnR://16
				if(irint9 == 1 && irint8 == 1) return 1;
				if(irint8 == 1) return 2;
				return 2; 
				break;
		case nLfR://17
				if(irint8 == 1) return 1;
				return 8; 
				break;
		case fLnR://18
				if(irint9 == 1) return 1;
				return 2;
				break;
		case fLfR://19
				//if(irint10 == 1 && irint9 == 1 && irint8 == 1) return 1;
				//if(irint10 == 1 && irint9 == 1 ) return 8;
				if(irint9 == 1 && irint8 == 1) return 2;
				//if(irint10 == 1 && irint8 == 1) return 3;
				//if(irint10 == 1) return 8;
				if(irint9 == 1) return 1;
				if(irint8 == 1) return 2;
				return 1; 
				break;
		case nFnLnR://20
				if(irint8 == 1) return 6;
				return 4; 
				break;
		case nFnLfR://21
				return 7;
				break;
		case nFfLnR://22 
				return 3; 
				break;
		case nFfLfR://23
				if(irint8 == 1) return 3;
				return 7; 
				break;
		case fFnLnR://24
				if(irint9 == 1) return 1;
				if(irint8 == 1) return 2;
				return 1;
				break;
		case fFnLfR://25 
				if(irint8 == 1) return 1;
				return 8; 
				break;
		case fFfLnR://26
				if(irint9 == 1) return 1;
				return 2;  
				break;
		case fFfLfR://27
				//if(irint10 == 1 && irint9 == 1 && irint8 == 1) return 1;
				//if(irint10 == 1 && irint9 == 1 ) return 8;
				if(irint9 == 1 && irint8 == 1) return 2;
				//if(irint10 == 1 && irint8 == 1) return 3;
				//if(irint10 == 1) return 7;
				if(irint9 == 1) return 1;
				if(irint8 == 1) return 3;
				return 1; 
				break; 
		
					}
}