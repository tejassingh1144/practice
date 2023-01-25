#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dp;
int minSum(int i,int j,int m,int n){
    if(i==m && j==n)
        dp[i][j] = grid[i][j];        
    if(dp[i][j] != -1)
        return dp[i][j];
    if( i+1 <= m)
        dp[i][j] = grid[i][j]+minSum(i+1,j,m,n);
    if( j+1 <= n){
        if(dp[i][j] > grid[i][j]+minSum(i,j+1,m,n) || dp[i][j] == -1)
            dp[i][j] = dp[i][j+1] + grid[i][j];
    }
    return dp[i][j];
}
int main(){
    int m,n,weight;
    cin >> m;
    cin >> n;
    for(int i=0;i<m;i++){
        vector<int> row;
        grid.push_back(row);
        for(int j=0;j<n;j++){
            cin >> weight;
            grid[i].push_back(weight);
        }
    }
    for(int i=0;i<m;i++){
        vector<int> row;
        dp.push_back(row);
        dp[i].assign(n,-1);
    }
    minSum(0,0,m-1,n-1);
    cout << dp[0][0] << endl;
    cout << endl;
    return 0;
}