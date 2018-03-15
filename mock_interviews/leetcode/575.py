class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        hashing = {}
        for candy in candies:
            if candy in hashing.keys():
                hashing[candy] += 1
            else:
                hashing[candy] = 0
        if len(hashing) > len(candies)/2:
            return int(len(candies)/2)
        else:
            return len(hashing)
