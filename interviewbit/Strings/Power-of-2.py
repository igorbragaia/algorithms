class Solution:
    # @param A : string
    # @return an integer
    def power(self, A):
        A = int(A)
        return int((A&(A-1) == 0) & (A > 1))