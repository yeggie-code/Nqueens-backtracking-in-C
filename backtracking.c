#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

int a[30];
int count = 0;

int place(int pos)
{
    int i; 
    for(i=0;i<pos;i++)//from 1st row to the (current row-1) to check with all prev queens
    {
        if ((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
        return 0;//if a queen exists in the same column or diagonally
    }
    return 1;//if no queen exists in the same column or diagonally  
 }

void print_sol(int n)
{
    int i,j ;
    count++;
    printf("\n\nsolution #%d: \n",count);
    for(i=0;i<n;i++)
    { 
        for(j=1;j<=n;j++){ 
            if(a[i]==j)
            printf("Q\t");
            else
                printf("*\t");
        }
    printf("\n");
    }
}

void queen(int k, int n)
{
    if(k > n)
    {
        print_sol(n);
        return;
    }
    for(a[k-1] = 1; a[k-1] <= n; a[k-1]++)
    {
        if(place(k-1))
        {
            queen(k+1, n);
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    queen(1, n);
    printf("\n Total solutions=%d",count);
}