/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-07 15:50:15
 */
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <memory>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s);
    int lengthOfLongestSubstring(string s);
    int maxArea(vector<int>& height);
    vector<int> searchRange(vector<int>& nums, int target);
    void fast_order(vector<int>& nums);
    void sort(vector<int>& nums);
    void heapSort(vector<int>& nums);
};