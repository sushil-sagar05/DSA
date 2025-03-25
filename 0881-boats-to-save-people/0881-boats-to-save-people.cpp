class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int n=people.size();
       int output=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(people[i]+people[j]==limit){
                output++;
                i++;
                j--;
            }else if (people[i]<=limit){
                    output++;
                    i++;
            }
        }
        return output;
    }
};