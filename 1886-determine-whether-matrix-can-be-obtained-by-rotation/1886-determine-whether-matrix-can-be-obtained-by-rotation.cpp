class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=target.size();
        for(int cnt=1;cnt<=4;cnt++){
            bool isPossible=true;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]!=target[i][j]){
                        isPossible=false;
                        break;
                    }
                }
            
            if(!isPossible) break;
            }
            if(isPossible){
                return true;
            }else{
            rotate(mat);
            }
        }
        return false;
    }
};