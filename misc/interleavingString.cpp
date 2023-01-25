#include <bits/stdc++.h>
using namespace std;
int** dp;
string s1,s2,s3;
int isFitting(int i,int j){
    if( i==0 && j==0)
        return 1;
    if(dp[i][j] == 1 )
        return 1;
    int res = 0;
    if (i && s1[i - 1] == s3[i+j-1] && !res)
        res = isFitting(i-1,j);
    if (j && s2[j - 1] == s3[i+j-1] && !res)
        res = isFitting(i,j-1);
    dp[i][j] = res;
    return dp[i][j];
}
int main(){
    cin >> s1 >> s2 >> s3;
    dp = new int*[s1.length()];
    for(int i=0;i<=s1.length();i++){
        dp[i] = new int[s2.length()];
        for(int j=0;j<=s2.length();j++)
            dp[i][j] = -1;
    }
    cout << isFitting(s1.length(),s2.length()) << endl;
    return 0;
}