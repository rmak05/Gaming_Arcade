#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char b_t[3][3];
const char PLAYER_t='X';
const char COMPUTER_t='O';

void resentb_t();
void printb_t();
int checkFreeSpaces_t();
char ConvertToUpperCase_t(char c);
void PLAYER_tMove_t();
void COMPUTER_tMove_t();
char checkWinner_t();
void printWinner_t(char);
void play_t();
int TicTacToeRules();

// int main(){
//     play_t();
// }

void resentb_t(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) b_t[i][j]=' ';
    }
}

void printb_t(){

    printf("\033[1;32m");
    printf("     A   B   C \n\n");
    printf("\033[0m");

    for(int i=0;i<5;i++){
        if(i%2==0){
            printf("\033[1;34m %d  \033[0m",(i/2)+1);
            for(int j=0;j<11;j++){
                if(j==3 || j==7) printf("|");
                if(j==0 || j==4 || j==8){
                    if(b_t[i/2][j/4]=='X'){
                        printf("\033[1;31m");
                        printf(" %c ",b_t[i/2][j/4]);
                        printf("\033[0m");
                    }
                    else if(b_t[i/2][j/4]=='O'){
                        printf("\033[0;33m");
                        printf(" %c ",b_t[i/2][j/4]);
                        printf("\033[0m");
                    }
                    else printf(" %c ",b_t[i/2][j/4]);
                }
            }
            printf("\n");
        }
        else{
            for(int j=0;j<15;j++){
                if(j<4) printf(" ");
                else if(j==7 || j==11) printf("|");
                else printf("-");
            }
            printf("\n");
        }
        
    }



    printf("\n\n");
}

int checkFreeSpaces_t(){
    int freeSpaces=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) if(b_t[i][j]==' ') freeSpaces++;
    }
    return freeSpaces;
}

char ConvertToUpperCase_t(char c){
    if(c>='A' && c<='Z') return c;
    else return c-32;
}

void PLAYER_tMove_t(){
    int x,y;
    char h[2];
    printf("Enter the coordinate of tile : ");
    scanf("%s",&h);
    h[0]=ConvertToUpperCase_t(h[0]);
    y=h[0]-65;
    x=h[1]-49;
    if(b_t[x][y]!=' ') {
        printf("invalid move!\n");
        system("pause");
        system("cls");
        printb_t();
        PLAYER_tMove_t();
    }
    else {
        b_t[x][y]=PLAYER_t;
    }
    
}

void COMPUTER_tMove_t(){
    srand(time(NULL));
    int x,y;
     if(checkFreeSpaces_t()>0){
         if(b_t[0][0]==b_t[0][1] && b_t[0][0]=='X' && b_t[0][2]==' ') {x=0;y=2;}
    else if(b_t[0][1]==b_t[0][2] && b_t[0][1]=='X' && b_t[0][0]==' ') {x=0;y=0;}
    else if(b_t[0][0]==b_t[0][2] && b_t[0][0]=='X' && b_t[0][1]==' ') {x=0;y=1;}

    else if(b_t[1][1]==b_t[1][2] && b_t[1][1]=='X' && b_t[1][0]==' ') {x=1;y=0;}
    else if(b_t[1][0]==b_t[1][2] && b_t[1][0]=='X' && b_t[1][1]==' ') {x=1;y=1;}
    else if(b_t[1][0]==b_t[1][1] && b_t[1][0]=='X' && b_t[1][2]==' ') {x=1;y=2;}

    else if(b_t[2][1]==b_t[2][2] && b_t[2][2]=='X' && b_t[2][0]==' ') {x=2;y=0;}
    else if(b_t[2][0]==b_t[2][2] && b_t[2][0]=='X' && b_t[2][1]==' ') {x=2;y=1;}
    else if(b_t[2][0]==b_t[2][1] && b_t[2][0]=='X' && b_t[2][2]==' ') {x=2;y=2;}

    else if(b_t[0][0]==b_t[1][0] && b_t[0][0]=='X' && b_t[2][0]==' ') {x=2;y=0;}
    else if(b_t[0][0]==b_t[2][0] && b_t[0][0]=='X' && b_t[1][0]==' ') {x=1;y=0;}
    else if(b_t[1][0]==b_t[2][0] && b_t[1][0]=='X' && b_t[0][0]==' ') {x=0;y=0;}

    else if(b_t[1][1]==b_t[0][1] && b_t[0][1]=='X' && b_t[2][1]==' ') {x=2;y=1;}
    else if(b_t[1][1]==b_t[2][1] && b_t[1][1]=='X' && b_t[0][1]==' ') {x=0;y=1;}
    else if(b_t[0][1]==b_t[2][1] && b_t[0][1]=='X' && b_t[1][1]==' ') {x=1;y=1;}

    else if(b_t[2][2]==b_t[1][2] && b_t[2][2]=='X' && b_t[0][2]==' ') {x=0;y=2;}
    else if(b_t[2][2]==b_t[0][2] && b_t[2][2]=='X' && b_t[1][2]==' ') {x=1;y=2;}
    else if(b_t[1][2]==b_t[0][2] && b_t[0][2]=='X' && b_t[2][2]==' ') {x=2;y=2;}

    else if(b_t[0][0]==b_t[1][1] && b_t[0][0]=='X' && b_t[2][2]==' ') {x=2;y=2;}
    else if(b_t[2][2]==b_t[0][0] && b_t[0][0]=='X' && b_t[1][1]==' ') {x=1;y=1;}
    else if(b_t[1][1]==b_t[2][2] && b_t[1][1]=='X' && b_t[0][0]==' ') {x=0;y=0;}

    else if(b_t[0][2]==b_t[1][1] && b_t[0][2]=='X' && b_t[2][0]==' ') {x=2;y=0;}
    else if(b_t[2][0]==b_t[1][1] && b_t[2][0]=='X' && b_t[0][2]==' ') {x=0;y=2;}
    else if(b_t[2][0]==b_t[0][2] && b_t[0][2]=='X' && b_t[1][1]==' ') {x=1;y=1;}
    
    else {
         do{
            x=rand()%3;
            y=rand()%3;
            }while(b_t[x][y]!=' ');
    }
    b_t[x][y]=COMPUTER_t;
    }
    else printWinner_t(' ');
}

char checkWinner_t(){
    for(int i = 0; i < 3; i++){
      if(b_t[i][0] == b_t[i][1] && b_t[i][0] == b_t[i][2]) return b_t[i][0];
       }

    for(int i = 0; i < 3; i++){
      if(b_t[0][i] == b_t[1][i] && b_t[0][i] == b_t[2][i]) return b_t[0][i];
       }

    if(b_t[0][0] == b_t[1][1] && b_t[0][0] == b_t[2][2]) return b_t[0][0];
   
    if(b_t[0][2] == b_t[1][1] && b_t[0][2] == b_t[2][0]) return b_t[0][2];

    return ' ';
}

void printWinner_t(char winner){
    if(winner==PLAYER_t) printf("YOU WIN!\n");
    else if(winner==COMPUTER_t) printf("YOU LOSE!\n");
    else if(winner==' ') printf("IT'S A TIE\n");
}

void play_t(){
        system("cls");
        char winner=' ';
        char response=' ';

        resentb_t();

        while(1){
            system("cls");
            printb_t();
            PLAYER_tMove_t();
            winner=checkWinner_t();
            if(winner!=' ' || checkFreeSpaces_t()==0) break;
            COMPUTER_tMove_t();
            winner=checkWinner_t();
            if(winner!=' ' || checkFreeSpaces_t()==0) break;
        }

        system("cls");
        printb_t();
        printWinner_t(winner);
}

int TicTacToeRules(){
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
    printf(" - Tic Tac Toe board consists of a 3x3 grid.");
    for(int i=0;i<76;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - Players take turns placing their marks ('X' or 'O') on an empty square."); 
    for(int i=0;i<46;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The first player to get three of their marks in a row, horizontally, vertically, or diagonally, wins the game.");
    for(int i=0;i<7;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If all 9 squares are filled and above given condition is not satisfied, the game is a tie.");
    for(int i=0;i<27;i++) printf(" ");
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
    printf(" - You must enter the coordinates of the tile on which he/she wishes to make his/her move.");
    for(int i=0;i<30;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - For example, if you want to choose the tile containing second row and third column, then you must enter \"C2\" or \"c2\".");
    for(int i=0;i<0;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<120;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");
}