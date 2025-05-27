class Solution {
public:
    bool solve(int index, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (dfs(index + 1, matchsticks, sides, target))
                 return true;
                sides[i] -= matchsticks[index];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int m : matchsticks) {
        sum += m;
        }
        if (sum % 4 != 0)
        return false;
        int side = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); 
        vector<int> sides(4, 0);
        return solve(0, matchsticks, sides, side);
    }
};
