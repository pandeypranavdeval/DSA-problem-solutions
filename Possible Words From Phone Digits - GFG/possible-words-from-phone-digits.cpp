//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int ind,int digits[],int &n,string &op, map<int,string>m,vector<string>&ans){
        if(ind==n){
            ans.push_back(op);
            return;
        }
        string cur=m[digits[ind]];
        for(int i=0;i<cur.size();i++){
            op.push_back(cur[i]);
            solve(ind+1,digits,n,op,m,ans);
            op.pop_back();
        }
        return;
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans;
        map<int,string>m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";m[5]="jkl";m[6]="mno";m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
        if(N==0){
            return ans;
        }
        string op;
        solve(0,a,N,op,m,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends