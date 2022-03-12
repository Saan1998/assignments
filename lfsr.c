#include<stdio.h>
int main()
{
	int n, i=0,j=0,k=0,temp, count=1 , flag;
	int a[n], b[n], c[100];
	printf("Enter the degree of the LFSR:");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("enter initial seed");
		scanf("%d", &a[i]);
	}
	for(i=0;i<n;i++)
	b[i]=a[i];
	i=0;
	int t1, t2;
	printf( "enter the tap 1 position");
	scanf("%d", & t1);
     printf( "enter the tap 2 position");
	scanf("%d", & t2);
	
	while(1)
	{
		c[k++]=a[n-1];
		temp=(a[t1]+a[t2])%2;
		for(i=n-1;i>0;i--)
		{
			a[i]=a[i-1];
		}
		a[0]=temp;
		i=0;
		while(i<n)
		{
			if(a[i] != b[i])
			{
			    count++;
			  
			    break;
			}   
			else
			i++;
		}
		if(i==n)
	      break;
	
		else
	{	
		      flag = 0;
              printf("The random bits are: ");
              for(i = 0; i < n; i++)
                {
                  printf("%d",a[i]);
                  flag++;
                   if(n == flag)
                     {
                        printf("\n");
                        printf(" ");
                         flag = 0;
                    }
               }
		continue;
	}
}
	
	printf("the count is : %d", count);
	printf("\n the key stream : ");
	
	for(i=0;i<k;i++)
	{
		printf("\n %d", c[i]);
	}
	
	return 0;
}


