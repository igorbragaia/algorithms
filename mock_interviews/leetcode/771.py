class Solution:
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        response = 0
        hashing = {}
        for char in J:
            hashing[char] = 0
        for char in S:
            if char in hashing.keys():
                hashing[char] += 1
        for key,value in hashing.items():
            response += value
        return response
