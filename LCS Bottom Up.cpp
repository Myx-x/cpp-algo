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
            if(arr_a[i-1]==arr_b[j-1]) memo[i][j]=memo[i-1][j-1]+1; //if same letter is detected, add up left diagonal with 1 (last character in both string)
            else memo[i][j]=max(memo[i-1][j],memo[i][j-1]); //else just choose the current maximum lcs
        }
    }
    printf("%d\n", memo[strlen(arr_a)][strlen(arr_b)]);
}