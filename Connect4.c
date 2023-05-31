#include<stdio.h>
#include <stdlib.h>

char pc4_1[25]="player-1";    //player 1 of connect 4
char pc4_2[25]="player-2";    //player 2 of connect 4
int bdc4[8][8];     //board of connect 4
int rowc4[8];
int start_c4;
int end_c4;
int br_c4=0;

void board_c4(int rows,int columns);
int inputc4(int player);
int checkwinnerc4(char symbol);
void game_start_c4();
void game_process_c4();
void rotatearray_c4(int a);
int Connect4Rules();

// int main(){
//     game_start_c4();
//     game_process_c4();        
// }

void board_c4(int rows,int columns){
    printf("    ");
    printf("\033[1m");
    printf("\033[1;31m");
    for(int i=49;i<49+columns;i++) printf(" %c  ",i);
    printf("\033[0m");
    printf("\033[1m");
    printf("\n   %c",218);
    for(int i=0;i<columns-1;i++) printf("%c%c%c%c",196,196,196,194);
    printf("%c%c%c%c\n",196,196,196,191);
    for(int i=0;i<rows;i++){
        printf("   %c",179);
        for(int j=0;j<columns;j++){
            if(bdc4[i][j]=='O'){
                printf("\033[1;36m");
                printf(" O ");
            }
            else if(bdc4[i][j]=='X'){
                printf("\033[1;33m");
                printf(" O ");
            }else{
                printf(" %c ",bdc4[i][j]);
            }
            printf("\033[0m");
            printf("\033[1m");
            printf("%c",179);
        }
        if(i!=rows-1){
            printf("\n   %c",195);
            for(int i=0;i<columns-1;i++) printf("%c%c%c%c",196,196,196,197);
            printf("%c%c%c%c\n",196,196,196,180);
        }else{
            printf("\n   %c",192);
            for(int i=0;i<columns-1;i++) printf("%c%c%c%c",196,196,196,193);
            printf("%c%c%c%c\n",196,196,196,217);
        }
    }
}

int inputc4(int player){    
    printf("Which column do you choose : ");
    int columnc4;
    scanf("%d",&columnc4);
    if(columnc4==-1){
        br_c4=1;
    }
    else if(columnc4<1||columnc4>8) return 0;
    else{
        if(player==1){
            if((rowc4[columnc4-1])<0) return 0;
            bdc4[rowc4[columnc4-1]][columnc4-1]='X';
            rowc4[columnc4-1]-=1;
            return 1;
        }else{
            if((rowc4[columnc4-1])<0) return 0;
            bdc4[rowc4[columnc4-1]][columnc4-1]='O';
            rowc4[columnc4-1]-=1;
            return 1;
        }
    }    
}

int checkwinnerc4(char symbol){
    int count=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(bdc4[i][j]==symbol) count++;
            else count=0;
            if(count==4){
                start_c4=i;
                end_c4=j;
                return 1;
            }
        }
        count=0;
    }
    count=0;
    for(int j=0;j<8;j++){
        for(int i=0;i<8;i++){
            if(bdc4[i][j]==symbol) count++;
            else count=0;
            if(count==4) return 2;
        }
        count=0;
    }
    count=0;
    for(int k=0;k<15;k++){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(i+j==k){
                    if(bdc4[i][j]==symbol)count++;
                    else count=0;
                    if(count==4) return 3;
                }
            }
        }
        count=0;
    }
    count=0;
    rotatearray_c4(0);
    for(int k=0;k<15;k++){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(i+j==k){
                    if(bdc4[i][j]==symbol)count++;
                    else count=0;
                    if(count==4){
                        rotatearray_c4(1);
                        return 4;
                    }
                }
            }
        }
        count=0;
    }
    rotatearray_c4(1); 
    return 0;
}

void rotatearray_c4(int a){
    // step 1: transpose the array
    for (int i = 0; i < 8; i++) {
        for (int j = i; j < 8; j++) {
            int temp = bdc4[i][j];
            bdc4[i][j] = bdc4[j][i];
            bdc4[j][i] = temp;
        }
    }
    // step 2: reverse each row ->for a=0 counterclockwise
    if(a==0){
        for (int i = 0; i < 8; i++) {
            int start = 0;
            int end = 8 - 1;
            while (start < end) {
                int temp = bdc4[i][start];
                bdc4[i][start] = bdc4[i][end];
                bdc4[i][end] = temp;
                start++;
                end--;
            }
        }
    }
    // step 2: reverse each column ->for a =1 clockwise
    if(a==1){
        for (int i = 0; i < 8; i++) {
            int start = 0;
            int end = 8 - 1;
            while (start < end) {
                int temp = bdc4[start][i];
                bdc4[start][i] = bdc4[end][i];
                bdc4[end][i] = temp;
                start++;
                end--;
            }
        }
    }
}

void game_start_c4(){
 //   printf("----------------------Welcome to connect-4 game-------------------------------\n\n");
 //   printf("------------------------------------------------------------------------------\n\n");

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            bdc4[i][j]=' ';                 //filling the board with empty variables
        }
    }
    for(int i=0;i<8;i++){
        rowc4[i]=7;                         //initialisation of row variables to 7
    }
    // bdc4[7][7]='x';    
}

void game_process_c4(){
    int z=0;        //variable to check which player chance;
    while(1 && br_c4==0){
        int count=0; 
        for(int x=0;x<8;x++){
            if(rowc4[x]<0) count++;
        } 
        if(count==8){
            printf("Game over , it's a Tie\n");
            break;
        }
        if(z%2==0){
            board_c4(8,8);
            printf("%s chance :-\n",pc4_1);
            if(inputc4(1)==0){
                printf("Invalid value Try again\n");
                system("pause");
                system("cls");
                continue;
            }
            else if(br_c4!=1){
                if(checkwinnerc4('X')==1 || checkwinnerc4('X')==2 || checkwinnerc4('X')==3 || checkwinnerc4('X')==4){
                    system("cls");
                    board_c4(8,8);
                    printf("%s won the game\n",pc4_1);
                    break;
                }
                // system("pause");
                system("cls");
                z++;
            }
        }else{
            board_c4(8,8);
            printf("%s chance :-\n",pc4_2);
            if(inputc4(2)==0){
                printf("Invalid value Try again\n");
                system("pause");
                system("cls");
            }
            else if(br_c4!=1){
                if(checkwinnerc4('O')==1 || checkwinnerc4('O')==2 || checkwinnerc4('O')==3 || checkwinnerc4('O')==4){
                    system("cls");
                    board_c4(8,8);
                    printf("%s won the game\n",pc4_2);
                    break;
                }
                //system("pause");
                system("cls");
                z++;
            }
        } 
        
    }
    br_c4=0;
}

int Connect4Rules(){
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
    printf(" - This is a two player game.");
    for(int i=0;i<91;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - This game consists of 8x8 grid.");
    for(int i=0;i<86;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game is played in turns.");
    for(int i=0;i<89;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Imagine the board to be placed vertically with gravity acting downwards.");
    for(int i=0;i<45;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - Any token when put in a column will fall to the bottom.");
    for(int i=0;i<62;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The goal is to make a row, column or a diagonal of four tokens.");
    for(int i=0;i<54;i++) printf(" ");
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
    printf(" - To choose a column, just enter the column number.");
    for(int i=0;i<68;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - Press \"-1\" to exit the game.");
    for(int i=0;i<89;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186); 
    for(int i=0;i<120;i++) printf(" "); 
    printf("%c\n",186);

    printf("%c",200);
    for(int i=0;i<120;i++) printf("%c",205);
    printf("%c\n",188);

    system("pause");
}

