class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // this is  o(log(n)) approach to solve using BS uses o(1)
        // that uses prop refer to techdose YTch
        int lo=0;
        int hi=nums.size()-1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2]){
            return nums[nums.size()-1];
        }
        while(lo<=hi){
            int mid=(hi+lo)>>1;
            if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            else if(((mid%2==0)&&nums[mid]==nums[mid+1])||((mid%2==1)&&nums[mid]==nums[mid-1])){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            
        }
        return -1;
    }
};
