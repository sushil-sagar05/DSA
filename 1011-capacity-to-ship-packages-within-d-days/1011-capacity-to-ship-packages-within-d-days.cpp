class Solution {
public:
    bool DaysRequired(vector<int>& weights,int mid, int days){
        int actualDays=1;
        int currload=0;
        for(int x:weights){
           if(currload + x>mid){
            actualDays++;
            currload=0;
           }
           currload+=x;
        }
        return actualDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            int mid = low+(high-low)/2;
            if(DaysRequired(weights,mid,days)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};