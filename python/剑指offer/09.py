class CQueue:

    def __init__(self):
        self.w=[]

    def appendTail(self, value: int) -> None:
        self.w.append(value)



    def deleteHead(self) -> int:
        if(self.w==0):
            return -1
        return self.w.pop(0)



# Your CQueue object will be instantiated and called as such:
obj = CQueue()
obj.appendTail("CQueue")
param_2 = obj.deleteHead()
print(param_2)