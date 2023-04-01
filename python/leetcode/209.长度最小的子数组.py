#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        min_length,sum_=sum(nums),0

        start=0
        for end in range(len(nums)):
            sum_+=nums[end]
            # if(sum>=target):
            #     min_length=min(min_length,end-start+1)
            
            while sum_>=target:
                min_length=min(min_length,end-start+1)
                sum_ -=nums[start]
                start+=1
        if min_length==sum(nums):
            return 0
        return min_length
                
# @lc code=end

