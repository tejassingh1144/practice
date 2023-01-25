#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> dp2;
vector<int> dp3;
vector<int> amount;
int robNext(int i, int li){
	if(dp[i] != -1)
		return dp[i];
	if( i == li || i == li-1){
		dp[i] = amount[i];
		return dp[i];
	}
	if( i == li-2){
		dp[i] = amount[i] + amount[i+2];
		return dp[i];
	}
	int robN = robNext(i+2,li);
	int robNN = robNext(i+3,li);
	int largerRob = robN > robNN ? robN : robNN;
	dp[i] = largerRob + amount[i];
	return dp[i];
}
int robNext2(int i, int li){
	if(dp2[i] != -1)
		return dp2[i];
	if( i == li || i == li-1){
		dp2[i] = amount[i];
		return dp2[i];
	}
	if( i == li-2){
		dp2[i] = amount[i] + amount[i+2];
		return dp2[i];
	}
	int robN = robNext2(i+2,li);
	int robNN = robNext2(i+3,li);
	int largerRob = robN > robNN ? robN : robNN;
	dp2[i] = largerRob + amount[i];
	return dp2[i];
}
int robNext3(int i, int li){
	if(dp3[i] != -1)
		return dp3[i];
	if( i == li || i == li-1){
		dp3[i] = amount[i];
		return dp3[i];
	}
	if( i == li-2){
		dp3[i] = amount[i] + amount[i+2];
		return dp3[i];
	}
	int robN = robNext3(i+2,li);
	int robNN = robNext3(i+3,li);
	int largerRob = robN > robNN ? robN : robNN;
	dp3[i] = largerRob + amount[i];
	return dp3[i];
}
int retMax(vector<int>& v){
	int max = 0;
	for(auto itr = v.begin(); itr < v.end(); itr++){
		if(*itr > max)
			max = *itr;
	}
	return max;
}
int rob(vector<int>& nums){
	amount = nums;
	dp.assign(nums.size(),-1);
	dp2.assign(nums.size(),-1);
	dp3.assign(nums.size(),-1);
	if(nums.size() < 4)
		return retMax(nums);
	int maxRob = 0;
	if(robNext(0,nums.size()-2) > maxRob)
		maxRob = dp[0];
	if(robNext2(1,nums.size()-1) > maxRob)
		maxRob = dp2[1];
	if(robNext3(2,nums.size()-1) > maxRob)
		maxRob = dp3[2];
	return maxRob;
}
int main(){
	return 0;
}
