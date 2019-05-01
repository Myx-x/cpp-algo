#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    printf("Data count: ");
    scanf("%d", &n);

    int data[1000];
    for(int i=0;i<n;i++)
    {
        printf("Input data %d: ", i);
        scanf("%d", &data[i]);
    }

    for(int i=1;i<n;i++)
    {
        int tmp=data[i];
        int j=i-1;
        while(tmp<data[j] && j>0)
        {
            data[j+1]=data[j];
            j--;
        }
        if(tmp>=data[j]) data[j+1]=tmp;
        else
        {
            data[j+1]=data[j];
            data[j]=tmp;
        }

        /*for(int j=0;j<n;j++)
            printf("%d ", data[j]);
        printf("\n");*/

    }

    for(int i=0;i<n;i++)
        printf("%d ", data[i]);
    printf("\n");
}