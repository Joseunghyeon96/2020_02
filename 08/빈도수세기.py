import operator


##전역 변수
inStr = ""

countDic = {}
countList = []

if __name__ == "__main__":
    inStr = input("문자열 입력:")

    for ch in inStr:
        if 'ㄱ' <= ch and ch <= '힣':
            if ch in countDic:
                countDic[ch] += 1
            else:
                countDic[ch] =1

    countList = sorted(countDic.items(),key = operator.itemgetter(1), reverse = True)

    print("원문\n%s"% inStr)
    print("------------------------\n문자\t빈도수\n------------------------")
    for i in range(0,len(countList)):
        print(countList[i][0],"\t",countList[i][1])
