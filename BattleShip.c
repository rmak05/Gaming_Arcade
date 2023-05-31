#include <stdio.h>
#include <stdlib.h>

void PrintBoard_BS(int s);
int ValidityCheck1_BS(int a,int b,int c,int d,int length,int s);
int ValidityCheck2_BS(int a,int b,int s);
int max_BS(int x,int y);
int min_BS(int x,int y);
void PlaceShip_BS(int a,int b,int c,int d,int length,int s,int ship);
void SetBoard_BS(int s);
void InitializeBoard_BS();
int HitCheck_BS(int a,int b,int s);
void PlayGame_BS();
void PrintShipSizes_BS();
char ConvertToUpperCase_BS(char c);
int BattleShipRules();

unsigned char Board_BS[5][9][9];
char Coordinates_BS[2];
int Hits1_BS=0,Hits2_BS=0;
int Terminate_BS=1;

// int main()
// {
//     InitializeBoard_BS();    
//     SetBoard_BS(1);
//     SetBoard_BS(2);   
//     PlayGame_BS();
 
//     return 0;
// }

char ConvertToUpperCase_BS(char c)
{
    if(c>='A' && c<='Z') return c;
    else return c-32;
}

void PrintShipSizes_BS()
{
    
    printf("\nThe ships are -\n");
    printf("Carrier    : ");
    printf("\033[1;34m");
    printf("%c%c%c%c%c\n",4,4,4,4,4);
    printf("\033[0m");
    printf("Battleship : ");
    printf("\033[1;34m");
    printf("%c%c%c%c\n",16,16,16,16);
    printf("\033[0m");
    printf("Crusier    : ");
    printf("\033[1;34m");
    printf("%c%c%c\n",17,17,17);
    printf("\033[0m");
    printf("Submarine  : ");
    printf("\033[1;34m");
    printf("%c%c%c\n",30,30,30);
    printf("\033[0m");
    printf("Destroyer  : ");
    printf("\033[1;34m");
    printf("%c%c\n\n",31,31);
    printf("\033[0m");
}

int ValidityCheck2_BS(int a,int b,int s)
{
    if(1<=a && a<=8 && 1<=b && b<=8)
    {
        if(Board_BS[s][b][a] == ' ') return 1;
        else return 0;
    }
    else return 0;
}

void PlayGame_BS()
{
    int a,b,k,m;
    int z=0;
    char x;

    while(z==0 && Terminate_BS==1)
    {
        while(z==0)
        {
        PrintShipSizes_BS();
        PrintBoard_BS(3);
        printf("\nPlayer 1 , enter the target coordinates : ");
        scanf("%s",Coordinates_BS);
        
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            z=1;
            break;
        }
        
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        if( ValidityCheck2_BS(a,b,3)==0 )
        {
            printf("Invalid coordinates , please enter again\n");
            system("pause");
            system("cls");
            continue;
        }
        k = HitCheck_BS(a,b,2);
        if(k==1)
        {
            Hits1_BS++;
            Board_BS[3][b][a] = Board_BS[2][b][a];
            printf("It's a Hit !\n");
            if(Hits1_BS==17) m=1;
            else m=0;
            system("pause");
            system("cls");
            PrintShipSizes_BS();
            PrintBoard_BS(3);
            if(m==1)
            {
                printf("\nPlayer 1 has Won !\n");
                z=1;
                break;
            }
            system("pause");      
            system("cls");
            break;
        }
        else 
        {
            Board_BS[3][b][a] = '0';
            printf("It's a Miss\n");
            system("pause");
            system("cls");
            PrintShipSizes_BS();
            PrintBoard_BS(3);
            system("pause");
            system("cls");
            break;
        }
        }
        
        while(z==0)
        {
        PrintShipSizes_BS();    
        PrintBoard_BS(4);
        printf("\nPlayer 2 , enter the target coordinates : ");

        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            z=1;
            break;
        }
        
        scanf("%s",Coordinates_BS);
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        if( ValidityCheck2_BS(a,b,4)==0 )
        {
            printf("Invalid coordinates , please enter again\n");
            system("pause");
            system("cls");
            continue;
        }
        k = HitCheck_BS(a,b,1);
        if(k==1)
        {
            Hits2_BS++;
            Board_BS[4][b][a] = Board_BS[1][b][a];
            printf("It's a Hit !\n");
            if(Hits2_BS==17) m=1;
            else m=0;
            system("pause");
            system("cls");
            PrintShipSizes_BS();
            PrintBoard_BS(4);
            if(m==1)
            {
                printf("\nPlayer 2 has Won !\n");
                z=1;
                break;
            }
            system("pause");
            system("cls");
            break;
        }
        else 
        {
            Board_BS[4][b][a] = '0';
            printf("It's a Miss\n");
            system("pause");
            system("cls");
            PrintShipSizes_BS();
            PrintBoard_BS(4);
            system("pause");
            system("cls");
            break;
        }
        }
    }
    Terminate_BS=1;
}

int HitCheck_BS(int a,int b,int s)
{
    if(Board_BS[s][b][a] != ' ') return 1;
    else return 0;
}

void InitializeBoard_BS()
{
    int i,j;
    
    for(i=0;i<=8;i++)            
        for(j=0;j<=8;j++)
        {
            Board_BS[1][i][j] = ' ';  
            Board_BS[2][i][j] = ' ';
            Board_BS[3][i][j] = ' ';
            Board_BS[4][i][j] = ' ';
        }
}

void SetBoard_BS(int s)
{
    int a,b,c,d;
    char x,y;
    
    system("cls");
    if(Terminate_BS==1)
    {
    do
    {
        PrintShipSizes_BS();
        PrintBoard_BS(s);
        printf("\nPlayer %d , set the positions of your ships\n\n",s);
        printf("Enter first endpoint of Carrier : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        printf("Enter second endpoint of Carrier : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        y=Coordinates_BS[0];
        y=ConvertToUpperCase_BS(y);
        d=Coordinates_BS[1]-48;
        c=y-64;
        
        if( ValidityCheck1_BS(a,b,c,d,5,s)==0 )
        {
            printf("Invalid endpoints , please enter again\n");
            system("pause");
            system("cls");
        }
    }while( ValidityCheck1_BS(a,b,c,d,5,s)==0 );
    PlaceShip_BS(a,b,c,d,5,s,4);
    system("cls");
    }
    
    if(Terminate_BS==1)
    {
    do
    {
        PrintShipSizes_BS();
        PrintBoard_BS(s);
        printf("\nPlayer %d , set the positions of your ships\n\n",s);
        printf("Enter first endpoint of Battleship : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        printf("Enter second endpoint of Battleship : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        y=Coordinates_BS[0];
        y=ConvertToUpperCase_BS(y);
        d=Coordinates_BS[1]-48;
        c=y-64;
        
        if( ValidityCheck1_BS(a,b,c,d,4,s)==0 )
        {
            printf("Invalid endpoints , please enter again\n");
            system("pause");
            system("cls");
        }
    }while( ValidityCheck1_BS(a,b,c,d,4,s)==0 );
    PlaceShip_BS(a,b,c,d,4,s,16);
    system("cls");
    }
    
    if(Terminate_BS==1)
    {
    do
    {
        PrintShipSizes_BS();
        PrintBoard_BS(s);
        printf("\nPlayer %d , set the positions of your ships\n\n",s);
        printf("Enter first endpoint of Cruiser : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        printf("Enter second endpoint of Cruiser : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        y=Coordinates_BS[0];
        y=ConvertToUpperCase_BS(y);
        d=Coordinates_BS[1]-48;
        c=y-64;
        
        if( ValidityCheck1_BS(a,b,c,d,3,s)==0 )
        {
            printf("Invalid endpoints , please enter again\n");
            system("pause");
            system("cls");
        }
    }while( ValidityCheck1_BS(a,b,c,d,3,s)==0 );
    PlaceShip_BS(a,b,c,d,3,s,17);
    system("cls");
    }
    
    if(Terminate_BS==1)
    {
    do
    {
        PrintShipSizes_BS();
        PrintBoard_BS(s);
        printf("\nPlayer %d , set the positions of your ships\n\n",s);
        printf("Enter first endpoint of Submarine : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        printf("Enter second endpoint of Submarine : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        y=Coordinates_BS[0];
        y=ConvertToUpperCase_BS(y);
        d=Coordinates_BS[1]-48;
        c=y-64;
        
        if( ValidityCheck1_BS(a,b,c,d,3,s)==0 )
        {
            printf("Invalid endpoints , please enter again\n");
            system("pause");
            system("cls");
        }
    }while( ValidityCheck1_BS(a,b,c,d,3,s)==0 );
    PlaceShip_BS(a,b,c,d,3,s,30);
    system("cls");  
    }

    if(Terminate_BS==1)
    {
    do
    {
        PrintShipSizes_BS();
        PrintBoard_BS(s);
        printf("\nPlayer %d , set the positions of your ships\n\n",s);
        printf("Enter first endpoint of Destroyer : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        x=Coordinates_BS[0];
        x=ConvertToUpperCase_BS(x);
        b=Coordinates_BS[1]-48;
        a=x-64;
        printf("Enter second endpoint of Destroyer : ");
        scanf("%s",Coordinates_BS);
        if(ConvertToUpperCase_BS(Coordinates_BS[0])=='E' && ConvertToUpperCase_BS(Coordinates_BS[1])=='X') 
        {
            Terminate_BS=0;
            return;
        }
        y=Coordinates_BS[0];
        y=ConvertToUpperCase_BS(y);
        d=Coordinates_BS[1]-48;
        c=y-64;
        
        if( ValidityCheck1_BS(a,b,c,d,2,s)==0 )
        {
            printf("Invalid endpoints , please enter again\n");
            system("pause");
            system("cls");
        }
    }while( ValidityCheck1_BS(a,b,c,d,2,s)==0 );
    PlaceShip_BS(a,b,c,d,2,s,31);
    system("cls");
    PrintShipSizes_BS();
    PrintBoard_BS(s);
    system("pause");
    system("cls");
    }
}


void PlaceShip_BS(int a,int b,int c,int d,int length,int s,int ship)
{
    int p,lx,ly,hx,hy;
    char ship2;

    ship2 = ship;
    lx = min_BS(a,c);
    ly = min_BS(b,d);
    hx = max_BS(a,c);
    hy = max_BS(b,d);  
          
    if(a==c)
    {
        for(p=ly;p<=hy;p++)
        { 
             Board_BS[s][p][a]=ship2;
        }
    }
    else 
    {
        for(p=lx;p<=hx;p++)
        {
            Board_BS[s][b][p]=ship2;
        }
    }
}

int max_BS(int x,int y)
{
    if(x>=y) return x;
    else return y;
}

int min_BS(int x,int y)
{
    if(x<=y) return x;
    else return y;
}

void PrintBoard_BS(int s)
{
    int i,j;
    printf("\033[1;31m");
    printf("     A   B   C   D   E   F   G   H\n");
    printf("\033[0m");
   
    for(i=1;i<=17;i++)
    {
        if(i%2==1)
        {
            for(j=1;j<=33;j++)
            {
                if(j==1 && i==1) printf("   %c",218);
                else if(j==1 && i==17) printf("   %c",192);
                else if(j==1) printf("   %c",195);
                else if(j==33 && i==1) printf("%c",191);
                else if(j==33 && i==17) printf("%c",217);
                else if(j==33) printf("%c",180);
                else if(j%4==1 && i==1) printf("%c",194);
                else if(j%4==1 && i==17) printf("%c",193);
                else if(j%4==1) printf("%c",197);
                else printf("%c",196);
            }
        }
        else 
        {    
            printf("\033[1;33m"); 
            printf("%2d ",i/2);
            printf("\033[0m");
            for(j=1;j<=17;j++)
            {
                if(j%2==1) printf("%c",179);
                else 
                {
                    if(Board_BS[s][i/2][j/2] != '0')
                    {
                        printf("\033[1;34m");
                        printf(" %c ",Board_BS[s][i/2][j/2]); 
                        printf("\033[0m");
                    }
                    else
                    {
                        printf("\033[0;30m");
                        printf(" %c ",Board_BS[s][i/2][j/2]); 
                        printf("\033[0m");
                    }
                }
            }
        }
        printf("\n");
    }
    
}

int ValidityCheck1_BS(int a,int b,int c,int d,int length,int s)
{
    int Tlength,lx,ly,hx,hy,p;
    int check=0;
    
    lx = min_BS(a,c);
    ly = min_BS(b,d);
    hx = max_BS(a,c);
    hy = max_BS(b,d);
    
    if(1<=a && a<=8 && 1<=b && b<=8 && 1<=c && c<=8 && 1<=d && d<=8)
    {
        if(a==c) Tlength = hy-ly+1;
        else if(b==d) Tlength = hx-lx+1;
        
        if(a==c || b==d)
        {
            if(Tlength==length)
            {
                     if(a==c)
                     {
                         for(p=ly;p<=hy;p++)
                         { 
                             if(Board_BS[s][p][a]==' ') check=1;
                             else
                             {
                                 check=0;
                                 break;
                             }
                         }
                     }
                     else 
                     {
                         for(p=lx;p<=hx;p++)
                         { 
                             if(Board_BS[s][b][p]==' ') check=1;
                             else 
                             {
                                 check=0;
                                 break;
                             }
                         }
                     }
                     return check;
            }
            else return 0;
        }
        else return 0;
    }  
    else return 0;
}

int BattleShipRules(){
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
    printf(" - Each player's board will consist of five ships namely Carrier, Battleship, Cruiser, Submarine and Destroyer.");
    for(int i=0;i<9;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Each player has to set these ships on his respective 8x8 board.");
    for(int i=0;i<54;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - A ship can only be placed vertically or horizontally.");
    for(int i=0;i<64;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The sizes of the ships are : Carrier(5),Battleship(4),Cruiser(3),Submarine(3),Destroyer(2).");
    for(int i=0;i<26;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Once the ships have been set on both players' boards ,the game starts.");
    for(int i=0;i<47;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game is played in turns.");
    for(int i=0;i<89;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - First , player 1 makes his move and attacks a tile on the opponent's board.");
    for(int i=0;i<42;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - If there is a enemy ship on that tile , it's a hit and player 1 will even get to know which ship he hit. ");
    for(int i=0;i<12;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - If this is not the case , then it is a miss.Then the turn goes to player 2.");
    for(int i=0;i<42;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - The game continues till all the ships of any player have been destroyed declaring the other player winner.");
    for(int i=0;i<11;i++) printf(" ");
    printf("%c\n",186); 

    printf("%c",186);  
    printf(" - Note that you can't attack the same tile twice.");
    for(int i=0;i<70;i++) printf(" ");
    printf("%c\n",186);

    printf("%c",186);  
    printf(" - Ships can't be played overlapping each other.");
    for(int i=0;i<72;i++) printf(" ");
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
    printf(" - While placing the ships , the length of the ship must match with the given coordinates.");
    for(int i=0;i<30;i++) printf(" ");
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