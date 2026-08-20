class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        for(int i=0;i<n;i++) {
            sum += nums[i];
        }    
        for (int i = 0; i < n; i++) {
            right = sum - left - nums[i];   //nums[i] == pivot element
            if (right == left) {            // sum == total sum of nums
                return i;                   // left and right are just to separate the two values
            }
            left += nums[i];
        }
        return -1;
    }
};