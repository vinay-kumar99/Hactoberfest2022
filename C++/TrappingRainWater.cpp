class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax[n];
        int rightMax[n];
        int m = 0;
        for(int i = 0; i < n; i++) {
            m = max(m, height[i]);
            leftMax[i] = m;
        }
        m = 0;
        for(int i = n - 1; i >= 0; i--) {
            m = max(m, height[i]);
            rightMax[i] = m;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};