#include<stdio.h>
#include<stdlib.h>

/* Author : Soner Türkoðlu
 *
 *
 *
 */


int menu_fonk(int,int,int,int,int,int,int,int,int,int,float);		// declaration of function prototype
void menu_1(int,int);
void menu_2(int,int);
void menu_3(int,int,int,int,int);
void menu_4(int,float,float);

int main(){
	
	int count,		// declaration of variable for get the count from user
		temp,		// 	declaration of variable  to assign the random grade to temp variable		
		temp1=-1,	//	declaration of variable to find the most successful student and most unsuccessful student's grade
		temp2=101,	
		temp3,		//	declaration of variable to find the most successful student and most unsuccessful student's index
		temp4,
		i;			//	declaration of variable for loop
				
	int total1=0,											//	declaration of variable to find the students have letter grade 
		total2=0,
		total3=0,
		total4=0,
		total5=0;											
	float total_sum=0;										// 	declaration of variable to avarage of students' grade 
	
	printf("Enter student count:\n");						// 	get the count of student
	scanf("%d",&count);									
	while(count<3 || count>50){								// check the count is between 3 and 50
		printf("Not in Range!!!\n");
		printf("Enter student count:\n");
		scanf("%d",&count);
	}
	srand(40);
	for(i=1; i<=count; i++){						
		temp=rand()%101;
		total_sum+=temp;
		printf("%d\t",temp);
		if(90<=temp && temp<=100){
				total1++;
		}
		else if(80<=temp && temp<=89){
				total2++;
		}
		else if(70<=temp && temp<=79){
				total3++;
		}
		else if(60<=temp && temp<=69){
				total4++;
		}
		else {
			total5++;
		}
		if(temp>=temp1){
			temp1=temp;
			temp3=i;
		}
		if(temp<=temp2){
			temp2=temp;
			temp4=i;
		}
	}
	menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
	
	
	
	return 0;
}

int menu_fonk(int count,int temp1,int temp2,int temp3,int temp4,int total1,int total2,int total3,int total4,int total5,float total_sum){
	
	int a;
	float avarage;
	printf("\nStudent Score Calculator Menu for %d Student\n\n",count);
	printf("1) Most successful student\n");
	printf("2) Most unsuccessful student\n");
	printf("3) Letter Grade Statistics\n");
	printf("4) Calculate Avertage\n");
	printf("5) Show all Data\n");
	printf("Make Selection:");
	scanf("%d",&a);
	switch (a){
		
		case 1 :
			menu_1(temp3,temp1);
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
		case 2 :
			menu_2(temp2,temp4);
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
		case 3 :
			menu_3(total1,total2,total3,total4,total5);
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
		case 4 :
			menu_4(count,total_sum,avarage);
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
		case 5 :
			menu_1(temp3,temp1);
			menu_2(temp2,temp2);
			menu_3(total1,total2,total3,total4,total5);
			menu_4(count,total_sum,avarage);
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
		case -1 :
			return 0 ;
			break;
		default :
			printf("False selection!!!");
			menu_fonk(count,temp1,temp2,temp3,temp4,total1,total2,total3,total4,total5,total_sum);
			break;
			
	}
	
	

}


void menu_1(int temp3,int temp1){								// part one for switch case menu 
	
	printf("Most successfully student:\n");
	printf("Index %d:\n",temp3);
	printf("Score %d:\n",temp1);
	if(90<=temp1 && temp1<=100){
		printf("Letter Grade: A\n");
	}
	else if(80<=temp1 && temp1<=89){
			printf("Letter Grade: B\n");
	}
	else if(70<=temp1 && temp1<=79){
			printf("Letter Grade: C\n");
	}
	else if(60<=temp1 && temp1<=69){
			printf("Letter Grade: D\n");
	}
	else {
		printf("Letter Grade: F\n");
	}

	
}

void menu_2(int temp2,int temp4){								// 	part two for switch case menu 
	
	printf("Most unsuccessfully student:\n");
			printf("Index %d:\n",temp4);
			printf("Score %d:\n",temp2);
			if(90<=temp2 && temp2<=100){
				printf("Letter Grade: A\n");
			}
			else if(80<=temp2 && temp2<=89){
					printf("Letter Grade: B\n");
			}
			else if(70<=temp2 && temp2<=79){
					printf("Letter Grade: C\n");
			}
			else if(60<=temp2 && temp2<=69){
					printf("Letter Grade: D\n");
			}
			else {
				printf("Letter Grade: F\n");
			}
			
}

void menu_3(int total1,int total2,int total3,int total4,int total5){			// part three for switch case menu 
	
	printf("\n%d student got letter grade 'A'",total1);
	printf("\n%d student got letter grade 'B'",total2);
	printf("\n%d student got letter grade 'C'",total3);
	printf("\n%d student got letter grade 'D'",total4);
	printf("\n%d student got letter grade 'F'\n",total5);
	
}

void menu_4(int count,float total_sum,float avarage){							// part four for switch case menu 
	
	avarage=total_sum/count;
	printf("\nThe avarage Score of %d Student is %.2f\n ",count,avarage);
	
}
