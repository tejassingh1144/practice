#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    if(s[0] == '0'){
        cout << 0 << endl;
        return 0;
    }
    int* dp = new int[s.length()];
    for(int i=0;i<s.length();i++)
        dp[i] = -1;
    //bottom - up 
    int n1,n2,ways;
    ways = 1;
    dp[0] = 1;
    for(int i=1; i<s.length();i++){
        n1 = s[i]-48;
        if(n1 != 0){
            dp[i] = ways;
            n2 = (s[i-1]-48)*10 + n1;
            if(s[i-1] != '0' && n2<=26)
                ways += dp[i-1];
        }
        else{
            if(s[i-1] == '0'){
                cout << 0 << endl;
                return 0;
            }
            ways = dp[i-1];
            n2 = (s[i-1] - 48)*10;
            if(n2 <=26)
                dp[i] = dp[i-1];
            else
                cout << 0 << endl;
                return 0;
        }
    }
    cout << ways << endl;
    cout << endl;
    return 0;
}