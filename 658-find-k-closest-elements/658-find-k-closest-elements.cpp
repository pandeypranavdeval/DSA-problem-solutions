class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>v;
        int n=arr.size();
        priority_queue<pair<int,int>>q;
        for(int i=0;i<k;i++){
            q.push({abs(arr[i]-x),arr[i]});
        }
        for(int i=k;i<n;i++){
            int diff=abs(arr[i]-x);
            if(diff<q.top().first){
                q.pop();
                q.push({diff,arr[i]});
            }
            else if(diff==q.top().first&&arr[i]<q.top().second){
                q.pop();
                q.push({diff,arr[i]});
            }
        }
        while(!q.empty()){
            int t=q.top().second;
            v.push_back(t);
            q.pop();
        }
        sort(v.begin(),v.end());
        return v;
    }
};