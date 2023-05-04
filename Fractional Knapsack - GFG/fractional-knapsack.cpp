//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        double ans=0;
        vector<pair<double,int>>ratio(n);
        for(int i=0;i<n;i++){
            ratio[i].first=(double)arr[i].value/arr[i].weight;
            ratio[i].second=i;
        }
        sort(ratio.rbegin(),ratio.rend());
        for(int i=0;i<n;i++){
            if(arr[ratio[i].second].weight<=w){
                ans+=arr[ratio[i].second].value;
                w-=arr[ratio[i].second].weight;
            }
            else{
                ans+=ratio[i].first*w;
                w=0;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends