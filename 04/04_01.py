## 변수 선언
money , c500, c100, c50, c10 = 0,0,0,0,0

## main code
money = int(input("교환할 금액을 입력하세요."))

c500 = money // 500
money = money % 500

c100 = money // 100
money %= 100

c50 = money // 50
money %= 50

c10 = money // 10
money %= 10

print("\n500원 짜리 ==> %d개"% c500)
print("100원 짜리 ==> %d개"% c100)
print("50원 짜리 ==> %d개"% c50)
print("10원 짜리 ==> %d개"% c10)
