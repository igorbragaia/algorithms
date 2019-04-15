class Solution:
    def __init__(self):
        self.hashmap = {}
        self.ans = []
        self.flag = None

    def fractionToDecimal(self,A,B):
        if B == 0:
            return ''
        if A == 0:
            return 0

        response = ""
        if (A>0 and B<0) or (A<0 and B>0):
            response += "-"
        A = abs(A)
        B = abs(B)

        level = 1
        while True:
            if A == 0:
                break
            if A in self.hashmap:
                self.flag = level - self.hashmap[A]
                break
            if level > 1:
                self.hashmap[A] = level
                A *= 10
            self.ans.append(int(A/B))
            A=A%B
            level += 1

        if self.flag is not None:
            response += str(self.ans[0]) + "." + "".join([str(x) for x in self.ans[1:-self.flag]]) + "(" + "".join([str(x) for x in self.ans[-self.flag:]]) + ")"
        else:
            response += str(self.ans[0])
            if len(self.ans) > 1:
                response += "." + "".join([str(x) for x in self.ans[1:]])

        return response
