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




void selectSort(vector<int> &vec)
{
    if(vec.empty() || vec.size() < 2)
    {
        return;
    }
    int len = vec.size();
    for(int i = 0;i<len - 1;++i)
    {
        int minIndex = i;
        for(int j = i + 1;j<len;++j)
        {
            if(vec[j]<vec[minIndex])
            {
                swap(vec[minIndex],vec[j]);
            }
        }
    }
}