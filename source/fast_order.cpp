/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-23 16:35:24
 */
#include "hot.hpp"
void quick_sort(vector<int>& q, int l, int r) {
    if(l >= r)
        return;
    int i = l, j = r, x = q[l];
    while(i < j) {
        while (i < j && q[j] >= x)
            j--;
        if(i < j) 
            q[i++] = q[j]; // j坑
        while (i < j && q[i] < x)
            i++;
        if(i < j) 
            q[j--] = q[i]; // i坑
    }
    q[i] = x;
    quick_sort(q, l, i - 1);
    quick_sort(q, i + 1, r);
}
void Solution::fast_order(vector<int>& nums) {
    quick_sort(nums, 0, nums.size() - 1);
}