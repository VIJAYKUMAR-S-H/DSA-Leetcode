class Solution(object):
    def maxProduct(self, n):
        dig=[]
        while n>0:
            dig.append(n%10)
            n=n//10
        dig.sort(reverse=True)
        return dig[0]*dig[1]        
        