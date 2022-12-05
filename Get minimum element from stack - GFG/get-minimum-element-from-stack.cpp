//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minele;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty()){
            return -1;
        }
        return minele;
       }
       
       /*returns poped element from stack*/
       int pop(){
           int x=-1;
           //Write your code here
           if(s.empty()){
            return -1;
        }
        else{
            if(s.top()>=minele){
                x=s.top();
                s.pop();
            }
            else{
                x=minele;
                minele=(2*1LL*minele)-s.top();
                s.pop();
            }
        }
        return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
            s.push(x);
            minele=x;
        }
        else{
            if(x>=minele){
                s.push(x);
            }
            else{
                s.push((2*1LL*x)-minele);
                minele=x;
            }
        }
        return;
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends