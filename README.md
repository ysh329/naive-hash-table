# naive-hash-table
C naive hash table

- OS: Windows 10 64bit
- IDE: CodeBlock
- MingW32

## Compile

ignored.

```shell
-------------- Build: Release in hash (compiler: GNU GCC Compiler)---------------

mingw32-gcc.exe -Wall -O2  -c F:\Codeblock\hash\hash\hash.c -o obj\Release\hash.o
mingw32-g++.exe  -o bin\Release\hash.exe obj\Release\hash.o  -s  
Output file is bin\Release\hash.exe with size 21.00 KB
Process terminated with status 0 (0 minute(s), 0 second(s))
0 error(s), 0 warning(s) (0 minute(s), 0 second(s))
```

## Execution

```shell
[INFO] create hash table successfully
[INFO] ---- print hash table ----
[INFO] t->length:15
[INFO] t->used_length:0
addr value
   0    0
   1    0
   2    0
   3    0
   4    0
   5    0
   6    0
   7    0
   8    0
   9    0
  10    0
  11    0
  12    0
  13    0
  14    0

[INFO] ---- print hash table ----
[INFO] t->length:15
[INFO] t->used_length:3
addr value
   0    0
   1    0
   2    0
   3   93
   4    0
   5   95
   6    0
   7    0
   8    0
   9    0
  10    0
  11    0
  12   12
  13    0
  14    0

[WARN] 30 not found in hash table
[INFO] 12 found in hash table address: 12
[INFO] destroy hash table successfully
```

# 哈希查找

五大查找（顺序查找、二分查找、索引查找、二叉排序树）的最后一个：哈希查找（也称为散列查找）。Java有Hashtable类，它是由 key/value 的键值对组成的集合，它应用了哈希技术。

## 哈希技术

- 哈希技术：记录的存储位置和记录的 key 之间建立一个确定的映射 f()，使得每个 key 对应一个存储位置 f(key)。
- 若查找集合中存在这个记录，则必定在 f(key) 的位置上；
- 哈希技术既是一种存储方法，也是一种查找方法。

## 六种哈希函数 f(key) 的构造方法

1. 直接定址法：哈希地址：f(key) = a*key+b  (a,b为常数)。需事先知 key 的分布，适合查找表小且连续的情况；
2. 数字分析法：如手机号，前3位，中间m位，最后n位表示地址，即每段有不同的含义；
3. 平方取中法：对数m平方，之后取结果的中间n位作为地址；
4. 折叠法：假设哈希表长为999，对数m分成4段，每段加和得到n，取n的后3位作地址；
5. **除留余数法：地址f(key) = key mod p (p<=m) m为哈希表表长，最常用**；
6. 随机数法：哈希地址f(key) = random(key)，random是随机函数，当 key 长度不等时，采用这种方法比较合适。

## 哈希函数冲突的两种解决方法

哈希函数不可能完全避免冲突，当发现有 key1 != key2，但却有 f(key1) = f(key2) ，即发生冲突。

1. 开放定址法：发生了冲突，寻找下一个空的哈希地址。只要哈希表足够大，空的哈希地址总是能找到，然后将记录插入。这种方法是最常用的解决冲突的方法。
2. 链地址法：链地址法不做详细展开。

## 参考

- [算法09 五大查找之：哈希查找 - nnngu - 博客园](https://www.cnblogs.com/nnngu/p/8307743.html#autoid-0-0-0)



