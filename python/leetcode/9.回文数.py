#
# @lc app=leetcode.cn id=9 lang=python3
#
# [9] 回文数
#

# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x=str(x)
        # for i in range(0,len(str_x)//2+1):
        #     if str_x[i]!=str_x[-i-1]:
        #         return False
        # return True
        return  str_x==str_x[::-1]


            


# @lc code=end

