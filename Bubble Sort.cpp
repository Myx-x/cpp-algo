#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int data[1000];

    for(int i=0;i<n;i++)
    {
        printf("Input data %d: ", i);
        scanf("%d", &data[i]);
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n-i;j++)
        {
            if(data[j]<data[j-1]) swap(data[j],data[j-1]);
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ", data[i]);
    
    printf("\n");
}