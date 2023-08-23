//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    int dx[]={1,-1,0,0 ,1,1,-1,-1};
        int dy[]={0,0,1,-1,-1,1,1,-1};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            int p=0;
	            if(grid[i][j]==word[p]){
	                int x=i;
	                int y=j;
	                p++;
	                for(int k=0;k<8;k++){
	                    int nx=x+dx[k];
	                    int ny=y+dy[k];
	                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==word[p]){
	                        while(p!=word.size()){
	                            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==word[p]){
	                                nx+=dx[k];
	                                ny+=dy[k];
	                                p++;
	                            }
	                            else{
	                                p=1;
	                                break;
	                            }
	                        }
	                    }
	                    if(p==word.size()){
	                       ans.push_back({i,j});
	                       break;
	                    }
	                }
	            }
	        }
	    }
	    //sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends