inFp= None
inStr = ""

inFp = open("D:/school/temp/data1.txt", 'r')

inStr = inFp.readline()
print(inStr , end = "")

inStr = inFp.readline()
print(inStr, end ="")

inStr = inFp.readline()
print(inStr, end="")

inFp.close()
