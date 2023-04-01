class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self._min=0
        self.w=[]


    def push(self, x: int) -> None:
        if(len(self.w)==0):
            self._min=x
        else:
            self._min=min(self._min,x)
        self.w.append(x)


    def pop(self) -> None:
        if(len(self.w)==0):
            return 
        self.w.pop()
        self._min=0 if len(self.w)==0 else min(self.w)


    def top(self) -> int:
        return self.w[len(self.w)-1]


    def min(self) -> int:
        return self._min



# Your MinStack object will be instantiated and called as such:
minStack = MinStack()

minStack.push(-2)
minStack.push(0)
minStack.push(-3)
print(minStack.min())
minStack.pop()
minStack.top()
minStack.min()
