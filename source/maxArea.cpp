/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-07 20:31:20
 */
#include "hot.hpp"
int Solution::maxArea(vector<int>& height) {
    //开始指向左右边界，谁矮谁动。证明：矮的一定不会成为边界
    int l = 0;
    int r = height.size() - 1;
    int ans = 0;
    while(l < r) {
        ans = max(ans, (r - l) * min(height[l],height[r]));
        if(height[l] <= height[r])
            l++;
        else
            r--;
    }
    return ans;
}