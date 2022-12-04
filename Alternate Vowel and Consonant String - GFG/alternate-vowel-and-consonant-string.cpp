//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int n){
        map<char,int>m1,m2;
        int ct1=0,ct2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                m1[s[i]]++;
                ct1++;
            }
            else{
                m2[s[i]]++;
                ct2++;
            }
        }
        //cout<<ct1<<ct2<<" ";
        if(abs(ct1-ct2)==0||abs(ct1-ct2)==1){
            if(ct1>=ct2){
                int p1=0;
                for(auto &it:m1){
                    for(int i=0;i<it.second;i++){
                        s[p1]=it.first;
                        p1+=2;
                    }
                }
                int p2=1;
                for(auto &it:m2){
                    for(int i=0;i<it.second;i++){
                        s[p2]=it.first;
                        p2+=2;
                    }
                }
            }
            else{
                int p1=1;
                for(auto &it:m1){
                    for(int i=0;i<it.second;i++){
                        s[p1]=it.first;
                        p1+=2;
                    }
                }
                int p2=0;
                for(auto &it:m2){
                    for(int i=0;i<it.second;i++){
                        s[p2]=it.first;
                        p2+=2;
                    }
                }
            }
            return s;
        }
        else{
           s="-1"; 
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends