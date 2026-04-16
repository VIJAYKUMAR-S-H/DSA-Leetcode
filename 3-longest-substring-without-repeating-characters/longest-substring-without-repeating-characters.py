class Solution(object):
    def lengthOfLongestSubstring(self, s):
        char_map = {}
        left = 0
        max_length = 0

        for right in range(len(s)):
            # If character already seen, move left pointer
            if s[right] in char_map:
                left = max(left, char_map[s[right]] + 1)

            # Update latest index of character
            char_map[s[right]] = right

            # Update maximum length
            max_length = max(max_length, right - left + 1)

        return max_length