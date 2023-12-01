#include<stdio.h>
int main()
{
	int pid[15],bt[15],n,wt[15],tt[15],i,j,t,tp;
	float awt,att;
	printf("enter no of processes:");
	scanf("%d",&n);
	printf("enter process id of all the processes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("enter burst time of all the processes");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	//bubble sort
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(bt[j]>bt[j+1])
			{
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
				
				tp=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=tp;
			}
		}
	}
	
	//sjf
/*	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	for(i=0;i<n;i++)
	{
		tt[i]=wt[i]+bt[i];
	}
	printf("processid  brust time  wating time turnaround time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",bt[i]);
		printf("%d\t\t",wt[i]);
		printf("%d",tt[i]);
		awt+=wt[i];
		att+=tt[i];
		printf("\n");
	}
	awt=awt/n;
	att=att/n;
	printf("average waiting time = %f\n",awt);
	printf("average turn around time = %f",att);*/
	for(j=0;j<n;j++)
	{
		wt[j]=0;
		tt[j]=0;
		for(i=0;i<j;i++)
		{
			wt[j]=wt[j]+bt[i];
		}
		tt[j]=wt[j]+bt[j];
		awt=awt+wt[j];
		att=att+tt[j];
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t %d\t %d\t %d\t",pid[i],bt[i],wt[i],tt[i]);
		printf("\n");
	}
}
