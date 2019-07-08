/*
 bubble sort(버블 정렬)
 배열을 순회하며 현재 원소가 그 오른쪽의 원소보다 크면 위치를 바꾼다.
 Time Complexity : O(N^2)
*/

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
    for (int j=size-1; j>=1; --j)
    {
        auto swapped = false;
        for (int i=0; i<j; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                auto tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Print(int arr[], int size)
{
    for (int i=0; i<size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {3, 5, 1, 9, 8, 2, 4, 10, 6, 7};
    auto size = (int)(sizeof(arr) / sizeof(arr[0]));
    Print(arr, size);
    BubbleSort(arr, size);
    Print(arr, size);
    return 0;
}
