#include<stdio.h>

/*	Author : Soner Türkoðlu
 *
 *
 *
 */



typedef enum {								// using the enumerator for new variable type //			
				white_man=1, 
				black_man=2, 
				white_king=3, 
				black_king=4, 
				empty=0
			} piece;
			
typedef enum {								// using the enumerator for new variable type //
				white = 10, 
				black = 20
			} player;

piece board[8][8];				// declaration of array for board of turkish draught //



										// declaration of function prototype //	
void init_board(piece board[][8]);							
int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p);
int check_end_of_game(piece board[][8]);
void display_board(piece board[][8]);
void sample_game_1();
void sample_game_2();


int main(){
	
	
	
	sample_game_1();
	sample_game_2();

	
	
	return 0;
}



void init_board(piece board[][8]){
	
	int i,j;						// declaration of variable for loop //
	
	for(i=0; i<8; i++){				// assigning empty to board for game //	
		
		for(j=0; j<8; j++){
			board[i][j]=empty;
		}
	}
	
	for(i=1; i<3; i++){			// assigning black man to board for black player //
		
		for(j=0; j<8; j++){
			board[i][j]=black_man;
		}
	}
	
	for(i=5; i<7; i++){			// assigning black man to board for white player //
		
		for(j=0; j<8; j++){
			board[i][j]=white_man;
		}
	}
}

int move(piece board[][8], int from_x, int from_y, int to_x, int to_y, player p){
	
	int i;				// declaration of variable for loop //
	int counter1=0;		
	int counter2=0;
	int counter3=0;
	int counter4=0;
	from_x-=1;
	from_y-=1;
	to_x-=1;
	to_y-=1;
	
	if(p==white && (board[from_x][from_y]!=white_man && board[from_x][from_y]!=white_king) ){		// if the player choose wrong place or wrong pieces, function returns -1 //
		return -1;
	}
	if(p==black && (board[from_x][from_y]!=black_man && board[from_x][from_y]!=black_king) ){		// if the player choose wrong place or wrong pieces, function returns -1 //
		return -1;
	}
	
	if(to_x>7 || 0>to_x){				// if the player choose outside of board, function returns -1 //
		return -1;
	}
	if(to_y>7 || 0>to_y){				// if the player choose outside of board, function returns -1 //
		return -1;
	}
	
	if(board[to_x][to_y]!=empty){		// the piece's next place  must be empty //
			
		return -2;	
	}
	
	if(from_x!=to_x && from_y!=to_y){	 // the piece never don't have cross step //
		return -2;
	}
	
	
	if(board[from_x][from_y]==white_man){		// if player choose the white_man , do the below //
		
		if(from_y==to_y && from_x==to_x+1){    // this selection for forward (one step) moves //  
			
			if(to_x==0){
				board[to_x][to_y]=white_king;
				board[from_x][from_y]=empty;
				return 1;
			}
			
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_y==to_y && from_x==to_x+2 && (board[to_x+1][to_y]==black_man || board[to_x+1][to_y]==black_king)){  // this selection for forward and jump (two step) move //
			
			if(to_x==0){
				board[to_x][to_y]=white_king;
				board[to_x+1][to_y]=empty;
				board[from_x][from_y]=empty;
				return 1;
			}
			board[to_x][to_y]=white_man;
			board[to_x+1][to_y]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y+1==to_y){ 		// this selection for right (one step) move //
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y+2==to_y && (board[to_x][to_y-1]==black_man || board[to_x][to_y-1]==black_king)){ 	// this selection for right jump (two step) move  //
			board[to_x][to_y]=white_man;
			board[to_x][to_y-1]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y==to_y+1){ 		// this selection for left (one step) move //
			board[to_x][to_y]=white_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y==to_y+2 && (board[to_x][to_y+1]==black_man || board[to_x][to_y+1]==black_king)){	// this selection for left  jump (two step) move //
			board[to_x][to_y]=white_man;
			board[to_x][to_y+1]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		return -2;
	}
	
	if(board[from_x][from_y]==black_man){			// if player choose the black_man , do the below //
		
		if(from_y==to_y && from_x+1==to_x){			// this selection for forward (one step) moves // 
			if(to_x==7){
				board[to_x][to_y]=black_king;
				board[from_x][from_y]=empty;
				return 1;
			}
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_y==to_y && from_x+2==to_x && (board[from_x+1][to_y]==white_man || board[from_x+1][to_y]==white_king)){	// this selection for forward and jump (two step) move //
			
			if(to_x==7){
				board[to_x][to_y]=black_king;
				board[from_x+1][to_y]=empty;
				board[from_x][from_y]=empty;
				return 1;
			}
			board[to_x][to_y]=black_man;
			board[from_x+1][to_y]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y+1==to_y){				// this selection for right (one step) move //
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y+2==to_y && (board[to_x][to_y-1]==white_man || board[to_x][to_y-1]==white_king)){			// this selection for right jump (two step) move  //
			board[to_x][to_y]=black_man;
			board[to_x][to_y-1]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y==to_y+1){			// this selection for left (one step) move //
			board[to_x][to_y]=black_man;
			board[from_x][from_y]=empty;
			return 1;
		}
		
		if(from_x==to_x && from_y==to_y+2 && (board[to_x][to_y+1]==white_man || board[to_x][to_y+1]==white_king)){		// this selection for left  jump (two step) move //
			board[to_x][to_y]=black_man;
			board[to_x][to_y+1]=empty;
			board[from_x][from_y]=empty;
			return 1;
		}
		return -2;
	}
	
	
	if(board[from_x][from_y]==white_king){		// if player choose the white_king , do the below //
		
		
		if(from_x==to_x){         	
			
			if(from_y<to_y){					// this selection for right  move //
				for(i=from_y+1; i<to_y-1; i++){
					if(	board[from_x][i]!=empty)
						counter1++;
				}
				if(counter1==0 && (board[from_x][to_y-1]==black_man || board[from_x][to_y-1]==black_king)){
					board[to_x][to_y]=white_king;
					board[to_x][to_y-1]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter1==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
			
			if(from_y>to_y){					// this selection for left  move //
				for(i=from_y-1; to_y+1<i; i--){
					if(	board[from_x][i]!=empty)
						counter2++;
				}
				if(counter2==0 && (board[from_x][to_y+1]==black_man || board[from_x][to_y+1]==black_king)){
					board[to_x][to_y]=white_king;
					board[to_x][to_y+1]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter2==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
					return 1;
				}	
			}
			
		}
		
		if(from_y==to_y){
			
			if(from_x<to_x){				// this selection for down  move //
				for(i=from_x+1; i<to_x-1; i++){
					if(	board[i][from_y]!=empty)
						counter3++;
				}
				if(counter3==0 && (board[to_x-1][from_y]==black_man || board[to_x-1][from_y]==black_king)){
					board[to_x][to_y]=white_king;
					board[to_x-1][from_y]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter3==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
			
			if(from_x>to_x){			// this selection for up  move //
				for(i=from_x-1; to_x+1<i; i--){	
					if(	board[i][from_y]!=empty)
						counter4++;
				}
				if(counter4==0 && (board[to_x+1][from_y]==black_man || board[to_x+1][from_y]==black_king)){
					board[to_x][to_y]=white_king;
					board[to_x+1][from_y]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter4==0){
					board[to_x][to_y]=white_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
		}
		
	}
	
	counter1=0;
	counter2=0;
	counter3=0;
	counter4=0;
	
	
	if(board[from_x][from_y]==black_king){		// if player choose the black_king , do the below //
		
	
		if(from_x==to_x){
			
			if(from_y<to_y){					// this selection for right  move //
				for(i=from_y+1; i<to_y-1; i++){
					if(	board[from_x][i]!=empty)
						counter1++;
				}
				if(counter1==0 && (board[from_x][to_y-1]==white_man || board[from_x][to_y-1]==white_king)){
					board[to_x][to_y]=black_king;
					board[to_x][to_y-1]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter1==0){
					board[to_x][to_y]=black_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
			
			if(from_y>to_y){					// this selection for left  move //
				for(i=from_y-1; to_y+1<i; i--){
					if(	board[from_x][i]!=empty)
						counter2++;
				}
				if(counter2==0 && (board[from_x][to_y+1]==white_man || board[from_x][to_y+1]==white_king)){
					board[to_x][to_y]=black_king;
					board[to_x][to_y+1]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter2==0){
					board[to_x][to_y]=black_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
			
		}
		
		if(from_y==to_y){
			
			if(from_x<to_x){					// this selection for down  move //
				for(i=from_x+1; i<to_x-1; i++){
					if(	board[i][from_y]!=empty)
						counter3++;
				}
				if(counter3==0 && (board[to_x-1][from_y]==white_man || board[to_x-1][from_y]==white_king)){
					board[to_x][to_y]=black_king;
					board[to_x-1][from_y]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter3==0){
					board[to_x][to_y]=black_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
			
			if(from_x>to_x){					// this selection for up  move //
				for(i=from_x-1; to_x+1<i; i--){
					if(	board[i][from_y]!=empty)
						counter4++;
				}
				if(counter4==0 && (board[to_x+1][from_y]==white_man || board[to_x+1][from_y]==white_king)){
					board[to_x][to_y]=black_king;
					board[to_x+1][from_y]=empty;
					board[from_x][from_y]=empty;
					return 1;
				}
				if(counter4==0){
					board[to_x][to_y]=black_king;
					board[from_x][from_y]=empty;
					return 1;
				}
			}
		}
	}
	

	
	
	
}


int check_end_of_game(piece board[][8]){
	
	int white_counter=0;		// declaration of variable for count of white man //
	int black_counter=0;		// declaration of variable for count of black man //
	int i,j;				// declaration of variable for loop //
	
	for(i=0; i<8; i++){
		
		for(j=0; j<8; j++){
			if(board[i][j]==white_man)
				white_counter++;
		}
	}
	
	for(i=0; i<8; i++){
		
		for(j=0; j<8; j++){
			if(board[i][j]==black_man)
				black_counter++;
		}
	}
	
	if(black_counter!=0 && white_counter!=0){
		
		printf("Game countinues");
		
		return -1;
	}
	
	if(black_counter==0){
		
		printf("White wins the game");
		return white;
	}
	
	if(white_counter==0){
		
		printf("Black wins the game");
		return black;
	}
	
}

void display_board(piece board[][8]){
	
	int i,j;					// declaration of variable for loop //
	
	for(i=0; i<8; i++){											
		
		for(j=0; j<8; j++){						// printing the board //
			if(board[i][j]==empty)
				printf("-");
			if(board[i][j]==black_man)
				printf("b");
			if(board[i][j]==white_man)
				printf("w");
			if(board[i][j]==black_king)
				printf("B");
			if(board[i][j]==white_king)
				printf("W");
		}
		printf("\n");
	}
	
}


void sample_game_1(){
	
	init_board(board);				// initializing  the board of game //
	
	
	move(board,6,3,5,3,white);		// player's move in game // 
	move(board,3,8,4,8,black);
	move(board,6,7,5,7,white);
	move(board,2,8,3,8,black);
	move(board,6,6,5,6,white);
	move(board,2,7,2,8,black);
	move(board,5,6,5,5,white);
	move(board,4,8,5,8,black);
	move(board,6,8,4,8,white);
	move(board,3,8,5,8,black);
	move(board,5,8,5,6,black);
	move(board,5,6,5,4,black);
	move(board,5,4,5,2,black);
	move(board,6,2,4,2,white);
	move(board,3,2,5,2,black);
	move(board,6,1,6,2,white);
	move(board,5,2,5,1,black);
	move(board,6,2,6,1,white);
	move(board,3,1,4,1,black);
	move(board,6,1,6,2,white);
	move(board,3,7,4,7,black);
	move(board,6,2,5,2,white);
	move(board,5,1,5,3,black);
	move(board,6,4,6,3,white);
	move(board,3,3,4,3,black);
	move(board,6,5,5,5,white);
	move(board,2,8,3,8,black);
	move(board,7,4,6,4,white);
	move(board,3,8,4,8,black);
	move(board,6,4,5,4,white);
	move(board,5,3,5,2,black);
	move(board,6,3,5,3,white);
	move(board,4,3,6,3,black);
	move(board,6,3,8,3,black);
	move(board,5,5,5,6,white);
	move(board,4,8,5,8,black);
	move(board,7,6,6,6,white);
	move(board,8,3,5,3,black);
	move(board,7,7,6,7,white);
	move(board,5,3,5,5,black);
	move(board,5,5,5,7,black);
	move(board,5,7,7,7,black);
	move(board,7,7,7,4,black);
	move(board,7,2,6,2,white);
	move(board,7,4,8,4,black);
	move(board,5,2,7,2,black);
	move(board,7,1,7,3,white);
	move(board,8,4,8,3,black);
	move(board,6,6,6,7,white);
	move(board,8,3,6,3,black);
	move(board,6,3,6,8,black);
	move(board,6,8,8,8,black);
	
}

void sample_game_2(){
	
	board[1][2]=black_man;		// initializing  the board of game //
	board[1][3]=black_man;
	board[1][4]=black_man;
	board[1][5]=black_man;
	board[2][1]=black_man;
	board[2][2]=black_man;
	board[2][3]=black_man;
	board[2][4]=black_man;
	board[2][6]=black_man;
	board[2][7]=black_man;
	board[3][0]=black_man;
	board[3][1]=black_man;
	board[3][2]=black_man;
	board[3][5]=black_man;
	board[3][7]=black_man;
	board[4][5]=black_man;
	
	board[4][2]=white_man;			// initializing  the board of game //
	board[4][3]=white_man;
	board[4][4]=white_man;
	board[4][6]=white_man;
	board[4][7]=white_man;
	board[5][0]=white_man;
	board[5][1]=white_man;
	board[5][2]=white_man;
	board[5][3]=white_man;
	board[5][4]=white_man;
	board[5][6]=white_man;
	board[5][7]=white_man;
	board[6][2]=white_man;
	board[6][3]=white_man;
	board[6][4]=white_man;
	board[6][5]=white_man;	
	
	move(board,6,2,5,2,white);		// player's move in game //
	move(board,4,2,6,2,black);
	move(board,5,4,4,4,white);
	move(board,5,6,5,4,black);
	move(board,5,4,5,2,black);
	move(board,4,4,4,2,white);
	move(board,4,2,2,2,white);
	move(board,2,3,2,1,black);
	move(board,6,4,5,4,white);
	move(board,6,2,6,4,black);
	move(board,6,4,6,6,black);
	move(board,6,6,8,6,black);
	move(board,5,4,4,4,white);
	move(board,3,4,5,4,black);
	move(board,6,7,6,6,white);
	move(board,8,6,5,6,black);
	move(board,5,7,5,5,white);
	move(board,5,5,5,3,white);
	move(board,5,3,5,1,white);
	move(board,5,1,3,1,white);
	move(board,3,1,1,1,white);
	
}
