#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int board[100];
int sal[100] = {};
int p1pos = -1;
int p2pos = -1;

void print_board();
void fill_board();
void move_player(int*,int);

int main(){
    srand(time(0));
    fill_board();
    int iter = 1;
    int win = 1;
    while(win){
        print_board();
        if(iter%2)
            printf("P1 move");
        else
            printf("P2 move");
        printf("\nPress Enter to roll the die");
        getchar();                          //waits till the user hits enter
        int die = rand()%6 +1;
        printf("\nYou rolled %d\n", die);
        if(iter%2)
            move_player(&p1pos,die);
        else
            move_player(&p2pos,die);
        iter++;
        if(p1pos == 99 || p2pos == 99)
            win = 0;
    }
    if(p1pos == 99)
        printf("P1 won!!");
    else
        printf("P2 won!!");
    printf("\nThanks for playing");
}

void print_board(){
    for(int i = 99; i >= 0; i--){
        int j = (i/10)*20+9 - i;
        if((i/10)%2)
            if(p1pos == i)                //prints the board 
                printf("#P1<- ");         //replaces the numbers by #P1 and #P2
            else if(p2pos == i)           //if the player is on it
                printf("#P2<- ");
            else 
                printf("%3d   ",board[i]);
        else    
            if(p1pos == j)
                printf("#P1<- ");
            else if(p2pos == j)
                printf("#P2<- ");
            else 
                printf("%3d   ",board[j]);
        if(!(i%10))
            printf("\n\n");
    }
    printf("LADDERS:                SNAKES:\n");
    printf(" 1 to 38                17 to  7\n");
    printf(" 4 to 14                54 to 34\n");
    printf(" 9 to 31                62 to 19\n");
    printf("21 to 42                64 to 60\n");
    printf("28 to 84                87 to 24\n");
    printf("51 to 67                93 to 73\n");
    printf("71 to 91                95 to 75\n");
    printf("80 to 99                98 to 79\n");
}
void fill_board(){
    for(int i = 0; i < 100; i++)
        board[i] = i+1;
    sal[3] = 10;              // (-) means snakes
    sal[0] = 37;              // (+) means ladders
    sal[8] = 22;              //position increases or decreases 
    sal[16] = -10;            //by the relative amount
    sal[20] = 21;
    sal[27] = 56;
    sal[50] = 16;
    sal[61] = -43;
    sal[63] = -4;
    sal[70] = 20;
    sal[86] = -63;
    sal[92] = -20;
    sal[94] = -20;
    sal[97] = -19;

}
void move_player(int* player_pos,int die){
    if(*player_pos + die > 99)
        return;
    *player_pos = *player_pos + die + sal[*player_pos + die];
}
