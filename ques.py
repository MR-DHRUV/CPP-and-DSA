def swapdigits(arr):
    n = len(arr)
    unique_pairs = []
    for i in range(n):
        for j in range(i+1,n):
            str1 = str(arr[i])
            str2 = str(arr[j])
            if len(str1)==len(str2):
                if sorted(str1)==sorted(str2):
                    if len([None for i in range(len(str1)) if str1[i]!=str2[i]])==2:
                        unique_pairs.append((arr[i],arr[j],))
    return unique_pairs

arr = [3, 23, 156, 4324, 324, 651, 165, 32]
print(swapdigits(arr))