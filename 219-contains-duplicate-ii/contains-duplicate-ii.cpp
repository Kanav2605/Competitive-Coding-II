class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mpp;
        for(int i=0;i<n;i++){
            int ans = nums[i];
            if (mpp.find(ans) != mpp.end() && i - mpp[ans] <= k ) {
                return true;
            }
            mpp[ans] = i;
        }
        return false;
    }
};