class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;
        int min_even = INT_MAX;

        for (int ans : nums1) {
            if (ans % 2 == 0) {
                min_even = min(min_even, ans);
            }else{
                min_odd = min(min_odd, ans);
            }
        }

        if (min_odd == INT_MAX)
            return true;
        return min_odd < min_even;
    }
};