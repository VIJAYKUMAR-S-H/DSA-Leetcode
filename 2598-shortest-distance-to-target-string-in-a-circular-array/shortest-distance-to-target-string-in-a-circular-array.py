class Solution(object):
    def closestTarget(self, words, target, startIndex):
        n = len(words)
        ans = float('inf')

        for i in range(n):
            if words[i] == target:
                right = abs(i - startIndex)
                left = n - right
                ans = min(ans, min(right, left))

        return ans if ans != float('inf') else -1