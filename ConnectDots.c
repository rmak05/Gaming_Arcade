#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char b_dot[11][11][3];
int p1_score_dot=0;
int p2_score_dot=0;
int br_dot=0;

void initial_dot();
char ConvertToUpperCase_dot(char c);
void input_dot(int r);
void out_dot();
void printSelectedBoard_dot(int i, int j);
int freeSpaces_dot();
void marking_dot(int r);
void count_dot(int r);
int checkWinner_dot();
void winner_dot(int r);
void play_dot();
int ConnectDotsRules();

// int main(){
//     initial_dot();
//     out_dot();
//     play_dot();
//     return 0;
// }

void initial_dot(){    //initial updating the board
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            if(i%2==0 && j%2==0) b_dot[i][j][0]=249; // dot
            else b_dot[i][j][0]=' ';

            b_dot[i][j][1]=' ';
            b_dot[i][j][2]=' ';
        }
    }
}

char ConvertToUpperCase_dot(char c){
    if(c>='A' && c<='Z') return c;
    else return c-32;
}

void input_dot(int r){
    int a,b,x;     // for taking the input from user where to draw line
    char d[2];

    // printf("enter the row number: ");
    // scanf("%d",&a); a=2*a-2;
    // printf("enter the starting point: ");
    // scanf("%d",&b);  b=2*b-1; 

    printf("Enter the dot coordinate: ");
    scanf("%s",&d);
    if( (d[0]=='E' || d[0]=='e') && (d[1]=='x' || d[1]=='X')){
        br_dot=1;

    }
    else{
    d[0]=ConvertToUpperCase_dot(d[0]);

    a=2*(d[1]-48)-2;
    b=2*(d[0]-64)-1;
    

    printf("Enter the direction 1(right) 2(down): ");
    scanf("%d",&x);

    
        if(x==1 && b_dot[a][b][0]==' ') {
            b_dot[a][b][0]=196;
            b_dot[a][b][r]=196;
        }
        else if(x==2 && a!=18 && b_dot[a+1][b-1][0]==' '){
            b_dot[a+1][b-1][0]=179;
            b_dot[a+1][b-1][r]=179;
        }
        else {
            printf("Invalid Input!!\n");
            system("pause");
            system("cls");
            out_dot();
            if(r==1) printf("\nPLAYER 1:\n");
            else printf("\nPLAYER 2:\n");
            input_dot(r);
        }
    
    }
}

void out_dot(){
    system("cls");
    
    printf("\033[1;31m");
    printf("    A   B   C   D   E   F\n\n");
    printf("\033[0m");

    for(int i=0;i<11;i++){
        if(i%2==0){

            printf("\033[1;32m");
            printf("%d  ",(i/2)+1);
            printf("\033[0m");

            for(int j=0;j<11;j++){
                if(j%2==0) printf(" %c",b_dot[i][j][0]);
                else{
                    printSelectedBoard_dot(i,j);
                }
            }
            printf("\n");
        }
        else{
            printf("   ");
            for(int j=0;j<11;j++){
                printSelectedBoard_dot(i,j);
            }
            printf("\n");
        }

    }
    count_dot(1); count_dot(2);
    printf("\nP1 SCORE : %d\n",p1_score_dot);
    printf("P2 SCORE : %d\n",p2_score_dot);
    printf("SPACES LEFT : %d\n",freeSpaces_dot());
}

void printSelectedBoard_dot(int i, int j){

    if(b_dot[i][j][1]!=' ') {
        printf("\033[1;33m");
        printf(" %c",b_dot[i][j][1]);
        printf("\033[0m");
    }

    if(b_dot[i][j][2]!=' '){
        printf("\033[1;34m");
        printf(" %c",b_dot[i][j][2]);
        printf("\033[0m");
    }

    if(b_dot[i][j][1]==' ' && b_dot[i][j][2]==' '){
        printf(" %c",b_dot[i][j][0]);
    }
}

int freeSpaces_dot(){
    int r=0;   // this keeps count of places where player can move
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i%2==0 && j%2==1 && b_dot[i][j][0]==' ') r++;
            if(i%2==1 && j%2==0 && b_dot[i][j][0]==' ') r++;
        }
    }
    return r;
}

void marking_dot(int r){  // this is supposed to update 1 or 2 in board
    char a=179,b=196;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if( (b_dot[i][j-1][0]==a) && (b_dot[i][j+1][0]==a) && (b_dot[i-1][j][0]==b) && (b_dot[i+1][j][0]==b) && (b_dot[i][j][0]==' ') ){
                if(r==1){
                    b_dot[i][j][0]=49; 
                    b_dot[i][j][1]=49;
                }
                else {
                    b_dot[i][j][0]=50; 
                    b_dot[i][j][2]=50;
                }
            }
        }
    }
}

void count_dot(int r){
    int k=0;  // for updating the score of players
    char a;
    if(r==1) a=49;
    else a=50;

    for(int i=1;i<10;i+=2){
        for(int j=1;j<10;j+=2){
            if(b_dot[i][j][0]==a) k++;
        }
    }

    if(r==1) p1_score_dot=k;
    else p2_score_dot=k;
}

int checkWinner_dot(){
    if(p1_score_dot>12) return 1;
    if(p2_score_dot>12) return 2;
    return 0;
}

void winner_dot(int r){
    if(r==1){
        printf("\033[1;33m");
        printf("WINNER IS PLAYER 1!!\n");
        printf("\033[0m");
    }
    else if(r==2){
        printf("\033[1;34m");
        printf("WINNER IS PLAYER 2!!\n");
        printf("\033[0m");
    }
}

void play_dot(){
    int s=0,z=0;
    while(freeSpaces_dot!=0 && s!=1 && br_dot==0){
        while(1 && br_dot==0){
        
            system("cls");
            out_dot();
            printf("PLAYER1 :\n");
            input_dot(1);
            int a=p1_score_dot;
            
            marking_dot(1);
           
            system("cls");
            //count_dot(1);
            out_dot();
            int x = checkWinner_dot();
            if( x==1 || x==2){
                winner_dot(x);
                s=1;
                z=1;
                break;
            }
            if(a==p1_score_dot) break;
        
        }
        while(z==0 && br_dot==0){
            system("cls");
            out_dot();
            printf("PLAYER2 :\n");
            input_dot(2);
            int b=p2_score_dot;
            
            marking_dot(2);
            
            system("cls");
           // count_dot(2);
            out_dot();
            int x = checkWinner_dot();
            if( x==1 || x==2 ){
                winner_dot(x);
                s=1;
                break;
            }
            if(b==p2_score_dot) break;
        }   
    }
    br_dot=0;
}

int ConnectDotsRules(){

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
    printf(" - This is a two player game, say A and B.");
    for(int i=0;i<78;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - A board of 36 dots arranged onto a 6x6 square is provided .");
    for(int i=0;i<58;i++) printf(" ");
    printf("%c\n",186);


    printf("%c",186);  
    printf(" - Each player takes turns, starting from A, to draw a line either vertically or horizontally joining two adjacent");
    for(int i=0;i<6;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   dots on the board.");
    for(int i=0;i<99;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Each player tries to complete a 1x1 square by joining these lines.");
    for(int i=0;i<51;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The player who played the last move before a square is made gets the square and a point is awarded to him.");
    for(int i=0;i<11;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game ends when either all the points are exhausted or when a player reaches certain score which the");
    for(int i=0;i<14;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   other player can reach.");
    for(int i=0;i<94;i++) printf(" ");
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
    printf(" - You must then enter the direction of the line (either right or down).");
    for(int i=0;i<48;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Press \"EX\" or \"Ex\" or\"eX\" or\"ex\" to exit the game.");
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