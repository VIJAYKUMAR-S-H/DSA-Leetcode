class Solution:
    def canFinish(self, numCourses, prerequisites):
        graph = {i: [] for i in range(numCourses)}

        # build graph
        for a, b in prerequisites:
            graph[a].append(b)

        visit = [0] * numCourses  # 0=unvisited, 1=visiting, 2=visited

        def dfs(course):
            if visit[course] == 1:
                return False  # cycle detected
            if visit[course] == 2:
                return True   # already checked

            visit[course] = 1  # mark as visiting

            for pre in graph[course]:
                if not dfs(pre):
                    return False

            visit[course] = 2  # mark as done
            return True

        for c in range(numCourses):
            if not dfs(c):
                return False

        return True