#include <bits/stdc++.h>
using namespace std;

class Result
{
public:
    int left;
    int right;
    int sum;
};

int findMax(int a, int b)
{
    return a > b ? a : b;
}

int findMax(int a, int b, int c)
{
    return (findMax(a, b) > c) ? findMax(a, b) : c;
}

Result findMaxCrossingSubArray(int array[], int left, int mid, int right)
{
    Result r;
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;
    int maxLeft, maxRight;

    // Find the maximum subarray sum in the left half
    for (int i = mid; i >= left; i--)
    {
        sum += array[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            maxLeft = i;
        }
    }

    // Find the maximum subarray sum in the right half
    sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += array[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            maxRight = i;
        }
    }

    r.left = maxLeft;
    r.right = maxRight;
    r.sum = leftSum + rightSum;
    return r;
}

Result findMaxSubArray(int array[], int left, int right)
{
    Result r;

    if (left == right)
    {
        r.left = left;
        r.right = right;
        r.sum = array[left];
    }
    else
    {
        int mid = (left + right) / 2;

        Result leftResult = findMaxSubArray(array, left, mid);
        Result rightResult = findMaxSubArray(array, mid + 1, right);
        Result crossResult = findMaxCrossingSubArray(array, left, mid, right);

        // Compare and find the maximum of the three results
        if (leftResult.sum >= rightResult.sum && leftResult.sum >= crossResult.sum)
            return leftResult;
        else if (rightResult.sum >= leftResult.sum && rightResult.sum >= crossResult.sum)
            return rightResult;
        else
            return crossResult;
    }

    return r;
}

int main()
{
    int array[] = {2, -4, 1, 9, -6, 7, -3};
    int n = sizeof(array) / sizeof(array[0]);

    Result maxSubArray = findMaxSubArray(array, 0, n - 1);

    cout << "Maximum Subarray Sum: " << maxSubArray.sum << endl;
    // cout << "Left Index: " << maxSubArray.left << endl;
    // cout << "Right Index: " << maxSubArray.right << endl;
    cout << "Subarray: " << endl;
    for (int i = maxSubArray.left; i <= maxSubArray.right;i++){
        cout << array[i]<<" ";
    }
    cout << endl;

    return 0;
}
