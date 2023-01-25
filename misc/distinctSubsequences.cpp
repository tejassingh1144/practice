#include <bits/stdc++.h>
using namespace std;
/*
    int func(string s,string t){
        int ways = 0;
        if the last char of of s matches t:
            ways += func(s-1,t-1);
        ways += func(s-1,t);
        return way; 
    }
*/
int** dp;
string s,t;
int subSequences(int i,int j){
    if(i<j)
        return 0;
    if(j < 0)
        return 1; 
    if(dp[i][j] != -1)
        return dp[i][j];
    int ways = 0;
    if(s[i] == t[j])
        ways += subSequences(i-1,j-1);
    ways += subSequences(i-1,j);
    dp[i][j] = ways;
    return dp[i][j];
}
int main(){
    cin >> s >> t;
    int ls = s.length();
    int lt = t.length();
    dp = new int*[ls];
    for(int i=0;i<ls;i++){
        dp[i] = new int[lt];
        for(int j=0;j<lt;j++)
            dp[i][j] = -1;
    }
    cout << subSequences(ls-1,lt-1) << endl;
    return 0;
}