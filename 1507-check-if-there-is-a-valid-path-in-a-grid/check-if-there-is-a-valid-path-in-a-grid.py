from collections import deque
from typing import List

class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])

        directions = {
            1: [(0,-1), (0,1)],        # LEFT, RIGHT
            2: [(-1,0), (1,0)],        # UP, DOWN
            3: [(0,-1), (1,0)],        # LEFT, DOWN
            4: [(0,1), (1,0)],         # RIGHT, DOWN
            5: [(0,-1), (-1,0)],       # LEFT, UP
            6: [(0,1), (-1,0)]         # RIGHT, UP
        }

        opposite = {
            (0,1): (0,-1),
            (0,-1): (0,1),
            (1,0): (-1,0),
            (-1,0): (1,0)
        }

        queue = deque([(0, 0)])
        visited = set([(0, 0)])

        while queue:
            x, y = queue.popleft()

            # reached destination
            if x == m - 1 and y == n - 1:
                return True

            for dx, dy in directions[grid[x][y]]:
                nx, ny = x + dx, y + dy

                if 0 <= nx < m and 0 <= ny < n:
                    # check both-direction connection
                    if (nx, ny) not in visited and opposite[(dx, dy)] in directions[grid[nx][ny]]:
                        visited.add((nx, ny))
                        queue.append((nx, ny))

        return False