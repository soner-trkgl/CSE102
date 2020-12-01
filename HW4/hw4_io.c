/*
** hw4_io.c:
**
** The source file implementing input and output functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/


#include "hw4_io.h"


int read_polynomial3(double * a0, double * a1, double * a2, double * a3){        						// getting the coefficient of polynomial //
	
	printf("Enter the coefficients of a degree-3:\n");
	scanf("%lf",&*a3);
	printf("Enter the coefficients of a degree-2:\n");
	scanf("%lf",&*a2);
	printf("Enter the coefficients of a degree-1:\n");
	scanf("%lf",&*a1);	
	printf("Enter the coefficients of a degree-0:\n");
	scanf("%lf",&*a0);
}


int read_polynomial4(double * a0, double * a1, double * a2, double * a3, double * a4){					// getting the coefficient of polynomial //
	
	printf("Enter the coefficients of a degree-4:\n");
	scanf("%lf",&*a4);
	printf("Enter the coefficients of a degree-3:\n");
	scanf("%lf",&*a3);
	printf("Enter the coefficients of a degree-2:\n");
	scanf("%lf",&*a2);
	printf("Enter the coefficients of a degree-1:\n");
	scanf("%lf",&*a1);
	printf("Enter the coefficients of a degree-0:\n");
	scanf("%lf",&*a0);
	
	
	
	return 0;
}

void write_polynomial3(double a0, double a1, double a2, double a3){							//  writting the polynomial type //
	

	
		
	printf("%.1lfx^3",a3);
	if(a2==0){
		
	}
	else if(a2>0) {
		printf("+%.1lfx^2",a2);
	}
	else if(a2<0){
		printf("%.1lfx^2",a2);
	}
	
	
	if(a1==0){
		
	}
	else if(a1>0) {
		printf("+%.1lfx^1",a1);
	}
	else if(a1<0){
		printf("%.1lfx^1",a1);
	}
	
	
	if(a0==0){
		
	}
	else if(a0>0) {
		printf("+%.1lf",a0);
	}
	else if(a0<0){
		printf("%.1lf",a0);
	}
	

	
}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4){					//  writting the polynomial type //
	
	
	printf("%.1lfx^4",a4);
	if(a3==0 ){
		
	}
	else if(a3>0){
		printf("+%.1lfx^3",a3);
	}
	else if(a3<0){
		printf("%.1lfx^3",a3);	
	}
	
	
	if(a2==0){
		
	}
	else if(a2>0) {
		printf("+%.1lfx^2",a2);
	}
	else if(a2<0){
		printf("%.1lfx^2",a2);
	}
	
	
	if(a1==0){
		
	}
	else if(a1>0) {
		printf("+%.1lfx^1",a1);
	}
	else if(a1<0){
		printf("%.1lfx^1",a1);
	}
	
	
	if(a0==0){
		
	}
	else if(a0>0) {
		printf("+%.1lf",a0);
	}
	else if(a0<0){
		printf("%.1lf",a0);
	}
	
	
	
}
