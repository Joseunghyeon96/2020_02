def inputData():
    a = int(input("첫번째 숫자 입력:"))
    b = int(input("첫번째 숫자 입력:"))

    outputData(a,b)

def outputData(x,y):
    print("%d + %d = %d"%(x,y,x+y))
    print("%d - %d = %d"%(x,y,x-y))
    print("%d X %d = %d"%(x,y,x*y))
    print("%d / %d = %d"%(x,y,x/y))

inputData()
