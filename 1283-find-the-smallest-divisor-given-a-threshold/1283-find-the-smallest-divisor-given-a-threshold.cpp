class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1,hi=1e6;
        int ans=0;
        int ct=0;
        while(lo<hi){
            ct++;
            // if(ct==28){
            //     break;
            // }
            long long int mid=(lo+hi)/2;
            
            long long int sum=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0){
                    sum+=nums[i]/mid;
                }
                else{
                    sum+=(nums[i]/mid)+1;
                }
            }
            // cout<<sum<<" ";
            // cout<<mid<<" ";
            if(sum<=threshold){
                hi=mid;
                ans=mid;
            }
            else{
                lo=mid+1;
            }
            
        }
        return ans;
    }
};