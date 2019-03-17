def maxDiff(arr):
    if (len(arr) < 1):
        return (-1, -1)
    lindex = len(arr) - 1
    sindex = lindex
    index = (lindex, sindex)
    maxdiff = arr[lindex] - arr[sindex]

    for i in range(lindex - 2, -1, -1):
        if (arr[lindex] - arr[i] > maxdiff):
            maxdiff = arr[lindex] - arr[i]
            sindex = i
            index = (lindex, sindex)
        elif (arr[i] > arr[lindex]):
            lindex = i
            sindex = i 
    return index
    
def main():
    text = raw_input("Enter list of numbers: ")
    arr = map(int, text.split())
    index = maxDiff(arr)
    print index
    
if __name__ == '__main__':
    main()