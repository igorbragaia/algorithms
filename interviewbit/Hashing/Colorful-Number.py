class Solution:
    # @param A : integer
    # @return an integer
    def colorful(self, A):
        array = [int(char) for char in str(A)]
        new_array = []
        for i in range(len(array)):
            for j in range(i, len(array)):    
                new_array.append(self.prod(array[i:j+1]))
        return len(new_array) == len(set(new_array))
    
    def prod(self, array):
        ans = 1
        for el in array:
            ans *= el
        return ans