inStr,outStr = "",""
count,i = 0,0

inStr = input("문자열 입력: ")
count= len(inStr)

for i in range(0,count):
    outStr += inStr[count - (i+1)]

print("내용 거꾸로 출력 => %s" % outStr)
