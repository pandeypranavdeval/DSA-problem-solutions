class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int flag1=1,flag2=1,flag3=1,flag4=1;
                if((i-1)>=0&&mat[i][j]<=mat[i-1][j]){
                    flag1=0;
                }
                if((i+1)<=m-1&&mat[i][j]<=mat[i+1][j]){
                    flag2=0;
                }
                if((j-1)>=0&&mat[i][j]<=mat[i][j-1]){
                    flag3=0;
                }
                if((j+1)<=n-1&&mat[i][j]<=mat[i][j+1]){
                    flag4=0;
                }
                if(flag1&&flag2&&flag3&&flag4){
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
            if(v.size()==2){
                break;
            }
        }
        return v;
    }
};