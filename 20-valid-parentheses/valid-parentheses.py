class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)

            elif len(stack) != 0 and i == ')' and stack[len(stack)-1] == '(':
                stack.pop()

            elif len(stack) != 0 and i == ']' and stack[len(stack)-1] == '[':
                stack.pop()

            elif len(stack) != 0 and i == '}' and stack[len(stack)-1] == '{':
                stack.pop()

            else:
                return False

        return len(stack) == 0
