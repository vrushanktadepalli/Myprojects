#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

char board[3][3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int free_spaces;
void print_board();
void reset_board();
void player_move();
void computer_move();
char check_winner();
int place_O(char);


int main(){
	char win, p;
	do {
    	reset_board();
    	win = ' ';
    	do{
    		print_board();
    		free_spaces--;
    		if((free_spaces % 2) == 0)	
				player_move();
			else	
				computer_move();
    		win	= check_winner();
    	}while(win == ' ' && free_spaces >= 0);
    	print_board();
    	if(win == 'X')
    		printf("You Win!\n");
    	else if(win == 'O') 
    		printf("You Lose!\n");
    	else 
    		printf("It's a Draw!\n");
    	scanf("%c", &p);
    	printf("Do you want to play again(Y/N): ");
    	scanf("%c", &p);
    	p = toupper(p);
	}while(p == 'Y');
	printf("Thanks for playing!");
}

void reset_board() {
	free_spaces = 9;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			board[i][j] = ' ';
}
void print_board() {
	printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}
void player_move() {
	int x, y, k = 0;
	do {
		k = 0;
		printf("Row#: ");
		scanf("%d", &x);
		printf("Column#: ");
		scanf("%d", &y);
		x--;
		y--;
		if(board[x][y] != ' ') {
			printf("Invalid\n");
			k++;
			print_board();
		}
		else
			board[x][y] = 'X';
	} while(k > 0);
}
void computer_move() {
	srand(time(NULL));
	if(place_O('O'))      //if cannot place 'O' to win
		return;
	if(place_O('X'))	  //if cannot block 'X'
		return;
	int x, y, k = 0;      //place 'O' randomly
	do{
		x=rand() % 3;
		y=rand() % 3;
		k = 0;
		if(board[x][y] == ' ')
			board[x][y] = 'O';
		else k++;
	}while(k > 0 && free_spaces > 0);
}
char check_winner() {
	for(int i = 0; i < 3; i++){
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
			return board[i][0];
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return board[0][i];
	}
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
		return board[0][0];
	if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
		return board[2][0];
	return ' ';
}

int place_O(char a){
	if (board[0][0] == board[2][2] && board && board[1][1] == ' '){
		board[1][1]= 'O';
		return 1;
	}
	for(int i = 0; i < 3; i++)     //checks all rows and columns
		for(int j = 0; j < 3; j++){
			if(board[i][j] == board[i][(j+1) % 3] && board[i][j] == a && board[i][(j+2) % 3] == ' '){
	        board[i][(j+2) % 3] = 'O';
	        return 1;
			}
			if(board[j][i] == board[(j+1) % 3][i] && board[j][i] == a && board[(j+2) % 3][i] == ' '){
	        board[(j+2) % 3][i] = 'O';
	        return 1;
			}
		}
	for(int i = 0; i < 3; i++)    //checks diagonals
		if(board[i][i] == board[(i+1) % 3][(i+1) % 3] && board[i][i] == a && board[(i+2) % 3][(i+2) % 3] == ' '){
			board[(i+2) % 3][(i+2) % 3] = 'O';
			return 1;
		}
	if(board[2][0] == board[1][1] && board[2][0] == a && board[0][2] == ' '){
 	    board[0][2] = 'O';
   	    return 1;
   	}
   	if(board[1][1] == board[0][2] && board[1][1] == a && board[2][0] == ' '){
   	    board[2][0] = 'O'; 
  	    return 1;
       }
   	if(board[0][2] == board[2][0] && board[0][2] == a && board[1][1] == ' '){
   	    board[1][1] = 'O';
   	    return 1;
   	}
	return 0;
}
