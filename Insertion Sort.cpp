#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    printf("Data count: ")
    scanf("%d", &n);

    int data[1000];
    for(int i=0;i<n;i++)
    {
        printf("Input data %d: ", i);
        scanf("%d", &data[i]);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(data[j]<data[j-1]) swap(data[j],data[j-1]);
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ", data[i]);
    printf("\n");
}