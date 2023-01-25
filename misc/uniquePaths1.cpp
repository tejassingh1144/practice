#include <bits/stdc++.h>
using namespace std;
int** dp;
int minPaths(int i,int j,int m,int n){
    if( i==m && j==n){
        dp[i][j] = 1;
        return 1;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int minP = 0;
    if( i+1 <= m)
        minP += minPaths(i+1,j,m,n);
    if( j+1 <= n)
        minP += minPaths(i,j+1,m,n);
    dp[i][j] = minP;
    return dp[i][j];
}
int main(){
    int m,n;
    cin >> m;
    cin >> n;
    dp = new int*[m];
    for(int i=0;i<m;i++){
        int* arr = new int[n];
        dp[i] = arr;
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    }
    minPaths(0,0,m-1,n-1);
    cout << dp[0][0] << endl;
    cout << endl;
    return 0;
}