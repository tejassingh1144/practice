#include <bits/stdc++.h>
using namespace std;
int* dp;
int climb(int i,int n){
    if(i==n){
        dp[i] = 1;
        return dp[i];
    }
    if(dp[i] != -1)
        return dp[i];
    dp[i] = climb(i+1,n);
    if(i+2 <= n)
        dp[i]+=  climb(i+2,n);
    return dp[i];
}
int main(){
    int n;
    cin >> n;
    dp = new int[n+1];
    for(int i=0;i<n+1;i++)
        dp[i] = -1;
    climb(0,n);
    cout << dp[0] << endl;
    cout << endl;
    return 0;
}