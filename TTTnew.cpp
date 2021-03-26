#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
char frame[9]={'1','2','3','4','5','6','7','8','9'};
int count=0;
//globally declared char array(frame) and int count so as to in many functions
void startscreen(){
	int gd=0,gm,i=0,k=15,inc=260;
	initgraph(&gd,&gm,"");
	while(inc!=440){
		setcolor(i++);
		setlinestyle(0,0,3);
		rectangle(5,5,getmaxx()-5,getmaxy()-5);
		setcolor(k--);
		setlinestyle(2,0,3);
		rectangle(20,20,getmaxx()-20,getmaxy()-30);
		setcolor(rand()%15);
		settextstyle(10,0,10);
		outtextxy(50,30,"TIC");
		setcolor(rand()%15);
		outtextxy(200,130,"TAC");
		setcolor(rand()%15);
		outtextxy(350,230,"TOE");
		setcolor(4);
		setfillstyle(4,14);
		inc=inc+10;
		bar(230,370,inc,400);
		settextstyle(0,0,2);
		setcolor(4);
		outtextxy(260,410,"Loading...");
		if(i==16&&k<0){
			    i=0;
			    k=15;
			}
   		Sleep(200);
	        cleardevice();
		}
		closegraph();
	}
void show();
void playersymbol();
void run();
void play();
void replace(char x,char y);
int result();
int main()
{
int win;
char cont;
startscreen();
labelcontinue:
    system("cls");
/*used to clear input buffer(temparary storage location)
In case of char only (enter pressed after first input will store in buffer
And will taken as input for second char scanning*/
printf("\t\t\tTIC TAC TOE GAME");
show();
playersymbol();
run();
play();
label: /*to perform the same things again and again(take input and replace
the matrice with symbol untill game draw or any player won)*/
system("cls");
show();
play();
win=result();
system("cls");
show();
if(count<9) /*after palying 9 times the game is ended if no player won then
it shows draw*/
{
	if(win==1)
	{
		printf("player 1 won!");
		count=0;/*initializing 0 because if user wants to play again
		then count will become 0 not 9*/
	}
	else if(win==2)
		{
			printf("player 2 won!");
			count=0;
		}
	else
		goto label;
}
else
{
    if(win==1)
	{
		printf("player 1 won!");
		count=0;/*initializing 0 because if user wants to play again
		then count will become 0 not 9*/
	}
	else if(win==2)
		{
			printf("player 2 won!");
			count=0;
		}
		else{
printf("\nGAME DRAWN!!!!!");
count=0;}
}
printf("\n\n\n\n!WANTS TO PLAY GAME AGAIN?");
printf("\n\n!Enter Y for YES and N for NO:\n");
fflush(stdin);
scanf("%c",&cont);
if(cont=='y'||cont=='Y')
{  /*initialize whole matrix with 1,2,.....,9 because after playing game once
the matrices position is converted into x and y  */
frame[0]='1';
frame[1]='2';
frame[2]='3';
frame[3]='4';
frame[4]='5';
frame[5]='6';
frame[6]='7';
frame[7]='8';
frame[8]='9';
goto labelcontinue;
}
getch();
return 0;
}
void show()
{
	printf("\n\n\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",frame[0],frame[1],frame[2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",frame[3],frame[4],frame[5]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",frame[6],frame[7],frame[8]);
	printf("\t\t\t---|---|---\n");
}
void playersymbol()
{
	printf("\nplayer 1 symbol: x\n");
	printf("\nplayer 2 symbol: y\n");
}
void run()
{
	char startchance;
	printf("\n\tGame will start by:    player 1 or player 2?\n");
	fflush(stdin);/*used to clear input buffer(temporary storage location)
	requires in case of char array only,(enter pressed after scanning
	of first input will stored in buffer and will taken as inpu for
	second char time scanning*/
	scanf("%c",&startchance);
}
void play()
{
	char pos,sym;
	printf("\n ENTER POSITION AND SYMBOL OF PLAYER:\n");
	fflush(stdin);
	scanf("%c",&pos);
	fflush(stdin);
	scanf("%c",&sym);
	count++;
	replace(pos,sym);
}
void replace(char pos,char sym)
{
int i;
for(i=0;i<=8;i++)
	{
		if(frame[i]==pos)//replace input position by symbol
		{
			frame[i]=sym;
		}
	}
}
int result()
{
if((frame[0]=='x'&&frame[1]=='x'&&frame[2]=='x')||(frame[0]=='x'&&frame[3]=='x'&&frame[6]=='x')||(frame[0]=='x'&&frame[4]=='x'&&frame[8]=='x'))
return 1;
else if((frame[0]=='y'&&frame[1]=='y'&&frame[2]=='y')||(frame[0]=='y'&&frame[3]=='y'&&frame[6]=='y')||(frame[0]=='y'&&frame[4]=='y'&&frame[8]=='y'))
return 2;
else if((frame[1]=='x'&&frame[4]=='x'&&frame[7]=='x')||(frame[2]=='x'&&frame[5]=='x'&&frame[8]=='x')||(frame[3]=='x'&&frame[4]=='x'&&frame[5]=='x'))
return 1;
else if((frame[6]=='x'&&frame[7]=='x'&&frame[8]=='x')||(frame[2]=='x'&&frame[4]=='x'&&frame[6]=='x'))
return 1;
else if((frame[1]=='y'&&frame[4]=='y'&&frame[7]=='y')||(frame[2]=='y'&&frame[5]=='y'&&frame[8]=='y')||(frame[3]=='y'&&frame[4]=='y'&&frame[5]=='y'))
return 2;
else if((frame[6]=='y'&&frame[7]=='y'&&frame[8]=='y')||(frame[2]=='y'&&frame[4]=='y'&&frame[6]=='y'))
return 2;
else
return 0;
}
