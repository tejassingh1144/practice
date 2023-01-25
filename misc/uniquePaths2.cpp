#include <bits/stdc++.h>
using namespace std;
int** dp;
vector<vector<int>> obstacles;
int minPaths(int i,int j,int m,int n){
    if( i==m && j==n){
        if(obstacles[i][j] == 1)
            dp[i][j] = 0;
        else
            dp[i][j] = 1;
        return dp[i][j];
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int minP = 0;
    if( i+1 <= m){
        if(obstacles[i+1][j] == 0)
            minP += minPaths(i+1,j,m,n);
    }
    if( j+1 <= n){
        if(obstacles[i][j+1] == 0)
            minP += minPaths(i,j+1,m,n);
    }
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