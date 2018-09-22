def latest(a):
    sd = {}
    for i in range(len(a)):
        sdate = a[i][0].split('-')
        date = int(sdate[0])*30+int(sdate[1])
        if date in sd:
            val = sd[date]
            val.append([a[i][1], int(a[i][2]), int(a[i][3])])
            sd[date] = val
            #stud.append(([a[i][1], int(a[i][2]), int(a[i][3])]))
        else:
            sd[date] = [[a[i][1], int(a[i][2]), int(a[i][3])]]
    
    arr = []
    i = 0
    for k, v in sd.items():
        print v
        avg = 0
        for item in v:
            dif = item[2] - item[1]
            if dif < 0:
                dif = 0
            avg += dif
        avg = avg // len(v)
        print "avg : ", avg
        maxx = v[0][2] - v[0][1] - avg
        smax = v[0][0]
        for item in v:
            item[2] = item[2] - item[1] - avg
            if item[2] < 0:
                item[2] = 0
            
            if item[2] > maxx:
                maxx = item[2]
                smax = item[0] 
        arr.append(smax)
        
    return arr
    
    
arr = [["02-12", "rsdfam", "540", "570"], ["04-12", "ram", "540", "560"], ["04-12", "cfram", "540", "550"], ["04-12", "abram", "540", "535"]]
lis = latest(arr)
print lis

        
    