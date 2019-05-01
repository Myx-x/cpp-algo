#include<bits/stdc++.h>

using namespace std;

int main()
{   
    int n;
    printf("Data count: ");
    scanf("%d", &n);

    int ndata[1000];
    int ndatamax=-1;
    memset(ndata,0,sizeof(ndata));

    for(int i=0;i<n;i++)
    {
        printf("Input data %d: ", i);
        int x;
        scanf("%d", &x);
        ndata[x]++;
        ndatamax=max(ndatamax,x);
    }

    for(int i=0;i<=ndatamax;i++) if(ndata[i]!=0) for(int j=0;j<ndata[i];j++) printf("%d ", i);

}