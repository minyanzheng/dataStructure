/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-08-01 14:24:17
 */
#include"hot.hpp"
int binary_bound(int[] nums, int target) {
    if(nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size();
    while(left < right) {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid;
        }
    }
    return -1;
}

int left_bound(int[] nums, int target) {
    int n = nums.length();
    if(n == 0) return -1;
    int left = 0;
    int right = n - 1; // n; 
    while(left <= right) { // <
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            right = mid - 1; // mid
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid - 1; //mid
        }
    }
    if(left == n) return -1;
    return nums[left] == target? left : -1;
}

int right_bound(int[] nums, int target) {
    if(nums.size() == 0)
        return -1;
    int left = 0;
    int right = nums.size(); // -1
    while(left < right) { // <=
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            left = mid + 1; 
        }
        else if(nums[mid] < target) {
            left = mid + 1;
        }
        else if(nums[mid] > target) {
            right = mid; // mid - 1
        }
    } 
    if(left == 0) return -1; 
    return nums[left - 1] == target ? left - 1 : -1;    
}