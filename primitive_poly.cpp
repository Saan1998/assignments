
#include<stdio.h>
#include<math.h>
int b[100],seed[100],fin[100],n,l;
int deci_convert(int d[])
{
    int term=1,decimal=d[n-1],i;
    for(i=n-1;i>0;i--)
    {
        term=term*2;
        decimal=decimal+(d[i-1]*term);
    }
    return(decimal);
    
}

int generator(int seed[], int c[])
{
    int sum=0,i,sum1=0;
    for(i=0;i<n;i++)
    {
        sum=sum+(c[i]*seed[i]);
    }
    for(i=n-1;i>0;i--)
    {
        seed[i]=seed[i-1];
    }
    seed[0]=(sum % 2);
    return(deci_convert(seed));
}

void bin_convert(int d)
{
    int i=n-1,j;
    while (d!=0) 
    {
      fin[i]=d%2;
      d=d/2;
      i=i-1;
    }
    for(j=i;j>=0;j--)
    {
       fin[j]=0;
    }
}

int main ()
{
    int i,j,dec;
    int index_no=0;
    int count=0;
    printf("Enter the degree of the polynomial:");
    scanf("%d",&n);
    printf("Enter the initial seed :\n");
    int initial= -100;
    l=pow(2, n)-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&seed[i]);
    }
    dec=deci_convert(seed);
    for(i=1;i<l+1;i++)
    {
        bin_convert(i);
        if(fin[n-1]==1)
        {
            while(initial !=dec) 
            {
                initial=generator(seed,fin);
                count++;
            }
            if(count==l)
            {
            	index_no++;
            	printf("%d. ",index_no);
            	printf("count is %d and ",count);
            	printf(" the polynomial is 1+");
                for(j=0;j<n-1;j++)
                {
                	if(fin[j] !=0)
                    printf(" x^%d+", j+1);
                }
                printf(" x^%d", n);
                printf("\n");
            }
            initial=-100;count=0;
        }
    }
    return 0;
}

