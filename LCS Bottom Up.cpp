#include<bits/stdc++.h>
 
using namespace std;

char arr_a[100];
char arr_b[100];

int main()
{
    scanf("%s", arr_a);
    scanf("%s", arr_b);

    //Initialization
    int memo[100][100];
    memset(memo,-1,sizeof memo);

    //Basecase
    for(int i=0;i<strlen(arr_a);i++) memo[i][0]=0;
    for(int i=0;i<strlen(arr_b);i++) memo[0][i]=0;

    //Transisitions
    for(int i=1;i<=strlen(arr_a);i++)
    {
        for(int j=1;j<=strlen(arr_b);j++)
        {
            if(arr_a[i-1]==arr_b[j-1]) memo[i][j]=memo[i-1][j-1]+1;  //if same letter is detected, add up left diagonal with 1 (last character in both string)
            else memo[i][j]=max(memo[i-1][j],memo[i][j-1]); //else just choose the current maximum lcs
        }
    }

    int longest = memo[strlen(arr_a)][strlen(arr_b)];
    printf("%d\n", longest);

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