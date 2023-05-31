#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int arr1_bin[5][5];
int arr2_bin[5][5];
int check_arr_bin[25];
int check_arr1_bin[25];
int p1_bin=0;
int p2_bin=0;
int br_bin=0;

void inintialize_bin();
void starting_bin();
void input_arena_bin(int a,int arr[a][a],int r); //to input int array
int validityCheck_bin(int a);
void o_bin(int a,int arr[a][a],int r);
void output_arena_bin(int a,int arr[a][a],int r);// to output the array
void player_move_bin(int r); // for taking input a number and cut in both the array
int  checkWinner_bin(); // for finding the winner
void printWinner_bin(int a);// to print the winner and tie
void play_bin();
void BingoRules();

// int main(){
//     printf("  WELCOME TO THE BINGO\n\n");
//     play_bin();
//     return 0;
// }

void inintialize_bin(){
    for(int i=0;i<25;i++) {
        check_arr_bin[i]=i+1;
        check_arr1_bin[i]=i+1;
    }

}

void starting_bin(){
    for(int i=0;i<25;i++){
        for(int j=0;j<25;j++){
            arr1_bin[i][j]=0;
            arr2_bin[i][j]=0;
        }
    }
}

void input_arena_bin(int a,int arr[a][a],int k){
    o_bin(a,arr,k);
    int r,i=0,j=0;
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++) {
           // getchar();

        while(i<5){
            printf("Enter value for %c%d : ",j+65,i+1);
            scanf("%d",&r);
            if(r==-1) {
                br_bin=-1;
                break;
            }
            if(validityCheck_bin(r)==1){
                arr[i][j++]=r; 
                system("cls");
                if(k==1) printf("Enter for player1:\n\n");
                if(k==2) printf("Enter for player2:\n\n"); 
                o_bin(a,arr,k);
                if(j==5) i++;
                if(j==5) j=0;
            }
            else{
                printf("Invalid Input!!\n");
                system("pause");
                system("cls");
                if(k==1) printf("Enter for player1:\n\n");
                if(k==2) printf("Enter for player2:\n\n"); 
                o_bin(a,arr,k);
            }
            
        }


 //       }
//     }
 }

int validityCheck_bin(int a){
        int r=0;
        for(int i=0;i<25;i++){
            if(check_arr_bin[i]==-1) r++;
        }
        if(r==25) inintialize_bin();
        if(a<=0 || a>25 || check_arr_bin[a-1]==-1) return 0;
        else{
            check_arr_bin[a-1]=-1;
            return 1;
        }
    
}

void o_bin(int a, int arr[a][a],int r){

    int i,j;
    printf("\033[1;32m");
    printf("   %2c   %2c   %2c   %2c   %2c  \n",'A','B','C','D','E');
    printf("\033[0m");
    for(i=0;i<13;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<26;j++)
            {
                if(j==0 && i==0) printf("  %c",218);
                else if(j==0 && i==12) printf("  %c",192);
                else if(j==0) printf("  %c",195);
                else if(j==25 && i==0) printf("%c",191);
                else if(j==25 && i==12) printf("%c",217);
                else if(j==25) printf("%c",180);
                else if(j%5==0 && i==0) printf("%c",194);
                else if(j%5==0 && i==12) printf("%c",193);
                else if(j%5==0) printf("%c",197);
                else printf("%c",196);
            }
        }
        else 
        {    
            if(i==1){
                   for(int j=0;j<11;j++){
                    if(j%2==0) printf("  %c",179);
                    else{
                                printf("\033[1;30m");
                       if(j==1) printf("%2c",'B');
                       if(j==3) printf("%2c",'I');
                       if(j==5) printf("%2c",'N');
                       if(j==7) printf("%2c",'G');
                       if(j==9) printf("%2c",'O');
                                printf("\033[0m");
                    }
                   }
                }
            for(int j=0;j<11;j++){
                
                if(i!=1){
                     if(j%2==1) printf("%2d ",arr[(i-3)/2][j/2]);
                    // else if(j%2==1 && arr[(i-3)/2][j/2]==0){
                        // printf("\033[1;31m");
                        // printf("%2d ",arr[(i-3)/2][j/2]);
                        // printf("\033[0m");
                    // }
                    else if(j==0){
                        printf("\033[1;32m");
                        printf("%d",(i-3)/2 + 1);
                        printf("\033[0m");
                        printf(" %c ",179);
                       // printf("%d %c ",(i-3)/2 + 1,179);
                    }
                    else printf("%c ",179);
                }
            }
        }
        printf("\n");
    }
}

void output_arena_bin(int a,int arr[a][a],int r){

    int i,j;
    checkWinner_bin();

    for(i=0;i<13;i++)
    {
        if(i%2==0)
        {
            for(j=0;j<26;j++)
            {
                if(j==0 && i==0) printf("%c",218);
                else if(j==0 && i==12) printf("%c",192);
                else if(j==0) printf("%c",195);
                else if(j==25 && i==0) printf("%c",191);
                else if(j==25 && i==12) printf("%c",217);
                else if(j==25) printf("%c",180);
                else if(j%5==0 && i==0) printf("%c",194);
                else if(j%5==0 && i==12) printf("%c",193);
                else if(j%5==0) printf("%c",197);
                else printf("%c",196);
            }
        }
        else 
        {    
            if(i==1){
                   // printf("%c %2c %c %2c %c %2c %c %2c %c %2c %c",179,'B',179,'I',179,'N',179,'G',179,'O',179);
                   for(int j=0;j<11;j++){
                    if(j%2==0) printf("%c ",179);
                    else{
                       if(j==1){
                            if( (r==1 && (p1_bin-1) >=0) ){
                                printf("\033[1;34m");
                                printf("%2c ",'B');
                                printf("\033[0m");
                            }
                            else if((r==2 && (p2_bin-1) >=0)){
                                printf("\033[1;35m");
                                printf("%2c ",'B');
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;30m");
                                printf("%2c ",'B');
                                printf("\033[0m");
                            }
                    
                       }
                       if(j==3){
                            if( (r==1 && (p1_bin-2) >=0) ){
                                printf("\033[1;34m");
                                printf("%2c ",'I');
                                printf("\033[0m");
                            }
                            else if((r==2 && (p2_bin-2) >=0)){
                                printf("\033[1;35m");
                                printf("%2c ",'I');
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;30m");
                                printf("%2c ",'I');
                                printf("\033[0m");
                            }
                       }
                       if(j==5){
                            if( (r==1 && (p1_bin-3) >=0) ){
                                printf("\033[1;34m");
                                printf("%2c ",'N');
                                printf("\033[0m");
                            }
                            else if((r==2 && (p2_bin-3) >=0)){
                                printf("\033[1;35m");
                                printf("%2c ",'N');
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;30m");
                                printf("%2c ",'N');
                                printf("\033[0m");
                            }
                       }
                       if(j==7){
                            if( (r==1 && (p1_bin-4) >=0) ){
                                printf("\033[1;34m");
                                printf("%2c ",'G');
                                printf("\033[0m");
                            }
                            else if((r==2 && (p2_bin-4) >=0)){
                                printf("\033[1;35m");
                                printf("%2c ",'G');
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;30m");
                                printf("%2c ",'G');
                                printf("\033[0m");
                            }
                       }
                       if(j==9){
                            if( (r==1 && (p1_bin-5) >=0)  ){
                                printf("\033[1;34m");
                                printf("%2c ",'O');
                                printf("\033[0m");
                            }
                            else if((r==2 && (p2_bin-5) >=0)){
                                printf("\033[1;35m");
                                printf("%2c ",'O');
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;30m");
                                printf("%2c ",'O');
                                printf("\033[0m");
                            }
                       }
                                
                    }
                   }
                }
            for(int j=0;j<11;j++){
                
                if(i!=1){
                    if(j%2==1 && arr[(i-3)/2][j/2]!=0) printf("%2d ",arr[(i-3)/2][j/2]);
                    else if(j%2==1 && arr[(i-3)/2][j/2]==0){
                        printf("\033[1;31m");
                        printf("%2d ",arr[(i-3)/2][j/2]);
                        printf("\033[0m");
                    }
                    else printf("%c ",179);
                }
            }
        }
        printf("\n");
    }
}

void player_move_bin(int k){
    int r;
   // static int k=0; 
    printf("Enter a number: ");
    scanf("%d",&r);
    if(r==-1){
        br_bin=-1;
    }
    else if( r<26 && r>0 && check_arr1_bin[r-1]==r){
        check_arr1_bin[r-1]=-1;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(arr1_bin[i][j]==r) arr1_bin[i][j]=0;
                if(arr2_bin[i][j]==r) arr2_bin[i][j]=0;
            }
        }
    }
    else{
        printf("Invalid Input!\n");
        system("pause");
        system("cls");
        if(k==1){
            printf("Player 1\n\n");
            output_arena_bin(5,arr1_bin,1);
        }
        else{
            printf("Player 2\n\n");
            output_arena_bin(5,arr2_bin,2);
        }
        player_move_bin(k);

    }
    

    /*k++;
    if(k%2==1) output_arena_bin(5,arr1_bin[5][5]);
    else output_arena_bin(5,arr2_bin[5][5]);*/

}

int checkWinner_bin(){
    int c=0,d=0;
        for(int i=0;i<5;i++){
            int a=0,b=0,f=0,e=0;
        for(int j=0;j<5;j++){
            if(arr1_bin[i][j]==0) a++; // for checking in rows
            if(arr2_bin[i][j]==0) b++;

            if(arr1_bin[j][i]==0) e++; // for checking in columns
            if(arr2_bin[j][i]==0) f++;
        }
        if(a==5) c++;
        if(e==5) c++;
        if(b==5) d++;
        if(f==5) d++;
    }
        int i=0,j=0,a=0,b=0,e=0,f=0;
        while(i<5 && j<5){
            if(arr1_bin[i][j]==0) a++;    // for checking in diagonals
            if(arr2_bin[i][j]==0) b++;
            if(arr1_bin[i][4-j]==0) e++;
            if(arr2_bin[i][4-j]==0) f++;
            i++; j++;
        }
        if(a==5) c++;
        if(e==5) c++;
        if(b==5) d++;
        if(f==5) d++;

        p1_bin=c;
        p2_bin=d;

        if(c>=5 && d<5) return 1;
        else if(c<5 && d>=5) return 2;
        else if(c>=5 && d>=5) return 3;
        else return 0;
}

void printWinner_bin(int a){
    if(a==1){
        system("cls");
        printf("Player1 Grid\n");
        output_arena_bin(5,arr1_bin,1);
        printf("Player1 is WINNER!\n");
    }
    else if(a==2) {
        system("cls");
        printf("Player2 Grid\n");
        output_arena_bin(5,arr2_bin,2);
        printf("Player2 is WINNER!\n");
    }
    else {
        system("cls");
        printf("Player1 Grid\n");
        output_arena_bin(5,arr1_bin,1);
        printf("Player2 Grid\n");
        output_arena_bin(5,arr2_bin,2);
        printf("It's a Tie!\n");
    }
}

void play_bin(){
    if(br_bin==0){
    inintialize_bin();
    starting_bin();
    printf("Enter for player1:\n\n");
    input_arena_bin(5,arr1_bin,1);
    system("cls");
    }
    if(br_bin==0){
    printf("PLAYER1 GRID\n\n");
    output_arena_bin(5,arr1_bin,1);
    system("pause");
    system("cls");
    }
    if(br_bin==0){
    printf("Enter for player2:\n\n");
    input_arena_bin(5,arr2_bin,2);
    system("cls");
    }
    if(br_bin==0){
    printf("PLAYER2 GRID\n\n");
    output_arena_bin(5,arr2_bin,2);
    system("pause");
    system("cls");
    }

    while(1 && br_bin==0){    // 0 is base case
        if(br_bin==0){
        printf("Player 1\n\n");
        output_arena_bin(5,arr1_bin,1);
        player_move_bin(1);
        system("cls");
        }
        if(br_bin==0){
        printf("Player 1\n\n");
        output_arena_bin(5,arr1_bin,1);
        int r=checkWinner_bin();
        if(r==1 || r==2 || r==3) { // 1 for player1.... 2 for player2.... 3 for tie
            printWinner_bin(r);
            break;
        }
        
        system("pause");
        system("cls");
        }
        if(br_bin==0){
        printf("Player 2\n\n");
        output_arena_bin(5,arr2_bin,2);
        player_move_bin(2);
        system("cls");
        }
        if(br_bin==0){
        printf("Player 2\n\n");
        output_arena_bin(5,arr2_bin,2);
        int s=checkWinner_bin();
        if(s==1 || s==2 || s==3) {
            printWinner_bin(s);
            break;
        }
        
        system("pause");
        system("cls");
        }
    }
    br_bin=0;
}

void BingoRules(){
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
    printf(" - Each player gets a 5x5 square board and has to fill it with integers from 1 to 25.");
    for(int i=0;i<35;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The first player takes his chance and calls out a number of his choice.");
    for(int i=0;i<46;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - This number is crossed out by both the players.");
    for(int i=0;i<70;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Then the second player calls out another number, and both the players cross it out.");
    for(int i=0;i<34;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Whenever a player strikes out an entire row, column or main diagonal, a letter of BINGO gets highlighted.");
    for(int i=0;i<12;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - When the entire BINGO gets highlighted, the player wins.");
    for(int i=0;i<61;i++) printf(" ");
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
    printf(" - You must enter a value (1 to 25, non repetitive) in each tile to set the board.");
    for(int i=0;i<38;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - When it's your turn, you must enter the number that you want to strike out.");
    for(int i=0;i<42;i++) printf(" ");
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