**C++十种排序方法（快速排序、冒泡排序等等）**

一、[冒泡排序](https://so.csdn.net/so/search?q=%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F&spm=1001.2101.3001.7020)  
1、概念及思路：冒泡排序顾名思义就是大的数沉下去，小的数浮上来，就跟气泡在水底浮上来一样；基本的思路很简单，就是相邻的两个数相比较，如果前面那个数比后面那个数大，则换位置，否则不需要换。以此循环下去（这里指的是从小到大排序，当然也可以从大到小）

2、代码演示：

```cpp
#include<iostream>
using namespace std;
int main() {
	
	int i;
	int arr[10] = { 1,5,2,3,6,8,7,9,4 ,0};//初始化数组
	for (int i = 0; i < 9;i++) {//一共循环10次

		for (int j = 0; j < 9-i; j++) {//执行的次数依次递减
			if (arr[j]>arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;//交换值
			}
		}
	}
		
		
	
	for (int j = 0; j < 10; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}
1234567891011121314151617181920212223242526
```

二、选择排序

1、思路：第一个数依次跟后面9个数比较，找出最小的那个数，放到前面来，在每次两两比较过程中，前面的数若比后面的数大，则交换其下标值，以此循环9次就可以找出10个数中的最小那个。再那第二个数与后面8个数比较找出当中的最小值，以此类推…（这里也是以从小到大为例）

2、代码演示：

```cpp
#include<iostream>
using namespace std;
int main() {
	
	int i;
	int arr[10] ;//初始化数组
	
	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];//输入10要排序的数
	}

	for (int i = 0; i < 10;i++) {//一共循环10次

		for (int j = 0; j < 10; j++) {//找到10个数当中的最小值
			if (arr[j]>arr[i ]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;//交换值
			}
		}
	}
		
		
	
	for (int j = 0; j < 10; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}
1234567891011121314151617181920212223242526272829303132
```

三、插入排序  
1、思路：从第二个数开始与第一个数比较，小的插入到前面，这样就排好前面两个数的位置了，第二次循环，把第三个数与前面两个数依次比较，如果小于第二个数的数，则把它插到第二个数的位置（实际上是交换两个数的值），然后再与第一个数比较，如果小则插到第一个数的位置，这样前面三个数就拍好的位置，以此类推，循环两次可以把前面三个数排好位置，循环9次就可以把10个数的位置顺序排好了。

2、代码演示

```cpp
#include<iostream>
using namespace std;
int main() {
	
	int i;
	int arr[10] ;//初始化数组
	
	for (i = 0; i < 10; i++)
	{
		cin >> arr[i];//输入10要排序的数
	}

	for (int i = 1; i < 10;i++) {//10个数循环9次

		for (int j = i; j >0; j--) {//从第二个数开始与第一个数比较，小的插入到前面
			if (arr[j-1]>arr[j]) {
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;//插到前面来（交换值）
			}
		}
	}
		
		
	
	for (int j = 0; j < 10; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}
1234567891011121314151617181920212223242526272829303132
```

四、希尔排序  
1、思路：首先定义一个gap,从第0个数开始，每隔一个gap取出一个数，将取出来的数进行比较，方法类似插入排序。第二轮从第二个数开始，每隔一个gap取出一个数再进行插入排序。四轮就可以取完（假如数组有15个数）。之后再将gap倍减，进行前面的步骤，直至gap为1.

2、代码演示：

```cpp
#include<iostream>
using namespace std;
int main() {
	
	int i;
	int arr[15] = {9,6,11,3,5,12,8,7,10,15,14,4,1,13,2};//初始化数组
	
	
	
	for (int gap = 4; gap > 0; gap /=2)//定义一个空隙为4，依次减倍
	{
		for (int i = gap; i < 15; i++) {

			for (int j = i; j >gap - 1; j -= gap) {
				//从第0个数开始，每隔4个数进行两两比较
				if (arr[j - gap]>arr[j]) {
					int temp = arr[j - gap];
					arr[j - gap] = arr[j];
					arr[j] = temp;//插到前面来（交换值）
				}
			}
		}
	}
	
		
		
	
	for (int j = 0; j < 15; j++)//打印数组
	{
		cout << arr[j] << endl;
	}
	system("pause");
	return 0;
}
12345678910111213141516171819202122232425262728293031323334
```

五、归并排序  
1、思路：设定一个中间值，把数组分成两组：第一组和第二组（假定两组已排好序），然后定义一个全新的数组，用来存放排好序的数。开始比较两个数组的数的大小，小的放全新数组里面，第一个数组跳到下一个位置，然后跟第二个数组比较，小的继续放全新的数组里面，以此循环下去，去到不符合条件为止（写着程序里了）

2、代码演示：

```cpp
#include<iostream>
using namespace std;
int main() {
	int arr[7] = {1,4,7,8,3,6,9};//初始化数组
	int mid = 7 / 2;//设定一个中间值，把数组分成两组（假定两组已排好序）
	//cout << mid << endl;
	int i=0,j=mid+1, k=0;//设定三个变量，i,j表示两组数组的开始下标
	int temp[7] = {};//定义一个全新的数组，用来存放排好序的数
	while (i <= mid&&j < 7) {//判断i,j的值是否到达临界
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			k++;
			i++;
			

		}
		else {
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid) temp[k++] = arr[i++];//补全另外两种情况，未能同时满足&&
	while (j < 7) temp[k++] = arr[j++];

	for (int k = 0; k < 7; k++)//打印数组
	{
		cout << temp[k] << endl;
	}
	system("pause");
	return 0;
}
1234567891011121314151617181920212223242526272829303132
```

六、快速排序

1、思路：快速排序和归并排序一样，都采用了分至和递归的思想。首先选取一个数字pivot作为中心轴，然后把数组中比pivot大的数放在pivot的右边，比pivot小的事放在pivot的左边。通过第一次排序就可以得到一个有顺序的pivot，再将左子序列或者右子序列重复进行上面的操作，直至左子序列或者右子序列的数字为一。

2、代码演示：

```cpp
#include<iostream>
using namespace std;
void quickSort(int a[], int, int);//原型声明
int main()
{
	int array[] = { 32,64,12,43,69,5,78,10,3,70 },k;
	int len = sizeof(array) / sizeof(int);//数组长度
//cout << len << endl;
	cout << "The orginal arrayare:" << endl;
	for ( k = 0; k<len; k++)
		cout << array[k] << " ";
	cout << endl;

	quickSort(array, 0, len - 1);
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k<len; k++)
		cout << array[k] << " ";//打印数组
	cout << endl;
	system("pause");
	return 0;
}

void quickSort(int s[], int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}
12345678910111213141516171819202122232425262728293031323334353637383940414243
```

七、计数排序  
1、思路：基数排序是一种非比较排序，常用于规模大，数字种类小的排序中，如考试成绩排名、人口年龄等等。思路很简单，但实现起来不容易，首先得定义两个数组，一个用于存放数字种类的个数，另一个用于存放排好序的数组。然后遍历整个数组，记录下数组中各数字的个数存放于第一个数组中，比如1出现一次，就存放于temp\[arr\[1\]\]中，然后再将这些出现的个数一次存放在新的数组中，从而达到排好序。

2、代码演示：

```cpp
#include<iostream>
using namespace std;
int arr[] = {3,2,3,1,5,6,8,6}, temp[1001], result[1001], n;
int main() {
	int len = sizeof(arr)/sizeof(int);//数组长度
	cout << len << endl;
	//cin >> n;
	for (int i = 0; i < len; i++)
	{
		temp[arr[i]]++;
	}
	for (int i = 0; i < len; i++)
	{
		temp[i+1]+=temp[i];
	}
	for (int i = len - 1; i >= 0; i--)
	{
		result[--temp[arr[i]]] = arr[i];
	}
	for (int i = 0; i < len; i++)//打印数组
	{
		
		cout << result[i] << " ";
	}
	system("pause");
	return 0;
}
123456789101112131415161718192021222324252627
```

八、基数排序

1、思路：基数排序和计数排序一样都是非比较排序，思路比较简单，但是代码实现还是有点难度的。假定一组数只有三位数组成，先将个位上的数按顺序好，如个位上是1就放在数组index为1的数组中；将个位上排好序之后，将数从上到下取出来（先进先出）进行十位上的排序，再进行百位上的排序。三轮排序之后就会呈现出一个有序的数组。

2、代码实现

```cpp
#include <iostream>
using namespace std;
//打印数组
void printArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
//求数据的最大位数,决定排序次数

int maxbit(int data[], int n)
{
	int d = 1; //保存最大的位数
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void radixsort(int data[], int n) //基数排序
{
	int d = maxbit(data, n);
	int temp[10];
	int count[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将temp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到temp中
		{
			k = (data[j] / radix) % 10;
			temp[count[k] - 1] = data[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			data[j] = temp[j];
		radix = radix * 10;
	}
}

int main()
{
	int array[10] = { 73,22,93,43,55,14,28,65,39,81 };
	radixsort(array, 10);
	printArray(array, 10);
	system("pause");
	return 0;
}

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566
```

九、堆排序  
1、思路：步骤一：建立大根堆–将n个元素组成的无序序列构建一个大根堆，  
步骤二：交换堆元素–交换堆尾元素和堆首元素，使堆尾元素为最大元素；  
步骤三：重建大根堆–将前n-1个元素组成的无序序列调整为大根堆  
2、代码演示：\`

```cpp
#include<iostream>
using namespace std;
void adjust(int arr[], int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int max = index;
	if (left<len && arr[left] > arr[max]) max = left;
	if (right<len && arr[right] > arr[max]) max = right;  // max是3个数中最大数的下标
	if (max != index)                 // 如果max的值有更新
	{
		swap(arr[max], arr[index]);
		adjust(arr, len, max);       // 递归调整其他不满足堆性质的部分
	}

}
void heapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
	{
		adjust(arr, size, i);
	}
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
		adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
	}
}

int main()
{
	int array[8] = { 6, 0, 15, 4, 21, 5, 7, 10 };
	heapSort(array, 8);
	for (auto it : array)
	{
		cout << it << endl;
	}
	system("pause");
	return 0;
}
12345678910111213141516171819202122232425262728293031323334353637383940
```

十、桶排序  
略