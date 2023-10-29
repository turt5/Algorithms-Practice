#include <iostream>
using namespace std;

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << array[i] << endl;
        }
        else
        {
            cout << array[i] << ", ";
        }
    }
}

void merge(int array[], int left, int mid, int right)
{
    int size1 = (mid - left) + 1;
    int size2 = (right - (mid + 1)) + 1;

    int temp1[size1];
    int temp2[size2];

    for (int i = 0; i < size1; i++)
    {
        temp1[i] = array[i + left];
    }

    for (int i = 0; i < size2; i++)
    {
        temp2[i] = array[i + mid + 1];
    }

    // now compare and sort
    int i = 0;    // temp1
    int j = 0;    // temp2
    int k = left; // array

    while (i < size1 && j < size2)
    {
        if (temp1[i] >= temp2[j])
        {
            array[k] = temp2[j];
            j++;
        }
        else
        {
            array[k] = temp1[i];
            i++;
        }

        k++;
    }

    while (i < size1)
    {
        array[k] = temp1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        array[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int left = 0;
    int right = n - 1;

    cout << endl;
    cout << "Before sorting: " << endl;
    print(array, n);

    cout << endl;
    cout << "After sorting: " << endl;
    mergeSort(array, left, right);
    print(array, n);
}