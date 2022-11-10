//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long x) {
        queue<long long>q;
        for(int i=0;i<=9;i++){
            q.push(i);
        }
        long long ans=0;
        while(!q.empty()){
            long num=q.front();
            q.pop();
            if(num>x){
                continue;
            }
            ans=num>ans?num:ans;
            long lastdigit=num%10;
            if(lastdigit!=0){
                long first=num*10+(lastdigit-1);
                q.push(first);
            }
            if(lastdigit!=9){
                long second=num*10+(lastdigit+1);
                q.push(second);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends