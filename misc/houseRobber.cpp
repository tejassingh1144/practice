#include <bits/stdc++.h>
using namespace std;
vector<int> memo;
vector<int>amount;
int frontRob(int i){
	if(i == memo.size()-1 || i==memo.size()-2){
		memo[i] = amount[i];
		return memo[i];
	}	
	if( i == memo.size() - 3){
		memo[i] = amount[i] + amount[i+2];
		return memo[i];
	}
	if(memo[i] != -1)
		return memo[i];
	int robN = frontRob(i+2);
	int robNN = frontRob(i+3);
	int maxRob = (robN<robNN)?robN:robNN;
	memo[i] = maxRob;
	return maxRob;
}

int rob(vector<int>& nums){
	amount = nums;
	memo.assign(amount.size(),-1);
	return (frontRob(0) > frontRob(1))?frontRob(0):frontRob(1);
}
int main(){

	return 0;
}
