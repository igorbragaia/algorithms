class Solution:
    # @param A : string
    # @return a strings
    def simplifyPath(self, A):
        path = [word for word in A.split('/') if word != '']
        root = []
        for word in path:
            if word == '..':
                if len(root) > 0:
                	root.pop()
            elif word != '.':
                root.append(word)
        return '/' + '/'.join(root)
                