class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int size = INT_MAX;
        int low = 0;

        for (int high = 0; high < n; high++) {
            sum += nums[high];
            while (sum >= target) {
                sum -= nums[low];
                size = min(size, (high - low + 1));
                low++;
            }
        }
        if (size == INT_MAX)
            size = 0;
        return size;
    }
};