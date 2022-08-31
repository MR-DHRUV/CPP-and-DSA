
class MountainArray
{
public:
    int get(int index);
    int length();
};

int peak(MountainArray &mountainArr)
{
    int start = 0;
    int end = mountainArr.length() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (mountainArr.get(mid) > mountainArr.get(mid + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

int BinarySearch(MountainArray &mountainArr, int start, int end, int target)
{
    if (mountainArr.get(0) <= mountainArr.get(mountainArr.length() - 1))
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }

            else if (mountainArr.get(mid) > target)
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }
    }
    else
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) == target)
            {
                return mid;
            }

            else if (mountainArr.get(mid) > target)
            {
                start = mid + 1;
            }

            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int max = peak(mountainArr);
        int a = BinarySearch(mountainArr, 0, max, target);

        if (a == -1)
        {
            int b = BinarySearch(mountainArr, max+1, mountainArr.length() - 1, target);
            return b;
        }

        else
        {
            return a;
        }
    }
};