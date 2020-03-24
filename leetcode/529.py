class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        timePoints = sorted(timePoints)
        ans = 24*60 + self.parseStrToInt(timePoints[0]) - self.parseStrToInt(timePoints[-1])
        for i in range(1, len(timePoints)):
            ans = min(ans, self.parseStrToInt(timePoints[i]) - self.parseStrToInt(timePoints[i-1]))
        return ans
    
    def parseStrToInt(self, timePoint) -> int:
        [hour, minutes] = timePoint.split(":")
        return int(hour)*60 + int(minutes)
    