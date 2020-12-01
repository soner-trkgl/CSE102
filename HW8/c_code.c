#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


/*	Author : Soner Türkoðlu
 *
 *
 *
 *
 */
typedef enum {
	
	P,
	S,
	M,
	B,
	T
}block_type;

struct block{
	char text[15];
	int data;
	block_type type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
};



void f_initialize (struct block board[][10]);
void  f_print(struct block board[][10]);
int f_single(struct block board[][10],int ,int );








int main() {
	
	int x;
	struct block board[10][10];
	srand(time(NULL));
	f_initialize (board);
	f_print(board);

	printf("Move count :%d",f_single(board,9,9));   // 9-9 game start cordinate
	
	
	return 0;
}



void f_initialize (struct block board[][10]){
	
	int i,j;
	int counter=1;
	
	
	for(i=9; 0<=i; i--){
		
		if(i % 2 == 0){
			for(j=0; j<10; j++){
				board[i][j].data=counter;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].text[0]='\0';
				counter++;
			}
		}
		if(i % 2 == 1){
			for(j=9; 0<=j; j--){
				board[i][j].data=counter;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].text[0]='\0';
				counter++;
			}
		}
		
	}
	
	strcpy (board[9][9].text,"1(Start)");
	strcpy (board[9][3].text,"M{11}");
	board[9][3].type=M;
	board[9][3].jump_x=8;
	board[9][3].jump_y=0;
	strcpy (board[9][4].text,"S{1}");
	board[9][4].type=S;
	board[9][4].jump_x=9;
	board[9][4].jump_y=9;
	strcpy (board[8][6].text,"M{28}");
	board[8][6].type=M;
	board[8][6].jump_x=7;
	board[8][6].jump_y=2;
	strcpy (board[8][2].text,"P");
	board[8][2].type=P;
	strcpy (board[7][5].text,"S{12}");
	board[7][5].type=S;
	board[7][5].jump_x=8;
	board[7][5].jump_y=1;
	strcpy (board[7][1].text,"B") ;
	board[7][1].type=B;
	board[7][1].jump_x=6;
	board[7][1].jump_y=6;
	strcpy (board[6][9].text,"T");
	board[6][9].type=T;
	board[6][9].jump_x=7;
	board[6][9].jump_y=4;
	strcpy (board[6][5].text,"B");
	board[6][5].type=B;
	board[6][5].jump_x=6;
	board[6][5].jump_y=0;
	strcpy (board[6][1].text,"M{52}") ;
	board[6][1].type=M;
	board[6][1].jump_x=4;
	board[6][1].jump_y=1;
	strcpy (board[5][5].text,"S{22}") ;
	board[5][5].type=S;
	board[5][5].jump_x=7;
	board[5][5].jump_y=8;
	strcpy (board[5][2].text,"P") ;
	board[5][2].type=P;
	strcpy (board[5][0].text,"B") ;
	board[5][0].type=B;
	board[5][0].jump_x=4;
	board[5][0].jump_y=5;
	strcpy (board[4][9].text,"S{44}") ;
	board[4][9].type=S;
	board[4][9].jump_x=5;
	board[4][9].jump_y=6;
	strcpy (board[4][6].text,"M{77}") ;
	board[4][6].type=M;
	board[4][6].jump_x=2;
	board[4][6].jump_y=6;
	strcpy (board[4][3].text,"T") ;
	board[4][3].type=T;
	board[4][3].jump_x=4;
	board[4][3].jump_y=8;
	strcpy (board[3][7].text,"S{52}") ;
	board[3][7].type=S;
	board[3][7].jump_x=4;
	board[3][7].jump_y=1;
	strcpy (board[3][4].text,"B") ;
	board[3][4].type=B;
	board[3][4].jump_x=2;
	board[3][4].jump_y=9;
	strcpy (board[3][1].text,"M{77}") ;
	board[3][1].type=M;
	board[3][1].jump_x=2;
	board[3][1].jump_y=6;
	strcpy (board[2][8].text,"T") ;
	board[2][8].type=T;
	board[2][8].jump_x=3;
	board[2][8].jump_y=3;
	strcpy (board[2][5].text,"M{83}") ;
	board[2][5].type=M;
	board[2][5].jump_x=1;
	board[2][5].jump_y=7;
	strcpy (board[2][2].text,"S{68}") ;
	board[2][2].type=S;
	board[2][2].jump_x=3;
	board[2][2].jump_y=2;
	strcpy (board[1][8].text,"B") ;
	board[1][8].type=B;
	board[1][8].jump_x=1;
	board[1][8].jump_y=3;
	strcpy (board[1][5].text,"P") ;
	board[1][5].type=P;
	strcpy (board[1][1].text,"M{94}") ;
	board[1][1].type=M;
	board[1][1].jump_x=0;
	board[1][1].jump_y=3;
	strcpy (board[0][2].text,"T");
	board[0][2].type=T;
	board[0][2].jump_x=1;
	board[0][2].jump_y=7;
	strcpy (board[0][7].text,"S{72}") ;
	board[0][7].type=S;
	board[0][7].jump_x=2;
	board[0][7].jump_y=1;
	strcpy (board[0][8].text,"S{56}") ;
	board[0][8].type=S;
	board[0][8].jump_x=4;
	board[0][8].jump_y=5;
	strcpy (board[0][9].text,"100(Finish)") ;
	
	
	
	
	
}


void f_print(struct block board[][10]){
	
	int i,j;
	
	for(i=0; i<10; i++){
		
		for(j=0; j<10; j++){
			if(board[i][j].text[0] != '\0' ){
				printf("%s\t",board[i][j].text);
			}
			else {
				printf("%d\t",board[i][j].data);
			}
		}
		printf("\n");
	}

}


int f_single(struct block board[][10],int to_x,int to_y){
	
	
	int temp_x,temp_y;
	int rand_num;
	
	temp_x=to_x;
	temp_y=to_y;
	rand_num=(rand() % 6 ) + 1 ;
	
	
	if(to_x % 2 == 1){
		to_y-=rand_num;
		if(to_y < 0){
			to_x--;
			to_y=(to_y * -1) - 1;
		}
	}
	else {
		to_y+=rand_num;
		if(to_y > 9){
			to_x--;
			to_y=9 -(to_y - 9) + 1;
		}
	}
	
	
	if(to_x == 0 && to_y == 9){
		printf("Move : %d\n",board[to_x][to_y].data);
		return 1 ;
	}
	else {
		if( to_x == -1 ){
			printf("Move : %d\n",board[temp_x][temp_y].data);
			return f_single(board,temp_x,temp_y) + 1;
		}
		else {
			if( board[to_x][to_y].text[0] != '\0' ){
			
				if( board[to_x][to_y].type == P){
					printf("Move : %d\n",board[temp_x][temp_y].data);
					return f_single(board,temp_x,temp_y) + 1;
				}
				else {
					printf("Move : %d\n",board[to_x][to_y].data);
					printf("Move : %d\n",board[board[to_x][to_y].jump_x][board[to_x][to_y].jump_y].data);
					return f_single(board,board[to_x][to_y].jump_x,board[to_x][to_y].jump_y) + 1;
				}
			}
			else {
				printf("Move : %d\n",board[to_x][to_y].data);
				return f_single(board,to_x,to_y) + 1;
			}
		}
		
	}
	
}
	

