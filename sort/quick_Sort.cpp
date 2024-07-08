#include <iostream>
#include <vector>
using namespace std;

// 快速排序的分区函数
int partition(vector<int>& arr, int L, int R) {
    if (L > R) return -1; // 无效情况，不应发生
    if (L == R) return L; // 基础情况：只有一个元素要分区

    int less = L - 1;   // 指向小于基准的区域末尾
    int more = R;       // 指向大于基准的区域开始
    int index = L;      // 遍历数组的指针

    while (index < more) {
        if (arr[index] == arr[R]) {
            index++;    // 跳过与基准相等的元素
        } else if (arr[index] < arr[R]) {
            // 交换 arr[index] 和 arr[less + 1]
            swap(arr[index], arr[++less]);
            index++;    // 交换后移动index指针
        } else {
            // 交换 arr[index] 和 arr[more - 1]
            swap(arr[index], arr[--more]);
            // 不移动index指针，因为arr[more]需要重新评估
        }
    }

    // 最后，交换 arr[R] 和 arr[more]，将基准放在正确的位置上
    swap(arr[R], arr[more]);

    // 返回分区点
    return more;
}

// 快速排序递归函数
void quickSort(vector<int>& arr, int L, int R) {
    if (L >= R) return; // 基础情况：区间内只有一个或者没有元素

    int mid = partition(arr, L, R); // 分区操作，返回基准的位置

    // 递归对左右子数组进行排序
    quickSort(arr, L, mid - 1);
    quickSort(arr, mid + 1, R);
}

// 测试快速排序
int main() {
    vector<int> arr = {3, 2, 5, 1, 4};
    int n = arr.size();

    cout << "原始数组：";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "排序后数组：";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
