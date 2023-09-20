//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        void leftshift(vector<int>&bin,int &d){
            vector<int>temp;
            for(int i=0;i<d;i++){
                temp.push_back(bin[i]);
            }
            for(int i=0;i<16-d;i++){
                bin[i]=bin[i+d];
            }
            int j=0;
            for(int i=16-d;i<16;i++){
                bin[i]=temp[j++];
            }
        }
        void rightshift(vector<int>&bin2,int &d){
            vector<int>temp;
            for(int i=16-d;i<16;i++){
                temp.push_back(bin2[i]);
            }
            for(int i=15;i>=d;i--){
                bin2[i]=bin2[i-d];
            }
            int j=0;
            for(int i=0;i<d;i++){
                bin2[i]=temp[j++];
            }
        }
        vector <int> rotate (int n, int d){
            vector<int>bin;
            vector<int>ans(2,0);
            while(n){
                int b=n%2;
                bin.push_back(b);
                n/=2;
            }
            for(int i=bin.size();i<16;i++){
                bin.push_back(0);
            }
            reverse(bin.begin(),bin.end());
            vector<int>bin2=bin;
            d=d%16;
            leftshift(bin,d);
            rightshift(bin2,d);
            int a=0;
            for(int i=15;i>=0;i--){
                ans[0]+=(pow(2,i)*bin[15-i]);
            }
            for(int i=15;i>=0;i--){
                ans[1]+=(pow(2,i)*bin2[15-i]);
            }
            //cout<<endl;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends