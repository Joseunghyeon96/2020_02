## 변수
parking = []
top, carName, outCar = 0, "A",""
select = 9

## 메인 코드
while(select!=3):
    select = int(input("<1> 자동차 넣기 <2> 자동차 빼기 <3> 끝: "))

    if select == 1:
        if top >= 5:
            print("주차장이 꽉 찼습니다.")
        else:
            parking.append(carName)
            print("%s 자동차 들어감. 주차장 상태 => %s" %(parking[top],parking))
            top += 1
            carName = chr(ord(carName)+1)

    elif select == 2:
        if(top<=0):
            print("빠져나갈 차가 없습니다.")
        else:
            outCar = parking.pop()
            print("%s 자동차 나감. 주차장 상태 => %s"%(outCar,paring))
            top-=1
            carName = chr(ord(carName)-1)
    elif select ==3:
        break
    else :
        print("잘못 입력했습니다. 다시 입력해주세요.")

print("현재 주차장에 %d 대가 있음"%top)
print("프로그램을 종료합니다.")
