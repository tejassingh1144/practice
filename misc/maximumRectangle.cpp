#include <bits/stdc++.h>
using namespace std;
int** dpR;
int** dpD;
int** grid;
int m,n;
int rightLongestChain(int i,int j){
    if(j==n)
        return 0;
    if(grid[i][j] == 0){
        dpR[i][j] = 0;
        return dpR[i][j];
    }
    if(dpR[i][j] != -1)
        return dpR[i][j];
    int right;
    right = 1;
    right += rightLongestChain(i,j+1);
    dpR[i][j] = right;
    return right;
}
int downLongestChain(int i,int j){
    if( i==m )
        return 0;
    if(grid[i][j] == 0){
        dpD[i][j] = 0;
        return dpD[i][j];
    }
    if(dpD[i][j] != -1)
        return dpD[i][j];
    int down;
    down = 1;
    down += downLongestChain(i+1,j);
    dpD[i][j] = down;
    return down;
}
int main(){
    cin >> m;
    cin >> n;
    dpR = new int*[m];
    dpD = new int*[m];
    grid = new int*[m];
    for(int i=0;i<m;i++){
        dpR[i] = new int[n];
        dpD[i] = new int[n];
        grid[i] = new int[n];
        for(int j=0;j<n;j++){
            dpR[i][j] = -1;
            dpD[i][j] = -1;
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            downLongestChain(i,j);
            rightLongestChain(i,j);
        }
    }
    int maxArea = 0;
    int area,tmp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            tmp = dpD[i][j];
            int l=0;
            while(l<dpR[i][j]){
                if(dpD[i][j+l] < tmp)
                    tmp = dpD[i][j+l];
                area = (l+1)*tmp;
                if(area > maxArea)
                    maxArea = area;
                l++;
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout << dpR[i][j] << " " << dpD[i][j] << " | ";
    //     }
    //     cout << endl;
    // }
    // cout << dpR[1][2] << " " << dpD[1][2] << endl;
    cout << maxArea << endl;
    cout << endl;
    return 0;
}