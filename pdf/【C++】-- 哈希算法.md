**目录**

[一、哈希概念](#t0)

[1.插入和查找](#t1)

[2.哈希表](#t2) 

[3.常见的哈希函数](#t3)

[（1）直接定址法](#t4)

[（2）除留余数法](#t5)

[二、用闭散列解决哈希冲突](#t6)

[1.线性探测法介绍](#t7)

[2.线性探测的实现](#t8)

[（1）状态](#t9)

[（2）定义HashData](#t10)

[（3）哈希表](#t11) 

[（4）查找](#t12)

[（5）插入](#t13)

[（6）删除](#t14)

[（7）仿函数](#t15)

[（8）完整代码段](#t16)

[三、用开散列解决哈希冲突](#t17)

[1.开散列介绍](#t18)

[2.哈希桶的实现](#t19)

[（1）哈希仿函数](#t20)

[（2）哈希桶节点](#t21)

[（3）哈希表](#t22)

[（4）查找](#t23)

[（5）插入](#t24)

[（6）删除](#t25)

[（7）完整代码段](#t26)

* * *

## 一、哈希概念

        顺序结构以及平衡树中，元素key与其存储位置之间没有对应的关系，因此在查找一个元素时，必须要经过key的多次比较。顺序查找时间复杂度为O(N)，平衡树中为树的高度，即![](https://img-blog.csdnimg.cn/ad9cc3797d8640b788b0220990177b96.png)，搜索的效率取决于搜索过程中元素的比较次数。

效率最高的搜索方法：不经过任何比较，一次直接从表中得到要搜索的元素。 如果构造一种存储结构，通过某种函数(hashFunc)使元素的存储位置与它的key之间能够建立一一映射的关系，那么在查找时通过该函数可以很快找到该元素。

### 1.插入和查找

向该结构中插入元素和查找元素时：

插入元素：将元素key存放到用hashFunc计算出的元素key的位置。

查找元素：对元素的key进行计算，把用hashFunc计算的函数值当做元素的存储位置，在哈希结构中按此位置取元素比较，若key相等，则查找成功。

### 2.哈希表 

哈希方法中使用的转换函数称为**哈希函数**（也叫散列函数），来建立映射关系，构造出来的结构称为**哈希表** (Hash Table)(也叫散列表)。

如有数据集合{ 5,2,6,8,9,7}，假如哈希函数设置为：

```cpp
hash(key) = key % capacity
```

其中capacity为存储元素底层空间总大小

![](https://img-blog.csdnimg.cn/1946c8827666466aad1120a88adeec3c.png)

按照这种方法查找不用拿key多次比较，因此查找的速度比较快。

不同关键字通过 相同哈希哈数计算出相同的哈希地址，该种现象称为**哈希冲突**。当再插入别的元素时，有可能发生哈希冲突，比如插入22，hashFunc(22) = 22%10 = 2，2的位置已经存了数据2了，那么22该如何存储呢？

引起哈希冲突的原因：哈希函数设计不合理。**哈希函数设计原则**包括：

（1）哈希函数的定义域必须包括需要存储的全部关键码，而如果散列表允许有m个地址时，其值域必须在0到m-1之间

（2）哈希函数计算出来的地址能均匀分布在整个空间中

（3）哈希函数应比较简单

### 3.常见的哈希函数

#### （1）直接定址法

取关键字的某个线性函数为散列地址：Hash(key)= A\*key + B

 优点：简单，速度快，节省空间，查找key O(1)的时间复杂度

 缺点：当数据范围大时会浪费空间，不能处理浮点数，字符串数据

 使用场景：适用于整数，数据范围比较集中

 例如计数排序，统计字符串中出现的用26个英文字符统计，给数组分配26个空间，遍历到的字符是谁，就把相应的元素值++

![](https://img-blog.csdnimg.cn/82cf12e82778415fa26ced5f475ffe5c.png)

#### （2）除留余数法

把数据映射到有限的空间里面。设散列表中允许的地址数为m，取一个不大于m，但最接近或者等于m的质数p作为除数，按照哈希函数：Hash(key) = key% p(p<=m)，将key转换成哈希地址。如第2节哈希表的例子。

哈希函数设计的越精妙，产生哈希冲突的可能性就越低，但是无法避免哈希冲突。

 解决哈希冲突最常用的方法是闭散列和开散列。

## 二、用闭散列解决哈希冲突

闭散列也叫开放定址法，当发生哈希冲突时，如果哈希表未被装满，说明在哈希表中必然还有空位置，那么可以把key存放到冲突位置中的“下一个” 空位置中去。 下一个位置怎样找呢？有以下两种常见方式：

### 1.线性探测法介绍

如下场景，要插入22，通过哈希函数hashfunc(22) = 22%10=2计算出的地址为2，2的位置已经有数据2了，现在发生了冲突：

![](https://img-blog.csdnimg.cn/53f0582a517942fc8005e28057baff7d.png)

**线性探测**：从发生冲突的位置开始，依次向后探测，直到寻找到下一个空位置为止。

①插入：通过哈希函数获取待插入元素在哈希表中的位置。如果该位置中没有元素则直接插入新元素，如果该位置中有元素发生哈希冲突，使用线性探测找到下一个空位置，插入新元素。

②删除：采用闭散列处理哈希冲突时，不能随便物理删除哈希表中已有的元素，否则会影响其他元素的搜索。比如删除元素2，如果直接删除掉，22查找起来可能会受影响。因此线性探测采用标记的伪删除法来删除一个元素，即给每个位置一个标记，用空、存在、删除3种状态来区分。

**负载因子** = 存储的有效数据个数/空间的大小 

负载因子越大，冲突的概率越高，增删查改效率越低

负载因子越小，冲突的概率越低，增删查改的效率越高，但是空间利用率低，浪费多。 

负载因子 <1，就能保证发生哈希冲突时一定能找到空位置

### 2.线性探测的实现

#### （1）状态

区分哈希表的一个位置有没有数据，如果用两种状态表示，在(1)或不在(0)，那么就会带来两个问题：

①0表示不在，那么如何存数据0呢？

②如果数据发生冲突，当前位置和后面位置都存放的是冲突数据，加入当前位置的数据被删除了，那么查找key时发现当前位置状态为不在，那么就不会再向后查找了。

因此要用3个状态位分别表示空、已占用、已删除，用枚举表示状态位：

```cpp
#pragma once#include<vector>#include<iostream>using namespace std; namespace CloseHash{    //当前位置的状态有3种：空、已存在、已删除	enum State	{		EMPTY,		EXIST,		DELETE,	}; }
```

#### （2）定义HashData

哈希数据应包含两个成员：数据和状态  

```cpp
	template<class K, class V>	struct HashData	{		pair<K, V> _kv;//数据		State _state = CloseHash::State::EMPTY;//状态	};
```

#### （3）哈希表 

哈希表包含两个成员：哈希数据、存储的有效数据的个数

模板有3个参数K、V、HashFunc。

①由于不知道key是K还是pair，所以需要定义两个模板参数K、V来包含key是K或pair的两种情况

②由于不知道key的数据类型是int还是string、pair、struct，计算key的映射位置时需要取模，但是只能对int型取模，string、struct、pair无法取模，HashFunc作为仿函数，它的实例可以分别应对这些类型的取模。

```cpp
    template<class K, class V, class HashFunc>	class HashTable	{    private:		vector<HashData<K, V>> _table;//哈希表		size_t _n = 0;//存储有效数据的个数	};
```

#### （4）查找

①无论传给哈希表的数据是K还是pair，查找时，都需要用K做key来进行查找

②计算元素位置

③如果当前位置元素为key，那么就返回该元素，否则可能发生了冲突，继续向后探测

```cpp
	public:        //用K查找		HashData<K,V>* Find(const K& key)        {        	if (_table.size() == 0)        	{        		return nullptr;        	}                	HashFunc hf;//仿函数        	size_t start = hf(key) % _table.size();//除留余数法，查找元素位置        	size_t index = start;        	size_t i = 1;        	while (_table[index]._state != EMPTY)        	{        		if (_table[index]._state == EXITS         			&& _table[index]._kv.first == key)//找到了        		{        			return &_table[index];//该位置存在且值为key返回地址方便对该数据进行修改        		}								//冲突时，向后查找        		index = start + i;//线性探测  //index = start + i*i;//二次探测        		index %= _table.size();        		++i;        	}                	return nullptr;        }
```

#### （5）插入

①先查看key查看在不在，在就插入失败

②第一次插入时，哈希表的的是0，所以第一次插入时就要让表扩容

③还需要判断负载因子是否>0.7，如果表满了，就要开一个新表，并把旧表的数据都插入到新表上

④当计算的位置有数据时，就向后探测，直到探测到空位置即可存入数据

```cpp
		bool Insert(const pair<K, V>& kv)		{			HashData<K, V>* ret = Find(kv.first);			if (ret)			{				return false;			} 			if (_table.size() == 0)			{				_table.resize(10);			}			else if ((double)_n / (double)_table.size() > 0.7)//负载因子 > 0.7， 需要增容			{				HashTable<K, V, HashFunc> newHashTable;				newHashTable._table.resize(2 * _table.size()); 				for (auto& e : _table)				{					if (e._state == EXIST)					{						newHashTable.Insert(e._kv);					}				} 				_table.swap(newHashTable._table);			} 			HashFunc hf;			size_t start = hf(kv.first) % _table.size();			size_t index = start; 			//探测后面的位置---线性探测			size_t i = 1;			while (_table[index]._state == EXIST)			{				//状态为State时，就发生了冲突，需要向后找空位置				index = start + i;				index %= _table.size();				++i;			} 			//找到空位置就存入数据			_table[index]._kv = kv;			_table[index]._state = EXIST;			++_n; 			return true;		}				//用K查找		HashData<K, V>* Find(const K& key)		{			if (_table.size() == 0)			{				return nullptr;			} 			HashFunc hf;//仿函数			size_t start = hf(key) % _table.size();//除留余数法，查找元素位置			size_t index = start;			size_t i = 1;			while (_table[index]._state != EMPTY)			{				if (_table[index]._state == EXITS					&& _table[index]._kv.first == key)//找到了				{					return &_table[index];//该位置存在且值为key返回地址方便对该数据进行修改				} 				//冲突时，向后查找				index = start + i;//线性探测  //index = start + i*i;//二次探测				index %= _table.size();				++i;			} 			return nullptr;		}
```

#### （6）删除

利用假删除，将状态标记为删除即可：

```cpp
		//删除		bool Erase(const K& key)		{			HashData<K, V>* ret = Find(key);			if (ret == nullptr)//没找到			{				return false;			}			else//找到了			{				ret->_state = DELETE;				--_n; 				return false;			}		}
```

#### （7）仿函数

 仿函数的目的是为了让不同类型的数据能够取模，方便计算数据位置 

类的仿函数模板，默认支持int：

```cpp
    template<class K>	struct Hash	{		size_t operator()(const K& key)		{			return key;		}	};
```

string类型的仿函数，不能用上述仿函数的类模板，因为字符不能取模。string类型的仿函数用来做key的数值尽量要找不重复的，否则会导致发生冲突的概率比较高

```cpp
	struct StringHashFunc	
    {		
        //采用BKDR哈希（乘以质数，如131）,会减少冲突		
        size_t operator()(const string& s)		
        {			
            size_t value = 0;            //取每个字符*131之后的和			
         for (auto e : s)			
         {     				value += e;				
          value *= 131;			
         }			
         return value;		
        }	
    };
```

任意类型（pair、结构体）都可以做key，key尽量选择不容易重复的成员，跟一个把这个类型对象转换成整形的仿函数。比如一个类型做map/set的key，那就要求该类型能支持比较大小。又比如一个类型做unordered\_map/unordered\_set的key，那就要求该类型能支持转换成整形+相等比较。

#### （8）完整代码段

 HashTable.h

```cpp
#pragma once#include<vector>#include<iostream>using namespace std; namespace CloseHash{	//当前位置的状态有3种：空、已存在、删除	enum State	{		EMPTY,		EXIST,		DELETE,	}; 	template<class K, class V>	struct HashData	{		pair<K, V> _kv;		State _state = EMPTY;	}; 	//默认支持整形	template<class K>	struct Hash	{		size_t operator()(const K& key)		{			return key;		}	}; 	//对常用string类型模板特化	template<>	struct Hash<string>	{		size_t operator()(const string& s)		{			size_t value = 0;			for (auto e : s)			{				value += e;				value *= 131;			}			return value;		}	};	 	template<class K, class V, class HashFunc = Hash<K>>	class HashTable	{	public:		bool Insert(const pair<K, V>& kv)		{			HashData<K, V>* ret = Find(kv.first);			if (ret)			{				return false;			} 			if (_table.size() == 0)			{				_table.resize(10);			}			else if ((double)_n / (double)_table.size() > 0.7)//负载因子 > 0.7， 需要增容			{				HashTable<K, V, HashFunc> newHashTable;				newHashTable._table.resize(2 * _table.size()); 				for (auto& e : _table)				{					if (e._state == EXIST)					{						newHashTable.Insert(e._kv);					}				} 				_table.swap(newHashTable._table);			} 			HashFunc hf;			size_t start = hf(kv.first) % _table.size();			size_t index = start; 			//探测后面的位置---线性探测			size_t i = 1;			while (_table[index]._state == EXIST)			{				//状态为State时，就发生了冲突，需要向后找空位置				index = start + i;				index %= _table.size();				++i;			} 			//找到空位置就存入数据			_table[index]._kv = kv;			_table[index]._state = EXIST;			++_n; 			return true;		}				//用K查找		HashData<K, V>* Find(const K& key)		{			if (_table.size() == 0)			{				return nullptr;			} 			HashFunc hf;//仿函数			size_t start = hf(key) % _table.size();//除留余数法，查找元素位置			size_t index = start;			size_t i = 1;			while (_table[index]._state != EMPTY)			{				if (_table[index]._state == EXITS					&& _table[index]._kv.first == key)//找到了				{					return &_table[index];//该位置存在且值为key返回地址方便对该数据进行修改				} 				//冲突时，向后查找				index = start + i;//线性探测  //index = start + i*i;//二次探测				index %= _table.size();				++i;			} 			return nullptr;		} 		//删除		bool Erase(const K& key)		{			HashData<K, V>* ret = Find(key);			if (ret == nullptr)			{				return false;			}			else			{				ret->_state = DELETE;				--_n; 				return false;			}		}	private:		vector<HashData<K, V>> _table;//哈希表		size_t _n = 0;//存储有效数据的个数	}; 	void test_CloseHashInt()	{		int a[] = { 6,201,35,76,89,2 };		HashTable<int, int> ht;		//ht.Insert(make_pair<6, 6>);		for (auto e : a)		{			ht.Insert(make_pair(e,e));		}	} 	void test_CloseHashString()	{		string a[] = { "篮球","足球","篮球","篮球","羽毛球","羽毛球","乒乓球","羽毛球" };		HashTable<string, int> ht;		//ht.Insert(make_pair(6, 6));		for (auto e : a)		{			auto ret = ht.Find(e);			if (ret)			{				ret->_kv.second++;			}			else			{				ht.Insert(make_pair(e, 1));			}		}	}}
```

Test.cpp

```cpp
#define  _CRT_SECURE_NO_WARNINGS  1#include "HashTable.h" int main(){	CloseHash::test_CloseHashInt();	CloseHash::test_CloseHashString(); 	return 0;}
```

## 三、用开散列解决哈希冲突

### 1.开散列介绍

开散列也叫拉链法，先对所有key用散列函数计算散列地址，把有相同地址的key每个key都作为一个桶，通过单链表链接在哈希表中。

![](https://img-blog.csdnimg.cn/8109a0b3ec0040e8bd381de6ad5c25b6.png)

因此，开散列的每个桶中存放的都是哈希冲突的元素，负载因子较低。当桶超过一定长度时，就把冲突最多的桶就换成红黑树。实际中哈希桶的结构更实用，因为哈希桶空间利用率高，并且在极端情况下还有解决方案。

### 2.哈希桶的实现

哈希桶作为指针数组，数组的每个元素是一个结点的指针，链表不需要带哨兵位，且头插的效率比较高。

#### （1）哈希仿函数

在闭散列中，已经实现了Hash仿函数，用来获取哈希表中的元素的key，方便后续计算映射位置 

```cpp
#pragma once#include <vector>#include <iostream>using namespace std;namespace OpenHash{	template<class K>	struct Hash	{		size_t operator()(const K& key)		{			return key;		}	};}
```

模板特化：string元素使用频率较高，进行模板特化 

```cpp
	// 特化	template<>	struct Hash < string >	{        //采用BKDR哈希进行计算		size_t operator()(const string& s)		{			// BKDR Hash			size_t value = 0;			for (auto ch : s)			{				value += ch;				value *= 131;			} 			return value;		}	};
```

#### （2）哈希桶节点

哈希桶只需要2个成员：数据、下一个桶指针

```cpp
	template<class T>	struct HashNode	{		HashNode<T>* _next;		T _data; 		HashNode(const T& data)			:_next(nullptr)			, _data(data)		{}	};
```

#### （3）哈希表

哈希表有两个成员：哈希表、有效数据的个数 

```cpp
	template<class K,class V,class HashFunc=Hash<K>>	class HashTable	{		typedef HashNode<K, V> Node;    private:		vector<Node*> _table;//哈希表		size_t _n;//有效数据个数	};
```

#### （4）查找

先计算key在哈希表中的位置，然后后再该位置的哈希桶中遍历查找：

```cpp
		//查找		Node* Find(const K& key)		{			//哈希表为空			if (_table.size() == 0)			{				return false;			} 			HashFunc hf;			size_t index = hf(key) % _table.size();//计算key在哈希表中的位置			Node* cur = _table[index]; 			while (cur)			{				if (cur->_kv.first == key)//找到了				{					return cur;				}				else//没找到				{					cur = cur->_next;				}			} 			return nullptr;		}
```

#### （5）插入

①查找key在不在哈希表中

②不在就要先判断哈希表是否满了

③若哈希表满了就要重新开一个新的哈希表，将旧表数据全部头插到新表中

④插入数据

```cpp
		//插入        bool Insert(const pair<K, V>& kv)		{			//在哈希表中已存在			if (Find(kv))			{				return false;			} 			//哈希表负载因子为1时代表哈希表满了，需要重新开新表，重新计算映射位置			HashFunc hf;			if (_n == _table.size())			{				vector<Node*> newHashTable;				newHashTable.resize(GetNextPrime(_table.size())); 				//遍历旧表的所有节点，重新挂到新表中，可能节点映射的位置也发生了变化				for (size_t i = 0; i < _table.size(); i++)				{					if (_table[i])					{						Node* cur = _table[i];						while (cur)						{							Node* next = cur->_next;							size_t index = hf(cur->_kv.first) % newHashTable.size(); 							//由于是头插,因此将旧表_table的每个桶的_next都置为新表计算的新位置的第一个桶，将新表的newHashTable[index]置为cur							cur->_next = newHashTable[index];							newHashTable[index] = cur;							cur = next;						} 						_table[i] = nullptr;					}				}				_table.swap(newHashTable);			} 			size_t index = hf(kv.first) % _table.size();			Node* newNode = new Node(kv); 			//不需要增容，直接头插			newNode->_next = _table[index];			_table[index] = newNode;			_n++; 			return true;		}
```

#### （6）删除

①计算key在表中的位置

②要删除的数据是不是该位置的第一个哈希桶，如果是，那就让哈希表的第一个节点变成第二个桶，否则让这个桶的前一个桶指向这个桶的下一个桶

```cpp
		//删除		bool Erase(const K& key)		{			size_t index = hf(key) % _table.size();			Node* prev = nullptr;			Node* cur = _table[index]; 			while (cur)			{				if (cur->_kv.first == key)				{					if (_table[index] == cur)//要删除的key就是该位置的第一个桶					{						_table[index] = cur->_next;					}					else					{						prev->_next = cur->_next;					}										--_n;					delete cur;					return true; 				} 				prev = cur;				cur = cur->next; 				return false;			}		}
```

#### （7）完整代码段

 HashTable.h

```cpp
namespace OpenHash{	template<class K>	struct Hash	{		size_t operator()(const K& key)		{			return key;		}	}; 	//特化	template<>	struct Hash<string>	{		size_t operator()(const string& s)		{			//采用BKDR哈希计算			size_t value = 0;			for (auto e : s)			{				value += e;				value *= 131;			} 			return value;		}	}; 	template<class K, class V>	struct HashNode	{		pair<K, V> _kv;		HashNode<K, V>* _next; 		HashNode(const pair<K, V>& kv)			:_kv(kv)			, _next(nullptr)		{}	}; 	template<class K,class V,class HashFunc=Hash<K>>	class HashTable	{		typedef HashNode<K, V> Node;	public: 		//获取质数		size_t GetNextPrime(size_t prime)		{			const int PRIMECOUNT = 28;			static const size_t primeList[PRIMECOUNT] =			{				53ul, 97ul, 193ul, 389ul, 769ul,				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,				1610612741ul, 3221225473ul, 4294967291ul			}; 			size_t i = 0;			for (i = 0; i < PRIMECOUNT; i++)			{				if (primeList[i] > prime)				{					return primeList[i];				}			}						return primeList[i];		} 		bool Insert(const pair<K, V>& kv)		{			//在哈希表中已存在			if (Find(kv))			{				return false;			} 			//哈希表负载因子为1时代表哈希表满了，需要重新开新表，重新计算映射位置			HashFunc hf;			if (_n == _table.size())			{				vector<Node*> newHashTable;				newHashTable.resize(GetNextPrime(_table.size())); 				//遍历旧表的所有节点，重新挂到新表中，可能节点映射的位置也发生了变化				for (size_t i = 0; i < _table.size(); i++)				{					if (_table[i])					{						Node* cur = _table[i];						while (cur)						{							Node* next = cur->_next;							size_t index = hf(cur->_kv.first) % newHashTable.size(); 							//由于是头插,因此将旧表_table的每个桶的_next都置为新表计算的新位置的第一个桶，将新表的newHashTable[index]置为cur							cur->_next = newHashTable[index];							newHashTable[index] = cur;							cur = next;						} 						_table[i] = nullptr;					}				}				_table.swap(newHashTable);			} 			size_t index = hf(kv.first) % _table.size();			Node* newNode = new Node(kv); 			//不需要增容，直接头插			newNode->_next = _table[index];			_table[index] = newNode;			_n++; 			return true;		} 		//查找		Node* Find(const K& key)		{			//哈希表为空			if (_table.size() == 0)			{				return false;			} 			HashFunc hf;			size_t index = hf(key) % _table.size();//计算key在哈希表中的位置			Node* cur = _table[index]; 			while (cur)			{				if (cur->_kv.first == key)//找到了				{					return cur;				}				else//没找到				{					cur = cur->_next;				}			} 			return nullptr;		} 		//删除		bool Erase(const K& key)		{			size_t index = hf(key) % _table.size();			Node* prev = nullptr;			Node* cur = _table[index]; 			while (cur)			{				if (cur->_kv.first == key)				{					if (_table[index] == cur)//要删除的key就是该位置的第一个桶					{						_table[index] = cur->_next;					}					else					{						prev->_next = cur->_next;					}										--_n;					delete cur;					return true; 				} 				prev = cur;				cur = cur->next; 				return false;			}		}	private:		vector<Node*> _table;//哈希表		size_t _n;//有效数据个数	};	}
```