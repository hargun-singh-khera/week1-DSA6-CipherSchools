#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return (nums[start] == target ? start : -1);
    }
    else
    {
        // start < end -> Sunny
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // find element in the right section of array
            return firstOccurrence(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // find element in the left section of array
            return firstOccurrence(nums, start, mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // We dont know whether the current element is the first occurrence or not?
            if (mid == 0)
                return mid;
            return firstOccurrence(nums, start, mid - 1, target);
        }
    }
}

int lastOccurrence(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }
    else if (start == end)
    {
        return (nums[start] == target ? start : -1);
    }
    else
    {
        // start < end -> Sunny
        int mid = start + (end - start) / 2;
        if (nums[mid] < target)
        {
            // find element in the right section of array
            return lastOccurrence(nums, mid + 1, end, target);
        }
        else if (nums[mid] > target)
        {
            // find element in the left section of array
            return lastOccurrence(nums, start, mid - 1, target);
        }
        else
        {
            // nums[mid] == target
            // We dont know whether the current element is the first occurrence or not?
            if ((mid == end) || (mid + 1 <= end && nums[mid] < nums[mid + 1]))
                return mid;
            return lastOccurrence(nums, mid + 1, end, target);
        }
    }
}

vector<int> frstAndLastOccurrence(vector<int> &nums, int target)
{
    int first = firstOccurrence(nums, 0, nums.size() - 1, target);
    int last = lastOccurrence(nums, 0, nums.size() - 1, target);
    return {first, last};
}

int main()
{
    vector<int> nums = {1, 2, 2, 2, 2, 2, 3, 4, 5};
    int target = 2;
    vector<int> result = frstAndLastOccurrence(nums, target);
    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;
    return 0;
}