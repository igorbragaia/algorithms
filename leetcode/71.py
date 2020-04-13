class Solution:
    def simplifyPath(self, path: str) -> str:
        parsed_path = path.split("/")
        stack = []
        for str in parsed_path:
            if str == "." or str == "":
                continue
            elif str == "..":
                if len(stack):
                    stack.pop()
            else:
                stack.append(str)
        return "/" + "/".join(stack)