#include <bits/stdc++.h>
using namespace std;
// vector<int> memo;
// vector<int> jumps;
// int jump(int i){
// 	if(i == jumps.size()-1)
// 		return 1;
// 	if(i > jumps.size()-1)
// 		return 0;
// 	if(memo[i] != -1)
// 		return memo[i];
// 	memo[i] = 0;
// 	for(int j = jumps[i] ; j >= 1 ; j--){
// 		if(jump(i+j) == 1){
// 			memo[i] = 1;
// 			break;
// 		}
// 	}
// 	return memo[i];

// }
bool canJump(vector<int>& nums){
	int remJump = nums[0];
	int i=1;
	while(remJump != 0){
		if(i == nums.size())
			return true;	
		remJump--;
		if(nums[i] > remJump)
			remJump = nums[i];
		i++;
	}
	return false;
}
int main(){	
	return 0;
}

