#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genRandom_HC(int n);
int validity_check_HC(int a, int n);
int toss_choice_HC();
int toss_HC(int odd_or_even, int playerToss, int compToss, int choice);
void game_HC();
void odd_even(int odd_or_even);
void comp_bat_first_HC(int playerMove, int compMove, int playerScore, int compScore);
void player_bat_first_HC(int playerMove, int compMove, int playerScore, int compScore);
int HandCricketRules();

// int main()
// {
//     game_HC();
//     return 0;
// }

int genRandom_HC(int n)
{
    srand(time(NULL));
    return (rand() % n);
}

int validity_check_HC(int a, int n)
{
    if (a < 0 || a > n) {
        return 0;
    } else {
        return 1;
    }
}

void game_HC()
{
    int playerScore=0, compScore=0;
    int playerMove, compMove;
    int playerToss, compToss;
    int odd_or_even, choice;
    int v, c;

    odd_or_even = toss_choice_HC();
    v = validity_check_HC(odd_or_even, 1);

    if (v == 1) {
        odd_even(odd_or_even);
        c = toss_HC(odd_or_even, playerToss, compToss, choice);

        if (c == 1) {
            comp_bat_first_HC(playerMove, compMove, playerScore, compScore);
            
        } else {
            player_bat_first_HC(playerMove, compMove, playerScore, compScore);
        }
    }
    else {
        printf("\033[0;31m");
        printf("INVALID INPUT, ENTER AGAIN.\n");
        printf("\033[0m");
        game_HC();     
    }
}

int toss_choice_HC()
{
    int a;
    printf("\033[1;35m");
    printf("\nChoose 1 for Odd or 0 for Even: ");
    printf("\033[0m");
    scanf("%d", &a);
    int v = validity_check_HC(a, 1);
    if (v==1) {
        return a;
    } else {
        printf("\033[1;31m");
        printf("INVALID INPUT, ENTER AGAIN.\n");
        printf("\033[0m");
        toss_choice_HC();
    }
}

void odd_even(int odd_or_even)
{
    if (odd_or_even == 1) {
        printf("\033[1;34m");
        printf("You have chosen Odd.\n");
        printf("\033[0m");
    } else if (odd_or_even == 0) {
        printf("\033[1;34m");
        printf("You have chosen Even.\n");
        printf("\033[0m");

    }
}

int toss_HC(int odd_or_even, int playerToss, int compToss, int choice)
{
    printf("\033[1;36m");
    printf("Enter your number (from 0 to 6 only): ");
    scanf("%d", &playerToss);
    printf("\033[0m");
    int v = validity_check_HC(playerToss, 6);
    if (v == 1) {
        compToss = genRandom_HC(7);
        printf("\033[1;36m");
        printf("Computer's number: %d\n\n", compToss);
        printf("\033[0m");
        if (odd_or_even == 1) {
            if ((playerToss + compToss) % 2 == 0) {
                printf("\033[1;36m");
                printf("You lose the toss.\n");
                printf("\033[0m");
                choice = genRandom_HC(2);
                if (choice == 1) {
                    printf("\033[1;36m");
                    printf("Computer chose to bat first.\n");
                    printf("\033[0m");
                } else {
                    printf("\033[1;36m");
                    printf("Computer chose to bowl first.\n");
                    printf("\033[0m");
                }
            } else {
                printf("\033[1;36m");
                printf("You win the toss!\n");
                printf("\033[0m");              
                while (choice != 0 && choice != 1) {
                    printf("\033[1;36m");
                    printf("What would you like to do first, bat or bowl? (Select 0 to bat first and 1 to bowl first): ");
                    scanf("%d", &choice);
                    printf("\033[0m");
                    if (choice == 0) {
                        printf("\033[1;36m");
                        printf("\nYou chose to bat first.\n");
                        printf("\033[0m");
                    } else if (choice==1) {
                        printf("\033[1;36m");
                        printf("\nYou chose to bowl first.\n");
                        printf("\033[0m");
                    } else {
                        printf("\033[1;31m");
                        printf("INVALID INPUT, ENTER AGAIN.\n");
                        printf("\033[0m");
                    }
                }    
            }
        } else {
            if ((playerToss + compToss) % 2 != 0) {
                printf("\033[1;32m");
                printf("You lose the toss.\n");
                printf("\033[0m");
                choice = genRandom_HC(2);
                if (choice == 1) {
                    printf("\033[1;32m");
                    printf("\nComputer chose to bat first.\n");
                    printf("\033[0m");
                } else {
                    printf("\033[1;32m");
                    printf("\nComputer chose to bowl first.\n");
                    printf("\033[0m");
                }
            } else {
                printf("\033[1;32m");
                printf("You win the toss!\n");
                printf("\033[0m");
                while (choice != 0 && choice != 1) {
                    printf("\033[1;32m");
                    printf("What would you like to do first, bat or bowl? (Select 0 to bat first and 1 to bowl first): ");
                    scanf("%d", &choice);
                    printf("\033[0m");
                    if (choice == 0) {
                        printf("\033[1;32m");
                        printf("\nYou chose to bat first.\n");
                        printf("\033[0m");
                    } else if(choice==1) {
                        printf("\033[1;32m");
                        printf("\nYou chose to bowl first.\n");
                        printf("\033[0m");
                    } else {
                        printf("\033[1;31m");
                        printf("INVALID INPUT, ENTER AGAIN.\n");
                        printf("\033[0m");
                    }
                }
            }
        }
    } else {
        printf("\033[1;31m");
        printf("INVALID INPUT, ENTER AGAIN.\n");
        printf("\033[0m");
        toss_HC(odd_or_even, playerToss, compToss, choice);
    }
    return choice;
}

void comp_bat_first_HC(int playerMove, int compMove, int playerScore, int compScore)
{
    //computer batting first
    system("pause");
    system("cls");
    printf("\nFIRST INNINGS : \n\n");
    for (int game_start1 = 0; game_start1 > -1; game_start1++) {
        
        printf("\033[1;32m");
        printf("Your move (from 0 to 6 only) : ");
        scanf("%d", &playerMove);
        printf("\033[0m");

        int v = validity_check_HC(playerMove, 6);
        if (v == 1) {
            compMove = genRandom_HC(7);
            printf("\033[1;33m");
            printf("\nYour move : %d\nComputer's move : %d\n", playerMove, compMove);
            printf("\033[0m");

            if (playerMove == compMove) {
                printf("\033[1;33m");
                printf("\nOUT!\n");
                printf("\nTARGET FOR YOU : %d\n\n", compScore + 1);
                printf("\033[0m");
                break;
            }

            compScore += compMove;
            printf("\033[1;33m");
            printf("Computer's current score : %d\n\n", compScore);
            printf("\033[0m");

        } else {
            printf("\033[1;31m");
            printf("INVALID INPUT, ENTER AGAIN.\n");
            printf("\033[0m");
        }        
    }

    //player batting second
    system("pause");
    system("cls");
    printf("\nSECOND INNINGS : \n\n");
    for (int game_start2 = 0; game_start2 > -1; game_start2++) {
        
        printf("\033[1;32m");
        printf("Your move (from 0 to 6 only) : ");
        scanf("%d", &playerMove);
        printf("\033[0m");

        int v = validity_check_HC(playerMove, 6);
        if (v == 1) {
            compMove = genRandom_HC(7);
            printf("\033[1;33m");
            printf("\nYour move : %d\nComputer's move : %d\n", playerMove, compMove);
            printf("\033[0m");

            if (playerMove == compMove) {
                printf("\033[1;34m");
                printf("\nOUT!\n");
                if (playerScore == compScore) {
                    printf("IT'S A DRAW!\n\n");
                    printf("\033[0m");
                    break;
                } else {
                    printf("YOU LOST!\n\n");
                    printf("\033[0m");
                    break;
                }
                printf("\033[0m");
            }

            playerScore += playerMove;
            printf("\033[1;33m");
            printf("Your current score : %d\n\n", playerScore);
            printf("\033[0m");

            if (playerScore > compScore) {
                printf("YOU WON!\n\n");
                printf("\033[0m");
                break;
            }
        } else {
            printf("\033[1;31m");
            printf("INVALID INPUT, ENTER AGAIN.\n");
            printf("\033[0m");
        }        
    }
}

void player_bat_first_HC(int playerMove, int compMove, int playerScore, int compScore)
{
    //player batting first
    system("pause");
    system("cls");
    printf("\nFIRST INNINGS : \n\n");
    for (int game_start = 0; game_start > -1; game_start++) {
        printf("\033[1;32m");
        printf("Your move (from 0 to 6 only) : ");
        scanf("%d", &playerMove);
        printf("\033[0m");
        
        int v = validity_check_HC(playerMove, 6);
        if (v == 1) {
            compMove = genRandom_HC(7);
            printf("\033[1;33m");
            printf("\nYour move : %d\nComputer's move : %d\n", playerMove, compMove);
            printf("\033[0m");

            if (playerMove == compMove) {
                printf("\033[1;34m");
                printf("\nOUT!\n");
                printf("\nTARGET FOR COMPUTER : %d\n\n", playerScore + 1);
                printf("\033[0m");
                break;
            }

            playerScore += playerMove;
            printf("\033[1;33m");
            printf("Your current score : %d\n\n", playerScore);
            printf("\033[0m");

        } else {
            printf("\033[1;31m");
            printf("INVALID INPUT, ENTER AGAIN.\n");
            printf("\033[0m");
        }
    }

    //computer batting second
    system("pause");
    system("cls");
    printf("\nSECOND INNINGS : \n\n");
    for (int game_start = 0; game_start > -1; game_start++) {
        printf("\033[1;32m");
        printf("Your move (from 0 to 6 only) : ");
        scanf("%d", &playerMove);
        printf("\033[0m");

        int v = validity_check_HC(playerMove, 6);
        if (v == 1) {
            compMove = genRandom_HC(7);
            printf("\033[1;33m");
            printf("\nYour move : %d\nComputer's move : %d\n", playerMove, compMove);
            printf("\033[0m");

            if (playerMove == compMove) {
                printf("\033[1;34m");
                printf("\nOUT!\n");
                if (playerScore == compScore) {
                    printf("IT'S A DRAW!\n\n");
                    printf("\033[0m");
                    break;
                } else {
                    printf("YOU WON!\n\n");
                    printf("\033[0m");
                    break;
                }
                printf("\033[0m");
            }

            compScore += compMove;
            printf("\033[1;33m");
            printf("Computer's current score : %d\n\n", compScore);
            printf("\033[0m");
            
            if (compScore > playerScore) {
                printf("YOU LOST!\n\n");
                printf("\033[0m");
                break;
            }
        } else {
            printf("\033[1;31m");
            printf("INVALID INPUT, ENTER AGAIN.\n");
            printf("\033[0m");
        }        
    }
}

int HandCricketRules(){
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
    printf(" - In this game, you first have to choose whether you want to pick Odd or Even for the toss");
    for(int i=0;i<29;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   (analogous to Heads and Tails in cricket).");
    for(int i=0;i<75;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Then enter a number from 0 to 6 (say x).");
    for(int i=0;i<77;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The computer also randomly picks up a number (say y).");
    for(int i=0;i<64;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Now suppose (x + y) is even and you chose Even, then you win the toss. The same follows for the other cases.");
    for(int i=0;i<9;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Once the user/computer wins, they will choose whether to bat first or bowl first.");
    for(int i=0;i<36;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The player who is batting enters a number, and the opponent who is bowling also provides a number");
    for(int i=0;i<20;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   (both these numbers have to be from 0 to 6).");
    for(int i=0;i<73;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If these two numbers are not equal, the number entered by the batting player is added to his/her score.");
    for(int i=0;i<14;i++) printf(" ");
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
    printf(" - All the instruction will be provided during the game.");
    for(int i=0;i<64;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - To play just enter the number you want to choose.");
    for(int i=0;i<68;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<120;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");
    return 0;
}