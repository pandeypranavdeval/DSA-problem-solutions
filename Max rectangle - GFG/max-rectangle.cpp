//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int Mah(vector<int>&heights){
        stack<int>st;
        int maxA=0;
        int n=heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else{
                    width=i-st.top()-1;
                }
                maxA=max(maxA,(width*height));
            }
            st.push(i);
        }
        return maxA;
    }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        int ans=0;
        vector<int>v;
        for(int j=0;j<m;j++){
            v.push_back(matrix[0][j]);
        }
        
        ans+=Mah(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v[j]=0;
                }
                else{
                    v[j]+=matrix[i][j];
                }
            }
            ans=max(ans,Mah(v));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends