## 一:前言

        在**[\[C/C++\]数据结构 堆的详解](http://t.csdnimg.cn/uVmLy "[C/C++]数据结构 堆的详解")**中,介绍了什么是堆,并且完成了堆的实现和一系列接口,包括向上调整法和向下调整法等,接下来小编介绍一个有点量级的[排序方法](https://so.csdn.net/so/search?q=%E6%8E%92%E5%BA%8F%E6%96%B9%E6%B3%95&spm=1001.2101.3001.7020)\------**堆排序**,时间复杂度为**O(n\*lgn)**

## **二:堆排序详解**

### **2.1 方法介绍**

**1.首先将待排序数组建为大堆,此时堆顶元素就为数组最大值了**

**2.交换堆顶和堆尾元素,此时最大元素就到了堆尾,目前数组最大元素就排好了,现在就假设堆里没有当前这个最大元素了,堆头下面的左右子树仍然是大堆,只需要再将堆顶元素向下调整到合适位置,剩下的n-1个元素还是大堆**

**3.堆头堆尾交换,向下调整,如此反复就可排序**

**ps.排序以升序为例,升序建大堆,降序建小堆**        

* * *

**那么怎么将待排序数组建为大堆呢?**

        假设数组第一个元素是堆,再把第二个元素插入,向上调整为堆,插入第三个元素时,前两个是堆,向上调整,插入第四个元素时,前三个元素是堆,以此反复就可以把所有元素建为堆

```cobol
//建堆	for (int i = 1; i < size; i++)	{		AdjustUp(a, i);	}
```

### 2.2 排序

     假设我们的待排序数组为:

![](https://img-blog.csdnimg.cn/91888da02e084b519c9c4d2d636c5668.png)

  建好大堆以后就可以开始排序了

![](https://img-blog.csdnimg.cn/b51c983348144a68b9ec8486c847ca14.png)![](https://img-blog.csdnimg.cn/9f3696d3528e459c8d99d2aaa4d4f4eb.png)

#### **过程如下:**

**处理最大元素:**

先将堆头元素和堆尾元素交换

![](https://img-blog.csdnimg.cn/efedc601ac7740eb94c4c73c8856cdad.png)

忽略9,将1向下调整到合适位置

![](https://img-blog.csdnimg.cn/a30acecc86634c918cebfc288d19654e.png)

**处理次大元素:**

再次堆头堆尾交换

![](https://img-blog.csdnimg.cn/281c7942c9784d57b95b401af9f2a77b.png)

忽略8和9,将1向下调整到合适位置

![](https://img-blog.csdnimg.cn/0844e0c0be05498c824c8315646470ca.png)

**处理第三大元素:**

堆头堆尾交换

![](https://img-blog.csdnimg.cn/300fc6f390c8404795383d93da3db8bd.png)

忽略6和8和9,将2向下调整到合适位置

![](https://img-blog.csdnimg.cn/11a4e32a08234b9d9d5efe704785360e.png)

**处理第N大元素:**

........................

> 其实[堆排序](https://so.csdn.net/so/search?q=%E5%A0%86%E6%8E%92%E5%BA%8F&spm=1001.2101.3001.7020)的实质就是选择排序,每次可以选出一个最大数,放在堆尾,再去处理前n-1个数

#### 代码实现:

```c++
#include<stdio.h>
typedef int HeapDataType;
 
void swap(HeapDataType* a, HeapDataType* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//大堆
void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (parent - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//大堆
void AdjustDown(HeapDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
 
	while (child<size)
	{
		//找较大的孩子
		if (a[child + 1] > a[child] && child+1<size)
		{
			child = child + 1;
		}
 
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
 
void HeapSort(HeapDataType* a, int size)
{
	//建堆
	for (int i = 1; i < size; i++)
	{
		AdjustUp(a, i);
	}
	//排序:升序
	int end = size - 1;
	while (end>0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);  //end指最后一个元素,同时end的值为前面元素的个数
		end--;
	}
}
```

##### 测试:

```c++
int main()
{
	int a[] = { 9,8,6,5,4,2,2,1 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
```

#####   
![](https://img-blog.csdnimg.cn/0bb1a433abc244d3b3f0f8821046e73a.png)

![](https://img-blog.csdnimg.cn/cc822d218c80493e94a802b33f0c5890.jpeg)