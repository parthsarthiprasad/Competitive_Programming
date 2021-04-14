import string
def confidential(mn):
    sd = {}
    sn = [0]*len(mn)
    for i in range(len(string.digits)):
        sd[string.digits[i]] = string.digits[i-1]
    for j in range(len(mn)):
        sn[j] = sd[mn[j]]
    return(sn)

confidential("1234567")