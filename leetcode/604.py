class StringIterator:

    def __init__(self, compressedString: str):
        self.i = 0
        self.string = compressedString
        self.count = 0
        self.curr_char = compressedString[0]

    def next(self) -> str:
        if not self.hasNext():
            return " "
        
        if self.count == 0:
            self.getNextData()

        self.count -= 1
        return self.curr_char
    
    def getNextData(self):
        self.curr_char = self.string[self.i]
        self.i += 1
        n_str = ""
        while self.i < len(self.string) and self.string[self.i].isdigit():
            n_str += self.string[self.i]
            self.i += 1
        self.count = int(n_str)

    def hasNext(self) -> bool:
        if self.count == 0 and self.i < len(self.string):
            self.getNextData()

        return self.count > 0


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()