class Solution:
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        
        for i in range(len(strs[0])):   # iterate characters of first word
            for s in strs:              # compare with every string
                # check mismatch or out of bound
                if i >= len(s) or s[i] != strs[0][i]:
                    return strs[0][:i]
        
        return strs[0]