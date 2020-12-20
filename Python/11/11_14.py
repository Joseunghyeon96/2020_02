myStr = '파이썬은 재미 있어요. 파이썬만 매일매일 공부하고 싶어요. ^^'
strPosList = []
index = 0

while True:
    try:
        index = myStr.index('파이썬',index)
        strPosList.append(index)
        index = index+1
    except :
         break

print('파이썬 글자위치 ->', strPosList)
