//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    long long po(int n,int r){
        if(r==0){
            return 1;
        }
        long long p1=po(n,r/2)%1000000007;
        long long p2=(p1*p1)%1000000007;
        if(r&1){
            p2=p2*n;
        }
        return p2%1000000007;
    }
    
    long long power(int n,int r){
        //cout<<n<<" "<<r<<" ";
        long long ans=po(n,r);
        return ans;
    }
};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends