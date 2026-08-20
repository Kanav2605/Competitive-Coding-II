class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int worst = nums[0];
        int best = nums[0];
        int ans = nums[0];
        int min_ans = nums[0];
        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            int a = nums[i] + best;
            int b = nums[i];
            int c = nums[i] + worst;
            best = max(a, max(b, c));
            worst = min(a, min(b, c));
            ans = max(ans, best);

            min_ans = min(min_ans, worst);
            sum += nums[i];
        }
        if (ans < 0)
            return ans;
        return max(ans, sum - min_ans);
    }
};