#include <bits/stdc++.h>
using namespace std;
/*
    example: n = 1
                ()
             n = 2 
                ()() (())
             n = 3
                (()()) ((())) ()()() ()(()) (())()
             n = 4
                ((()())) (((()))) (()()()) (()(())) ((())()) ()(()()) ()((())) ()()()() ()()(()) (())()()
*/
void addCombination(vector<string>& v,string s){
   int key = 1;
   for(auto itr = v.begin();itr < v.end();itr++){
      if((*itr).compare(s) == 0)
         key = 0 ;
   }
   if(key == 1)
      v.push_back(s);   
}
int main(){
   vector<vector<string>> brs;
   vector<string> n1;
   n1.push_back("()");
   brs.push_back(n1);
   int n;
   cin >> n;
   for(int i = 1;i<n;i++){
      vector<string> combinations;
      brs.push_back(combinations);
      for(int j = 0;j<brs[i-1].size();j++){
         string s = "(" + brs[i-1][j] + ")";
         brs[i].push_back(s);
      }
      for(int j=0;j<brs.size()-1;j++){
         for(int k=0;k<brs[j].size();k++){
            for(int l=0;l<brs[i-1-j].size();l++){
               string s = brs[j][k] + brs[i-1-j][l];
               addCombination(brs[i],s);
            }
         }
      }
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<brs[i].size();j++)
         cout << brs[i][j] << " ";
      cout << endl;
   }
   cout << endl;
   return 0;
}