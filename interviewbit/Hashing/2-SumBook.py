class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return a list of integers
    def twoSum(self, A, B):
        lista = []
        new_hash = {}
        for i in range(len(A)):
            if A[i] not in new_hash:
                new_hash[A[i]] = [i]
            else:
                new_hash[A[i]].append(i)
                
        for i in range(len(A)):
            if B - A[i] in new_hash:
                temp = [x for x in new_hash[B - A[i]] if x > i]
                if len(temp) > 0:
                    lista.append((min(temp) + 1, i +1))
        lista = sorted(lista)
        if lista != []:
            return (lista[0][1], lista[0][0])
        return lista