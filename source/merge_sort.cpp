/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-23 18:59:18
 */
#include "hot.hpp"
void mergeSort(vector<int>& nums, int l, int r) {
    if(l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    vector<int> tmp(r - l + 1, 0);
    int a = l;
    int b = mid + 1;
    int cnt = 0;
    while(a <= mid && b <= r) {
        if(nums[a] < nums[b])
            tmp[cnt++] = nums[a++];
        else
            tmp[cnt++] = nums[b++];
    }
    while(a <= mid)
        tmp[cnt++] = nums[a++];
    while(b <= r)
        tmp[cnt++] = nums[b++]; 
    for(int i = 0; i < r - l + 1; i++) {
        nums[l + i] = tmp[i];
    }
    return;
}
void Solution::sort(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return;
}
