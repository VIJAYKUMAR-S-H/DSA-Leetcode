/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int left = 0;
    int right = numsSize - 1;
    int pos = numsSize - 1;
    
    int* result = (int*)malloc(numsSize * sizeof(int));
    
    while(left <= right)
    {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];
        
        if(leftSq > rightSq)
        {
            result[pos] = leftSq;
            left++;
        }
        else
        {
            result[pos] = rightSq;
            right--;
        }
        pos--;
    }
    
    *returnSize = numsSize;
    return result;
}
    
