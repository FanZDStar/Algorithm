#include <iostream>
#include <vector>

using namespace std;

// 合并两个有序数组
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int p1 = left;
    int p2 = mid + 1;
    int i = 0;
    while (p1 <= mid && p2 <= right) {
        temp[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid) {
        temp[i++] = arr[p1++];
    }
    while (p2 <= right) {
        temp[i++] = arr[p2++];
    }
    for (i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}

// 归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

