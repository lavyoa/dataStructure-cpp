//
//  quick Sort (퀵소트)
//

#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &arr, int startIdx, int endIdx)
{
    auto pivot = arr[endIdx];
    auto partitionIdx = startIdx;
    for (auto i=startIdx; i<endIdx; ++i)
    {
        if (arr[i] <= pivot)
        {
            // swap
            auto tmp = arr[i];
            arr[i] = arr[partitionIdx];
            arr[partitionIdx] = tmp;
            partitionIdx++;
        }
    }
    auto tmp = arr[partitionIdx];
    arr[partitionIdx]  = arr[endIdx];
    arr[endIdx] = tmp;
    
    return partitionIdx;
}

void QuickSort(vector<int> &arr, int startIdx, int endIdx)
{
    if (startIdx >= endIdx)
        return;
    
    auto pivotIdx = Partition(arr, startIdx, endIdx);
    QuickSort(arr, startIdx, pivotIdx-1);
    QuickSort(arr, pivotIdx+1, endIdx);
}

void Print(vector<int> &arr)
{
    cout << "Printing ... " << endl;
    for (auto n : arr)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr = {3, 5, 8, 1, 7, 9, 2, 4, 6};
    Print(arr);
    QuickSort(arr, 0, (int)arr.size()-1);
    Print(arr);
    return 0;
}
