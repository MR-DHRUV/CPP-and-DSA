from collections import Counter
import math

def min_days_to_teach_song(song: str) -> int:
    # Step 1: Frequency count of each character in the song
    freq = Counter(song)
    
    # Step 2: Find all unique frequencies in the song
    unique_freqs = list(freq.values())
    
    # Step 3: Find the greatest common divisor (GCD) of all frequencies
    gcd = unique_freqs[0]
    maxi = max(unique_freqs)
    for f in unique_freqs[1:]:
        gcd = math.gcd(gcd, f)
    
    # Step 4: The GCD of frequencies gives the minimum number of days
    return 

# Example usage
song = "aaabbcc"
min_days = min_days_to_teach_song(song)
print(f"Minimum number of days to teach the song: {min_days}")


def minimum_k(input1):
    d = {}
    for i in input1:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1

    distinct_frequencies = set(d.values())
    return len(distinct_frequencies)

print(minimum_k("aaabbcc"))