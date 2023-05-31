#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Print_CR(int n,int s);
void PrintBoard_CR();
void InitializeBoard_CR();
void Split_CR(int a,int b,int s);
int SplitCheck_CR(int a,int b);
void PlayGame_CR();
char ConvertToUpperCase_CR(char c);
int SplitAvailability_CR();
int ValidityCheck_CR(int a,int b,int s);
int VictoryCheck_CR(int s);
int ChainReactionRules();

int Board_CR[11][7][3];
char Coordinates_CR[2];

// int main()
// {
//    InitializeBoard_CR();
//    PlayGame_CR();

//     return 0;
// }

int VictoryCheck_CR(int s)
{
    int i,j,count1=0,count2=0;
    
    for(i=1;i<=6;i++)
        for(j=1;j<=10;j++)
        {
            if( Board_CR[j][i][2]==1 ) count1++;
            if( Board_CR[j][i][2]==2 ) count2++;
        }
        
    if(s==1 && count2==0 && count1>1) return 1;
    else if(s==2 && count1==0 && count2>1) return 1;
    else return 0;
}

int ValidityCheck_CR(int a,int b,int s)
{
    if( (Board_CR[b][a][2]==0 || Board_CR[b][a][2]==s) && (1<=a && a<=6 && 1<=b && b<=10) ) return 1;
    else return 0;
}

int SplitAvailability_CR()
{
    int i,j;
    
    for(i=1;i<=6;i++)
        for(j=1;j<=10;j++)
        {
            if( SplitCheck_CR(i,j) == 1 ) return 1;
        }
        
    return 0;
}

char ConvertToUpperCase_CR(char c)
{
    if(c>='A' && c<='Z') return c;
    else return c-32;
}

void PlayGame_CR()
{
    int a,b,k,m,i,j;
    int z=0,u=0;
    char x;

    while(z==0)
    {
        while(z==0)
        {
            system("cls");
            PrintBoard_CR();
            printf("\nPlayer Red , enter the tile coordinates : ");
            scanf("%s",Coordinates_CR);

            if(ConvertToUpperCase_CR(Coordinates_CR[0])=='E' && ConvertToUpperCase_CR(Coordinates_CR[1])=='X') 
            {
                z=1;
                break;
            }

            x=Coordinates_CR[0];
            x=ConvertToUpperCase_CR(x);
            b=Coordinates_CR[1]-48;
            a=x-64;
            if( ValidityCheck_CR(a,b,1)==0 )
            {
                printf("Invalid coordinates , please enter again\n");
                system("pause");
                system("cls");
                continue;
            }  
            Board_CR[b][a][1]++;
            Board_CR[b][a][2]=1;
            

            while( SplitAvailability_CR() == 1)
            {
                system("cls");
                for(i=1;i<=6;i++)
                    for(j=1;j<=10;j++)
                    {
                        if( SplitCheck_CR(i,j)==1 && z==0) 
                        {
                            system("cls");
                            Split_CR(i,j,1);
                            PrintBoard_CR();
                            if( VictoryCheck_CR(1)==1 )
                            {
                                system("cls");
                                PrintBoard_CR();
                                printf("\033[1;31m");
                                printf("\nPlayer Red has won !\n\n");
                                printf("\033[0m");
                                z=1;
                            }
                            sleep(1);
                        }    
                    }
                if(z==1) break;
            }
            break;
        }
        
        while(z==0)
        {
            system("cls");
            PrintBoard_CR();
            printf("\nPlayer Green , enter the tile coordinates : ");
            scanf("%s",Coordinates_CR);

            if(ConvertToUpperCase_CR(Coordinates_CR[0])=='E' && ConvertToUpperCase_CR(Coordinates_CR[1])=='X') 
            {
                z=1;
                break;
            }

            x=Coordinates_CR[0];
            x=ConvertToUpperCase_CR(x);
            b=Coordinates_CR[1]-48;
            a=x-64;
            
            if( ValidityCheck_CR(a,b,2)==0 )
            {
                printf("Invalid coordinates , please enter again\n");
                system("pause");
                system("cls");
                continue;
            }
            Board_CR[b][a][1]++;
            Board_CR[b][a][2]=2;
            while( SplitAvailability_CR() == 1)
            {
                system("cls");
                for(i=1;i<=6;i++)
                    for(j=1;j<=10;j++)
                    {
                        if( SplitCheck_CR(i,j)==1 && z==0) 
                        {
                            system("cls");
                            Split_CR(i,j,2);
                            PrintBoard_CR();
                            if( VictoryCheck_CR(2)==1 )
                            {
                                system("cls");
                                PrintBoard_CR();
                                printf("\033[1;32m");
                                printf("\nPlayer Green has won !\n\n");
                                printf("\033[0m");
                                z=1;
                            }
                            sleep(1);
                        }    
                    }
                if(z==1) break;
            }
            break;
        }
    }
}

int SplitCheck_CR(int a,int b)
{
    if( ((a==1)||(a==6)) && ((b==1)||(b==10)) )
    {
        if( Board_CR[b][a][1]>=2 ) return 1;
    }
    else if(a==1 || a==6 || b==1 || b==10)
    {
        if( Board_CR[b][a][1]>=3 ) return 1;
    }
    else 
    {
        if( Board_CR[b][a][1]>=4 ) return 1;
    }
    
    return 0;
}

void Split_CR(int a,int b,int s)
{
    if( ((a==1)||(a==6)) && ((b==1)||(b==10)) )
    {
        if(a==1)
        {
            Board_CR[b][a][1]-=2;
            Board_CR[b][a+1][1]++;
            Board_CR[b][a+1][2]=s;
            if(b==1) 
            {
                Board_CR[b+1][a][1]++;
                Board_CR[b+1][a][2]=s;
            }    
            else
            {
                Board_CR[b-1][a][1]++;
                Board_CR[b-1][a][2]=s;
            }
        }
        else if(a==6)
        {
            Board_CR[b][a][1]-=2;
            Board_CR[b][a-1][1]++;
            Board_CR[b][a-1][2]=s;
            if(b==1) 
            {
                Board_CR[b+1][a][1]++;
                Board_CR[b+1][a][2]=s;
            }
            else 
            {
                Board_CR[b-1][a][1]++;
                Board_CR[b-1][a][2]=s;
            }    
        }
    }
    else if(a==1 || a==6 || b==1 || b==10)
    {
        if(a==1)
        {
            Board_CR[b][a][1]-=3;
            Board_CR[b][a+1][1]++;
            Board_CR[b-1][a][1]++;
            Board_CR[b+1][a][1]++;
            Board_CR[b][a+1][2]=s;
            Board_CR[b-1][a][2]=s;
            Board_CR[b+1][a][2]=s;
        }
        else if(a==6)
        {
            Board_CR[b][a][1]-=3;
            Board_CR[b][a-1][1]++;
            Board_CR[b-1][a][1]++;
            Board_CR[b+1][a][1]++;
            Board_CR[b][a-1][2]=s;
            Board_CR[b-1][a][2]=s;
            Board_CR[b+1][a][2]=s;
        }
        else if(b==1)
        {
            Board_CR[b][a][1]-=3;
            Board_CR[b+1][a][1]++;
            Board_CR[b][a-1][1]++;
            Board_CR[b][a+1][1]++;
            Board_CR[b+1][a][2]=s;
            Board_CR[b][a-1][2]=s;
            Board_CR[b][a+1][2]=s;
        }
        else if(b==10)
        {
            Board_CR[b][a][1]-=3;
            Board_CR[b-1][a][1]++;
            Board_CR[b][a-1][1]++;
            Board_CR[b][a+1][1]++;
            Board_CR[b-1][a][2]=s;
            Board_CR[b][a-1][2]=s;
            Board_CR[b][a+1][2]=s;
        }
    }
    else 
    {
            Board_CR[b][a][1]-=4;
            Board_CR[b+1][a][1]++;
            Board_CR[b-1][a][1]++;
            Board_CR[b][a+1][1]++;
            Board_CR[b][a-1][1]++;
            Board_CR[b+1][a][2]=s;
            Board_CR[b-1][a][2]=s;
            Board_CR[b][a+1][2]=s;
            Board_CR[b][a-1][2]=s;
    }
    if(Board_CR[b][a][1]==0) Board_CR[b][a][2]=0;
}

void Print_CR(int n,int s)
{
    char dot=79;
    
    if(s==0) 
    {
        printf("   ");
    }    
    else if(s==1)
    {
        printf("\033[1;31m");
        if(n==0) printf("   ");
        else if(n==1) printf(" %c ",dot);
        else if(n==2) printf("%c %c",dot,dot);
        else if(n>=3) printf("%c%c%c",dot,dot,dot);
        printf("\033[0m");
    }
    else if(s==2)
    {
        printf("\033[1;32m");
        if(n==0) printf("   ");
        else if(n==1) printf(" %c ",dot);
        else if(n==2) printf("%c %c",dot,dot);
        else if(n>=3) printf("%c%c%c",dot,dot,dot);
        printf("\033[0m");
    }
}

void PrintBoard_CR()
{
    int i,j;
    
    printf("\033[1;36m");
    printf("     A   B   C   D   E   F\n");
    printf("\033[0m");

    for(i=1;i<=21;i++)
    {
        if(i%2==1)
        {
            for(j=1;j<=25;j++)
            {
                if(j==1 && i==1) printf("   %c",218);
                else if(j==1 && i==21) printf("   %c",192);
                else if(j==1) printf("   %c",195);
                else if(j==25 && i==1) printf("%c",191);
                else if(j==25 && i==21) printf("%c",217);
                else if(j==25) printf("%c",180);
                else if(j%4==1 && i==1) printf("%c",194);
                else if(j%4==1 && i==21) printf("%c",193);
                else if(j%4==1) printf("%c",197);
                else printf("%c",196);
            }
        }
        else 
        {    
            printf("\033[1;34m"); 
            printf("%2d ",i/2);
            printf("\033[0m");
            for(j=1;j<=13;j++)
            {
                if(j%2==1) printf("%c",179);
                else 
                {
                    Print_CR(Board_CR[(i+1)/2][j/2][1],Board_CR[(i+1)/2][j/2][2]);
                }    
            }
        }
        printf("\n");
    }
}

void InitializeBoard_CR()
{
    int i,j;
    
    for(i=1;i<=6;i++)
        for(j=1;j<=10;j++)
        {
            Board_CR[i][j][1] = 0;
            Board_CR[i][j][2] = 0;
        }
} 

int ChainReactionRules(){
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
    printf(" - It is a two player game.");
    for(int i=0;i<93;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - The game is played in turns.");
    for(int i=0;i<89;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - In his/her turn , each player can place an atom on a 6x10 board at a place unoccupied by the opponent.");
    for(int i=0;i<15;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Each tile can hold a limited number of atoms beyond which they split.");
    for(int i=0;i<48;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - A corner tile can hold at maximum one atom,an edge tile can hold two atoms and an interior tile can hold 3 atoms.");
    for(int i=0;i<4;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - When a split occurs , the atoms now occupy the neighboring tiles of the tile where the split took place.");
    for(int i=0;i<13;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game continues until only atoms of one player are left on the board(except the initial move) ,declaring that");
    for(int i=0;i<5;i++) printf(" ");
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
    printf(" - You must enter the coordinates of the tile on which he/she wishes to make his/her move.");
    for(int i=0;i<30;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - For example, if you want to choose the tile containing second row and third column, then you must enter \"C2\" or \"c2\".");
    for(int i=0;i<0;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - When a split occurs , the atoms now occupy the neighboring tiles of the tile where the split took place.");
    for(int i=0;i<13;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - You can't place an atom on an opponent's tile.");
    for(int i=0;i<71;i++) printf(" ");
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
