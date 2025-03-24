class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int max=0;
        int i=0;
        int j=n-1;
        while(i<j){
            int base=j-i;
            int heights=min(height[i],height[j]);
            int area=base*heights;
            if(area>max){
                max=area;
            }
            if(height[i]>height[j]){
                j--;
            }else i++;
        }
        return max;
    }
};