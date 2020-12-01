#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_LEN 15



/*	Author : Soner Türkoðlu
 *
 *
 *
 */

typedef struct customer{
	
	int age;	
	char surname[STR_LEN];
	char name[STR_LEN];
	char gender[STR_LEN];
	struct customer* node;
	
}customer_t;



typedef struct room{
	
	int number;
	int capacity;
	int floor;
	customer_t* customer_p;
	struct room* node;
}room_t;




void add_room_to_end(room_t* room_list,int room_num ,int capacity,int floor);
void add_room_after_room_number (room_t* room_list,int room_next,int room_num ,int capacity,int floor);
void add_customer_to_end(room_t* room_list,char gender[STR_LEN], char name[STR_LEN], char surname[STR_LEN],int age);
void link_customers_to_room(room_t* room_list,char gender[STR_LEN], char name[STR_LEN], char surname[STR_LEN],int age);
void remove_room (room_t* room_list,int room_num);
void show_vacancy(room_t* room_list);
void print_list (room_t* room_list);

int foo_pow(int num1,int num2){
	
	int i;
	int result=1;
	for(i=0; i<num2; i++){
		result*=num1;
	}
	return result;
}


int main(){
	
	room_t room_list={0,0,0,NULL,NULL};
	room_t* room_listp;
	room_listp=&room_list;
	
	FILE *pt;
	
	int i=0;
	int counter1,counter2;
	int room_num=0,capacity=0,floor=0,room_next=0,age=0;
	
	char surname[STR_LEN];
	char name[STR_LEN];
	char gender[STR_LEN];
	char x='a';
	
	pt=fopen("rooms.txt","r");
	
	if(pt == NULL){
		printf("Reading error !!!\n");
	}
	
	while(x != EOF){
		x=fgetc(pt);
		while(x != '\n' && x != EOF){
			counter2=2;
			while(x != ','){
				room_num+=(x - 48) * foo_pow(10,counter2);
				counter2--;
				x=fgetc(pt);
			}
			x=fgetc(pt);
			while(x != ','){
				capacity+=(x - 48) ;
				x=fgetc(pt);
			}
			x=fgetc(pt);
			while(x != '\n'  && x != EOF){
				floor+=(x - 48) ;
				x=fgetc(pt);	
			}
		}
	
		add_room_after_room_number (&room_list,room_next,room_num ,capacity,floor);
		room_next=room_num;
		room_num=0,capacity=0,floor=0;
	}
	
	fclose(pt);


	pt=fopen("customers.txt","r");
	
	if(pt == NULL){
		printf("Reading error !!!\n");
	}
	
	x='a';
	
	while(x != EOF){
		x=fgetc(pt);
		while(x != '\n' && x != EOF){
			counter1=2;
			while(x != ','){
				room_num+=(x - 48) * foo_pow(10,counter1);
				counter1--;
				x=fgetc(pt);
			}
			x=fgetc(pt);
			while(x != ' '){
				name[i]=x;
				x=fgetc(pt);
				i++;
			}
			name[i]='\0';
			i=0;
			x=fgetc(pt);
			while(x != ','){
				surname[i]=x;
				x=fgetc(pt);
				i++;	
			}
			surname[i]='\0';
			x=fgetc(pt);
			counter1=1;
			while(x != ','){
				age+=(x - 48) * foo_pow(10,counter1);
				x=fgetc(pt);
				counter1--;	
			}
			x=fgetc(pt);
			i=0;
			while(x != '\n'  && x != EOF){
				gender[i]=x;
				x=fgetc(pt);
				i++;	
			}
			gender[i]='\0';
		}
		room_listp=&room_list;
		
		while(room_listp->number != room_num){
			room_listp=room_listp->node;
		}
		link_customers_to_room(room_listp,gender,name,surname,age);
		
		room_num=0,age=0;
	}
	fclose(pt);
	
	print_list (&room_list);
	
	return 0;
}


void add_room_to_end(room_t* room_list,int room_num ,int capacity,int floor){
	
	
	if(room_list->number == 0){
		room_list->number=room_num;
		room_list->capacity=capacity;
		room_list->floor=floor;
	}
	else{
		
		while(room_list->node != NULL){
			room_list=room_list->node;
		}
		room_list->node=(room_t*)calloc(1,sizeof(room_t));
		room_list=room_list->node;
		room_list->number=room_num;
		room_list->capacity=capacity;
		room_list->floor=floor;
		room_list->node=NULL;
		
	}
}

void add_room_after_room_number (room_t* room_list,int room_next,int room_num ,int capacity,int floor){
	
	room_t* temp;
	
	while(room_list->number != room_next && room_list->node != NULL){
		room_list=room_list->node;
	}
	
	if(room_list->node != NULL){
		temp=room_list->node;
		room_list->node=(room_t*)calloc(1,sizeof(room_t));
		room_list->number=room_num;
		room_list->capacity=capacity;
		room_list->floor=floor;
		room_list=room_list->node;
		room_list->node=temp;
	}
	else{
		add_room_to_end(room_list,room_num ,capacity,floor);
	}
	
}


void add_customer_to_end(room_t* room_list,char gender[STR_LEN], char name[STR_LEN], char surname[STR_LEN],int age){
	
	
		while(room_list->customer_p->node != NULL){
			room_list->customer_p=room_list->customer_p->node;
		}
		room_list->customer_p->node=(customer_t*)calloc(1,sizeof(customer_t));
		room_list->customer_p=room_list->customer_p->node;
		strcpy(room_list->customer_p->gender,gender);
		strcpy(room_list->customer_p->name,name);
		strcpy(room_list->customer_p->surname,surname);
		room_list->customer_p->age=age;
		room_list->customer_p->node=NULL;	
}

void link_customers_to_room(room_t* room_list,char gender[STR_LEN], char name[STR_LEN], char surname[STR_LEN],int age){
	
	
	if(room_list->customer_p == NULL){
		room_list->customer_p=(customer_t*)calloc(1,sizeof(customer_t));
		strcpy(room_list->customer_p->gender,gender);
		strcpy(room_list->customer_p->name,name);
		strcpy(room_list->customer_p->surname,surname);
		room_list->customer_p->age=age;
		room_list->customer_p->node=NULL;
	}
	else{
		add_customer_to_end(room_list,gender,name,surname,age);
	}
	
}

void remove_room (room_t* room_list,int room_num){
	
	room_t* pre;

	while(room_list->number != room_num){
		pre=room_list;
		room_list=room_list->node;
	}
	pre->node=room_list->node;
}


void show_vacancy(room_t* room_list){
	
	printf("List of empty room:\n");
	while(room_list != NULL){
		if(room_list->customer_p->name[0] == '\0'){
			printf("Room:%d",room_list->number);
		}
	}	
}

void print_list (room_t* room_list){
	
	while(room_list != NULL){
		printf("Room %d (Floor %d - capacity %dx):\n",room_list->number,room_list->floor,room_list->capacity);
		if(room_list->customer_p == NULL){
			printf("-> Empty\n");
		}
		while(room_list->customer_p != NULL){
			printf("-> %s %s (%d-%s)\n",room_list->customer_p->name,room_list->customer_p->surname,room_list->customer_p->age,room_list->customer_p->gender);
			room_list->customer_p=room_list->customer_p->node;
		}
		room_list=room_list->node;
	}
}



