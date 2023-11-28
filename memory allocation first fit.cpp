#include<stdio.h>
int main()
{
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
	for(i = 0; i < 10; i++)
	{
		allocation[i] = -1;
	}
	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)         
		for(j = 0; j < bno; j++)
			if(bsize[j] >= psize[i])
			{
				allocation[i] = j;
				bsize[j]-=psize[i];
				break;
			}
	printf("\nprocess no.\tprocess size.\tblock no.");
	for(i = 0; i < pno; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, psize[i]);
		if(allocation[i]!=-1)
			printf("%d",allocation[i]+1);
		else
			printf("Not allocated");
	}
}

