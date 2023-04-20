#include <bits/stdc++.h>
using namespace std;

#define ul unsigned long

ul getMax(ul arr[], long n)
{
    ul mx = arr[0];
    for (long i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    return mx;
}

int getDigit(ul n, int exp)
{
    return (n / exp) % 10;
}

ul *countSortHelper(ul data[], long Size, int div)
{
    ul count[10] = {0l};
    ul ans[Size];

    // counting
    for (long i = 0; i < Size; i++)
    {
        count[getDigit(data[i], div)]++;
    }

    // determining index
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // building ans
    for (int i = Size - 1; i >= 0; i--)
    {
        ans[count[getDigit(data[i], div)] - 1] = data[i];
        count[getDigit(data[i], div)]--;
    }

    for (int i = 0; i < Size; i++)
    {
        data[i] = ans[i];
    }

    return data;
}

ul *RadixSort(ul data[], long Size)
{
    int max = getMax(data, Size);
    int i = 1;

    while (max > 0)
    {
        data = countSortHelper(data, Size, i);
        i *= 10;
        max /= 10;
    }

    return data;
}

int main()
{
    // we first sort numbers on the basis of last digit, then second last and so on ...

    ul arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    long n = sizeof(arr) / sizeof(arr[0]);

    ul *ans = RadixSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}