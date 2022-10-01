#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int> brackets;
        int l = s.length();
        for(int i=0;i<l;i++){
            if('(' == s[i] || '{' == s[i] || '[' == s[i]){
              brackets.push(s[i]);
          }
          else{
              char br,topBr;
            br=s[i];
            if(brackets.empty())
                return false;
            topBr=brackets.top();
              if(!((br==')' && topBr=='(') || (br=='}' && topBr=='{') || (br==']' && topBr=='[')) )
                return false;
            brackets.pop();
          }
        }
        if(brackets.size()==0)
            return true;
        else
            return false;
    }
};

