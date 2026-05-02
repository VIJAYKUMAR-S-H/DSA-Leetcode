class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        total = numBottles
        empty = numBottles

        while empty >= numExchange:
            new = empty // numExchange
            total += new
            empty = new + (empty % numExchange)

        return total