#include <bits/stdc++.h>
using namespace std;
bool checkIfPalindrome(string s){
    int i = 0;
    int l = s.length()-1;
    while(i<s.length() && l>=0){
        if(s[i] != s[l])
            break;
        i++;l--;
    }
    if(i>l)
        return true;
    return false;
}
vector<vector<string>> partition(string s) {
    if(s.compare("") == 0){
        vector<vector<string>> v;
        return v;
    }
    if(s.length() == 1){
        vector<vector<string>> v;
        v.push_back({s});
        return v;
    }
    string endChar(1,s[s.length()-1]);
    vector<vector<string>> v = partition(s.substr(0,s.length()-1));
    int l = v.size();
    if(v.size()>0){
        for(int i=v[0].size()-1; i>0 ;i--){
            string tmp = "";
            vector<string> nV;
            int j;
            for(j = v[0].size()-1;j>=i;j--)
                tmp = v[0][j] + tmp;
            for(int k=0;k<=j;k++)
                nV.push_back(v[0][k]);
            cout << tmp + endChar << endl;
            if(checkIfPalindrome(tmp+endChar)){
                nV.push_back(tmp+endChar);
                v.push_back(nV);
            }
        }
    }
    for(int i=0;i<l;i++)
        v[i].push_back(endChar);
    if(checkIfPalindrome(s))
        v.push_back({s});
    return v;
}
int main(){
    string s;
    cin >> s;
    if(checkIfPalindrome(s))
        cout << "hello" << endl;
    return 0;
    vector<vector<string>> v = partition(s);
    cout << endl;
    for(auto i = v.begin(); i!=v.end();i++){
        for(auto j = (*i).begin(); j!= (*i).end();j++)
            cout << *j << " ";
        cout << endl;
    }

}