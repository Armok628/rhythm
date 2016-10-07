#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
const char quarter[]="\u2669";
const char eighth[]="\u266A";
const char beamedeighth[]="\u266B";
static double bar[8];
double sum();
int main(int argc, char *argv[])
{
	initscr();
	clear();refresh();
	int count=4;
	if (argc>1)
		sscanf(argv[1],"%d",&count);
	for (int c=0;c<count;c++)
	{
		int index=0;
		for (int i=0;i<8;i++)
			bar[i]=0;
		srand(time(0));
		do
		{
			if (sum()+0.5==4)
			{
				bar[index]=0.5;
			}
			else
				switch (rand()%2)
				{
					case 0:bar[index]=1.0;break;
					case 1:bar[index]=0.5;break;
				}
			index++;
		} while (sum()<4);
		/*
		for (int i=0;i<8;i++)
		{
			printf(bar[i])<<" ";
		}
		printf(endl;
		*/
		for (int i=0;i<8;i++)
		{
			if (bar[i]==1.0)
				printf(quarter);
			if (bar[i]==0.5)
			{
				if (i==7||bar[i+1]!=0.5)
					printf(eighth);
				else if (bar[i+1]==0.5)
				{
					printf(beamedeighth);
					i++;
				}
			}
		}
		fflush(stdout);
		if (c<3)
			printf(" | ");
		if (c==1)
			printf("\r\n");
		sleep(4);
	}
	sleep(1);
	printf("\n");
	endwin();
	return 0;
}
double sum()
{
	double sum=0;
	for (int i=0;i<8;i++)
		sum+=bar[i];
	return sum;
}
