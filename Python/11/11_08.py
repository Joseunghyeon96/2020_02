
inFp, outFp= None,None
inStr = ""

inFp = open("C:/Windows/win.ini",'r')
outFp = open("D:/school/temp/data3.txt",'w')

inList = inFp.readlines()
for inStr in inList :
    print(inStr)
    outFp.writelines(inStr)

inFp.close()   
outFp.close()
print("---정상적으로 파일에 복사 ---")
