#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int playerScore_rps = 0, compScore_rps = 0;

int genRandom_RPS(int n);
int moveCheck_RPS(char c1, char c2);
int validity_check_RPS(int a);
void scoreAddition_RPS(char c1, char c2);
void scoreCheck_RPS(int d1, int d2);
void game_RPS();
int RockPaperScissorsRules();

// int main()
// {
//     game_RPS();
//     return 0;
// }

int genRandom_RPS(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int validity_check_RPS(int a)
{
    if (a < 1 || a > 3) {
        return 0;
    } else {
        return 1;
    }
}

void game_RPS()
{
    int temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'};
    
    printf("\033[1m");
    for (int game_start = 0; game_start < 5; game_start++)
    {   
        system("cls");
        printf("\033[1;34m");
        printf("PLAYER'S TURN:\n");
        printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors.\n");
        printf("\033[0m");
        printf("\033[1m");

        scanf("%d", &temp);
        int valid = validity_check_RPS(temp);
        if (valid == 1) {
            playerChar = dict[temp-1];
            printf("\033[1;34m");
            if(playerChar=='r') printf("You chose Rock\n\n");
            else if(playerChar=='p') printf("You chose Paper\n\n");
            else if(playerChar=='s') printf("You chose Scissors\n\n");
            printf("\033[0m");
            printf("\033[1m");

            printf("\033[1;33m");
            printf("COMPUTER'S TURN:\n");
            temp = genRandom_RPS(3) + 1;
            compChar = dict [temp-1];
            if(compChar=='r') printf("Computer chose Rock\n\n");
            else if(compChar=='p') printf("Computer chose Paper\n\n");
            else if(compChar=='s') printf("Computer chose Scissors\n\n");
            printf("\033[0m");
            printf("\033[1m");

            scoreAddition_RPS(compChar, playerChar);
        } else {
            printf("\033[1;31m");
            printf("INVALID INPUT");
            printf("\033[0m");
            printf("\033[1m");

            printf("\033[1;34m");
            printf("  TRY AGAIN!\n\n");
            printf("\033[0m");
            printf("\033[1m");
            game_start--;
        }
        system("pause");
    }
    
    scoreCheck_RPS(playerScore_rps, compScore_rps);
}

int moveCheck_RPS(char c1, char c2)
{
    if (c1 == c2) {
        return 0;
    }

    if ((c1 == 'r') && (c2 == 's')) {
        return 1;
    } else if ((c1 == 'p') && (c2 == 'r')) {
        return 1;
    } else if ((c1 == 's') && (c2 == 'p')) {
        return 1;
    } else {
        return -1;
    }
}

void scoreAddition_RPS(char c1, char c2)
{
    if (moveCheck_RPS(c1, c2) == 1) {
        compScore_rps += 1;
        printf("\033[1;31m");
        printf("Computer got it!\n\n");
        printf("Player's Score : %d\nComputer's Score : %d\n", playerScore_rps, compScore_rps);
        printf("\033[0m");
        printf("\033[1m");
    } else if (moveCheck_RPS(c1, c2) == 0) {
        printf("\033[1;37m");
        printf("Draw!\n\n");
        printf("Player's Score : %d\nComputer's Score : %d\n", playerScore_rps, compScore_rps);
        printf("\033[0m");
        printf("\033[1m");
    } else if(moveCheck_RPS(c1,c2)==-1){
        playerScore_rps += 1;
        printf("\033[1;32m");
        printf("You got it!\n\n");
        printf("Player's Score : %d\nComputer's Score : %d\n", playerScore_rps, compScore_rps);
        printf("\033[0m");
        printf("\033[1m");
    }
}

void scoreCheck_RPS(int d1, int d2)
{
    system("cls");
    printf("Player's Score : %d\nComputer's Score : %d\n", playerScore_rps, compScore_rps);
    if (d1 > d2) {
        printf("\033[1;32m");
        printf("\nYOU WIN!\n");
        printf("\033[0m");
        printf("\033[1m");
    } else if (d1 < d2) {
        printf("\033[1;31m");
        printf("\nYOU LOSE!\n");
        printf("\033[0m");
        printf("\033[1m");
    } else {
        printf("\033[1;37m");
        printf("\nIt's a DRAW!\n");
        printf("\033[0m");
        printf("\033[1m");
    }
}

int RockPaperScissorsRules(){
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
    printf(" - In this game, the player has to choose either Rock, Paper or Scissors for one round.");
    for(int i=0;i<33;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Paper beats Rock, Rock beats Scissors and Scissors beat Paper.");
    for(int i=0;i<55;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If a player wins, he/she gets one point.");
    for(int i=0;i<77;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If both players choose the same, it's a draw and zero points are awarded.");
    for(int i=0;i<44;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - After five rounds, whoever scores more wins the game, or if the scores are level, then it is a draw.");
    for(int i=0;i<17;i++) printf(" ");
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
    printf(" - Choose 1 for Rock, 2 for Paper and 3 for Scissors.");
    for(int i=0;i<67;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<120;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");
}