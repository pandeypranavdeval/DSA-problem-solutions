class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // another o(n) approach
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n-1;){
            if(nums[i]==nums[i+1]){
                i+=2;
            }
            else{
                return nums[i];
            }
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        return -1;
    }
};