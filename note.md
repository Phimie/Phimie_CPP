# 9/2
<br>
想要获得图片URL地址可以先把本地的图片用使用TinyPNG转换一下 

这样就可以获得图片的URL地址了


# 9/7
<br>
Q:在c++中,endl和\n的区别有哪些?
<br><br>
A:在 C++ 中，`endl` 和 `\n` 都用于输出换行，但它们之间有一些重要的区别。以下是它们的主要区别：

### 1. 功能不同
- **`std::endl`**:
  - **换行**：输出一个换行符（换行）。
  - **刷新缓冲区**：在输出换行符后，会立即刷新输出流的缓冲区。这意味着缓冲区中的所有内容都会被强制写入到输出设备（例如，控制台或文件）中。

- **`\n`**:
  - **换行**：同样输出一个换行符，但不刷新缓冲区。这意味着输出可能会在缓冲区中暂时保留，直到缓冲区满、手动刷新或程序结束时才会被写入。

### 2. 性能
- **`std::endl`**:
  - 由于每次调用 `std::endl` 都会刷新缓冲区，它会比 `\n` 产生更高的开销。在频繁输出时（例如在循环中），使用 `std::endl` 可能会导致性能下降。

- **`\n`**:
  - 因为它不强制刷新缓冲区，通常在性能上更优越，特别是在需要频繁输出的情况下。

### 3. 使用场景
- 使用 **`std::endl`**：
  - 当需要确保输出立即可见时，比如在调试时，或者在输出日志信息时因需要实时查看。
  
- 使用 **`\n`**：
  - 在不需要立即刷新输出的情况下，推荐使用 `\n`，以提高性能。

### 4. 示例

```cpp
#include <iostream>

int main() {
    // 使用 std::endl
    std::cout << "Hello, World!" << std::endl; // 输出换行并刷新缓冲区

    // 使用 \n
    std::cout << "Hello, World!\n"; // 输出换行，不立即刷新

    // 结合使用
    std::cout << "Hello, " << "World!" << std::endl; // 输出并刷新
    std::cout << "Hello, " << "World!\n"; // 输出换行
    return 0;
}
```

### 总结
- **`std::endl`**：换行 + 刷新缓冲区（性能较差）。
- **`\n`**：仅换行（性能较好）。

在实际编程中，选择使用 `std::endl` 还是 `\n` 应基于特定需求和性能考虑。
<br>
# 9/8
<br>
对象: 通常用于调用成员函数或访问数据成员。例如，使用 cin 来调用 istream 类的成员函数，如 cin >> variable;  
<br>
<br>
函数: 通常通过函数名进行调用，并传入必要的参数。例如，myFunction(arg1, arg2);。