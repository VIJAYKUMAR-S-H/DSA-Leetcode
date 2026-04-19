class Solution(object):
    def addBinary(self, a, b):
        x = int(a, 2)
        y = int(b, 2)

        while y != 0:
            carry = (x & y) << 1
            x = x ^ y
            y = carry

        return bin(x)[2:]
        