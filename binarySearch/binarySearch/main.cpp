//  binarySearch Implementation
//  Time Complexity : O(logN)

#include <iostream>

using namespace std;

int BSRecursive(int arr[], int x, int start, int end)
{
    if (start > end)
        return -1;
    
    auto mid = start + (end - start) / 2;
    
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x)
        return BSRecursive(arr, x, mid+1, end);
    
    return BSRecursive(arr, x, start, mid-1);
}

// returns index of x if found, -1 if not found
int BSIterative(int arr[], int n, int x)
{
    auto start = 0;
    auto end = n-1;
    
    while (start <= end)
    {
        auto mid = (start + end)/2; // start + (end - start)/2 로 대신할 수 있음 : overflow 피할 수 있다
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
        {
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {1, 3, 4, 5, 6, 9, 10, 13, 15, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << BSIterative(arr, n, 10) << endl;
    cout << BSRecursive(arr, 10, 0, n-1) << endl;
    return 0;
}
