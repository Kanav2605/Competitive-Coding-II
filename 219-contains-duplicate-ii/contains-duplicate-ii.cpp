class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n  =nums.size();
        unordered_set<int> mpp;
        
        for (int i = 0; i < n; i++) {
            if (i > k) {
                mpp.erase(nums[i - k - 1]);
            }
            if (mpp.count(nums[i])) {
                return true;
            }
            mpp.insert(nums[i]);
        }
        return false;
    }
};