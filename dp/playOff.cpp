#include <bits/stdc++.h>
using namespace std;
/*
    101

    for 10 
        ans = [2,3] ;
        dp = [1,1];
    for 100
        ans = [2,3,4,5];
        dp = [1,3];
    for 101
        ans = [4,5,6,7];
        dp = [3,1]; 
    for 1010
        ans = [4,5,6,7,8,9,10,11,12,13] // 12,13,14,15 
        dp = [3,3];
    for 1011
        ans = [8,9,10,11,12,13,14,15] 
        dp = [7,1];
    for 10110
        dp = [7,3]
    for 10111
        dp = [15,1]
*/
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;  
    int l,r;
    l = 0;
    r = 0;
    for(char ch : s){
        if(ch == '1')
            l = l*2 + 1;
        else
            r = r*2 + 1;
    }
    for(int i = l+1; i <= (int)pow(2,n)-r;i++)
        cout << i << " ";
    cout << endl;
    return 0;
}