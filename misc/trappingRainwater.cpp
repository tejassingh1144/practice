#include <bits/stdc++.h>
using namespace std;
//Stacks solution 
// int main(){
//     vector<int> height;
//     int n,h,hf;
//     cin >> n;
//     for(int i=0;i<n;i++){
//         cin  >> h;
//         height.push_back(h); 
//     }
//     stack<int> traps;
//     int waterTrapped = 0;
//     traps.push(0);
//     for(int i=1;i<n;i++){
//         if(height[i] <= height[traps.top()])
//             traps.push(i); 
//         else{
//             hf = 0; 
//             while(height[i] >= height[traps.top()]){
//                 waterTrapped += (i-traps.top()-1)*(height[traps.top()] - hf);
//                 hf= height[traps.top()];
//                 traps.pop();
//                 if(traps.empty())
//                     break;
//             }
//             if(!traps.empty())
//                 waterTrapped += (i-traps.top()-1)*(height[i] - hf);
//             traps.push(i); 
//         }
//     }
//     cout << waterTrapped << endl;
//     return 0;
// }

// dp solution
vector<int> dp;
vector<int> height;
int fillWater(int i,int h){
    if( h < height[i])
        return h;
    if( i == height.size()-1)
        return (h<height[i])?h:height[i];
    if(dp[i] != -1)
        return dp[i];
    dp[i] = fillWater(i+1,h);
    if(dp[i] < height[i])
        dp[i] = height[i];
    return dp[i]; 
}
int main(){
    int n,h;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> h;
        height.push_back(h);
    }
    dp.assign(height.size(),-1);
    dp[height.size()-1] = height[height.size()-1];
    for(int i=0;i<n;i++)
        fillWater(i,height[i]);
    int waterTrapped = 0;
    for(int i=0;i<n;i++)
        waterTrapped += dp[i]-height[i];
    return 0;
}