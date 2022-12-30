/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> alphabet;
        int start = 0;
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(alphabet.find(s[i]) == alphabet.end())
            {
                alphabet.insert(s[i]);
            }
            else
            {
                for(; s[start] != s[i]; start++)
                {
                    alphabet.erase(s[start]);
                }
                start++;
            }
            int len = i - start + 1;
            if(len > maxlen) maxlen = len;
        }
        return maxlen;
    }
};
// @lc code=end

