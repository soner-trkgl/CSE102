#include<stdio.h>
#include<math.h>
#define PI 3.14

/*	Author : Soner Türkoðlu
 *
 *
 *
 */


double circle_area(double);
double calc_hypotenuse(int,int);
double calc_radius_of_smallest_circle(int,int);
double calc_radius_of_largest_circle(int,int);
double calc_area_of_smallest_circle(int,int);
double calc_area_of_largest_circle(int,int);
double calc_area_of_smallest_square(int,int);
double calc_area_of_largest_square(int,int);
double calc_area_of_square(int);
void display_result(double ,
					double ,
					double ,
					double );


int main(){

	int side1,side2;
	double largest_circle, largest_square, smallest_circle, smallest_square;
	
	printf("Lutfen dikdortgenin kenarlarini giriniz(cm)\n");
	scanf("%d %d",&side1,&side2);
	largest_circle=calc_area_of_largest_circle(side1,side2);
	largest_square=calc_area_of_largest_square(side1,side2);
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	smallest_square=calc_area_of_smallest_square(side1,side2);
	display_result(largest_circle,largest_square,smallest_circle,smallest_square);



	return 0;	
}

double circle_area(double radius){
	double area_of_circle;
	area_of_circle=PI*radius*radius;
	return area_of_circle;
}

double calc_hypotenuse(int side1,int side2){
	double hypotenuse;
	hypotenuse=sqrt(pow(side1,2)+pow(side2,2));
	return hypotenuse;
	
}

double calc_radius_of_smallest_circle(int side1,int side2){
	double radius_of_smallest_circle=sqrt(pow(side1,2)+pow(side2,2))/2;
	return radius_of_smallest_circle;
}

double calc_radius_of_largest_circle(int side1,int side2){
	double radius_of_largest_circle;
	if (side1<side2){
		radius_of_largest_circle=side1/2.0;
	}
	else {
		radius_of_largest_circle=side2/2.0;
	}
	return radius_of_largest_circle;
	
}

double calc_area_of_smallest_circle(int side1,int side2){
	double area_of_smallest_circle,r;
	r=calc_radius_of_smallest_circle(side1,side2);
	area_of_smallest_circle=PI*r*r;
	return area_of_smallest_circle;
	
}

double calc_area_of_largest_circle(int side1,int side2){
	double area_of_largest_circle,r;
	r=calc_radius_of_largest_circle(side1,side2);
	area_of_largest_circle=PI*r*r;
	return area_of_largest_circle;
}

double calc_area_of_smallest_square(int side1,int side2){
	double area_of_smallest_square;
	if(side1>side2){
		area_of_smallest_square=calc_area_of_square(side1);
	}
	else {
		area_of_smallest_square=calc_area_of_square(side2);
	}
	return area_of_smallest_square;
}

double calc_area_of_largest_square(int side1,int side2){
	double area_of_largest_square;
	if(side1<side2){
		area_of_largest_square=calc_area_of_square(side1);
	}
	else {
		area_of_largest_square=calc_area_of_square(side2);
	}
	return area_of_largest_square;
}

double calc_area_of_square(int side1){
	double area_of_square;
	area_of_square=side1*side1;
	return area_of_square;
	
	
}

void display_result(double largest_circle,
					double largest_square,
					double smallest_circle,
					double smallest_square){
	
	
	printf("\nEn buyuk dairenin alani: %.2lf",largest_circle);
	printf("\nEn buyuk karenin alani: %.2lf",largest_square);
	printf("\nEn kucuk dairenin alani: %.2lf",smallest_circle);
	printf("\nEn kucuk karenin alani: %.2lf",smallest_square);
	
}


