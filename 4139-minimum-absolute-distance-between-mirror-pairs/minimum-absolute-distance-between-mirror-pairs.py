class Solution(object):
    def minMirrorPairDistance(self, nums):
        def reverse_num(x):
            return int(str(x)[::-1])

        hashmap = {}   # stores reverse(nums[i]) -> index i
        min_dist = float('inf')

        for j in range(len(nums)):
            num = nums[j]

            # check if current number matches any previous reversed number
            if num in hashmap:
                min_dist = min(min_dist, j - hashmap[num])

            # store reverse of current number for future matches
            rev = reverse_num(num)
            hashmap[rev] = j

        return min_dist if min_dist != float('inf') else -1