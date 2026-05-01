class Solution(object):
    def trap(self, height):
        l=0
        r=len(height)-1
        lmax=0
        rmax=0
        water=0
        while l<r:
            if height[l]<height[r]:
                lmax=max(lmax,height[l])
                water+=lmax-height[l]
                l+=1
            else:
                rmax=max(rmax,height[r])
                water+=rmax-height[r]
                r-=1
        return water
               
        """
        :type height: List[int]
        :rtype: int
        """
        