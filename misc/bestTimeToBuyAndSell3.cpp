#include <bits/stdc++.h>
using namespace std;
int* dpF;
int* resF;
int* prices;
int* dpR;
int* resR;
int n;
int findTheLow(int i){
    if(i==0){
        dpF[i] = prices[i];
        resF[i] = 0;
        return prices[i];
    }
    if(dpF[i] != -1)
        return dpF[i];
    int min = prices[i];
    if(findTheLow(i-1) < min)
        min = findTheLow(i-1);
    dpF[i] = min;
    resF[i] = prices[i] - min;
    return dpF[i];
}
int findTheHigh(int i){
    if(i==n-1){
        dpR[i] = prices[i];
        resR[i] = 0;
        return prices[i];
    }
    if(dpR[i] != -1)
        return dpR[i];
    int max = prices[i];
    if(findTheHigh(i+1) > max)
        max = findTheHigh(i+1);
    dpR[i] = max ;
    resR[i] = max - prices[i] ;
    return dpR[i];
}
int main(){
    cin >> n;
    prices = new int[n];
    for(int i=0;i<n;i++)
        cin >> prices[i];
    dpF = new int[n];
    resF = new int[n];
    dpR = new int[n];
    resR = new int[n];
    for(int i=0;i<n;i++){
        dpF[i] = -1;
        dpR[i] =  -1;
    }
    findTheLow(n-1);
    findTheHigh(0);
    // for(int i=0;i<n;i++)
    //     cout << resF[i] << " ";
    // cout << endl;
    // for(int i=0;i<n;i++)
    //     cout << resR[i] << " ";
    // cout << endl;
    int fMax = 0;
    int rMax = 0;
    for(int i=0;i<n;i++){
        if(resF[i] > fMax)
            fMax = resF[i];
        else
            resF[i] = fMax;
    }
    for(int i=n-1;i>=0;i--){
        if(resR[i] > rMax)
            rMax = resR[i];
        else
            resR[i] = rMax;
    }
    int ans = resR[0];
    for(int i=0;i<n-1;i++){
        if(resF[i] + resR[i+1] > ans)
            ans = resF[i] + resR[i+1];
    }
    if(resF[n-1] > ans)
        ans = resF[n-1];
    cout << ans << endl;
    return 0;
}