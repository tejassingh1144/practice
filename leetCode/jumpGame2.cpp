class Solution {
public:
vector<int> memo;
vector<int> jumps;
int revJump(int i){
    if( i >= jumps.size()-1 ){
        return 0;
    }
    if(memo[i] != -1 )
        return memo[i];
    int minJump = jumps.size();
    int jumpsTook;
    for(int j = 1 ; j <= jumps[i] ; j++){
        jumpsTook = revJump(i+j);
        if(jumpsTook < minJump)
            minJump = jumpsTook;
    }
    memo[i] = minJump + 1;
    return memo[i];
}
int jump(vector<int>& nums){
    jumps = nums;
    memo.assign(nums.size(),-1);
    return revJump(0);
}
};
