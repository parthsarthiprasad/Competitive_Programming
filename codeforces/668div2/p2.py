t = int(input())
for i in range(0,t-1):  
    n = int(input())
    lst = [int(x) for x in input().split()]
    suma = 0
    totsum = 0
    for i in range(lst):
        suma = suma + i
        if(suma<0):
            totsum = totsum + abs(suma)
            suma=0
    print(totsum)

print(t)