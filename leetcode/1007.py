class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        maxAns = len(A) + 1
        ans = maxAns
        ans = min(ans, self.solve(A[0], A, B, maxAns))
        ans = min(ans, self.solve(B[0], A, B, maxAns))
        ans = min(ans, self.solve(A[0], B, A, maxAns))
        ans = min(ans, self.solve(B[0], B, A, maxAns))
        if ans == maxAns:
            return -1
        else:
            return ans

    def solve(self, top, A, B, maxAns) -> int:
        count = 0
        for i in range(len(A)):
            if A[i] == top:
                continue
            elif B[i] == top:
                count += 1
            else:
                return maxAns
        return count