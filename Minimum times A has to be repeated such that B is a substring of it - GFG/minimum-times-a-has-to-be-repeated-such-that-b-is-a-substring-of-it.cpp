//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        string temp=A;
        int moves=1;
        while(A.size()<B.size())
        {
            A+=temp;
            moves++;
        }
        if(A.find(B)!=-1)return moves;
        
        A+=temp;
        moves++;
        if(A.find(B)!=-1)return moves;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends