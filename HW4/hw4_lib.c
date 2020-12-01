/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/

#include "hw4_lib.h"



double integral(double f(double x), double xs, double xe, double delta){					
	
	int i;																		// declaration of variable for loop //
	double deltaX;																
	double x;
	double sum_of_area=0.0;														// sum of area of function between xs and xe //
	deltaX=(xs-xe)/delta;														
	x=xe+deltaX;																
	
	for(i=0; i<delta; i++){
		
		sum_of_area+=deltaX*f(x);												//  finding the sum of area (integration) //
		x+=deltaX;
		
		
		
	}
	return sum_of_area;
	
}


double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta){
	
	double i,j;																// declaration of variable for loop //
	double deltaX,deltaY;													// declaration of variable for interval divided by delta //
	double sum_of_volume=0.0;												// sum of volume of function between xs and xe //
	deltaX=(xs-xe)/delta;
	deltaY=(ys-ye)/delta;
	
	
	for(i=xe+deltaX; i<=xs; i+=deltaX){										//  finding the sum of volume (integration) //
		
		for(j=ye+deltaY; j<=ys; j+=deltaY){					
			
			sum_of_volume+=f(i,j)*deltaY*deltaX;
		}
		
	}
	return sum_of_volume;
	
}



int derivatives(double f(double a), double x, double eps, double * d1, double * d2){
	
	if(eps==0){
		return -1;
	}
	else {
		*d1=(f(x+eps)-f(x-eps))/eps;
		*d2=(f(x+eps)-2*f(x)+f(x-eps))/(eps*eps);
		return 1;
	}
}


int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2){
	
	if(eps==0.0){
		return -1;
	}
	else {
		
		*e1=((f(x+eps)-f(x-eps))/(2.0*eps)) - d1(x);
		*e2=((f(x+eps)-2.0*f(x)+f(x-eps))/(eps*eps)) - d2(x);
		if(*e1<0){
			*e1=*e1 * -1;
		}
		if(*e2<0){
			*e2=*e2 * -1;
		}
		
		return 1;
	}
	
}
