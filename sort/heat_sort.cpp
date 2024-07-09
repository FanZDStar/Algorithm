#include <iostream>
#include <vector>
using namespace std;

// 定义一个交换函数，使用异或运算实现不借助额外空间的交换
void swap(int &i, int &j)
{
    if (i == j) // 如果两个数相等，交换没有意义，直接返回
        return;
    i = i ^ j;  // i = i ^ j
    j = j ^ i;  // j = j ^ (i ^ j) = i
    i = i ^ j;  // i = (i ^ j) ^ i = j
}

// 向上调整函数，用于插入新元素后维护堆的性质
void AdjustUp(int a[], int child)
{
    int parent = (child - 1) / 2; // 计算子节点的父节点索引

    // 循环直到子节点到达堆顶或者父节点不再小于子节点
    while (child > 0)
    {
        if (a[parent] < a[child])
        {
            swap(a[parent], a[child]); // 如果父节点小于子节点，则交换它们
            child = parent; // 更新子节点索引为父节点索引
            parent = (parent - 1) / 2; // 更新父节点索引为新的父节点的父节点
        }
        else
        {
            break; // 如果父节点大于等于子节点，则调整结束
        }
    }
}

// 向下调整函数，用于删除堆顶元素后维护堆的性质
void AdjustDown(int a[], int size, int parent)
{
    int child = parent * 2 + 1; // 计算父节点的左孩子索引

    // 循环直到父节点无法再下沉或者已经到达堆底
    while (child < size)
    {
        // 找出父节点的较大孩子
        if (child + 1 < size && a[child + 1] > a[child])
        {
            child = child + 1; // 右孩子较大，选择右孩子
        }

        // 如果父节点小于较大的孩子，则交换父节点与较大孩子的位置
        if (a[parent] < a[child])
        {
            swap(a[parent], a[child]);
            parent = child; // 更新父节点索引为较大孩子的索引
            child = parent * 2 + 1; // 更新较大孩子索引为新的父节点的左孩子索引
        }
        else
        {
            break; // 如果父节点大于等于较大孩子，则调整结束
        }
    }
}

// 堆排序函数
void HeapSort(int a[], int size)
{
    // 建立初始堆，从最后一个非叶子节点开始向上调整
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        AdjustDown(a, size, i);
    }

    // 排序过程，每次将堆顶元素（最大值）与未排序部分的末尾元素交换，并重新调整堆
    int end = size - 1;
    while (end > 0)
    {
        swap(a[0], a[end]); // 将堆顶元素（最大值）与末尾元素交换
        AdjustDown(a, end, 0); // 调整剩余元素，重新生成最大堆
        end--; // 缩小堆的范围
    }
}

// 主函数，测试堆排序算法
int main()
{
    int a[] = { 9, 8, 6, 5, 4, 2, 2, 1 }; // 待排序数组
    int size = sizeof(a) / sizeof(a[0]); // 数组大小

    HeapSort(a, size); // 调用堆排序函数对数组进行排序

    // 打印排序后的数组
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0; // 返回成功状态
}
