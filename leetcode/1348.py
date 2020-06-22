class TweetCounts:

    def __init__(self):
        self.data = {}

    def recordTweet(self, tweetName: str, time: int) -> None:
        if tweetName not in self.data:
            self.data[tweetName] = {}
        if time not in self.data[tweetName]:
            self.data[tweetName][time] = 0
        
        self.data[tweetName][time] += 1

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        if freq == "minute":
            delta = 60
        if freq == "hour":
            delta = 60*60
        if freq == "day":
            delta = 60*60*24
        
        ans = []
        i = startTime
        while i <= endTime:
            count = 0
            j = 0
            while j < delta and i <= endTime:
                count += self.data[tweetName].get(i, 0)

                i += 1
                j += 1
                
            ans.append(count)
        
        return ans

# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)