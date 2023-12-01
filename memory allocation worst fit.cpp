#include<stdio.h>
int main()
{
	int ps[10],pn,bs[10],bn,i,j,idx,allocate[50];
	printf("enter no of process: ");
	scanf("%d",&pn);
	printf("enter size of each process:");
	for(i=1;i<=pn;i++)
	{
		scanf("%d",&ps[i]);
	}
	printf("enter no of blocks: ");
	scanf("%d",&bn);
	printf("enter size of each block:");
	for(i=1;i<=bn;i++)
	{
		scanf("%d",&bs[i]);
    }
    
    for(i=1;i<=pn;i++)
    {
    	allocate[i]=-1;
	}
	for(i=1;i<=pn;i++)
	{
		idx=-1;
		for(j=1;j<=bn;j++)
		{
			if(bs[j]>=ps[i])
			{
				if(idx==-1)
				idx=j;
				else if(bs[idx]<bs[j])
				idx=j;
			}
		}
		if(idx!=-1)
		{
			allocate[i]=idx;
			bs[idx]-=ps[i];
		}
	}
	
	printf("processid\tprocess size\tblock number\n");
	for(i=1;i<=pn;i++)
	{
		if(allocate[i]!=-1)
		{
			printf("%d\t %d\t %d\n",pn,ps[i],allocate[i]);
		}
		else
		{
			printf("%d\t %d\t not allocated\n",pn,ps[i]);
		}
	}
}
