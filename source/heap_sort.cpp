/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-24 14:52:41
 */
#include "hot.hpp"
void maxHeap(vector<int>& nums, int i, int len) { // 第i个节点为根节点，是否构成最大堆
    while(i * 2 + 1 <= len) {
        int lson = i * 2 + 1;
        int rson = i * 2 + 2;
        int large;
        if(lson <= len && nums[lson] > nums[i])
            large = lson;
        else
            large = i;
        if(rson <= len && nums[rson] > nums[large])
            large = rson;
        if(large != i) {
            int tmp = nums[i];
            nums[i] = nums[large];
            nums[large] = tmp;
            i = large;
        }
        else
            break;
    }
}
void buildMaxHeap(vector<int>& nums, int len) {
    for(int i = len / 2; i >= 0; i--)
        maxHeap(nums, i, len);
}
void Solution::heapSort(vector<int>& nums) {
    int len = nums.size() - 1;
    buildMaxHeap(nums, len);
    for(int i = len; i > 0; i--) {
        int tmp = nums[i];
        nums[i] = nums[0];
        nums[0] = tmp;
        maxHeap(nums, 0, i - 1);
    }
}