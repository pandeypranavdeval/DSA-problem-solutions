//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int ind,int i,int j,string &word,vector<vector<char>>&board){
        if(ind==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()){
            return false;// checking bound // basically dfs ka ques hai
        }
        if(word[ind]!=board[i][j]||board[i][j]=='!'){
            return false;
        }
        char kl=board[i][j];
        board[i][j]='!';
        bool d1=solve(ind+1,i-1,j,word,board);
        bool d2=solve(ind+1,i+1,j,word,board);
        bool d3=solve(ind+1,i,j-1,word,board);
        bool d4=solve(ind+1,i,j+1,word,board);
        board[i][j]=kl;
        return (d1||d2||d3||d4);
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends