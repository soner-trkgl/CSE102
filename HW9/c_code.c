#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>  				// I used math library for pow function //

/* 	Author : Soner Türkoðlu
 *
 *
 *
 *
 *
 */


typedef struct {		// declaration of structure //
	char** Map;
	int Width;
	int Height;
	int Flower_X;
	int Flower_Y;
}Forest;



typedef struct {		// declaration of structure //
	int Coord_X;
	int Coord_Y;
	int Water_Bottle_Size;
	
}Botanist;



void init_game (Forest* forest, Botanist* botanist);				// declaration of function prototype //
void print_map (Forest* forest);
int* search (Forest forest,int to_x,int to_y,int water,int counter);			// return the pointer involved coordinate x and y //


int main(){
	
	int* turn_value;
	Forest forest;				// declaration of forest structure //
	Botanist botanist;
	
	srand(time(NULL));
	
	init_game (&forest, &botanist);
	print_map (&forest);
	turn_value=search (forest, botanist.Coord_X , botanist.Coord_Y , botanist.Water_Bottle_Size,0);
	print_map (&forest);
	printf("\n");
	
	if( *turn_value == forest.Flower_X && *(turn_value+1) == forest.Flower_Y){
		printf("I have found it  on (%d,%d)\n",*turn_value,*(turn_value+1));
	}
	else {
		printf("Help! I am on (%d,%d)\n",*turn_value,*(turn_value+1));
	}
	
	
	return 0;
}

void init_game (Forest* forest, Botanist* botanist){
	

	char **pt;	
	char x;						// declaration of variable to get the caracter //
	char arr[20];				// declaration of array to  get the first and second line  //
	
			
	int i=0,j=0;				// declaration of variable for  loop  //
	int column=0,row=0;			// declaration of variable to get the row and column  //
	int water=0;				// declaration of variable to  get the water  //
	
	
	FILE *p;
	p=fopen("init.csv","r");					// file reading process  //
	
	if (  p== NULL){
		printf("opening error\n");
	}
	
	do{												
		x=fgetc(p);
		arr[i]=x;
		i++;
															// loop for  get  the water from file//
	}while(x != '\n');
	i--;
	for(j=0; j<i; j++){
		water+=( arr[j] - 48) * pow(10,i-j-1);	
	}
	botanist->Water_Bottle_Size=water;
	
	
	i=0;
	do{	
		x=fgetc(p);
		arr[i]=x;
		i++;
															// loop for  get  the row from file //
	}while (x != '\n' && x != ',');
	i--;
	for(j=0; j<i; j++){
		row+=( arr[j] - 48) * pow(10,i-j-1);		
	}
	forest->Width=row;
	
	
	i=0;
	do{
		x=fgetc(p);
		arr[i]=x;
		i++;
															// loop for  get  the column from file//
	}while (x != '\n' && x != ',');
	i--;
	for(j=0; j<i; j++){
		column+=( arr[j] - 48) * pow(10,i-j-1);		
	}
	forest->Height=column;
	

		
	pt  = (char **)malloc(sizeof(char *) * row);							// creating the memory using the malloc //
    pt[0] = (char *)malloc(sizeof(char) * column * row);
    
    for(i = 0; i < row; i++)
        pt[i] = (*pt + column * i);
	
	
	i=0;
	j=0;
	
	do {																// loop for  get  the map from file//
		
		do{
			x=fgetc(p);
			if( x != ',' && x !='\n' && x != EOF)  {
				pt[i][j]=x;
				j++;	
			}
		
			if(x == 'B'){
				botanist->Coord_X=i;
				botanist->Coord_Y=j;
			}
			if(x == 'F'){
				forest->Flower_X=i;
				forest->Flower_Y=j;
			}
			
		}while(x != '\n' && x != EOF);
		
		j=0;
		i++;
		
	}while( x != EOF );
	
	forest->Map=pt;
	
	fclose(p);
	
}

void print_map (Forest* forest){
	
	int i,j;


	for(i=0; i < forest->Width; i++){
		
		for(j=0; j < forest->Height; j++){
			printf("%c",forest->Map[i][j]);
		}
		printf("\n");
	}	
}


int* search (Forest forest,int to_x,int to_y,int water,int counter){
	
	int* value_return;
	int num_ran;
	int co_x,co_y;
	
	
	
	num_ran=rand() % 4 + 1;
	
	
	
	if( water == -1){
		printf("\n");
		printf("Searching....\n");
		printf("\n");
		forest.Map[to_x][to_y]='B';
		value_return=(int*)calloc(2,sizeof(int));
		*value_return=to_x;
		*(value_return + 1)=to_y;
		return value_return;
	}
	
	if( to_x == forest.Flower_X && to_y == forest.Flower_Y){
		printf("\n");
		printf("Searching....\n");
		printf("\n");
		forest.Map[to_x][to_y]='B';
		value_return=(int*)calloc(2,sizeof(int));
		*value_return=to_x;
		*(value_return + 1)=to_y;
		return value_return;
	}
	
	if(counter != 0){
		num_ran=counter;
	}
	
	if(num_ran == 1 ){
		forest.Map[to_x][to_y]=' ';
		co_x=to_x-1;
		co_y=to_y;
		if( -1< co_x && co_x< forest.Width && ( forest.Map[co_x][co_y] == ' ' || forest.Map[co_x][co_y] == 'F') ){
			search (forest,co_x, co_y,water-1,1);
		}else {
			
			search (forest,to_x, to_y, water,num_ran);
		}	
	}
	else {
		if(num_ran == 2){
			forest.Map[to_x][to_y]=' ';
			co_x=to_x;
			co_y=to_y+1;
			if( -1< co_y && co_y< forest.Height && ( forest.Map[co_x][co_y] == ' ' || forest.Map[co_x][co_y] == 'F')){
				search (forest,co_x, co_y,water-1,2);
			}else {
				search (forest,to_x, to_y, water,0);
			}
		}
		else {
			if(num_ran == 3){
				forest.Map[to_x][to_y]=' ';
				co_x=to_x+1;
				co_y=to_y;
				if( -1< co_x && co_x< forest.Width && ( forest.Map[co_x][co_y] == ' ' || forest.Map[co_x][co_y] == 'F')){
					search (forest,co_x, co_y,water-1,3);
				}else {
					search (forest,to_x, to_y, water,0);
				}
			}
			else{
				if(num_ran == 4){
				forest.Map[to_x][to_y]=' ';
				co_x=to_x;
				co_y=to_y-1;
				if( -1< co_y && co_y< forest.Height && ( forest.Map[co_x][co_y] == ' ' || forest.Map[co_x][co_y] == 'F')){
					search (forest,co_x, co_y,water-1,4);
				}else {
					search (forest,to_x, to_y, water,0);
				}
			}
			}
		}
	
		
	}
	
	
	
	
	
}

