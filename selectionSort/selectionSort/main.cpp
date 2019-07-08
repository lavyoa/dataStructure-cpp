/*
 selectionSort (선택 정렬)
 배열을 순회하며 가장 작은 값을 찾아 가장 왼쪽부터 위치시키며 자리를 바꿔준다.
 Time Complexity : O(N^2)
*/

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size)
{
    for (int i=0; i<size-1; ++i)
    {
        int minIdx = i;
        for (int j=i+1; j<size; ++j)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        
        if (minIdx == i)
            continue;
        
        int tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
}

void Print(int arr[], int size)
{
    for(int i=0; i<size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {3, 5, 9, 1, 8, 2};
    auto size = (int)(sizeof(arr) / sizeof(arr[0]));
    Print(arr, size);
    SelectionSort(arr, size);
    Print(arr, size);
    
    return 0;
}
