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




void bubble_sort(vector<int> &vec)
{
    if(vec.empty() || vec.size() < 2)
    {
        return;
    }
    int len = vec.size();
    for(int i = 0;i < len;++i)
    {
        for(int j = 0;j < len - i;++j)
        {
            if(vec[j+1]<vec[j])
            {
                swap(vec[j+1],vec[j]);
            }
        }
    }
}