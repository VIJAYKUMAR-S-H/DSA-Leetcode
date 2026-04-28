class Solution(object):
    def minOperations(self, grid, x):
        nums = []

        # Flatten grid
        for row in grid:
            for num in row:
                nums.append(num)

        # Check possibility
        remainder = nums[0] % x
        for num in nums:
            if num % x != remainder:
                return -1

        # Sort
        nums.sort()

        # Find median
        median = nums[len(nums)//2]

        # Count operations
        operations = 0
        for num in nums:
            operations += abs(num - median) // x

        return operations