/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-07 19:55:05
 */
#include "hot.hpp"
int Solution::lengthOfLongestSubstring(string s) {
    //双指针 否则右边的指针一直右移，遇到重复的左边的指针右移，直到不重复
    unordered_set<char> sets;
    int l = 0;
    int ans = 0;
    for(int r = 0; r < s.size(); r++) {
        if(sets.count(s[r]) <= 0)
            sets.insert(s[r]);
        else {
            sets.insert(s[r]);
            while (s[l] != s[r]) {
                sets.erase(s[l]);
                l++;
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}