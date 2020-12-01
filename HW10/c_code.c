#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


/*	Author : Soner Türkoðlu
 *
 *
 *
 *
 */

typedef struct data_note{
	
	char* arr_pt;
	struct data_note* pt;
	
}node_list;


double link_foo();
double arr_foo();
void time_foo(double foo() , char c);




int main(){

	char a='a',l='l';   	// a is array and l is linked list //
	
	time_foo(link_foo,l);
	time_foo(arr_foo,a);
	
	
	return 0;
}



double link_foo(){
	
	
	FILE *p;
	
	
	
	node_list* node_head;
	node_list* node_next;
	node_list* node_current;
	
	
	char c;
	
	long number=0;
	long counter1=0,counter2=0,counter3=0;
	int temp;
	int i=0,j=0;
	
	p=fopen("data.txt","r");
	
	if(p == NULL){
		printf("Opining error\n");
	}
	
	
	do{
		do{
			temp++;
			c=fgetc(p);
		}while(c !='\n' && c!=EOF);
		if(temp > counter2){
			counter2=temp;
		}
		temp=0;
		counter1++;		
	}while (c != EOF);
	
	
	rewind(p);
	
	node_head=(node_list*)malloc(sizeof(node_list));
	node_current=node_head;
	
	do{
		i=0;
		node_current->arr_pt=(char*)calloc(counter2,sizeof(char));
		node_current->pt=NULL;
		do{
			c=fgetc(p);
			node_current->arr_pt[i]=c;
			i++;	
		}while(c !='\n' && c!=EOF);
		node_current->arr_pt[i]='\0';
		node_next=(node_list*)malloc(sizeof(node_list));
		node_current->pt=node_next;
		node_current=node_current->pt;
		
	}while (c != EOF);
	node_current->pt=NULL;
	
	
	printf("Prime numbers are :\n");
	node_current=node_head;
	i=0;
	j=0;
	while( node_current->pt != NULL){
		
		number=0;
		counter3=0;
		while(node_current->arr_pt[i] != ','){
			i++;
		}
		for(j=0; j<i; j++){
			number+=(node_current->arr_pt[j] - 48) * pow(10,i-j-1);
		}
		
		for(j=1; j<number; j++){
			if(number % j == 0 ){
				counter3++;
			}
		}
		if(counter3 == 1 && number != 1){
			printf("%d\t",number);
		}
		node_current=node_current->pt;
			
	}
	printf("\n");
	fclose(p);
	
	return counter1;
}


double arr_foo(){
	
	FILE *p;
	
	
	char **arr;
	char c;
	
	long number=0;
	long counter1=0,counter2=0,counter3=0;
	int temp;
	int i=0,j=0,k=0;
	
	p=fopen("data.txt","r");
	
	if(p == NULL){
		printf("Opining error\n");
	}
	
	
	do{
		do{
			temp++;
			c=fgetc(p);
		}while(c !='\n' && c!=EOF);
		if(temp > counter2){
			counter2=temp;
		}
		temp=0;
		counter1++;		
	}while (c != EOF);
	
	arr=(char**)calloc(counter1, sizeof(char*));
	for(i=0; i<counter1; i++){
		arr[i]=(char*)calloc(counter2, sizeof(char));
	}
	
	rewind(p);
	i=0;
	j=0;
	
	
	do{	
		do{
			c=fgetc(p);
			arr[i][j]=c;
			j++;
		}while(c !='\n' && c!=EOF);
		arr[i][j]='\0';
		j=0;
		i++;	
	}while (c != EOF);
	
	printf("Prime numbers are :\n");
	
	for(i=0; i<counter1; i++){
		number=0;
		counter3=0;
		j=0;
		while(arr[i][j] != ','){
			j++;			
		}
		for(k=0; k<j; k++){
			number+=(arr[i][k] - 48) * pow(10,j-k-1);
		}
	
		for(k=1; k<number; k++){
			if(number % k == 0 ){
				counter3++;
			}
		}
		if(counter3 == 1 && number != 1){
			printf("%d\t",number);
		}		
	}
	printf("\n");
	fclose(p);
	return counter1;	
}


void time_foo(double foo(),char c){
	
	long counter;
	
	FILE *p1;

	clock_t time;
    time = clock();
    counter=foo();
    time = clock() - time;
    double run_time = ((double)time)/CLOCKS_PER_SEC;
	
	if(c == 'l'){
		p1=fopen("output_prime_LiknedList.txt","w");
	}
	
	if(c == 'a'){
		p1=fopen("output_prime_dynamic_array.txt","w");
	}
	
	if(p1 == NULL){
		printf("Writing error\n");
	}
	
	
	if(counter==500000){
		fprintf(p1,"Running time of the program (Between 1 and 500.000):");
		fprintf(p1,"%.4lf seconds",run_time);
		fprintf(p1,"\n");
	}
	
	if(counter==750000){
		fprintf(p1,"Running time of the program (Between 1 and 750.000):");
		fprintf(p1,"%.4lf seconds",run_time);
		fprintf(p1,"\n");
	}
	
	if(counter==1000000){
		fprintf(p1,"Running time of the program (Between 1 and 1.000.000):");
		fprintf(p1,"%.4lf seconds",run_time);
		fprintf(p1,"\n");
	}
	fclose(p1);
}




