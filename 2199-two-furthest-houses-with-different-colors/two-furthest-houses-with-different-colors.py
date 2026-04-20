class Solution(object):
    def maxDistance(self, colors):
        n = len(colors)
        ans = 0

        # compare with first house
        for i in range(n):
            if colors[i] != colors[0]:
                ans = max(ans, i)

        # compare with last house
        for i in range(n):
            if colors[i] != colors[n - 1]:
                ans = max(ans, n - 1 - i)

        return ans