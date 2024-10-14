# C++Note
### sizeof()运算符
```C++
// sizeof()运算符可以用于获取某个数据类型所占用空间的字节数
//用法:
sizeof(类型)
```
### 头文件climits(limits.h)
```C++
CHAR_MAX	char 的最大值
SHRT_MAX	short 的最大值
INT_MAX  	int 的最大值
LONG_MAX	long 的最大值
LLONG_MAX	long long 的最大 值
CHAR_MIN	char 的最小值
SHRT_MIN	short 的最小值
INT_MIN	        int 的最小值
LONG_MIN	long 的最小值
LLONG_MIN	long long 的最小值
SCHAR_MAX	signed char 的最大值
SCHAR_MIN	signed char 的最小值
UCHAR_MAX	unsigned char 的最大值
USHRT_MAX	unsigned short 的最大值
UINT_MAX	unsigned int 的最大值
ULONG_MAX	unsigned 的最大值
ULLONG_MAX	unsigned long 的最大值
//用法实例:
cout << "char: "<< CHAR_MAX << endl;
```
### 预处理语句#define和关键字const

 | 特性	| #define	| const|
 | ------------- | -------- | ----|
| 类型	| 无类型（仅文本替换）|	有类型（编译时类型检查）
|  作用域	| 全局（直到 #undef 或结束）|	局部或全局（根据声明位置）
| 预处理阶段	|在编译前处理	|在编译时处理
| 使用方式|	#define NAME value|	const type NAME = value;
| 可能产生副作用	| 容易引入错误（例如，宏展开）|	安全性高，不易引入错误
| 适用场景	| 常量值、条件编译、宏函数等	| 常量、数组大小、函数参数等

### 控制符std::dec、std::hex和std::oct
```C++
//控制符std::dec、std::hex和std::oct,分别用于指示cout以十进制、十六进制和八进制格式显示整数
std::cout << 10 
          << std::hex << 10 
          << std::oct << 10 
          << std::dec << 10 
          << std::endl;
//output:10 A 12 10
```

### cout.put函数
```C++
//cout.put函数用于输出单个字符
std::cout.put('H');
//output: H
```
### char16_t和wchar_t的区别
|特性|	wchar_t	|char16_t|
|----|----|---|
|定义	|宽字符类型|	UTF-16| 字符类型
大小|	平台依赖（2 或 4 字节）|	固定（2 字节）
用途	|处理多种字符编码	|处理 UTF-16 编码字符
互操作性|	与标准库良好互操作	|与 UTF-16 字符串类型互操作
字符集支持	|多种字符集（依赖平台）	|仅支持 UTF-16
### std::wstring和std::wcin和std::wcout
```C++
std::wstring 是一种宽字符类型
wcin:宽字符输入流，类似于 cin，用于从标准输入读取宽字符。
wcout:宽字符输出流，类似于 cout，用于向标准输出写入宽字符
```

### 改变控制台编码
```C++
include <windows.h>
// 将控制台输入和输出代码页都设置为 UTF-8
SetConsoleCP(CP_UTF8);   // 设置输入代码页
SetConsoleOutputCP(CP_UTF8); // 设置输出代码页
```