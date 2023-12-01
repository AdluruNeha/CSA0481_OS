#include<stdio.h>
int main()
{
	int n,no,r_s[20],frame[10],avail,fcount=0,i,j,k;
	printf("enter no of frames:");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		frame[i]=-1;
	}
	printf("enter no of pages:");
	scanf("%d",&n);
	printf("enter refrence pages:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&r_s[i]);
	}
	j=0;
	printf("\nref string \t page frames \t hit/fault\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",r_s[i]);
		avail=0;
		for(k=0;k<no;k++)
		{
			if(frame[k]==r_s[i])
			{
				avail=1;
				for(k=0;k<no;k++)
				 printf("%d\t",frame[k]);
				printf("h");
			}
		}
		if(avail==0)
		{
			frame[j]=r_s[i];
			j=(j+1)%no;
			fcount++;
			for(k=0;k<no;k++)
			 printf("%d\t",frame[k]);
			printf("f");
		}
		printf("\n");
	}
	printf("page faults = %d",fcount);
}
