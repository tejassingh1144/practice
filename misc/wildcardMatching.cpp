#include <bits/stdc++.h>
using namespace std;
vector<int*> dp;
int match(int i,int j, string s, string p){
    if(dp[i][j] != -1)
        return dp[i][j];
    else if(s[i] == ' '){
        if(p[j] == ' ')
            return 1;
        if( j < p.length()-1){
            if(p[j] == '*')
                dp[i][j] = match(i,j+1,s,p);
            else
                return 0;
        }
    }
    else if(p[j] == ' ') 
        return 0;
    if(s[i] == p[j] || p[j] == '?')
        dp[i][j] = match(i+1,j+1,s,p);
    else if(p[j] == '*'){
        if(p[j+1] == '*')
            dp[i][j]= match(i,j+1,s,p);
        else{
            int toMatch = 0;
            for(int l=j+1;l<p.length();l++){
                if(p[l] == '*')
                    break;
                toMatch++;
            }
            int key = 0;
            int tmpI = i;
            int tmpToMatch = toMatch;
            while(tmpI < s.length()){
                tmpToMatch = toMatch;
                for(int k=tmpI,l=j+1; (s[k] == p[l] || p[l] == '?') && k<s.length() && l<p.length(); k++,l++)
                    tmpToMatch--;
                if(tmpToMatch == 0)
                    break;
                tmpI++;
            }
            if(tmpToMatch == 0){
                if((tmpI+toMatch) >= s.length() && (j+1+toMatch >= p.length()))
                    dp[i][j] = 1;
                else if(tmpI+toMatch >= s.length())
                    dp[i][j] = 0;
                else{
                    dp[i][j] = match(tmpI+toMatch,j+1+toMatch,s,p);
                }
            }else
                dp[i][j] = 0;
        }
    }
    else
        dp[i][j] = 0;
    return dp[i][j];
}
int main(){
    string s,p;
    cin >> s;
    cin >> p;
    if(s.length() == 0){
        if(p.length() == 0)
            return true;
        else{
            for(int i=0;i<p.length();i++){
                if(p[i] != '*')
                    return false;
            }
            return true;
        }
    }
    if(p.length() == 0)
        return false;
    s = s + " ";
    p = p + " ";
    for(int i=0;i<s.length();i++){
        int* arr = new int[p.length()];
        dp.push_back(arr);
        for(int j=0;j<p.length();j++)
            dp[i][j] = -1;
    }
    match(0,0,s,p);
    if(dp[0][0])
        cout << "true";
    else
        cout << "false";
    cout << endl;
    return 0;
}