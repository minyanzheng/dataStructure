/*
 * @Author: zhengminyan@tetras.ai
 * @Date: 2022-07-07 15:31:51
 */
#include "hot.hpp"
string Solution::longestPalindrome(string s) {
    //dp[i][j]  i,j是否是回文字符串，长的可由短的得到。
    string ans = "";
    int size = s.size();
    if(size == 1) {
        return s;
    }
    if(size == 2) {
        if(s[0] == s[1])
            return s;
        return s.substr(0, 1);
    }
    ans += s[0];
    bool dp[size][size];
    int length = 0;
    for(int i = 0; i < size; i++)
        dp[i][i] = true;
    for(int L = 2; L <= size; L++) {
        for(int i = 0; i <= size - L; i++) {
            if(L == 2)
                dp[i][i + L - 1] = (s[i] == s[i + L - 1]);
            else
                dp[i][i + L - 1] = dp[i + 1][i + L - 2] && (s[i] == s[i + L - 1]);
            if(dp[i][i + L - 1] && L > length) {
                length = L;
                ans = s.substr(i, L);
            }
        }
    }
    return ans;
}
