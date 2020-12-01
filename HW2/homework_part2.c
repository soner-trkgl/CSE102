#include<stdio.h>

/* Author : Soner Türkoðlu
 *
 *
 *
 */


int main(){
	
	
	int number,    		//  declaration of variable
		counter=0, 		//  declaration of variable  
		temp,			// declaration of variable	
		temp2=0, 		// declaration of variable
		j,i;			// declaration of variable for loops
		
	printf("Enter the number: ");
	scanf("%d",&number);				//  get the number
	while(number<23 || number>98760){
		printf("Please enter the number again(between 23 and 98760)");			// check the number is between 23 and 98760
		scanf("%d",&number);
	}
	temp=number;
	while(temp!=0){			// 	find the number have  decimal places
		temp=temp/10;
		counter++ ;
		
	}
	temp2=number;
	for(j=0; j<counter; j++){										
		for(i=counter-1; j<i; i--){									
		temp2=temp2/10;
		}
		temp2=temp2%10;
		if(counter-j==5){
			printf("The fifth digit is %d\n",temp2);
		}
		else if(counter-j==4){
			printf("The fourth digit is %d\n",temp2);
		}
		else if(counter-j==3){
			printf("The third digit is %d\n",temp2);
		}
		else if(counter-j==2){
			printf("The second digit is %d\n",temp2);
		}
		else if(counter-j==1){
			printf("The first digit is %d\n",temp2);
		}
		temp2=number;
	}
	
	
	return 0;
}
