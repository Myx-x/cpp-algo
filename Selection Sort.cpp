#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    printf("Data count: ");
    scanf("%d", &n);
    int data[1000];

    //Input data
    for(int i=0;i<n;i++)
    {
        printf("Input data %d: ", i);
        scanf("%d", &data[i]);
    }

    //Seletion Sort.
    for(int i=0;i<n;i++)
    {
        int mindata=1e9,minindex;
        for(int j=i;j<n;j++)
        {
            if(mindata>data[j]) 
            {
                mindata=data[j];
                minindex=j;
            }
        }

        //Swap data[i] with lowest of data[1..n]
        swap(data[i],data[minindex]);
    }

    for(int i=0;i<n;i++)
        printf("%d ", data[i]);

    printf("\n");

    
}