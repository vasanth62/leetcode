class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = dict()
        maxlen = 0
        i = 0
        while i < len(s):
            c = s[i]
            if c in d:
                i = d[c] + 1
                maxlen = max(maxlen, len(d))
                d.clear()
            else:
                d[c] = i 
                i += 1
            
        return max(maxlen,len(d))

a = Solution()

print a.lengthOfLongestSubstring('dvdf')


