# 3 names - A, B, C
# add new number to lowest number in the current operation
def charity(arr):
    
    l = len(arr)
    if l == 1:
        return ['A']
    
    if l == 2:
        return ['A', 'B']
    
    charr = [0, 0, 0]
    for i in range(3):
        charr[i] = arr[i]
    
    op = ['A', 'B', 'C']
        
    for i in range(3, l):
        im = 0
        if charr[0] <= charr[1] and charr[0] <= charr[2]:
            im = 0
        elif charr[1] <= charr[0] and charr[1] <= charr[2]:
            im = 1
        else:
            im = 2
        charr[im] += arr[i]
        op.extend(op[im])
        
    return op


arr = [25, 8, 2, 35, 15, 120, 55, 42]
res = charity(arr)
print res
        