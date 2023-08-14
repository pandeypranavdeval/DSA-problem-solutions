//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        long long int k=0;
        for(int i=0;i<nums.size();i++){
            k=(k^nums[i]);
        }
        int p=0;
        for(int i=0;i<64;i++){
            if((k&(1<<i))!=0){
                p=i;
                break;
            }
        }
        long long int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<p))!=0){
                a=(a^nums[i]);
            }
            else{
                b=(b^nums[i]);
            }
        }
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends