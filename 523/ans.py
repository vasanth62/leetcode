'''
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
Note:
The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
'''
class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if len(nums) < 2:
            return False
        s = 0
        vals = set()
        mods = []

        for i,v in enumerate(nums):
            s += v
            d = s 
            if k:
                d = s % k
                if i >= 1 and d == 0:
                    return True
            mods.append(d)
            if i >= 1 and d in vals:
                return True
            if i >= 1:
                vals.add(mods[i-1])
        if s == 0 and k == 0:
            return True
        return False

print Solution().checkSubarraySum([23,52,2,6,4,7], 6)
print Solution().checkSubarraySum([0,0], 0)
print Solution().checkSubarraySum([0,1,0], 0)
print Solution().checkSubarraySum([0,1,0,0], 0)
print Solution().checkSubarraySum([5,2,4], 5)
