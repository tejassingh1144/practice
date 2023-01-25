#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int match(int i,int j,string s,string p){
    if(j < 0){
        if(i < 0)
            return 1;
        else 
            return 0;
    }
    if(i < 0){
        if(j%2 == 0)
            return 0;
        for(int tempJ = j; tempJ >= 0; tempJ-=2){
            if(p[tempJ] != '*')
                return 0;
        }
        return 1;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    bool res = true;
    if( p[j] == '*' ){
        int tempI = i;
        res = false;
        while(tempI > -1 && (s[tempI] == p[j-1] || p[j-1] == '.')) {
            res = res || match(tempI,j-1,s,p);
            if(res == true)
                break;
            tempI--;
        }
        if(!res){
            if(j-2 >= 0)
                res = match(i,j-2,s,p);
        }
    }else if( p[j] == '.' )
        res = res && match(i-1,j-1,s,p);
    else{
        if(s[i] == p[j])
            res = res && match(i-1,j-1,s,p);
        else
            res = false;
    }
    dp[i][j] = (res)?1:0;
    return dp[i][j];
}
int main(){
    string s,p;
    cin >> s;
    cin >> p;
    for(int i=0;i<s.length();i++){
        vector<int> dp2;
        dp.push_back(dp2);
        for(int j=0;j<p.length();j++)
            dp[i].push_back(-1);
    }
    match(s.length()-1,p.length()-1,s,p);
    if(dp[s.length()-1][p.length()-1] == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    // for(int i=0;i<s.length();i++){
    //     for(int j=0;j<p.length();j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}
