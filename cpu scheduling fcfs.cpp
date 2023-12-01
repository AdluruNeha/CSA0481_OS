#include<stdio.h>
int main()
{
	int pid[15],bt[15],n,wt[15],tt[15],i,j;
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
	wt[0]=0;
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
	printf("average turn around time = %f",att);
	
}
