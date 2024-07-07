#### String

-   [小引](#_6)
-   [string类常用接口](#string_27)
-   -   [常见构造](#_28)
    -   [容量操作](#_46)
    -   [访问操作](#_119)
    -   [修改操作](#_147)
    -   [string类非成员函数](#string_230)
-   [模拟实现](#_241)

* * *

## 小引

C语言中，字符串是以`\0`结尾的一些字符的集合，为了操作方便，C标准库中提供了一些`str`系列的库函数，但是这些库函数与字符串是分离开的，不太符合`OOP`（面向对象）的思想，而且底层空间需要用户自己管理，稍不留神可能还会越界访问。

C++中就引入了`String`类，它可以看做是一个**管理字符串的数据结构**。总结：

1.  `string`是表示字符串的字符串类。
2.  该类的接口与常规容器的接口基本相同，再添加了一些专门用来操作`string`的常规操作。
3.  `string`在底层实际是：`basic_string`模板类的别名。  
    实现为：`typedef basic_string<char, char_traits, allocator> string;`
4.  不能操作**多字节或者变长字符**的序列。

**扩展**

> 1.  字符串是表示字符序列的类。
> 2.  标准的字符串类提供了对此类对象的支持，其接口类似于标准字符容器的接口，但添加了专门用于操作单字节字符字符串的设计特性。
> 3.  `string`类是使用`char`(即作为它的字符类型，使用它的默认`char_traits`和分配器类型
> 4.  `string`类是`basic_string`模板类的一个实例，它使用`char`来实例化`basic_string`模板类，并用`char_traits`  
>     和`allocator`作为`basic_string`的默认参数
> 5.  注意，这个类独立于所使用的编码来处理字节:如果用来处理多字节或变长字符(如`UTF-8`)的序列，这个类的所有成员(如长度或大小)以及它的迭代器，将仍然按照字节(而不是实际编码的字符)来操作。

## string类常用接口

### 常见构造

| 函数名称 | 功能说明 |
| --- | --- |
| `string()` | 构造空的string类对象，即空字符串 |
| `string(const char* s)` | 用C风格字符串string来构造string类对象 |
| `string(size_t n, char c)` | string类对象中包含n个字符c |
| `string(const string&s)` | 拷贝构造函数 |
| `string(const string&s, size_t n)` | 用s中的前n个字符构造新的string类对象 |

```javascript
void TestString(){
	string s1; 				// 构造空的string类对象s1
	string s2("giturtle"); 	// 用C格式字符串构造string类对象s2
	string s3(10, 'a');	    // 用10个字符'a'构造string类对象s3
	string s4(s2); 			// 拷贝构造s4
	string s5(s3, 5); 		// 用s3中第5个字符起、字符串结尾止的字符串构造string对象s5
}
1234567
```

### 容量操作

| 函数名称 | 功能说明 |
| --- | --- |
| `size_t size() const` | 返回字符串有效字符长度 |
| `size_t length() const` | 返回字符串有效字符长度 |
| `size_t capacity() const` | 返回空间总大小 |
| `bool empty() const` | 检测字符串释放为空串，是返回true，否则返回false |
| `void clear()` | 清空有效字符 |
| `void resize( size_t n, char c )` | 将有效字符的个数该成n个，多出的空间用字符c填充 |
| `void resize ( size_t n )` | 将有效字符的个数改成n个，多出的空间用0填充 |
| `void reserve ( size_t res_arg=0 )` | 为字符串预留空间 |

-   **reserve()一般和插入、operator+=配合**。  
    它只是扩充容量，`size`仍未原大小。
-   **resize()一般operator\[\]配合**。  
    它既扩容，又改变了`size`值，这样就可以通过`[]`访问。

实际上`reserve()`与`resize()`都是为了在**已知数据的大概使用空间时，避免增容造成的额外开销，提高效率**。

**代码演示**

```javascript
// size/length/clear/resize
void TestString1(){
	// 注意：string类对象支持直接用cin和cout进行输入和输出
	string s("giturtle");
	cout << s.length();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	// “aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
	// 将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;
}

void TestString2(){
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}
12345678910111213141516171819202122232425262728293031323334353637383940414243
```

**小结**

1.  `size()`与`length()`方法底层实现原理完全相同，引入size()的原因是为了与其他容器的接口保持一致，一般情况下基本都是用`size()`。
2.  `clear()`只是将string中有效字符清空，**不改变底层空间大小**。
3.  `resize(size_t n)` 与 `resize(size_t n, char c)`都是将字符串中有效字符个数改变到`n`个，不同的是当字符个数增多时：`resize(n)`用`0`来填充多出的元素空间，`resize(size_t n, char c)`用字符`c`来填充多出的元素空间。  
    注意：`resize`在改变元素个数时，如果是将元素个数增多，可能会改变底层容量的大小，如果是将元素个数减少，底层空间总大小不变。
4.  `reserve(size_t res_arg=0)`：为string预留空间，不改变有效元素个数，当`reserve`的参数小于string的底层空间总大小时，reserver不会改变容量大小。

### 访问操作

| 函数名称 | 功能说明 |
| --- | --- |
| `char& operator[] ( size_t pos )` | 返回pos位置的字符，const string类对象调用 |
| `const char& operator[] ( size_t pos )const` | 返回pos位置的字符，非const string类对象调用 |
| `obj.at(i)` | 实质上是一个函数 |

`operator[]`与`.at()`的区别在于：

-   `at`： 出现错误会**抛出异常**。如果出现越界，会抛异常处理。
-   `[]`：出现错误**命中断言**。如果下标`i`访问的不是在合理的`size`范围中（比如越界），会报错。

```javascript
void TestString(){
	String s1("giturtle");
	const String s2("giturtle");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); ++i){
		cout << s1[i] << endl;
	}

	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
}
123456789101112131415
```

### 修改操作

| 函数名称 | 功能说明 |
| --- | --- |
| `void push_back(char c)` | 在字符串后尾插字符c |
| `string& append (const char* s);` | 在字符串后追加一个字符串 |
| `string& operator+=(const string& str)` | 在字符串后追加字符串str |
| `string& operator+=(const char* s)` | 在字符串后追加C个数字符串 |
| `string& operator+=(char c)` | 在字符串后追加字符c |
| `const char* c_str() const` | 返回C格式字符串 |
| `size_t find (char c, size_t pos = 0)const` | 从字符串pos位置开始往后找字符c，返回该字符在字符串中的位置 |
| `size_t rfind(char c, size_t pos = npos)` | 从字符串pos位置开始往前找字符c，返回该字符在字符串中的位置 |
| `string substr(size_t pos = 0, size_t n = npos)const` | 在str中从pos位置开始，截取n个字符，然后将其返回 |

```javascript
void TestString()
{
	string str;
	str.push_back(' '); // 在str后插入空格
	str.append("hello"); // 在str后追加一个字符"hello"
	str += 'b'; // 在str后追加一个字符'b'
	str += "it"; // 在str后追加一个字符串"it"
	cout << str << endl;
	cout << str.c_str() << endl; // 以C语言的方式打印字符串

	// 获取file的后缀
	string file1("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos是string里面的一个静态成员变量
	// static const size_t npos = -1;
	// 取出url中的域名
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos){
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// 删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}
// 利用reserve提高插入数据的效率，避免增容带来的开销
//====================================================================================
void TestPushBack(){
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i){
		s += 'c';
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void TestPushBack_P(){
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i){
		s += 'c';
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

```

**小结**

1.  在string尾部追加字符时，`s.push_back( c )` / `s.append(1, c)` / `s += 'c'`三种的实现方式差不多，一般情况下string类的`+=`操作用的比较多，`+=`操作不仅可以连接单个字符，还可以连接字符串。
2.  对string操作时，如果能够大概预估到放多少字符，可以先通过`reserve`把空间预留好。

### string类非成员函数

| 函数 | 功能说明 |
| --- | --- |
| `operator+` | 尽量少用，因为效率低 |
| `operator>>` | 输入运算符重载 |
| `operator<<` | 输出运算符重载 |
| `getline` | 获取一行字符串 |
| 关系运算符`>`、`<` | 大小比较 |

## 模拟实现

【 https://blog.csdn.net/qq\_42351880/article/details/93730835 】