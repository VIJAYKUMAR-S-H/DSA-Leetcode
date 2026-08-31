class Solution(object):
    def twoSum(self, nums, target):
        num_map = {}

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in num_map:
                return [num_map[complement], i]

            num_map[nums[i]] = i


        # class Solution:
        #     def twoSum(self, nums, target):
        #         for i in range(len(nums)):
        #             for j in range(i + 1, len(nums)):
        #                 if nums[i] + nums[j] == target:
        #                     return [i, j]