#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Author : Soner Türkoðlu
 *
 *
 *
 */

void menu();											
int getInt(int , int);
int numberGeneratorBetweenRange(int , int);							// declaration of function prototype //
void horseRacingGame();
void triangleOfSequences();
void countOccurrence();



int main()
{
	srand(time(NULL));						// calling the srand function to generate the number whichever time //
	menu();									// calling the menu function //
	
	

	return 0;
}
void menu(){
	
	int selection;									//	declaration of variable  for get the selection from user //
					
	do {
		printf("\n1. Horse Racing Game\n");			// printing the menu contetn //
		printf("2. Occurence Counter\n");
		printf("3. Triangle of Sequence\n");
		printf("0. Exit\n");
		printf("\nEnter Your Selection:\n");
		scanf("%d",&selection);						// getting the user's selection //
		switch(selection){
			case 1 :
				horseRacingGame();
				break;
			case 2 :
				countOccurrence();
				break;
			case 3 :
				triangleOfSequences();
				break;
			case 0 :
				break;
			default :
				printf("\nWrong Selection\n");
				break;
		}
	}while (selection!=0);
	
}

int getInt(int mini , int maxi){
	
	int number;										// This funtion control that number is betwen mini and maxi //
	printf("Enter The Number:");
	scanf("%d",&number);
	while(number<mini || number>maxi){
		printf("Enter the Number Again (between %d and %d ):",mini,maxi);
		scanf("%d",&number);
		
	}
	return number;
	
}

int numberGeneratorBetweenRange(int min , int max){
	
	int random;									// This function generate the number between min and max randomly //
	random=(rand()%(max-min+1))+min;		
	return random;
	
}

void horseRacingGame(){
	
	int i,j;                         // declaration of variable for loop //
	int temp1=21,temp2;				// declaration of variable for run time of horse //
	int temp3;						// declaration of variable for order of horse //
	int runs_time;				// declaration of variable to generate the horse's run time randomly //
	int numberOfHorse;				//declaration of variable to assingn how many horses will be in race //
	int horse_number;				// declaration of variable to get the number of horse from user //
			
	
	numberOfHorse=numberGeneratorBetweenRange(3 , 5);			// calling the function to generate the number of horse //
	horse_number=getInt(1 , numberOfHorse);						// calling the function to get the horse number from user //
	
	printf("\nNumber of Horse:%d\n",numberOfHorse);				//printing the race content //
	printf("Horse Number:%d\n",horse_number);
	printf("Racing starts...\n");
	
	for(i=1; i<=numberOfHorse; i++){						
		
		if(i==1){
			printf("Horse 1:");
		}
		else if(i==2){
			printf("Horse 2:");
		}
		else if(i==3){
			printf("Horse 3:");
		}
		else if(i==4){
			printf("Horse 4:");
		}
		else if(i==5){
			printf("Horse 5:");
		}
		runs_time=numberGeneratorBetweenRange(10 , 20);			// calling the function to generate the run time of horses //
		if(temp1>runs_time){
			temp1=runs_time;
			temp3=i;
		}
		else if(temp1==runs_time){
			temp2=runs_time;
		}
		
		for(j=0; j<runs_time; j++){
			printf("_ ");
		}
		printf("\n");
		
	}
	if(temp3==horse_number ){									//	printing the race result //
		printf("You Win!Winner is Horse %d",temp3);
	}
	else if(temp3!=horse_number){
		printf("You lose!Winner is Horse %d",temp3);
	}


	
}



void countOccurrence(){
	
	long big_number;
	int search_number;
	int i;							// declaration of variable for loop //
	int counter1=0,					// declaration of variable to get the number's decimal digit //
		counter2=0,
		counter3=0;
	int temp1,						// declaration of variable //
		temp2,
		temp3=1;

	printf("\nEnter the Big number\n");
	scanf("%d",&big_number);
	printf("\nEnter the Search number:\n");				// getting the search number //
	scanf("%d",&search_number);
	temp1=big_number;
	temp2=search_number;	
	while(temp1!=0){									// calculation of big number's decimal digit //
		temp1=temp1/10;
		counter1++;
	}
	do{													// calculation of search number's decimal digit //
		temp2=temp2/10;
		counter2++;
	}
	while(temp2!=0);
	
	for (i=0; i<counter2; i++){
		
		temp3*=10;
	}
	
	temp1=big_number;
	for (i = 0; i < counter1; i++){
			
			temp2=temp1%temp3;

			if (search_number==temp2)
			{
				counter3++;
			}
			temp1=temp1/10;

	}
	printf("Big Number :%d\n",big_number );				// printing the result //
	printf("Search Number :%d\n",search_number);
	printf("Occurence :%d\n",counter3 );	
	
}


void triangleOfSequences(){
	
	int value;												// declaration of variable //
	int number;												// declaration of variable //
	int i,j;												// declaration of variable for loop //
	value=numberGeneratorBetweenRange(2 , 10);
	for(i=1; i<=value; i++){
		
		
		for(j=1; j<=i; j++){
			
			number=i*j;
			printf("%d ",number);
			
		}
		printf("\n");
	
	}
	
}
