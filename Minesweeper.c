#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FLAG_LOGO 'F'

char msarr[10][10];
char msarr_input[10][10];
char cor_mines[2];
int game_over_mines=0;
int bomb_no_mines=0;
int br_mines=0;

void board_mines_check(int rows,int columns);
void board_mines(int rows,int columns);
void init_mines();
void init_mines_input();
void bombs_placement_mines();
void input_mines();
char ConvertToUpperCase_mines(char c);
void open_board_mines(int start,int end);
void check_win_mines();
void start_game_mines();
int MinesweeperRules();

// int main(){
//     start_game_mines();
// }

void board_mines(int rows,int columns){
    printf("\033[1m");
    printf("\033[1;31m");
    printf("No. of Flags (%c) left : %d\n\n",FLAG_LOGO,bomb_no_mines);
    printf("\033[0m");
    printf("\033[1m");
    printf("    ");    
    printf("\033[1;36m");
    for(int i=48;i<48+columns;i++) printf(" %c  ",i);
    printf("\033[0m");
    printf("\033[1m");
    printf("\n   %c",218);
    for(int i=0;i<columns-1;i++) printf("%c%c%c%c",196,196,196,194);
    printf("%c%c%c%c\n",196,196,196,191);
    for(int i=0;i<rows;i++){
        printf("\033[1;36m");
        printf(" %c ",65+i);
        printf("\033[0m");
        printf("\033[1m");   
        printf("%c",179);     
        for(int j=0;j<columns;j++){
            printf("\033[1;32m");
            if(msarr_input[i][j]==49) printf("\033[1;36m");
            if(msarr_input[i][j]==50) printf("\033[1;33m");
            if(msarr_input[i][j]==51) printf("\033[1;35m");
            if(msarr_input[i][j]==52) printf("\033[1;32m");
            if(msarr_input[i][j]==53) printf("\033[1;34m");
            if(msarr_input[i][j]==54) printf("\033[1;36m");
            if(msarr_input[i][j]==55) printf("\033[1;33m");
            if(msarr_input[i][j]==56) printf("\033[1;35m");
            if(msarr_input[i][j]==FLAG_LOGO) printf("\033[1;31m");
            if(msarr_input[i][j]==-24) printf("\033[1;30m");
            printf(" %c ",msarr_input[i][j]);
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
void board_mines_check(int rows,int columns){
    printf("    ");
    for(int i=48;i<48+columns;i++) printf(" %c  ",i);
    printf("\n   %c",218);
    for(int i=0;i<columns-1;i++) printf("%c%c%c%c",196,196,196,194);
    printf("%c%c%c%c\n",196,196,196,191);
    for(int i=0;i<rows;i++){
        printf(" %c %c",65+i,179);
        for(int j=0;j<columns;j++) printf(" %c %c",msarr[i][j],179);
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

void init_mines(){
    srand(time(NULL)); 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            msarr[i][j]=' ';          //filling the board with empty variables
        }
    }   
    while(bomb_no_mines<12){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){                
                int q=rand();
                if(q%8==0 && bomb_no_mines<12 && msarr[i][j]==' '){
                    msarr[i][j]=-24;
                    bomb_no_mines++;
                }
            }
        }
    }
}

void init_mines_input(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            msarr_input[i][j]=178;                //filling the board with empty variables
        }
    }
}

void bombs_placement_mines(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(msarr[i][j]!=-24) {
                int count=0;
                if((i>0&&i<9)&&(j>0&&j<9)){
                    if(msarr[i-1][j-1]==-24) count++;
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i-1][j+1]==-24) count++;
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                    if(msarr[i+1][j-1]==-24) count++;
                    if(msarr[i+1][j]==-24) count++;
                    if(msarr[i+1][j+1]==-24) count++;
                }else if((i==0)&&(j>0&&j<9)){
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                    if(msarr[i+1][j-1]==-24) count++;
                    if(msarr[i+1][j]==-24) count++;
                    if(msarr[i+1][j+1]==-24) count++;
                }else if((i==9)&&(j>0&&j<9)){
                    if(msarr[i-1][j-1]==-24) count++;
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i-1][j+1]==-24) count++;
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                }else if((j==9)&&(i>0&&i<9)){
                    if(msarr[i-1][j-1]==-24) count++;
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i+1][j-1]==-24) count++;
                    if(msarr[i+1][j]==-24) count++;
                }else if((j==0)&&(i>0&&i<9)){
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i-1][j+1]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                    if(msarr[i+1][j]==-24) count++;
                    if(msarr[i+1][j+1]==-24) count++;
                }else if((i==0)&&(j==0)){
                    if(msarr[i+1][j]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                    if(msarr[i+1][j+1]==-24) count++;
                }else if((i==0)&&(j==9)){
                    if(msarr[i+1][j]==-24) count++;
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i+1][j-1]==-24) count++;
                }else if((i==9)&&(j==0)){
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i][j+1]==-24) count++;
                    if(msarr[i-1][j+1]==-24) count++;
                }else if((i==9)&&(j==9)){
                    if(msarr[i-1][j]==-24) count++;
                    if(msarr[i][j-1]==-24) count++;
                    if(msarr[i-1][j-1]==-24) count++;
                }
                msarr[i][j]=count+48;
                if(msarr[i][j]==48) msarr[i][j]=' ';
            }
        }
    }
}

int count_arr_mines(int arr_no){
    if(arr_no==0){
        int count=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(msarr[i][j]>=49&&msarr[i][j]<=57){
                    count++;
                }
            }
        }
        return count;
    }
    if(arr_no==1){
        int count=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(msarr_input[i][j]>=49&&msarr_input[i][j]<=57){
                    count++;
                }
            }
        }
        return count;
    }
}

void start_game_mines(){
    system("cls");
    init_mines();
    init_mines_input();
    bombs_placement_mines();    
   // board_mines_check(10,10);    
    board_mines(10,10);
    while(game_over_mines==0 && br_mines==0) {
        input_mines();
        check_win_mines();
    }
    game_over_mines=0;
    bomb_no_mines=0;
    br_mines=0;
}

void input_mines(){
    int start,end;
    char dig_or_flag='a';
    printf("Enter the co-ordinates : ");    
    scanf("%s",cor_mines);
    if( (cor_mines[0]=='E'|| cor_mines[0]=='e') && (cor_mines[1]=='X' || cor_mines[1]=='x') ){
        br_mines=1;
    }
    else{
    getchar();
    while((((cor_mines[0]<48)||(cor_mines[0]>57 && cor_mines[0]<65)||(cor_mines[0]>74 && cor_mines[0]<97)||(cor_mines[0]>106))||((cor_mines[1]<48)||(cor_mines[1]>57 && cor_mines[1]<65)||(cor_mines[1]>74 && cor_mines[1]<97)||(cor_mines[1]>106)))){
        system("cls");
        board_mines(10,10);
        printf("invalid choice try again \n");
        printf("Enter the co-ordinates : ");    
        scanf("%s",cor_mines);
        getchar();
    }
    if(cor_mines[0]>64){
        start=ConvertToUpperCase_mines(cor_mines[0])-65;
        end=cor_mines[1]-48;
        if(msarr_input[start][end]==FLAG_LOGO){
            printf("Do you want to remove the "); 
            printf("\033[1;31m");
            printf("Flag %c (F) ",FLAG_LOGO);
            printf("\033[0m");
            printf("\033[1m");
            printf("or ");
            printf("leave it (E) : ");
            scanf("%c",&dig_or_flag);
            if(dig_or_flag=='E' || dig_or_flag=='e') return;
        }
        if (msarr_input[start][end]!=-78 && msarr_input[start][end]!=FLAG_LOGO){
            printf("invalid choice try again1 \n");
            return;
        }
        while(dig_or_flag!='d' && dig_or_flag!='D' && dig_or_flag!='f' & dig_or_flag!='F' && msarr_input[start][end]!=FLAG_LOGO){
            printf("Enter "); 
            printf("\033[1;31m");
            printf("Flag %c (F) ",FLAG_LOGO);
            printf("\033[0m");
            printf("\033[1m");
            printf("or ");
            printf("\033[1;30m");
            printf("Dig %c (D) ",31);
            printf("\033[0m");
            printf("\033[1m");
            printf(": ");
            scanf("%c",&dig_or_flag);
        }
        if(dig_or_flag=='d' || dig_or_flag=='D') open_board_mines(start,end);
        if(dig_or_flag=='f' || dig_or_flag=='F') {
            if(bomb_no_mines<=0){
                printf("You don't have any more flags.\n");
                return;
            }
            if(msarr_input[start][end]==FLAG_LOGO){
                msarr_input[start][end]=-78;
                bomb_no_mines++;
            }
            else{
                msarr_input[start][end]=FLAG_LOGO;
                bomb_no_mines--;
            }
            system("cls");
            board_mines(10,10);
        }
    } //printf("%d %d\n",ConvertToUpperCase_mines(cor_mines[0])-64,cor_mines[1]-48);
    else{ 
        start=ConvertToUpperCase_mines(cor_mines[1])-65;
        end=cor_mines[0]-48;
        if(msarr_input[start][end]==FLAG_LOGO){
            printf("Do you want to remove the "); 
            printf("\033[1;31m");
            printf("Flag %c (F) ",FLAG_LOGO);
            printf("\033[0m");
            printf("\033[1m");
            printf("or ");
            printf("leave it (E) : ");
            scanf("%c",&dig_or_flag);
            if(dig_or_flag=='E' || dig_or_flag=='e') return;
        }
        if (msarr_input[start][end]!=-78 && msarr_input[start][end]!=FLAG_LOGO){
            printf("invalid choice try again \n");
            return;
        }
        while(dig_or_flag!='d' && dig_or_flag!='D' && dig_or_flag!='f' & dig_or_flag!='F' && msarr_input[start][end]!=FLAG_LOGO){
            printf("Enter "); 
            printf("\033[1;31m");
            printf("Flag %c (F) ",FLAG_LOGO);
            printf("\033[0m");
            printf("\033[1m");
            printf("or ");
            printf("\033[1;30m");
            printf("Dig %c (D) ",31);
            printf("\033[0m");
            printf("\033[1m");
            printf(": ");
            scanf("%c",&dig_or_flag);
        }
        if(dig_or_flag=='d' || dig_or_flag=='D') open_board_mines(start,end);
        if(dig_or_flag=='f' || dig_or_flag=='F') {
            if(bomb_no_mines<=0){
                printf("You don't have any more flags.\n");
                return;
            }
            if(msarr_input[start][end]==FLAG_LOGO){
                msarr_input[start][end]=-78;
                bomb_no_mines++;
            }
            else{
                msarr_input[start][end]=FLAG_LOGO;
                bomb_no_mines--;
            }
            system("cls");
            board_mines(10,10);
        }
    } //printf("%d %d\n",ConvertToUpperCase_mines(cor_mines[1])-64,cor_mines[0]-48);
    }
}

char ConvertToUpperCase_mines(char c){
    if(c>='A' && c<='Z') return c;
    else return c-32;
}
 
void open_board_mines(int start,int end){
   // printf("%d",msarr_input[start][end]);
    if((start>=0&&start<=9)&&(end>=0&&end<=9)&&(msarr_input[start][end]==-78)){        
        if(msarr[start][end]>=49&&msarr[start][end]<=57){
            msarr_input[start][end]=msarr[start][end];
        }
        else if(msarr[start][end]==' '){
            msarr_input[start][end]=' ';
            sleep(0.5);
            system("cls");
            board_mines(10,10);
            open_board_mines(start-1,end-1);
            open_board_mines(start-1,end);
            open_board_mines(start-1,end+1);
            open_board_mines(start,end-1);
            open_board_mines(start,end+1);
            open_board_mines(start+1,end-1);
            open_board_mines(start+1,end);
            open_board_mines(start+1,end+1);
        }
        else if(msarr[start][end]==-24){
            game_over_mines=1;
            msarr_input[start][end]=-24;
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    if(msarr[i][j]==-24){
                        msarr_input[i][j]=-24;
                        sleep(1);
                        system("cls");
                        board_mines(10,10);
                    }
                }
            }
            printf("You Lost The Game\n");
            return;
        }
        sleep(0.5);
        system("cls");
        board_mines(10,10);
    }else{
        return;
    }
}

void check_win_mines(){
   // printf("%d %d",count_arr_mines(0),count_arr_mines(1));
    if(count_arr_mines(0)==count_arr_mines(1)){
        system("cls");
        board_mines(10,10);
        printf("                 You win.\n");
        game_over_mines=1;
    }
}

int MinesweeperRules(){
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
    printf(" - This game consists of 10x10 grid.");
    for(int i=0;i<84;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The grid is initially covered with tiles.");
    for(int i=0;i<76;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Some of these tiles conceal hidden mines beneath them.");
    for(int i=0;i<63;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The goal of the game is to uncover all the tiles that do not contain mines, without detonating any of the mines. ");
    for(int i=0;i<4;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game is won when all non-mine tiles are revealed.");
    for(int i=0;i<64;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If the selected tile contains a mine, you lose the game.");
    for(int i=0;i<61;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - When a tile is selected, it will reveal a number, indicating how many mines are present in its adjacent tiles.");
    for(int i=0;i<7;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - For example, if a tile displays the number \"3\", it means that there are three mines in the surrounding eight tiles.");
    for(int i=0;i<2;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - If a tile does not have any adjacent mines, it will automatically uncover all its neighbouring tiles until it");
    for(int i=0;i<8;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   reaches tiles with adjacent mines.");
    for(int i=0;i<83;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - To help identify potential mine locations, you can place flags on tiles that you suspect contain mines.");
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
    printf(" - You must enter the coordinates of the tile on which he/she wishes to make his/her move.");
    for(int i=0;i<30;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - For example, if you want to choose the tile containing second row and third column, then you must enter");
    for(int i=0;i<14;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf("   \"B2\" or \"b2\" or \"2B\" or \"2b\".");
    for(int i=0;i<88;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Enter \"F\" or \"f\" to place a flag.");
    for(int i=0;i<84;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Enter \"D\" or \"d\" to dig.");
    for(int i=0;i<93;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - To remove the flag choose the tile again.");
    for(int i=0;i<76;i++) printf(" ");
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