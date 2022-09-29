class Solution {
public:
    bool pred(int n,vector<int>&piles,int h){
             long long int a=0;
             for(int i=0;i<piles.size();i++){
                 if(piles[i]%n==0){
                     a+=(piles[i]/n);
                 }
                 else{
                     a+=(piles[i]/n)+1;
                 }
             }
            //cout<<a<<" ";
            return h>=a;   
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=0,hi=1e9;
        while(hi-lo>1){
            long long int mid=(hi+lo)/2;
            if(pred(mid,piles,h)){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        if(pred(hi,piles,h)){
            return hi;
        }
        else{
            return lo;
        }
        return -1;
    }
};