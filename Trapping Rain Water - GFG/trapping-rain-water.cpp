//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        int left=0,right=n-1;
        long long ans=0;
        int leftmx=0,rightmx=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=leftmx){
                    leftmx=height[left];
                }
                else{
                    ans+=leftmx-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=rightmx){
                    rightmx=height[right];
                }
                else{
                    ans+=rightmx-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends