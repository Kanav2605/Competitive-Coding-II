class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int best = nums[0];  //new
        int worst = nums[0];  //old
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int a = nums[i] * best;  //new
            int b = nums[i];  //old
            int c = nums[i] * worst;  //old potnetial 
            best = max(a, max(b, c));
            worst = min(a, min(b, c));
            ans = max(best, ans);
        }
        return ans;
    }
};