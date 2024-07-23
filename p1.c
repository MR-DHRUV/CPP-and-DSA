def count_commas(N):
    str_N = str(N)
    length = len(str_N)
    total_commas = 0
    
    if length <= 3:
        return 0
    
    for digits in range(4, length + 1):
        start = 10(digits - 1)
        end = min(N, 10digits - 1)
        num_count = end - start + 1
        commas_per_num = (digits - 1) // 3
        total_commas += num_count * commas_per_num
    
    return total_commas

TRY THIS