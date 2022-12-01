//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
        vector<int>v1;
        vector<int>v2;
    	for(int i=0;i<n/2;i++){
    	    v1.push_back(arr[i]);
    	}
    	for(int i=n/2;i<n;i++){
    	    v2.push_back(arr[i]);
    	}
    	reverse(v2.begin(),v2.end());
    	int p=0;
    	for(int i=0;i<v2.size();i++){
    	    arr[p]=v2[i];
    	    p+=2;
    	}
    	p=1;
    	for(int i=0;i<v1.size();i++){
    	    arr[p]=v1[i];
    	    p+=2;
    	}
    }
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends