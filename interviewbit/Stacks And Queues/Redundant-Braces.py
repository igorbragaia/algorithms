class Solution:
    # @param A : string
    # @return an integer
    def braces(self, A):
        brackets = ['(',')']
        operations = ['/','-','+','*']
        lista = [char for char in A if char in brackets or char in operations]
        new_lista = lista[0]
        for char in lista[1:]:
            if new_lista[-1] not in operations:
                new_lista += char
            elif char in brackets:
                new_lista += char
                
        stack = []
        for char in new_lista:
            if char == ')':
                if len(stack) >= 2 and stack[-1] in operations and stack[-2] == '(':
                    stack.pop()
                    stack.pop()
                else:
                    return True
            else:
                stack.append(char)
        return False
            
            
            