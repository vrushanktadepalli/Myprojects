#include <stdio.h>
#include <string.h>
#include <ctype.h>
void hangman(int);
int main(){
    char incorrect[6];
    char word[] = "COMPUTER", l;
    int n = strlen(word);
    char result[n + 1];
    for(int i = 0; i < n; i++)
        result[i] = '_';
    char word1[n];
    strcpy(word1, word);
    int correct = 0 ,wrong = 0, k = 0;
    while(correct < n && wrong < 6){
        printf("\n\n\n\n\n");
        for(int i = 0; i < n; i++)
            printf("%c", result[i]);
        printf("\n");
        hangman(wrong);                  //printing the respective hangman
        for(int i = 0; i < wrong; i++)   //counting the number of incorrect guesses
            printf("X");
        for(int i = 0; i < 6-wrong; i++)
            printf("-");
        printf("\nEnter your guess\n");
        scanf(" %c", &l);
        l = toupper(l);
        k = 0;
        for(int i = 0; i < n; i++)    //counting the number of times the
            if(l == word[i]){         //guess repeats in that word
                result[i] = word[i];
                word[i] = '.';
                correct++;
                k++;
            }
        if(k == 0){
            incorrect[wrong] = l;
            printf("Incorrect guesses are\n");   //printing the incorrect guesses
            for(int m = 0; m <= wrong; m++)
                printf("%c ", incorrect[m]);
            printf("\n");
            wrong++;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%c", result[i]);
    printf("\n");
    hangman(wrong);
    if(correct == n)
        printf("Correct!\nYou made %d mistake(s)", wrong);
    else
        printf("You lost!\nThe correct word was %s", word1);
}
void hangman(int k){
    switch(k){
        case 0:
        printf(" _______    \n");
        printf(" |     |    \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_________ \n");
        break;
        case 1:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_________ \n");
        break;
        case 2:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_________ \n");
        break;
        case 3:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |     |    \n");
        printf(" |    /|    \n");
        printf(" |   / |    \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_________ \n");
        break;
        case 4:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |     |    \n");
        printf(" |    /|\\  \n");
        printf(" |   / | \\ \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |          \n");
        printf(" |          \n");
        printf("_|_________ \n");
        break;
        case 5:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |     |    \n");
        printf(" |    /|\\  \n");
        printf(" |   / | \\ \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |    /     \n");
        printf(" |   /      \n");
        printf("_|_________ \n");
        break;
        case 6:
        printf(" _______    \n");
        printf(" |    _|_   \n");
        printf(" |   /   \\ \n");
        printf(" |   \\___/ \n");
        printf(" |     |    \n");
        printf(" |    /|\\  \n");
        printf(" |   / | \\ \n");
        printf(" |     |    \n");
        printf(" |     |    \n");
        printf(" |    / \\  \n");
        printf(" |   /   \\ \n");
        printf("_|_________ \n");
        break;
    }
}
