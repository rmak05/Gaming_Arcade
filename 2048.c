#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int arr2048[4][4];
int game_over_2048=0;                //0 for continuation 1 for lose 2 for win
int score_2048=0;
int terminate_2048=0;

#define ARROW_UP_2048 72
#define ARROW_DOWN_2048 80
#define ARROW_LEFT_2048 75
#define ARROW_RIGHT_2048 77

void board_2048(int rows,int columns);
int shiftleft_2048();
void rotatearray_2048(int a);
void game_2048_init();
int win_2048_check();
int game2048_by_arrowkeys();
int game_2048_lost();
void play_2048();
int TwoZeroFourEightRules();


// int main(){   
//     play_2048();       
// }

//---------------------------------function starts-------------------------

void board_2048(int rows,int columns){
    system("cls");
    printf("    ");
    // for(int i=48;i<48+columns;i++) printf("  %c     ",i);
    printf("\033[1m");
    printf("\033[1;31m");
    printf("SCORE : %d \n",score_2048);
    printf("\033[0m");
    printf("\033[1m");
    printf("\n   %c",218);
    for(int i=0;i<columns-1;i++) printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,194);
    printf("%c%c%c%c%c%c%c\n",196,196,196,196,196,196,191);
    for(int i=0;i<rows;i++){
        printf("   %c",179);
        for(int j=0;j<columns;j++){
            if(arr2048[i][j]==2){
                printf("\033[1;33m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==4){
                printf("\033[1;36m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==8){
                printf("\033[1;31m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==16){
                printf("\033[1;32m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==32){
                printf("\033[1;34m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==64){
                printf("\033[1;35m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==128){
                printf("\033[1;33m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==256){
                printf("\033[1;36m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==512){
                printf("\033[1;31m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==1024){
                printf("\033[1;32m");
                printf(" %4d ",arr2048[i][j]);
            }else if(arr2048[i][j]==2048){
                printf("\033[1;34m");
                printf(" %4d ",arr2048[i][j]);
            }
            else printf("      ");
            printf("\033[0m");
            printf("\033[1m");
            printf("%c",179);
        }
        if(i!=rows-1){
            printf("\n   %c",195);
            for(int i=0;i<columns-1;i++) printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,197);
            printf("%c%c%c%c%c%c%c\n",196,196,196,196,196,196,180);
        }else{
            printf("\n   %c",192);
            for(int i=0;i<columns-1;i++) printf("%c%c%c%c%c%c%c",196,196,196,196,196,196,193);
            printf("%c%c%c%c%c%c%c\n",196,196,196,196,196,196,217);
        }
    }
    printf("\033[0m");
}

int shiftleft_2048(){
    int i, j, k;
    int checkmove=0;
    for (i = 0; i < 4; i++) {
        k = 0;
        for (j = 1; j < 4; j++) {
            if (arr2048[i][j] != 0) {
                if (arr2048[i][k] == 0) {
                    arr2048[i][k] = arr2048[i][j];
                    arr2048[i][j] = 0;
                    checkmove=1;
                } else if (arr2048[i][k] == arr2048[i][j]) {
                    arr2048[i][k] *= 2;
                    printf("%d",arr2048[i][k]);
                    score_2048+=(arr2048[i][k]);
                    arr2048[i][j] = 0;
                    k++;
                    checkmove=1;
                } else {
                    k++;
                    arr2048[i][k] = arr2048[i][j];
                    if (j != k) {
                        arr2048[i][j] = 0;
                        checkmove=1;
                    }                    
                }
            }
        }
    }
    int check=0;
    int count=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr2048[i][j]==0) count++;
        }
    }
    if(checkmove==1){
        srand(time(NULL));
        while(check!=1){        
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    if(arr2048[i][j]==0){
                        if(check!=1){
                            int q=rand()%count;
                            int num_random=rand()%10;
                            if(q==0){
                                if (num_random==0) arr2048[i][j]=4;
                                else arr2048[i][j]=2;
                                check=1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void rotatearray_2048(int a){
    // step 1: transpose the array
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            int temp = arr2048[i][j];
            arr2048[i][j] = arr2048[j][i];
            arr2048[j][i] = temp;
        }
    }
    // step 2: reverse each row ->for a=0 counterclockwise
    if(a==0){
        for (int i = 0; i < 4; i++) {
            int start = 0;
            int end = 4 - 1;
            while (start < end) {
                int temp = arr2048[i][start];
                arr2048[i][start] = arr2048[i][end];
                arr2048[i][end] = temp;
                start++;
                end--;
            }
        }
    }
    // step 2: reverse each column ->for a =1 clockwise
    if(a==1){
        for (int i = 0; i < 4; i++) {
            int start = 0;
            int end = 4 - 1;
            while (start < end) {
                int temp = arr2048[start][i];
                arr2048[start][i] = arr2048[end][i];
                arr2048[end][i] = temp;
                start++;
                end--;
            }
        }
    }
}

void game_2048_init(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr2048[i][j]=0;
        }
    }
    srand(time(NULL));
    for(int a=0;a<2;a++){
        int check=0;
        while(check!=1){
            int first_index=rand()%4;
            int second_index=rand()%4;
            int num_random=rand()%10;
            if(arr2048[first_index][second_index]==0){
                if (num_random==0) arr2048[first_index][second_index]=4;
                else arr2048[first_index][second_index]=2;
                check=1;
            }
        }
    }
}


int win_2048_check(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr2048[i][j]==2048){
                printf("You won the 2048 game.");
                return 1;
            }
        }
    }
}

int game_2048_lost(){
    int bol=1;
    for(int rotation=0;rotation<4;rotation++){
        for(int i=0;i<4;i++){
            for(int j=1;j<4;j++){
                if((arr2048[i][j]==arr2048[i][j-1])||(arr2048[i][j]==0)){
                    bol=0;
                }
            }
        }
        rotatearray_2048(0);
    }
    return bol;
}

void game2048_by_wasd(){
    char choice='a';
    while(choice!='e'){
        printf("Choose the direction : ");
        choice=getchar();
        char y;
        y=getchar();
        if(choice=='a'){            //shift to left
            shiftleft_2048();
            board_2048(4,4);
        }
        if(choice=='s'){
            rotatearray_2048(0);     //rotate counterclockwise
            shiftleft_2048();
            rotatearray_2048(1);        //rotate clockwise
            board_2048(4,4);
        }
        if(choice=='w'){
            rotatearray_2048(1);     //rotate clockwise
            shiftleft_2048();
            rotatearray_2048(0);        //rotate counterclockwise
            board_2048(4,4);
        }
        if(choice=='d'){
            rotatearray_2048(1);     //rotate clockwise
            rotatearray_2048(1);        //rotate clockwise
            shiftleft_2048();
            rotatearray_2048(0);        //rotate counterclockwise
            rotatearray_2048(0);     //rotate counterclockwise
            board_2048(4,4);
        }
    }
}

int game2048_by_arrowkeys(){
    int key = _getch();
    if(key=='E' || key=='e') terminate_2048=1;
    switch (key){
        case ARROW_UP_2048:
            rotatearray_2048(1);        //rotate clockwise
            shiftleft_2048();
            rotatearray_2048(0);        //rotate counterclockwise
            board_2048(4,4);
            break;
        case ARROW_DOWN_2048:
            rotatearray_2048(0);         //rotate counterclockwise
            shiftleft_2048();
            rotatearray_2048(1);         //rotate clockwise
            board_2048(4,4);
            break;
        case ARROW_LEFT_2048:
            shiftleft_2048();           //shift to left
            board_2048(4,4);
            break;
        case ARROW_RIGHT_2048:
            rotatearray_2048(1);        //rotate clockwise
            rotatearray_2048(1);        //rotate clockwise
            shiftleft_2048();
            rotatearray_2048(0);        //rotate counterclockwise
            rotatearray_2048(0);        //rotate counterclockwise
            board_2048(4,4);
            break;
        case 'x':
            exit(0);
    }
}

void play_2048(){
    game_2048_init();
    board_2048(4,4);         
    while(game_over_2048==0 && terminate_2048==0){
        game2048_by_arrowkeys();
        if(win_2048_check()==1) game_over_2048=2;
        if(game_2048_lost()==1){
            game_over_2048=1;
            printf("You lost the game.");
        }
    } 
    game_over_2048=0;
    score_2048=0;
    terminate_2048=0;
}

int TwoZeroFourEightRules(){
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
    printf(" - This is a single player game.");
    for(int i=0;i<88;i++) printf(" ");
    printf("%c\n",186); 
    
    printf("%c",186);  
    printf(" - This game is played on a 4x4 grid of tiles.");
    for(int i=0;i<74;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - On your turn, you can move all of the tiles in a row or column in the direction of your choice.");
    for(int i=0;i<22;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - If two tiles with the same value touch (while sliding), they merge into a single tile with the value of the sum"); 
    for(int i=0;i<6;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   of the two tiles.");
    for(int i=0;i<100;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - A new tile with a value of 2 or 4 will randomly appear in an empty space on the grid after each move.");
    for(int i=0;i<16;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game ends when you can no longer make any moves.");
    for(int i=0;i<65;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - The goal of the game is to reach a tile with a value of 2048.");
    for(int i=0;i<56;i++) printf(" ");
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
    printf(" - Enter Page Up to slide up.");
    for(int i=0;i<91;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - Enter Page Down to slide down.");
    for(int i=0;i<87;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Enter Page Left to slide left.");
    for(int i=0;i<87;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Enter Page Right to slide right.");
    for(int i=0;i<85;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Press \"E\" or\"e\" to exit the game.");
    for(int i=0;i<84;i++) printf(" ");
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