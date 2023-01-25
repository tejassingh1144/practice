#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<int> stack;
    vector<int> binVec;
    binVec.assign(s.length(),0);
    for(int i=0;i<s.length();i++){
        if(s[i] == '(')
            stack.push(i);
        else{
            if(!stack.empty()){
                binVec[stack.top()] = 1;
                binVec[i] = 1;
                stack.pop();
            }
        }
    }
    int ans=0,chain=0;
    for(int i=0;i<s.length();i++){
        if(binVec[i] == 1)
            chain++;
        else{
            if(chain > ans)
                ans = chain;
            chain = 0;
        }
    }
    if(chain > ans)
        ans = chain;
    cout << ans << endl;
    return 0;
}