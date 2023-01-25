#include <bits/stdc++.h>
using namespace std;
/*
    example:
        (()()()())
          06040200
*/
vector< unsigned short int> dp;
int chain(int i,string s){
    if(i >= s.length()-1){
        if(i == s.length()-1)
            dp[i] = 0;
        else
            return 0;
    }
    if(dp[i] != -1)
        return dp[i];
    if(s[i] == '('){
        if(s[i+1] == ')'){
            dp[i] = 2;
        }
        else if(s[i+1] == '('){
            if(s[i+chain(i+1,s) + 1] == ')')
                dp[i] = 2 + chain(i+1,s);
            else 
                dp[i] = 0;
        }
        dp[i] += chain(i+dp[i],s);
    }else
        dp[i] = 0;
    return dp[i];
}
int main(){
    string s;
    cin >> s;
    dp.assign(s.length(),-1);
    for(int i=0;i<s.length();i++)
        chain(i,s);
    int max;
    for(int i=0;i<dp.size();i++){
        cout << dp[i] << " ";
        if(dp[i] > max)
            max = dp[i];
    }
    cout << endl << max;
    cout << endl;
    return 0;
}