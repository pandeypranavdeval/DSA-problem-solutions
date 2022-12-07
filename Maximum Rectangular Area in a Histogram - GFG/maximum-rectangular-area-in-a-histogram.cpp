//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
            vector<long long>nsl;
        vector<long long>nsr;
        stack<pair<long long,long long>>s;// because we are going to deal with pair of index
        int psdind=-1;
        for(int i=0;i<n;i++){
            if(s.empty()){
                nsl.push_back(psdind);
            }
            else{
                if(s.top().first<heights[i]){
                    nsl.push_back(s.top().second);
                }
                else{
                    while(!s.empty()&&s.top().first>=heights[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        nsl.push_back(psdind);
                    }
                    else{
                        nsl.push_back(s.top().second);
                    }
                }
            }
            s.push({heights[i],i});
        }
        psdind=n;
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                nsr.push_back(psdind);
            }
            else{
                if(s.top().first<heights[i]){
                    nsr.push_back(s.top().second);
                }
                else{
                    while(!s.empty()&&s.top().first>=heights[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        nsr.push_back(psdind);
                    }
                    else{
                        nsr.push_back(s.top().second);
                    }
                }
            }
            s.push({heights[i],i});
        }
        reverse(nsr.begin(),nsr.end());
        long long int ans=INT_MIN; 
        for(long long i=0;i<n;i++){
            ans=max(ans,(heights[i]*(nsr[i]-nsl[i]-1)));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends