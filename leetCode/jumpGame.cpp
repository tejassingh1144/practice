class Solution {
public:
bool canJump(vector<int>& nums){
    if(nums.size() == 1)
        return true;
	int remJump = nums[0];
	int i=1;
	while(remJump != 0){
		if(i == nums.size()-1)
			return true;	
		remJump--;
		if(nums[i] > remJump)
			remJump = nums[i];
		i++;
	}
	return false;
}

};
