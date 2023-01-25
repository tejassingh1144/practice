#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int maxSum,rightMaxSum;
    maxSum = arr[0];
    rightMaxSum = arr[0];
    for(int i=1;i<n;i++){
        if(rightMaxSum >= 0)
            rightMaxSum += arr[i];
        else
            rightMaxSum = arr[i];
        if(rightMaxSum > maxSum)
            maxSum = rightMaxSum; 
    } 
    cout << maxSum << endl;
    return 0;
}