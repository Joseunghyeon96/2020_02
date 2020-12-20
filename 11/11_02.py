inFp= None
inStr = ""

inFp = open("D:/school/temp/data1.txt", 'r')

while True:
    inStr = inFp.readline()
    if inStr =="":
        break
    print(inStr, end = "")

inFp.close()
