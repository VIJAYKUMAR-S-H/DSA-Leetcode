class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = [[False]*n for _ in range(m)]

        def dfs(r, c, pr, pc):
            # mark current as visited
            visited[r][c] = True

            # 4 directions
            directions = [(1,0), (-1,0), (0,1), (0,-1)]

            for dr, dc in directions:
                nr, nc = r + dr, c + dc

                # check valid and same character
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == grid[r][c]:
                    
                    # skip parent (important)
                    if nr == pr and nc == pc:
                        continue

                    # if already visited → cycle found
                    if visited[nr][nc]:
                        return True

                    # explore further
                    if dfs(nr, nc, r, c):
                        return True

            return False

        # check every cell
        for i in range(m):
            for j in range(n):
                if not visited[i][j]:
                    if dfs(i, j, -1, -1):
                        return True

        return False