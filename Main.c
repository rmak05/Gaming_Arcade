#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

#include "2048.c"
#include "BattleShip.c"
#include "Bingo.c"
#include "ChainReaction.c" 
#include "Connect4.c"
#include "ConnectDots.c"
#include "HandCricket.c"
#include "HuesAndCues.c"
#include "Minesweeper.c"
#include "RockPaperScissors.c"
#include "TicTacToe.c"

void MainMenu();
void call(int a);
void GameMenu(int r);
int TwoZeroFourEight();
int BattleShip();
int Bingo();
int ChainReaction();
int Connect4();
int ConnectDots();
int HandCricket();
int HuesAndCues();
int Minesweeper();
int RockPaperScissors();
int TicTacToe();

int Exit();

int main(){
    MainMenu();
    return 0;
}

void MainMenu()
{
    system("cls");
    printf("%c",201);                           //201-╔
    for(int i=0;i<60;i++) printf("%c",205);     //╔════════════════════════════════════════════════════════════╗
    printf("%c\n",187);                         //187-╗

    printf("%c",186);                           //186-║
    for(int i=0;i<15;i++) printf(" ");
    printf("%c",201);                           //201-╔
    for(int i=0;i<28;i++) printf("%c",196);     //║               ╔────────────────────────────╗               ║
    printf("%c",187);                           //187-╗
    for(int i=0;i<15;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<15;i++) printf("%c",176);     //176-░
    printf("%c",179);                           //179-│
    printf("  WELCOME TO GAMING ARCADE  ");     //║░░░░░░░░░░░░░░░│  WELCOME TO GAMING ARCADE  │░░░░░░░░░░░░░░░║
    printf("%c",179);
    for(int i=0;i<15;i++) printf("%c",176);
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<15;i++) printf(" ");
    printf("%c",200);                           //200-╚, 196- ─, 188-╝, 
    for(int i=0;i<28;i++) printf("%c",196);     //║               ╚────────────────────────────╝               ║
    printf("%c",188);
    for(int i=0;i<15;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");          //218-┌, 191-┐
    printf("%c",218);
    for(int i=0;i<12;i++) printf(" ");
    printf("%c",191);
    for(int i=0;i<23;i++) printf(" ");          //║                       ┌            ┐                       ║
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");
    printf("%c",179);                           //179-│
    printf(" MAIN  MENU ");
    printf("%c",179);
    for(int i=0;i<23;i++) printf(" ");          //║                       │ MAIN  MENU │                       ║
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");
    printf("%c",192);                           //192-└, 217-┘
    for(int i=0;i<12;i++) printf(" ");
    printf("%c",217);
    for(int i=0;i<23;i++) printf(" ");          //║                       └            ┘                       ║
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<60;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  1. 2048");
    for(int i=0;i<51;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  2. Battleship");
    for(int i=0;i<45;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  3. Bingo");
    for(int i=0;i<50;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  4. Chain Reaction");
    for(int i=0;i<41;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  5. Connect 4");
    for(int i=0;i<46;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  6. Connect Dots");
    for(int i=0;i<43;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  7. Hand Cricket");
    for(int i=0;i<43;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  8. Hues And Cues");
    for(int i=0;i<42;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf("  9. Minesweeper");
    for(int i=0;i<44;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 10. Rock Paper Scissors");
    for(int i=0;i<36;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 11. Tic Tac Toe");
    for(int i=0;i<44;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 12. EXIT");
    for(int i=0;i<51;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<60;i++) printf("%c",205);
    printf("%c\n",188);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    call(a);
}

void call(int a){
    switch(a){
        case 1 : TwoZeroFourEight();
        break;
        case 2 : BattleShip();
        break;
        case 3 : Bingo();
        break;
        case 4 : ChainReaction();
        break;
        case 5 : Connect4();
        break;
        case 6 : ConnectDots();
        break;
        case 7 : HandCricket();
        break;
        case 8 : HuesAndCues();
        break;
        case 9 : Minesweeper();
        break;
        case 10 : RockPaperScissors();
        break;
        case 11 : TicTacToe();
        break;
        case 12 : Exit();
        break;
    }
 }

int TwoZeroFourEight(){
    system("cls");
    GameMenu(1);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);

    system("cls");
    if(a==1) {
        play_2048(); 
        system("pause");
        TwoZeroFourEight();
    }
    else if(a==2) {
        TwoZeroFourEightRules();
        TwoZeroFourEight();
    }
    else MainMenu();
    return 0;
}

int BattleShip(){
    system("cls");
    GameMenu(2);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1){
        InitializeBoard_BS();    
        SetBoard_BS(1);
        SetBoard_BS(2);   
        PlayGame_BS();
        system("pause");
        BattleShip();
    }
    else if(a==2) {
        BattleShipRules();
        BattleShip();
    }
    else MainMenu();
    return 0;
}

int Bingo(){
    system("cls");
    GameMenu(3);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1) {
        play_bin();
        system("pause");
        Bingo();
    }
    else if(a==2){
        BingoRules();
        Bingo();
    }
    else MainMenu();
    return 0;
}

int ChainReaction(){
    system("cls");
    GameMenu(4);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1){
        InitializeBoard_CR();
        PlayGame_CR();
        system("pause");
        ChainReaction();
    }
    else if(a==2){
        ChainReactionRules();
        ChainReaction();
    }
    else MainMenu();
    return 0;
}

int Connect4(){
    system("cls");
    GameMenu(5);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1){
        game_start_c4();
        game_process_c4();  
        system("pause");
        Connect4();
     }
    else if(a==2){
        Connect4Rules();
        Connect4();
    }
    else MainMenu(); 
    return 0;
}


int ConnectDots(){
    system("cls");
    GameMenu(6);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1){
        initial_dot();
        out_dot();
        play_dot();
        system("pause");
        ConnectDots();
    }
    else if(a==2){
        ConnectDotsRules();
        ConnectDots();
    }
    else MainMenu();
    return 0;
}

int HandCricket(){
    system("cls");
    GameMenu(7);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1) {
        game_HC();
        system("pause");
        HandCricket();
    }
    else if(a==2){
        HandCricketRules();
        HandCricket();
    }
    else MainMenu();

    return 0;
}

int HuesAndCues(){
    system("cls");
    GameMenu(8);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1) {
        game_HCu();
        system("pause");
        HuesAndCues();
    }
    else if(a==2){
        HuesAndCuesRules();
        HuesAndCues();
    }
    else MainMenu();
}

int Minesweeper(){
    system("cls");
    GameMenu(9);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1){
        start_game_mines(); 
        system("pause");
        Minesweeper();
     }
    else if(a==2){
        MinesweeperRules();
        Minesweeper();
    }
    else MainMenu(); 
    return 0;
}

int RockPaperScissors(){
    system("cls");
    GameMenu(10);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1) {
        game_RPS();
        system("pause");
        RockPaperScissors();
    }
    else if(a==2){
        RockPaperScissorsRules();
        RockPaperScissors();
    }
    else MainMenu();

    return 0;
}

int TicTacToe(){
    system("cls");
    GameMenu(11);

    int a;
    printf("\nUser enter your choice : ");
    scanf("%d",&a);
    
    system("cls");
    if(a==1) {
        play_t();
        system("pause");
        TicTacToe();
    }
    else if(a==2){
        TicTacToeRules();
        TicTacToe();
    }
    else MainMenu();

    return 0;
}

int Exit(){

    system("cls");
        
    printf("%c",201);                           
    for(int i=0;i<60;i++) printf("%c",205);     
    printf("%c\n",187); 

    printf("%c",186);                           
    for(int i=0;i<15;i++) printf(" ");
    printf("%c",201);                           
    for(int i=0;i<28;i++) printf("%c",196);                   

    printf("%c",187);                           
    for(int i=0;i<15;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<15;i++) printf("%c",176);     
    printf("%c",179); 

    printf("    THANK YOU FOR PLAYING   "); 

    printf("%c",179);
    for(int i=0;i<15;i++) printf("%c",176);

    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<15;i++) printf(" ");

    printf("%c",200);                           
    for(int i=0;i<28;i++) printf("%c",196);                              

    printf("%c",188);
    for(int i=0;i<15;i++) printf(" ");

    printf("%c\n",186);
    printf("%c",186);

    for(int i=0;i<22;i++) printf(" ");         
    printf("%c",218);
    for(int i=0;i<13;i++) printf(" ");
    printf("%c",191);
    for(int i=0;i<23;i++) printf(" ");          
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<22;i++) printf(" ");
    printf("%c",179);                          
    printf("   CREDITS   ");
    printf("%c",179);
    for(int i=0;i<23;i++) printf(" ");          
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<22;i++) printf(" ");
    printf("%c",192);                          
    for(int i=0;i<13;i++) printf(" ");
    printf("%c",217);
    for(int i=0;i<23;i++) printf(" ");         
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<60;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 1. RAVILISETTY MAKARANDH");
    for(int i=0;i<35;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 2. SUPRIT NAIK");
    for(int i=0;i<45;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 3. OM PRAKASH BEHERA");
    for(int i=0;i<39;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 4. HARSH MAURYA");
    for(int i=0;i<44;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<60;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<60;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");
    system("cls");
    return 0;
}

void GameMenu(int r){
    printf("%c",201);                           
    for(int i=0;i<60;i++) printf("%c",205);     
    printf("%c\n",187);                         

    printf("%c",186);                           
    if(r!=10) for(int i=0;i<15;i++) printf(" ");
    else for(int i=0;i<12;i++) printf(" ");
    printf("%c",201);                           
    if(r!=10) for(int i=0;i<28;i++) printf("%c",196);                   
    else for(int i=0;i<34;i++) printf("%c",196);
    printf("%c",187);                           
    if(r!=10) for(int i=0;i<15;i++) printf(" ");
    else for(int i=0;i<12;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    if(r!=10) for(int i=0;i<15;i++) printf("%c",176);     
    else for(int i=0;i<12;i++) printf("%c",176);
    printf("%c",179);   

    if(r==1)  printf("       WELCOME TO 2048      "); 
    if(r==2)  printf("    WELCOME TO BATTLESHIP   ");
    if(r==3)  printf("       WELCOME TO BINGO     ");
    if(r==4)  printf("  WELCOME TO CHAIN REACTION ");
    if(r==5)  printf("    WELCOME TO CONNECT 4    ");
    if(r==6)  printf("   WELCOME TO CONNECT DOTS  ");
    if(r==7)  printf("   WELCOME TO HAND CRICKET  ");
    if(r==8)  printf("  WELCOME TO HUES AND CUES  ");
    if(r==9)  printf("   WELCOME TO MINESWEEPER   ");
    if(r==10) printf("  WELCOME TO ROCK PAPER SCISSORS  ");
    if(r==11) printf("   WELCOME TO TIC TAC TOE   ");    

    printf("%c",179);
    if(r!=10) for(int i=0;i<15;i++) printf("%c",176);
    else for(int i=0;i<12;i++) printf("%c",176);
    printf("%c\n",186);

    printf("%c",186);
    if(r!=10) for(int i=0;i<15;i++) printf(" ");
    else for(int i=0;i<12;i++) printf(" ");
    printf("%c",200);                           
    if(r!=10) for(int i=0;i<28;i++) printf("%c",196);                              
    else for(int i=0;i<34;i++) printf("%c",196);
    printf("%c",188);
    if(r!=10) for(int i=0;i<15;i++) printf(" ");
    else for(int i=0;i<12;i++) printf(" ");
    
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");         
    printf("%c",218);
    for(int i=0;i<12;i++) printf(" ");
    printf("%c",191);
    for(int i=0;i<23;i++) printf(" ");          
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");
    printf("%c",179);                          
    printf(" GAME  MENU ");
    printf("%c",179);
    for(int i=0;i<23;i++) printf(" ");          
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<23;i++) printf(" ");
    printf("%c",192);                          
    for(int i=0;i<12;i++) printf(" ");
    printf("%c",217);
    for(int i=0;i<23;i++) printf(" ");         
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<60;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 1. Play Game");
    for(int i=0;i<47;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 2. Rules");
    for(int i=0;i<51;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    printf(" 3. Back to Main Menu");
    for(int i=0;i<39;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);
    for(int i=0;i<60;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<60;i++) printf("%c",205);
    printf("%c\n",188);
    
}