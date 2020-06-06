#include<stdio.h>

void initialization(void);
void truth_initialization(void);
void frame(void);
void graph(void);
void left(void);
void right(void);
void up(void);
void down(void);
void test_left(int k);
void test_right(int k);
void test_up(int k);
void test_down(int k);
void test_right_up(int k);
void test_right_down(int k);
void test_left_up(int k);
void test_left_down(int k);
void test(int k);
void question(void);
void skip();
enum control{true, false} control;	
enum game{go, stop} game;
enum game_status{black, white} game_status;
enum run{yes, no} run;
enum eli_black{on, off} eli_black;
enum eli{a, b} eli;
int array[10][10], truth[10][10], x, y,i , j, count, count_black, count_white;
char move;
int main()
{   run=yes;
	while(run==yes)
	{
	control=true;
	count_black=2;
	count_white=2;
	game_status=black;
	initialization();
	frame();
    x=6, y=5;
    array[x][y]=1;
    array[4][4]=3;
    array[5][4]=2;
    array[4][5]=2;
    array[5][5]=3;
	graph();
	while(control==true)
	{
	if(game_status==black)
	{
		printf("Black¤U\n");
			
	}
	else if(game_status==white)
	{
		printf("White¤U\n");
	}	
	printf("Press WSAD to move.\n");
	printf("Press E to put chess piece.\n");
	printf("Press Q to concede.\n");	
	printf("Black:%d\nWhite:%d\n", count_black, count_white);
	move=getch();
	switch(move)
	{
		case'A':{
			if(array[x-1][y]!=5)
			{
			left();
	 	    }
			break;
		}
		case'D':{
			if(array[x+1][y]!=5)
			{
			right();
		    }
			break;
		}
		case'S':{
			if(array[x][y+1]!=4)
			{
			down();
		    }
			break;
		}
		case'W':{
			if(array[x][y-1]!=4)
			{
			up();
		    }
			break;
		}
		case'E':{
			if(game_status==black&&array[x][y]==1)
			{
				eli=no;
			test(1);
			if(eli==yes)
			{	
			array[x][y]=2;			
			game_status=white;	
			count_black++;
		    }
		    
		    }
		    else if(game_status==white&&array[x][y]==1)
		    {
		    	eli=no;
		    	test(2);
		    	if(eli==yes)
		    	{
		    	array[x][y]=3;		    	
		    	game_status=black;
		    	count_white++;
		        }
			}
			
			break;
		}
		case'Q':{
			if(game_status==black)
			{
				system("cls");
				printf("White wins.\n");
				question();
			}
			else 
			{
				system("cls");
				printf("Black wins.\n");
				question();
			}
			control=false;
			break;
		}
	}
	if(control==true)
	{
    system("cls");
	graph();
if(count_black+count_white==64)
{
	control=false;
	system("cls");
	if(count_black>count_white)
	{
		printf("Black wins.\n");
		question();
	}
	else if(count_black==count_white)
	{
		printf("Tie.\n");
		question();
	}
	else if(count_black<count_white)
	{
		printf("White wins.\n");
		question();
	}
}
}
}
}
system("cls");
printf("Game ended.\n");
}

void initialization(void)
{
for(j=0;j<10;j++)
{
	for(i=0;i<10;i++)
	{
		array[i][j]=0;
	}
	}	
}
void truth_initialization(void)
{
for(j=0;j<10;j++)
{
	for(i=0;i<10;i++)
	{
		truth[i][j]=0;
	}
	}		
}

void graph(void)
{
	for(j=0;j<10;j++)
	{
		for(i=0;i<10;i++)
		{
			if(array[i][j]==0)
			{
			  printf(" ");
			}
			else if(array[i][j]==1)
			{
				printf("^");
			}
			else if(array[i][j]==2)
			{
				printf("*");
			}
			else if(array[i][j]==3)
			{
				printf("O");
			}
			else if(array[i][j]==4)
			{
				printf("-");
			}
			else if(array[i][j]==5)
			{
				printf("l");
			}
		}
		printf("\n");
	}
}

void frame(void)
{
	for(j=0;j<10;j+=9)
	{
		for(i=0;i<10;i++)
		{
			array[i][j]=4;
		}
	}
	for(i=0;i<10;i+=9)
	{
		for(j=1;j<9;j++)
		{
			array[i][j]=5;
		}
	}
}

void left(void)
{
	if(array[x-1][y]==0)
	{
	array[x-1][y]=1;
    }
	if(array[x][y]==1)
	{
	array[x][y]=0;
    }
	x--;
}

void right(void)
{
	if(array[x+1][y]==0)
	{
	array[x+1][y]=1;
    }
	if(array[x][y]==1)
	{
	array[x][y]=0;
    }
	x++;
}

void up(void)
{
	if(array[x][y-1]==0)
	{
	array[x][y-1]=1;
    }
	if(array[x][y]==1)
	{
	array[x][y]=0;
    }
	y--;
}

void down(void)
{
	if(array[x][y+1]==0)
	{
	array[x][y+1]=1;
    }  
	if(array[x][y]==1)
	{
	array[x][y]=0;
    }
	y++;
}

void test_left(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;x-i>0, run==yes;i++)
	{
		if(array[x-i][y]==a)
		{
			count++;
		}
		if(array[x-i][y]==b)
		{
			eli_black=on;
		}
		if(array[x-i][y]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			
			array[x-j][y]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
		}
	}


void test_right(int k)
{    int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;x+i<19, run==yes;i++)
	{
		if(array[x+i][y]==a)
		{
			count++;
		}
		if(array[x+i][y]==b)
		{
			eli_black=on;
		}
		if(array[x+i][y]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x+j][y]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}

void test_up(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y-i>0, run==yes;i++)
	{
		if(array[x][y-i]==a)
		{
			count++;
		}
		if(array[x][y-i]==b)
		{
			eli_black=on;
		}
		if(array[x][y-i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x][y-j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}

void test_down(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y+j<19, run==yes;i++)
	{
		if(array[x][y+i]==a)
		{
			count++;
		}
		if(array[x][y+i]==b)
		{
			eli_black=on;
		}
		if(array[x][y+i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x][y+j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}
void test_right_up(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y+j<19, run==yes;i++)
	{
		if(array[x+i][y-i]==a)
		{
			count++;
		}
		if(array[x+i][y-i]==b)
		{
			eli_black=on;
		}
		if(array[x+i][y-i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x+j][y-j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}
void test_right_down(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y+j<19, run==yes;i++)
	{
		if(array[x+i][y+i]==a)
		{
			count++;
		}
		if(array[x+i][y+i]==b)
		{
			eli_black=on;
		}
		if(array[x+i][y+i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x+j][y+j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}
void test_left_up(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y+j<19, run==yes;i++)
	{
		if(array[x-i][y-i]==a)
		{
			count++;
		}
		if(array[x-i][y-i]==b)
		{
			eli_black=on;
		}
		if(array[x-i][y-i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x-j][y-j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}
void test_left_down(int k)
{   int a,b;
if(k==1)
{
	a=3;
	b=2;
}
else if(k==2)
{
	a=2;
	b=3;
}
    count=0;
	run=yes;
	eli_black=off;
	for(i=1;y+j<19, run==yes;i++)
	{
		if(array[x-i][y+i]==a)
		{
			count++;
		}
		if(array[x-i][y+i]==b)
		{
			eli_black=on;
		}
		if(array[x-i][y+i]!=a)
		{
			run=no;
		}
	}
	if(count>0&&eli_black==on)
	{
		eli=yes;
		for(j=1;j<=count;j++)
		{
			array[x-j][y+j]=b;
		}
		if(k==1)			
				count_black+=count, count_white-=count;			
			else if(k==2)			
				count_white+=count, count_black-=count;
	}
}
void test(int k)
{
	if(k==1)
	{
	test_left(1);
	test_right(1);
	test_up(1);
	test_down(1);
	test_right_up(1);
    test_right_down(1);
    test_left_up(1);
    test_left_down(1);
    }
    else if(k==2)
    {
    test_left(2);
	test_right(2);
	test_up(2);
	test_down(2);	
	test_right_up(2);
    test_right_down(2);
    test_left_up(2);
    test_left_down(2);
	}
}

void question(void)
{
	printf("Do you want to restart? >Yes  No");
	while(getch()!='E')
	{
		move=getch();
		if(move=='A')
		{
			system("cls");
					printf("Do you want to restart? >Yes  No");	
					control=true;
					run=yes;
		}
		else if(move=='D')
		{
			system("cls");
			printf("Do you want to restart?  Yes >No");	
			control=false;
			run=no;
		}
	}
}
void skip()
{
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			if(array[i][j]=0)
			{
			 test(1)
			}
		}
	}
}


