#include <bits/stdc++.h>
using namespace std;
/*
	example:babab
			aabbb
			bbabb
			gbbghgbbb
*/
bool isPalindrome(string s,int i,int j){
	bool res = true;
	while(i<j){
		res = res && (s[i] == s[j]);
		i++;
		j--;
	}
	return res;
}
vector<int> dp;
int palindrome(int i,string s){
	if(i == s.length()-1)
		return dp[i] = 1;
	if(dp[i] != -1)
		return dp[i];
	int iSib = palindrome(i+1,s);
	if( s[i] == s[i+iSib+1]  && (i+iSib +1 ) < s.length())
		dp[i] = iSib + 2;
	else{
		while(!isPalindrome(s,i,i+iSib))
			iSib--;	
		dp[i] = iSib + 1;
	}	
	return dp[i];
}
int main(){
	string s;
	cin >> s;
	int l = s.length();
	dp.assign(l,-1);
	palindrome(0,s);
	for(int i=0;i<l;i++)
		cout << dp[i] << " ";
	cout << endl;
	return 0;
}