#include<bits/stdc++.h>
 
using namespace std;

char arr_a[200];
char arr_b[200];

int memo[200][200];

//LCS Top-Down DP Approach
int lcs(int la, int lb)
{
    if(memo[la][lb]!=-1) return memo[la][lb];
    else
    {
        if(la<0 || lb<0) return 0;
        else if(arr_a[la]==arr_b[lb]) return memo[la][lb]=1+lcs(la-1,lb-1);
        else return memo[la][lb]=max(lcs(la-1,lb),lcs(la,lb-1));
    }
}

int main()
{
    //Input
    scanf("%s", arr_a);
    scanf("%s", arr_b);

    //Output
    memset(memo,-1,sizeof(memo));
    int longest=lcs(strlen(arr_a)-1,strlen(arr_b)-1);
    printf("%d\n",longest);
    
    //Initialization
    int pa=strlen(arr_a)-1;
    int pb=strlen(arr_b)-1;

    char res[100];
    int p=0;

    //Traverse Memo
    while(pa!=-1 && pb!=-1)
    {
        if(arr_a[pa]==arr_b[pb]) // If char equal, traverse diagonally left upwards
        {
            res[p++]=arr_a[pa];
            pa--;
            pb--;
        }
        else if(memo[pa-1][pb]>memo[pa][pb-1]) pa--; // if going upwards is feasible, go upwards
        else pb--; // if not, then traverse left
    }

    //Outputing result in reverse
    if(longest==0) printf("LCS not found");
    else for(int i=p-1;i>=0;i--) printf("%c", res[i]);
    printf("\n");

}