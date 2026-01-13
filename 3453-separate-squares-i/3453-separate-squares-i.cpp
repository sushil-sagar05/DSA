class Solution {
public:
    double areaBelow(double mid,vector<vector<int>> &squares){
        double area=0;
        for(auto &square:squares){
            double y=square[1],len=square[2];
            if(mid>=y+len){
                area+=len*len;
            }else if((mid>y)&&(mid<y+len)){
                area+=len*(mid-y);
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double y=0,totalArea=0;
        double yMin=INT_MAX,yMax=INT_MIN;
        for(auto &square:squares){
            double len=square[2];
            totalArea+=len*len;
            yMin=min(yMin,double(square[1]));
            yMax=max(yMax,double(square[1]+len));
        }
        double target=totalArea/2;
        double low=yMin,high=yMax;
        while(low<high){
            if(high-low<pow(10,-5)){
                break;
            }
            double mid=(low+high)/2;
            if(areaBelow(mid,squares)<target){
                low=mid;
            }else{
                y=mid;
                high=mid;
            }
        }
        return y;
    }
};