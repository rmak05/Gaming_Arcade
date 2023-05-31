#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define MAX_COLORS 5
#define PATTERN_SIZE 4

int game_HCu();
void generatePattern_HCu(int pattern[PATTERN_SIZE]);
void printPattern_HCu(int pattern[PATTERN_SIZE]);
void readInput_HCu(int input[PATTERN_SIZE]);
void evaluateGuess_HCu(int pattern[PATTERN_SIZE], int guess[PATTERN_SIZE], int *matchedColors, int *matchedPositions);
void printGuess_HCu(int guess[PATTERN_SIZE]);
void swap_HCu(int arr[],int i,int j);
void recursivebubblesort_HCu(int arr[],int n);
int HuesAndCuesRules();

// int main()
// {
//     game_HCu();
//     return 0;
// }

void generatePattern_HCu(int pattern[PATTERN_SIZE])
{
    int i;
    srand(time(NULL));
    for (i = 0; i < PATTERN_SIZE; i++) {
        pattern[i] = rand() % MAX_COLORS;
    }
}

int game_HCu()
{
    int pattern[PATTERN_SIZE];
    int guess[PATTERN_SIZE];
    int matchedColors, matchedPositions;
    int attempts = 0;

    generatePattern_HCu(pattern);
    //printPattern_HCu(pattern);
    while (attempts < MAX_ATTEMPTS) {
        printf("\nAttempt %d:\n", attempts + 1);
        readInput_HCu(guess);        
        evaluateGuess_HCu(pattern, guess, &matchedColors, &matchedPositions);
        printGuess_HCu(guess);

        if (matchedPositions == PATTERN_SIZE) {
            printf("Congratulations! You guessed the pattern correctly.\n");
            return 0;
        } else {
            printf("%d colors matched, %d positions matched.\n", matchedColors, matchedPositions);
            attempts++;
        }
    }

    printf("\nGame over! You ran out of attempts.\n");
    printf("The correct pattern was:\n");
    
    printPattern_HCu(pattern);
}

void swap_HCu(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void recursivebubblesort_HCu(int arr[],int n){
    for(int j=1;j<n;j++){
        if(arr[j]<arr[j-1]) swap_HCu(arr,j,j-1);
    }
    if(n-1>0) recursivebubblesort_HCu(arr,n-1);
}

void printPattern_HCu(int pattern[PATTERN_SIZE])
{
    int i;

    for (i = 0; i < PATTERN_SIZE; i++) {
        switch (pattern[i]) {
            case 0:
                printf("\033[1;31m%c", 4);
                printf("\033[0m"); // Red
                break;
            case 1:
                printf("\033[1;34m%c", 4);
                printf("\033[0m"); // Blue
                break;
            case 2:
                printf("\033[1;32m%c", 4);
                printf("\033[0m"); // Green
                break;
            case 3:
                printf("\033[1;33m%c", 4);
                printf("\033[0m"); // Yellow
                break;
            case 4:
                printf("\033[1;35m%c", 4);
                printf("\033[0m"); // Magenta
                break;
        }
    }

    printf("\n");
}

void readInput_HCu(int input[PATTERN_SIZE])
{
    char color;
    int i;

    for (i = 0; i < PATTERN_SIZE; i++) {
        printf("Enter color %d (Initial letter only): ", i + 1);
        scanf(" %c", &color);

        switch (color) {
            case 'R':
            case 'r':
                input[i] = 0; // Red
                break;
            case 'B':
            case 'b':
                input[i] = 1; // Blue
                break;
            case 'G':
            case 'g':
                input[i] = 2; // Green
                break;
            case 'Y':
            case 'y':
                input[i] = 3; // Yellow
                break;
            case 'M':
            case 'm':
                input[i] = 4; // Magenta
                break;
            default:
                printf("Invalid color! Please try again.\n");
                i--; // Retry the same position
                break;
        }
    }
}


void evaluateGuess_HCu(int pattern[PATTERN_SIZE], int guess[PATTERN_SIZE], int *matchedColors, int *matchedPositions)
{
    int i, j;
    int colors[MAX_COLORS] = {0};
    *matchedColors = 0;
    *matchedPositions = 0;

    // Count matched positions
    for (i = 0; i < PATTERN_SIZE; i++) {
        if (guess[i] == pattern[i]) {            
            (*matchedPositions)++;
        }
    }

    // Count matched colors
    int color_check[PATTERN_SIZE];
    int guess_check[PATTERN_SIZE];
    for(int i=0;i<PATTERN_SIZE;i++) color_check[i]=pattern[i];
    for(int i=0;i<PATTERN_SIZE;i++) guess_check[i]=guess[i];
    recursivebubblesort_HCu(color_check,PATTERN_SIZE);
    for(int i=0;i<PATTERN_SIZE;i++){
        for(int j=0;j<PATTERN_SIZE;j++){
            //printf("%d%d ",color_check[j],guess_check[i]);
            if(color_check[j]==guess_check[i] && color_check[j]!=-1 && guess_check[i]!=-1){
                (*matchedColors)++;
                color_check[j]=-1;
                guess_check[i]=-1;

            }
        }
    }
}

void printGuess_HCu(int guess[PATTERN_SIZE])
{
    int i;
    for (i = 0; i < PATTERN_SIZE; i++) {
        switch (guess[i]) {
            case 0:
                printf("\033[1;31m%c", 4);
                printf("\033[0m"); // Red
                break;
            case 1:
                printf("\033[1;34m%c", 4);
                printf("\033[0m"); // Blue
                break;
            case 2:
                printf("\033[1;32m%c", 4);
                printf("\033[0m"); // Green
                break;
            case 3:
                printf("\033[1;33m%c", 4);
                printf("\033[0m"); // Yellow
                break;
            case 4:
                printf("\033[1;35m%c", 4);
                printf("\033[0m"); // Magenta
                break;
        }
    }

    printf("\n");
}

int HuesAndCuesRules(){

    system("cls");

    printf("%c",201);                           
    for(int i=0;i<120;i++) printf("%c",205);     
    printf("%c\n",187); 

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",186);  
    printf(" RULES ");
    for(int i=0;i<113;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);
    
    printf("%c",186);  
    printf(" - This is a two player game (vs computer).");
    for(int i=0;i<77;i++) printf(" ");
    printf("%c\n",186);  

    printf("%c",186);  
    printf(" - In this game, the computer creates a linear colour pattern consisting of 4 colours with possible repetition.");
    for(int i=0;i<9;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The colours in the pattern can be Red,Blue,Green,Yellow,Magenta.");
    for(int i=0;i<53;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - The goal is to guess this pattern within 10 attempts.");
    for(int i=0;i<64;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - As a hint, after each attempt, the screen shows the number of colours that match, as well as the number of positions");
    for(int i=0;i<1;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf("   of the pattern that match with the actual pattern.");
    for(int i=0;i<67;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Note that if a colour is repeated, then those repetitions will be considered as separate colours and hint will be");
    for(int i=0;i<4;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf("   given accordingly.");
    for(int i=0;i<99;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - When a split occurs , the atoms now occupy the neighboring tiles of the tile where the split took place.");
    for(int i=0;i<13;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - As a hint, after each attempt, the screen shows the number of colours that match, as well as the number of positions");
    for(int i=0;i<1;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf("   player winner.");
    for(int i=0;i<103;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",186);  
    printf(" HOW TO PLAY ");
    for(int i=0;i<107;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The colours involved are Red,Blue,Green,Yellow and Magenta.");
    for(int i=0;i<58;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - To enter a colour , you just need to enter the first letter of the colour.");
    for(int i=0;i<43;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - For example , if you want to choose red , then enter \"R\" or \"r\".");
    for(int i=0;i<53;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<120;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");

}