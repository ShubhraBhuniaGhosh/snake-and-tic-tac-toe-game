#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
//______________________________________________________________________________________________________________________________
//GLOBAL VARIABLE FOR SNAKE GAME
 int width = 60  , height = 20, gameOver;
 int x_snakegame, y_snakegame, fruitx, fruity, flag, score;
 int tailx[100],taily[100];
 int countTail=0;
 char conti_S='y';
 //______________________________________________________________________________________________________________________________

//GLOBAL VARIABLE TIC TAC TOE
int gamewin1=0,gamewin2=0;
char a[3][3] = {{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'}};
int position=0;
char conti='y';
//______________________________________________________________________________________________________________________________

//CODE FOR TIC TAC TOE

void win(){
    int i;
    for(i=0;i<3;i++){
        if(a[i][0]==a[i][1] || a[i][1]==a[i][2]){
            if(a[i][0]=='X')
                gamewin1=1;
            if(a[i][0]=='O')
                gamewin2=1;
        }
        if(a[0][i]==a[1][i] || a[1][i]==a[2][i]){
            if(a[0][i]=='X')
                gamewin1=1;
            if(a[0][i]=='O')
                gamewin2=1;
        }
    }
        if(a[0][0]==a[1][1] || a[1][1]==a[2][2]){
            if(a[1][1]=='X'){
                gamewin1=1;
            }
            if(a[1][1]=='O'){
                gamewin2=1;
            }
        }
        if(a[0][2]==a[1][1] || a[1][1]==a[2][0]){
            if(a[1][1]=='X')
                gamewin1=1;
            if(a[1][1]=='O')
                gamewin2=1;
        }

}
//_____________________________________________________________________________________________________________________________

void show(){
    int i;
    printf("\n\n\t\t Two Player tic tac toe");
    printf("\n\n\t\t\t ___ ___ ___ \n");

    for(i=0;i<3;i++)
        printf("\t\t\t|_%c_|_%c_|_%c_|\n",a[i][0],a[i][1],a[i][2]);

    printf("\n\t Player 1 symbol : X");
    printf("\n\t Player 2 symbol : O\n");
}
//_____________________________________________________________________________________________________________________________

void check(int position,int player)
{
    int x=((position-1)/3);
    int y=position-1-(3*x);
    if(a[x][y]!='X'||a[x][y]!='O'){
        if(player==1)
           a[x][y]='X';
        else if(player==2)
            a[x][y]='O';
    }
}
//_____________________________________________________________________________________________________________________________

void player_1(){
    int x=0;
    int y=0;
    lable1:
    system("cls");
    show();
    printf("Player 1 : Enter position\n");
    scanf("%d",&position);
    if(position<1||position>9)
        goto lable1;
    x=((position-1)/3);
    y=position-1-(3*x);
    if(a[x][y]=='X'||a[x][y]=='O')
        goto lable1;
    check(position,1);
}
//______________________________________________________________________________________________________________________________

void player_2(){
    int x=0;
    int y=0;
    lable2:
    system("cls");
    show();
    printf("Player 2 : Enter position\n");
    scanf("%d",&position);
    if(position<1||position>9)
        goto lable2;
    x=((position-1)/3);
    y=position-1-(3*x);
    if(a[x][y]=='X'||a[x][y]=='O')
        goto lable2;
    check(position,2);
}
//_____________________________________________________________________________________________________________________________

void ttt(){
    int i=0,j,k,l=0;
    while(conti=='Y'||conti=='y'){
        for(i=0;i<4;i++){
            system("cls");
            show();
            player_1();
            win();
            if(gamewin1==1||gamewin2==1)
                break;
            system("cls");
            player_2();
            system("cls");
            win();
            if(gamewin1==1||gamewin2==1)
                break;
        }
        show();
        if(i==4){
            player_1();
            system("cls");
            show();
            win();
            if(gamewin1!=1&&gamewin2!=1){
                printf("\n\t\t\tmatch draw\n");
            }
        }
        if(gamewin1==1){
            system("cls");
            show();
            printf("\n\t\t\tPLAYER 1 WIN\n");
            goto lable3;
        }
        if(gamewin2==1){
            system("cls");
            show();
            printf("\n\t\t\tPLAYER 2 WIN\n");
            goto lable3;
        }
        lable3:
        printf("Do you want to play again?(Enter y for yes) ");
        fflush(stdin);
        scanf("%c",&conti);
            gamewin1=0;
            gamewin2=0;
            a[0][0]='1';
            a[0][1]='2';
            a[0][2]='3';
            a[1][0]='4';
            a[1][1]='5';
            a[1][2]='6';
            a[2][0]='7';
            a[2][1]='8';
            a[2][2]='9';
        position=0;

    }
    //getch();
}
//______________________________________________________________________________________________________________________________

//CODE FOR SNAKE GAME
 void setup(){
     gameOver = 0;
     x_snakegame = width/2;
     y_snakegame = height/2;
     label1:
         fruitx=rand()%width;
    if(fruitx==0)
        goto label1;
    label2:
         fruity=rand()%height;
    if(fruity==0)
        goto label2;
        score=0;
 }
//_____________________________________________________________________________________________________________________________

 void draw(){
     int i,j,k,ch=0;
     system("cls");
     for(i=0;i<height;i++){
        for(j=0;j<width;j++){
            if(i==0||j==0||i==height-1||j==width-1){
                printf("*");
            }
            else{
                    ch=0;
                if(i==y_snakegame&&j==x_snakegame){
                    printf("O");
                }
                else if (i==fruity&&j==fruitx)
                    printf("$");
                else{
                    for(k=0;k<countTail;k++)
                    {
                        if(i==taily[k]&& j==tailx[k]){
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                        printf(" ");
                }
            }
        }
        printf("\n");
     }
 }
 //_____________________________________________________________________________________________________________________________

 void input(){
     if(_kbhit())//if bebord is preed the fungtion will return a positivwe no
        {
            switch(getch()){
            case 'a'://aswz
                flag=1;
                break;
            case 's':
                flag=2;
                break;
            case 'w':
                flag=3;
                break;
            case 'z':
                flag=4;
                break;
        }
     }
 }
 //_____________________________________________________________________________________________________________________________

 void makeLogic(){
     int i;
     tailx[0]=x_snakegame;
     taily[0]=y_snakegame;
    for(i=countTail;i>=0;i--){
        tailx[i]=tailx[i-1];
        taily[i]=taily[i-1];
    }

     switch(flag){
         case 1: x_snakegame--;
         break;
         case 2: x_snakegame++;
         break;
         case 3: y_snakegame--;
         break;
         case 4: y_snakegame++;
         break;
         default:
         break;
     }
 if( x_snakegame<0||x_snakegame>width-1||y_snakegame<0||y_snakegame>height-1){
        gameOver=1;
        //if(x_snakegame<0)
    //x_snakegame=width-1;
         //if(x_snakegame>width-1)
    //x_snakegame=1;
            //if(y_snakegame<0)
    //y_snakegame=height-1;
            //if(y_snakegame>height-1)
    //y_snakegame=1;
 }
    for(i=0;i<countTail;i++){
        if(x_snakegame==tailx[i] && y_snakegame==taily[i])
            gameOver=1;
    }
    if(x_snakegame==fruitx && y_snakegame==fruity){
        label3:
         fruitx=rand()%width;
    if(fruitx==0)
        goto label3;
    label4:
         fruity=rand()%height;
    if(fruity==0)
        goto label4;
        score+=10;
        countTail+=1;
    }
}
//_____________________________________________________________________________________________________________________________

 void snakegame(){
     int i,j;
     while(conti_S=='y'||conti_S=='Y'){
         setup();

         while(!gameOver){
             draw();
     printf("\n\n\n W->UP");
     printf("\n Z->DOWN");
     printf("\n A->LEFT");
     printf("\n S->RIGHT\n");
             input();
             makeLogic();
            for(i=0;i<=32768;i++){// as delay function is not working delays by one second
                for(j=0;j<=2048;j++){}
            }
        }
        printf("%\nscore: %d ",score);
        printf("\nDo you want to play again?(enter y for yes) ");
        fflush(stdin);
        scanf("%c",&conti_S);
                gameOver=0;
                 x_snakegame=0;
                y_snakegame=0;
                fruitx=0;
                fruity=0;
                flag=0;
                score=0;
                for(i=0;i<100;i++){
                    tailx[i]=0;
                    taily[i]=0;
                }
                countTail=0;

    }
}
//_____________________________________________________________________________________________________________________________

int main()
{
    int game = 0;
    lable4:
    system("cls");
    printf("\n\n\n\t\t\tWhich game do you want to play ? \n");
    printf("\t\t\tEnter 1 : To play Snake game\n");
    printf("\t\t\tEnter 2 : To play Tic Tac Toe game\n");
    printf("\t\t\tEnter Any key : To EXIT\n");
    fflush(stdin);
    scanf("%d",&game);
    switch(game){
    case 1: conti_S='y';
            snakegame();
            goto lable4;
    case 2: conti='y';
            ttt();
            goto lable4;
    default: exit(1);

    }
    return 0;
}
