//
//  insertionSort (삽입 정렬)
//  배열의 왼쪽에 정렬된 서브배열을 놓고, 오른쪽에서부터 하나의 원소를 꺼내어 왼쪽의 정렬된 서브배열에 위치시킨다.
//  삽입정렬의 시간복잡도는 선택/버블정렬과 마찬가지로 O(N^2)이지만, 실제 사례에서는 삽입정렬이 평균적으로 효율이 좋다고 한다.

#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& arr, int size)
{
    for (auto i=1; i<size; ++i)
    {
        auto curVal = arr[i];
        auto newIdx = -1;
        for (auto j=i-1; j>= 0; --j)
        {
            if (curVal >= arr[j])
                break;
            
            arr[j+1] = arr[j];
            newIdx = j;
        }
        if (newIdx != -1)
            arr[newIdx] = curVal;
    }
}

void Print(vector<int> & arr)
{
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
        
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr = {3, 1, 2, 11, 5, 9, 7, 8, 10, 4};
    Print(arr);
    InsertionSort(arr, (int)arr.size());
    Print(arr);
    return 0;
}
