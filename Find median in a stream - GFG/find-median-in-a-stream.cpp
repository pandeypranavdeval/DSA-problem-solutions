//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    void insertHeap(int &num)
    {
        if(maxh.empty()||maxh.top()>num){
            maxh.push(num);
        }
        else{
            minh.push(num);
        }
        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(minh.size()>maxh.size()+1){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxh.size()==minh.size()){
            return (maxh.top()+minh.top())/2.0;
        }
        else{
            if(maxh.size()>minh.size()){
                return maxh.top();
            }
            else{
                return minh.top();
            }
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends