### 栈

[TOC]

C++的STL已经将栈的操作都封装成了函数，我们只需要引进`#include<stack>`头文件即可使用。

#### 栈的基本操作

##### 1.初始化

我们可以直接使用`stack<int> s;`来创建一个空的 stack 对象。

##### 2.判断是否为空栈

使用empty()函数来判断栈是否为空。`bool empty()` 

##### 3.入栈

使用push()函数来完成入栈操作。

![push()函数详解](https://img-blog.csdnimg.cn/2020041923302690.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNTc1NTA3,size_16,color_FFFFFF,t_70)

##### 4.出栈

使用pop()函数实现出栈

![pop()函数详解](https://img-blog.csdnimg.cn/20200419233247129.png)

##### 5.返回栈顶元素

使用top()函数返回栈顶元素

![top()函数详解](https://img-blog.csdnimg.cn/20200419233407595.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNTc1NTA3,size_16,color_FFFFFF,t_70)

###### 6.返回栈中元素的数目

使用size()函数返回栈中元素的数目

### String类型

```C++
#include<iostream>
#include<string>
using namespace std;
 
int main(){
	
	//string对象的初始化方法 
	string str1 = "Hello";  //string对象的初始化1 
	string str2("World");	//string对象的初始化2 
	string str3(6,'a');		//将6个重复的a赋值给str3
	/*string str = 'a'; string str('a'); string str = 4;  
	注意这是错误的初始化方法*/
	
	cout<<str1<<endl<<str2<<endl<<str3<<endl;
	
	//可以将字符赋值给string对象，例如：
	string s;
	s = 'a'; 
	cout<<s<<endl;
	 
	string str4;
	int len,len1;
	//复制str1到str4
	str4 = str1;
	cout<<"复制的结果为："<<str4<<endl; 
	
	//用assign()成员函数复制
	str4.assign(str1);
	cout<<"使用assign成员函数复制的结果为:"<<str4<<endl; 
	
	//用assign()成员函数部分复制
	str4.assign(str1,1,3); //从str1中下标为1的字符开始复制3个字符 
	cout<<"使用assign成员函数部分复制的结果为:"<<str4<<endl;
	
	//使用 + 连接str1和str2，并将结果存在str4中 
	str4 = str1 + str2;
	cout<<"用 + 连接的结果为："<<str4<<endl;
	
	//使用成员函数append()连接 str1和str2
	str1.append(str2);
	cout<<"使用成员函数append连接的结果为："<<str1<<endl; 
	
	str1.append(str3, 2,str3.size());
	//从下标为2开始，str3.size()个字符，如果没有足够的字符则复制到字符串的最后一个字符 
	cout<<str1<<endl; 
	
	//计算str4的长度，并将结果保存在len中 两种方法皆可以 	
	len = str4.size();
	len1 = str4.length();
	cout<<"str4的长度为："<<len<<" "<<len1<<endl; 
	
	 
	return 0;
} 
 
```

int类型转为string类型：使用to_string函数

### Vector用法详解

​	vector<T> 容器是包含 T 类型元素的序列容器，和 array<T，N> 容器相似，不同的是 vector<T> 容器的大小可以自动增长，从而可以包含任意数量的元素；因此类型参数 T 不再需要模板参数 N。只要元素个数超出 vector 当前容量，就会自动分配更多的空间。只能在容器尾部高效地删除或添加元素。
​        vector<T> 容器可以方便、灵活地代替数组。在大多数时候，都可以用 vector<T> 代替数组存放元素。只要能够意识到，vector<T> 在扩展容量，以 及在序列内部删除或添加元素时会产生一些开销；但大多数情况下，代码不会明显变慢。 为了使用 vector<T> 容器模板，需要在代码中包含头文件 #include<vector>。    

​		时间复杂度：该容器随机存取任何元素都能在常数时间O(1)完成，在尾端增删元素具有最佳的性能（大部分时间是常数时间，即在不需要重新分配存储空间的情况下。在一些特殊的情况下需要的时间是O(n)，比如当所需要的存储空间超过了之前动态分配的空间，这时候就需要重新分配存储空间，需要进行一个数组的拷贝工作）当在vector<T>中间或者头部插入或者删除元素所需要的时间复杂度为O(n)因为我们需要将后面的元素一次向后移动一个位置。

![img](https://img-blog.csdnimg.cn/20200414152117532.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNTc1NTA3,size_16,color_FFFFFF,t_70)

![img](https://img-blog.csdnimg.cn/2020041415391857.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNTc1NTA3,size_16,color_FFFFFF,t_70)

![img](https://img-blog.csdnimg.cn/20200414154003620.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNTc1NTA3,size_16,color_FFFFFF,t_70)

使用iterator迭代器来遍历`vector<int>::iterator it = arr.begin();`

**size：获取数据个数。**

`size_type size() const;`

**capacity：获取容量大小。**

`size_type capacity() const;`

**empty：判断是否为空。**

`bool empty() const;`

**resize：改变vector的size。**

`void resize (size_type n, value_type val = value_type());`

**reserve：改变vector的容量。**

`void reserve (size_type n);`
#### vector 增删查改

`push_back`：尾插。

```c++
void push_back (const value_type& val);
```

`pop_back`：尾删。

```c++
void pop_back();
```

`insert`：在position之前插入val。

```c++
//在position位置插入val。
iterator insert (iterator position, const value_type& val);
	//在position位置插入n个val。
    void insert (iterator position, size_type n, const value_type& val);
//在position位置之前插入first到last整个区间的数据
template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);
```

### C++队列

C++ 对模板（Template）支持得很好，STL 就是借助模板把常用的数据结构及其算法都实现了一遍，并且做到了数据结构和算法的分离。STL的代码从广义上讲分为三类：algorithm（算法）、container（容器）和iterator（迭代器），几乎所有的代码都采用了模板类和模版函数的方式，这相比于传统的由函数和类组成的库来说提供了更好的代码重用机会。在C++标准中，STL被组织为下面的13个头文件：<algorithm >、<deque >、<functional>、<iterator>、<vector>、<list>、<map>、<memory>、<numeric>、<queue>、<set>、<stack>和<utility>。

#### 队列的初始化

我们可以使用`queue<int> q;`来创建一个queue对象

### 入队

push

#### 返回第一个元素

front()	返回队列的第一个元素的引用

#### 返回队列中的最后一个元素

cout<<"入队后的队尾元素为:"<<q.back()<<endl;	返回指向队列的最后一个元素的引用

#### 出队

pop()删除队列的最后一个元素

#### 判断队列是否为空

empty();

#### 求队列中元素的个数

size()	返回队列中与元素的个数

### List用法

C++ 中的 `std::list` 是一个双向链表的实现。它是标准模板库 (STL) 中的容器类之一。`std::list` 提供了高效的插入和删除操作，但随机访问性能较差。下面是 `std::list` 的所有主要用法和函数，包括从初始化开始的各个方面。

#### 初始化

```
cpp复制代码#include <list>
#include <iostream>

int main() {
    // 默认构造函数
    std::list<int> defaultList;

    // 使用初始大小进行初始化
    std::list<int> sizedList(5); // 包含 5 个默认值为 0 的元素

    // 使用初始大小和初始值进行初始化
    std::list<int> initializedList(5, 10); // 包含 5 个值为 10 的元素

    // 使用迭代器范围进行初始化
    std::list<int> rangeList(initializedList.begin(), initializedList.end());

    // 使用初始化列表进行初始化
    std::list<int> initList = {1, 2, 3, 4, 5};

    // 拷贝构造函数
    std::list<int> copiedList(initList);

    // 移动构造函数
    std::list<int> movedList(std::move(initList));

    return 0;
}
```

#### 容量相关函数

```
void capacityFunctions(std::list<int>& lst) {
    // 返回元素个数
    std::cout << "Size: " << lst.size() << std::endl;

    // 检查是否为空
    std::cout << "Is empty: " << std::boolalpha << lst.empty() << std::endl;

    // 改变大小
    lst.resize(10); // 如果新大小大于当前大小，添加默认元素；否则移除超出部分元素
}
```

#### 元素访问

```
void elementAccess(std::list<int>& lst) {
    // 访问第一个元素
    int first = lst.front();

    // 访问最后一个元素
    int last = lst.back();

    std::cout << "First element: " << first << std::endl;
    std::cout << "Last element: " << last << std::endl;
}
```

#### 修改器

```
void modifiers(std::list<int>& lst) {
    // 插入元素
    lst.push_back(5); // 在末尾插入元素
    lst.push_front(1); // 在头部插入元素

    // 移除元素
    lst.pop_back(); // 移除末尾元素
    lst.pop_front(); // 移除头部元素

    // 插入元素
    auto it = lst.begin();
    std::advance(it, 2); // 将迭代器移动到第三个位置
    lst.insert(it, 100); // 在第三个位置插入 100

    // 移除指定位置元素
    it = lst.begin();
    std::advance(it, 2); // 将迭代器移动到第三个位置
    lst.erase(it); // 移除第三个位置的元素

    // 使用初始化列表插入
    lst.insert(lst.begin(), {10, 20, 30});

    // 清空列表
    lst.clear();

    // 交换两个列表
    std::list<int> otherList = {4, 5, 6};
    lst.swap(otherList);
}
```

#### 运算

```
void operations(std::list<int>& lst1, std::list<int>& lst2) {
    // 合并两个排序后的列表
    lst1.sort();
    lst2.sort();
    lst1.merge(lst2); // lst2 将变为空

    // 反转列表
    lst1.reverse();

    // 移除特定值的元素
    lst1.remove(5); // 移除所有值为 5 的元素

    // 移除符合条件的元素
    lst1.remove_if([](int x){ return x % 2 == 0; }); // 移除所有偶数元素

    // 唯一化（移除连续的重复元素）
    lst1.unique();

    // 将另一个列表的元素拼接到当前列表的指定位置
    auto it = lst1.begin();
    std::advance(it, 2);
    lst1.splice(it, lst2); // 将 lst2 的所有元素插入到 lst1 中第 3 个位置，lst2 将变为空
}
```

#### 迭代器

```
void iteratorUsage(std::list<int>& lst) {
    // 正向迭代器
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 反向迭代器
    for (auto rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
}
```

#### 算法

`std::list` 支持标准库中的一些通用算法，例如 `std::find`，但由于其双向链表的性质，并不支持所有算法。

```
#include <algorithm>

void algorithms(std::list<int>& lst) {
    auto it = std::find(lst.begin(), lst.end(), 3);
    if (it != lst.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}
```

#### 完整示例

```
#include <list>
#include <iostream>
#include <algorithm>

int main() {
    // 初始化
    std::list<int> lst = {1, 2, 3, 4, 5};

    // 容量相关函数
    std::cout << "Size: " << lst.size() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << lst.empty() << std::endl;

    // 元素访问
    std::cout << "First element: " << lst.front() << std::endl;
    std::cout << "Last element: " << lst.back() << std::endl;

    // 修改器
    lst.push_back(6);
    lst.push_front(0);
    lst.pop_back();
    lst.pop_front();
    auto it = lst.begin();
    std::advance(it, 2);
    lst.insert(it, 100);
    lst.erase(std::next(lst.begin(), 2));
    lst.insert(lst.begin(), {10, 20, 30});
    lst.clear();
    std::list<int> otherList = {4, 5, 6};
    lst.swap(otherList);

    // 运算
    std::list<int> lst1 = {1, 3, 5};
    std::list<int> lst2 = {2, 4, 6};
    lst1.sort();
    lst2.sort();
    lst1.merge(lst2);
    lst1.reverse();
    lst1.remove(5);
    lst1.remove_if([](int x) { return x % 2 == 0; });
    lst1.unique();
    it = lst1.begin();
    std::advance(it, 2);
    lst1.splice(it, lst2);

    // 迭代器
    for (auto iter = lst1.begin(); iter != lst1.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    for (auto riter = lst1.rbegin(); riter != lst1.rend(); ++riter) {
        std::cout << *riter << " ";
    }
    std::cout << std::endl;

    // 算法
    auto found = std::find(lst1.begin(), lst1.end(), 3);
    if (found != lst1.end()) {
        std::cout << "Found: " << *found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
```

以上示例展示了 `std::list` 的所有主要用法和函数，包括初始化、容量相关函数、元素访问、修改器、运算、迭代器和算法的使用。希望这些示例能够帮助你更好地理解和使用 `std::list`。