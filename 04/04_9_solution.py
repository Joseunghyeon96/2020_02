## 변수 선언
money , c50000, c10000,c5000,c1000 = 0,0,0,0,0
c500, c100, c50, c10 = 0,0,0,0

## main code
money = int(input("교환할 금액을 입력하세요."))

c50000 = money // 50000
money = money % 50000

c10000 = money // 10000
money = money % 10000

c5000 = money // 5000
money = money % 5000

c1000 = money // 1000
money %= 1000

c500 = money // 500
money = money % 500

c100 = money // 100
money %= 100

c50 = money // 50
money %= 50

c10 = money // 10
money %= 10

print("\n50000원: %d 10000원: %d 5000원: %d 1000원: %d"%(c50000,c10000,c5000,c1000))
print("500원: %d 100원: %d 50원: %d 10원: %d "%(c500,c100,c50,c10))
print("바꾸지 못한 돈 ==> %d원"% money)

