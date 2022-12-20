//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

#define LL long long int
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
                                                int i=0,j=0;
                                                list<LL>l;
                                                vector<LL>ans;
                                                while(j<n){
                                                    if(arr[j]<0){
                                                        l.push_back(arr[j]);
                                                    }
                                                    if(j-i+1==k){
                                                        ans.push_back(l.front());
                                                        if(l.front()==arr[i]){
                                                            l.pop_front();
                                                        }
                                                        i++;
                                                    }
                                                    j++;
                                                }
                                                return ans;
 }