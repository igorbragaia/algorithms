class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        logs = [log.split(":") for log in logs]
        ans = [0 for _ in range(n)]
        stack = [] # [idx, started at, carry]
        for log in logs:
            if log[1] == "start":
                stack.append([int(log[0]), int(log[2]), 0])
            else:
                carry = int(log[2]) - stack[-1][1] + 1
                print(stack)
                ans[stack[-1][0]] += carry - stack[-1][2]
                stack.pop()
                if len(stack):
                    stack[-1][2] += carry
        return ans
                
        