class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<int>> prefix(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                prefix[i][j]=(i>0 ? prefix[i-1][j]:0)+
                                (j>0 ? prefix[i][j-1]:0)
                                -((i>0 &&j>0)? prefix[i-1][j-1]:0)
                                +mat[i][j];
            }
        }
        auto sumSquare=[&](int i,int j,int r2,int c2){
            int sum=prefix[r2][c2];
            if(i>0)
            sum-=prefix[i-1][c2];
            if(j>0)
            sum-=prefix[r2][j-1];
            if(i>0&&j>0)
            sum+=prefix[i-1][j-1];
            return sum;
        };
        auto check=[&](int side){
            for(int i=0;i+side-1<rows;i++){
                for(int j=0;j+side-1<cols;j++){
                    int r2=i+side-1;
                    int c2=j+side-1;
                    if(sumSquare(i,j,r2,c2)<=threshold){
                        return true;
                    }
                }
            }
            return false;
        };
        int low=1;
        int high=min(rows,cols);
        int result=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid)){
                result=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return result;
    }
};