#include<stdio.h>
#define LINE_BUFFER 1024			// constant variable for line buffer //

/*	Author : Soner Türkoðlu
 *	
 *
 *
 *
 */



void menu();							// declaration of function prototype //
void encrypt_open_msg();
void decrypt_secret_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[], int line_lenght);

int main(){			
	
	menu();
	return 0;
}



void menu(){				// menu function //
	
	int x;					// declaration of variable for loop (while loop) //
	
	do{
		printf("1. Encrypt\n");
		printf("2. Decrypt\n");
		printf("0. Exit\n");
		printf("Choice:\n");
		scanf("%d",&x);
		
		switch(x){
			
			case 1:
				encrypt_open_msg();
				break;
			case 2:
				decrypt_secret_msg();
				break;
			case 0:
				break;
			
			default:
				printf("Wrong choice\n");
					
		}
				
	}while(x!=0);
	
}


void encrypt_open_msg(){
	
	int i=0; 				// declaration of variable for loop  //
	int line_length;		// declaration of variable for line length //
	int key_value;			//declaration of variable for key value //
	
	char x;					// declaration of variable for assigning the character from file to x and then assign the array //  
	char line[LINE_BUFFER];  //declaration of array for getting the word in file //
	
	printf("Enter the key value (between 1 and 26)\n");  
	scanf("%d",&key_value);
	
	FILE * file_p1;		// file pointer for file processing //		
	FILE * file_p2;
	
	if( (file_p1=fopen("open_msg.txt","r")) == NULL){
		
		printf("File reading error\n");
	}
	
	if( (file_p2=fopen("secret_msg.txt","w")) == NULL){
		
		printf("File writing error\n");
	}
	
	printf("Key: %d\n",key_value);
	
	while( (x=fgetc(file_p1)) != EOF ){
		
		do{
			line[i]=x;
			i++;	
		}while( (x=fgetc(file_p1)) != '\n' && x!= EOF);
		line[i]='\0';
		
		line_length=find_size_of_line(line);		// finding the length of line //
		reverse_line(line,line_length);				// reversing the line //
	
		for(i=0; i<line_length; i++){
		
			if(line[i]!=' ' && line[i]!='.'){		// function replaces each character by key value in reverse direction //

				if(line[i]-key_value<97){
			
					line[i]=line[i]+26-key_value;
				}
				else {
					line[i]=line[i]-key_value;
				}	
			}
			else{
			
				if(line[i]==' '){
					line[i]='_';
				}
		
				if(line[i]=='.'){
					line[i]='*';
				}
			}
		}
	
		printf("%s\n",line);
		
		fprintf(file_p2,"%s",line);		// printing the file //
		fprintf(file_p2,"\n");
		
		i=0;
	}
	
	fclose(file_p1);
	fclose(file_p2);
	
	
	
}


void decrypt_secret_msg(){
	
	int i;					// declaration of variable for loop  //
	int line_length;		// declaration of variable for line length //
	int key_value;			//declaration of variable for key value //
	
	char x;					// declaration of variable for assigning the character from file to x and then assign the array // 
	char line[LINE_BUFFER];	//declaration of array for getting the word in file //
	
	printf("Enter the key value (between 1 and 26)\n");
	scanf("%d",&key_value);
	
	FILE * file_p1; 		// file pointer for file processing //
	FILE * file_p2;
	
	if( (file_p1=fopen("secret_msg.txt","r")) == NULL){
		
		printf("File reading error\n");
	}
	
	if( (file_p2=fopen("open_msg.txt","w")) == NULL){
		
		printf("File writing error\n");
	}
	
	printf("Key: %d\n",key_value);
	
	while( (x=fgetc(file_p1)) != EOF ){
		
		do{
			line[i]=x;
			i++;	
		}while( (x=fgetc(file_p1)) != '\n' && x!= EOF);
		line[i]='\0';
		
		line_length=find_size_of_line(line);
		
		for(i=0; i<line_length; i++){
		
			if(line[i]!='*' && line[i]!='_'){
			
				if(line[i]+key_value>122){
			
					line[i]=line[i]+key_value-26;
				}
				else {
					line[i]=line[i]+key_value;
				}	
			}
			else{
			
				if(line[i]=='_'){
					line[i]=' ';
				}
		
				if(line[i]=='*'){
					line[i]='.';
				}
			}
		}
		
		reverse_line(line,line_length);  // reversing the line //
		printf("%s\n",line);
		fprintf(file_p2,"%s",line);		// printing the file //
		fprintf(file_p2,"\n");
		
		i=0;
	}
	
	
	
	
	fclose(file_p1);
	fclose(file_p2);
	
	
	
	
}



int find_size_of_line(char line[]){
	
	
	int counter=0;
	char karakter;
	
	do{
		karakter=line[counter];
		counter++;
		
	}while(karakter!='\0');
	
	return (counter-1);
}



void reverse_line(char line[], int line_length){
	
	int i;
	int j=line_length-1;
	char temp;
	
	for(i=0; i<line_length/2 ; i++){
		
		temp=line[i];
		line[i]=line[j];
		line[j]=temp;
		j--;
	}
	
}
