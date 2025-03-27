class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int i=0;
      int j=i+1;
      int crrprofit=0;
      int profit=0;
      while(j<prices.size()){
        if(prices[i]<prices[j]){
            crrprofit = prices[j]-prices[i];
            profit=max(profit,crrprofit);
        }else{
            i++;
        }
         j++;
      }
        
        return profit;
    }
};