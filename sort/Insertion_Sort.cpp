#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j) {
    if (i == j) {
        return;
    }
    if (arr[i] == arr[j]) {
        return;
    }
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[j] ^ arr[i];
    arr[i] = arr[i] ^ arr[j];
}



void insertSort(vector<int> &vec)
{
    if(vec.empty() || vec.size() < 2)
    {
        return;
    }
    int len = vec.size();
    for(int i = 1;i < len; ++i)
    {
        for(int j = i;j > 0 && vec[j]<vec[j-1];--j)
        {
            swap(vec , j , j - 1);
        }
    }
}