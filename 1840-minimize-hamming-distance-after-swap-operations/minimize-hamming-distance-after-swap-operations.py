class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        from collections import defaultdict, Counter

        parent = list(range(len(source)))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            parent[find(x)] = find(y)

        # Step 1: Build groups
        for a, b in allowedSwaps:
            union(a, b)

        # Step 2: Group indices
        groups = defaultdict(list)
        for i in range(len(source)):
            root = find(i)
            groups[root].append(i)

        # Step 3: Compare inside groups
        ans = 0
        for indices in groups.values():
            count = Counter()

            for i in indices:
                count[source[i]] += 1

            for i in indices:
                if count[target[i]] > 0:
                    count[target[i]] -= 1
                else:
                    ans += 1

        return ans