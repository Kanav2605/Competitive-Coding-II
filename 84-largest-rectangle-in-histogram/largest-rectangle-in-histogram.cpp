class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        // Left smaller element
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty())
                left[i] = -1;
            else
                left[i] = stk.top();

            stk.push(i);
        }

        // Empty end stack checking
        while (!stk.empty()) {
            stk.pop();
        }

        // Right smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty())
                right[i] = n;
            else
                right[i] = stk.top();

            stk.push(i);
        }

        // Area(max) calculation
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currentArea = heights[i] * width;
            maxArea = max(maxArea, currentArea);
        }

        return maxArea;
    }
};
