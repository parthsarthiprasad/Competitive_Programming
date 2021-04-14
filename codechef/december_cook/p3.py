t = int(input())
while(t>0):
    t-=1
    x = str(input())
    var = 0
    for element in x:
        if(element=='0'):
            var=var+1
        else:
            var= var-1
    var = abs(var)
    if(len(x)%2==1):
        print("-1")
    else:
        print(int(var/2))