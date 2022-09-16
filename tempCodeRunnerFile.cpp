
    if(n == m)
    {
        return 0;
    }

    int sumStart = 0;
    int sumEnd = 0;

    for (int i = 0; i < m; i++)
    {
        sumStart += arr[i];
    }

    int j = 0;

    while (j < m)
    {
        sumEnd += arr[n-j-1]; 
        j++;
    }
    
    // int diff = abs(sumStart-sumEnd);

    j = 0;

    for (int i = m ; i < n; i++)
    {
        int temp = sumStart + arr[i] - arr[j];
        j++;

        if(temp < sumStart)
        {
            sumStart = temp;
        }
    }
    
    j = n-1;

    for (int i = n-m-1; i >=0 ; i--)
    {
        int temp = sumEnd - arr[j] + arr[i];
        j--;

        if(temp > sumEnd)
        {
            sumEnd = temp;
        }
    }
    
    return abs(sumEnd - sumStart);