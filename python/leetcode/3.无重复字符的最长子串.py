#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length,w=0,{}

        start=0
        for end in range(len(s)):
            w[s[end]]=w.get(s[end],0)+1
            if(len(w)== end -start+1):
                max_length=max(max_length,end-start+1)
            
            while end-start+1>len(w):
                head=s[start]
                w[head]-=1
                if(w[head]==0):
                    del w[head]
                start+=1
        return max_length
        
# @lc code=end

