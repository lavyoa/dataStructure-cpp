/*
  quick Sort (퀵소트)
 피벗을 기준으로 배열을 나눈 후 나눠진 두 부분의 배열을 재귀적으로 나누어 정렬하는 방식.
 시간복잡도 : best/average 기준 O(NlogN), worst 기준 O(N^2) 이다.
 파티션을 할 때 밸런스파티션이 되면 (나눠진 모든 두 부분의 크기가 원 배열의 절반에 최대한 가까울수록) 효율이 좋고,
 반대로 이미 정렬된 배열인 경우 파티션이 배열의 중간즈음이 아니라 거의 끝 쪽에서 이뤄지기 때문에 효율이 나쁘다.
 이런 경우를 피하기 위해 RandomizedPartion 방식을 사용한다. 이는 피벗을 배열의 원소 중에서 무작위로 뽑는 방식이다.
Ranomized Partition방식을 통해 worst케이스를 대부분 피할 수 있기 때문에 효율이 좋은 알고리즘이다.
 
 Randomized Partition을 통해 피벗을 랜덤으로 고른 후, 이 원소를 배열의 제일 끝으로 보내 준 후 원래 방식대로 partition을 진행하면 된다.
 */


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
