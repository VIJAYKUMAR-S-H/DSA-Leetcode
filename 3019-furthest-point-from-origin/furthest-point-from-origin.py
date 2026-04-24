class Solution(object):
    def furthestDistanceFromOrigin(self, moves):
        L = moves.count('L')
        R = moves.count('R')
        blank = moves.count('_')
        
        # Option 1: move right
        right_pos = R + blank - L
        
        # Option 2: move left
        left_pos = L + blank - R
        
        return max(abs(right_pos), abs(left_pos))