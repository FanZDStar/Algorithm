// 归并排序

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    if (i == j)
        return;
    if (arr[i] == arr[j])
        return;
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[j] ^ arr[i];
    arr[i] = arr[i] ^ arr[j];
}

void merge(vector<int>& arr, int L, int M, int R) {
    vector<int> help(R - L + 1);
    int p1 = L;
    int p2 = M + 1;
    int i = 0;
    while (p1 <= M && p2 <= R) {
        help[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (i = 0; i < help.size(); i++) {
        arr[L + i] = help[i];
    }
}