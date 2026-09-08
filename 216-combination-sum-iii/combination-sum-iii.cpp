class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(k, n, 1, current, result);
        return result;
    }

private:
    void dfs(int k,
             int target,
             int start,
             vector<int>& current,
             vector<vector<int>>& result) {

        // If target becomes negative, stop this path
        if (target < 0) {
            return;
        }
        // If we picked exactly k numbers
        if (k == 0) {
            // Only valid if sum is exactly target
            if (target == 0) {
                result.push_back(current);
            }
            return;
        }

        for (int num = start; num <= 9; num++) {
            if (num > target) {
                break;
            }
            current.push_back(num);

            dfs(k - 1, target - num, num + 1, current, result);
            current.pop_back();
        }
    }
};