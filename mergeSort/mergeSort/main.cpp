/*
 mergeSort (합병정렬) : 주어진 배열을 반 씩 쪼개어 정렬 후 원배열에 합치는 방식을 재귀적으로 구현하는 정렬 방식.
 공간복잡도 : O(N)
 시간복잡도 : O(NlogN)
*/

#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int> &arr, int size)
{
    if (size <= 1)
        return;
    
    auto half = size / 2;
    vector<int> split_one(arr.begin(), arr.begin() + half);
    vector<int> split_two(arr.begin() + half, arr.end());
    
    auto one_length = (int)split_one.size();
    auto two_length = (int)split_two.size();
    
    mergeSort(split_one, one_length);
    mergeSort(split_two, two_length);
    
    int idx_one = 0, idx_two = 0, idx_arr = 0;
    
    // merge two splited arrays into one previous array
    while (idx_one < one_length && idx_two < two_length)
    {
        if (split_one[idx_one] <= split_two[idx_two])
        {
            arr[idx_arr] = split_one[idx_one];
            idx_one++;
            idx_arr++;
        }
        else
        {
            arr[idx_arr] = split_two[idx_two];
            idx_two++;
            idx_arr++;
        }
    }
    
    while (idx_one < one_length)
    {
        arr[idx_arr] = split_one[idx_one];
        idx_one++;
        idx_arr++;
    }
    
    while (idx_two < two_length)
    {
        arr[idx_arr] = split_two[idx_two];
        idx_two++;
        idx_arr++;
    }
}

void Print(vector<int> & arr)
{
    cout << "printing array ..." << endl;
    for (auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> arr = {3, 1, 2, 11, 5, 9, 7, 8, 10, 4, 6};
    Print(arr);
    mergeSort(arr, (int)arr.size());
    Print(arr);
    return 0;
}
