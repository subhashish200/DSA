/**************** Longest Substring Without Repeating Characters LeetCode solutions ******************************/
/************************ Time Complexity & Space Complexity = O(n) **********************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> distinct(256,-1);
        int maxLen = 0,start = -1;
        for(int i=0;i<s.length();i++){
            if(distinct[s[i]] > start){
                start = distinct[s[i]];
            }
            distinct[s[i]] = i;
            maxLen = max(maxLen,i-start);
        }
        return maxLen;
    }
}