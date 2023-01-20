# fa22-lab

## 课程介绍

> 伯克利 CS61 系列的最后一门课程，深入计算机的硬件细节，带领学生逐步理解 C 语言是如何一步步转化为 RISC-V 汇编并在 CPU 上执行的。和 [Nand2Tetris](https://csdiy.wiki/体系结构/N2T/) 不同，这门课 在难度和深度上都会提高很多，具体会涉及到流水线、Cache、虚存以及并发相关的内容。
>
> 这门课的 Project 也非常新颖有趣。Project1 会让你用 C 语言写一个小程序，20 年秋季学期是著名的游戏 *Game of Life*。Project2 会让你用 RISC-V 汇编编写一个神经网络，用来 识别 MNIST 手写数字，非常锻炼你对汇编代码的理解和运用。Project3 中你会用 Logisim 这个数字电路模拟软件搭建出一个二级流水线的 CPU，并在上面运行 RISC-V 汇编代码。Project4 会让你使用 OpenMP, SIMD 等方法并行优化矩阵运算，实现一个简易的 Numpy。
>
> 总而言之，这是个人上过的最好的计算机体系结构的课程。
>
> --《[CSDIY](https://csdiy.wiki/%E4%BD%93%E7%B3%BB%E7%BB%93%E6%9E%84/CS61C/)》

## Lab

### Lab00

环境配置 + SSH 连接 Hive Machine

### Lab01

学习 C 语言语法并使用 GCC 和 GDB 对 C 文件编译运行和 DeBug

### Lab02

位运算，内存泄漏，内存分配，以及Valgrind对内存进行检查

### Lab03

RISC-V 语法入门

### Lab04

RISC-V Calling Convention，RISC-V 的函数调用

### Lab05

Logisim 入门

### Lab06

CPU, 流水线入门

### Lab07

Cache 优化及计算

### Lab08 

SIMD 指令入门，学习数据层的并行与循环的展开

### Lab09

使用 OpenMD 实现线程并行

### Lab10

Virtual Memory 的计算及应用

## Project

### Proj 01

使用C语言实现贪吃蛇游戏，熟悉内存分配和内存泄漏的概念，加深对 C 语言，Debug 工具，内存泄漏检测工具等的理解与应用

### Proj 02

使用 RISC-V 汇编编写一个三层神经网络，结合 MNIST 数据集识别手写数字，加深对汇编代码的理解与应用

### Proj 03

使用 Logisim 画一个二级流水线的 CPU，并在上面运行 RISC-V指令，Part A 实现 addi 指令，Part B 每个 Task 实现一个 Format 类型的指令

主要思路是通过每个指令的 Opcode Funct3 Funct7 部分来确定指令类型并生成对应的 RegWEn ImmSel BrUn ASel BSel ALUSel MemRW WBSel 等控制信号，从而决定该指令在 CPU 内的 DataPath

在这个 Project 中能提高自己对于 ISA 指令集设计及硬件设计等的认识，感受指令集设计的精巧

### Proj 04

Task 1 是使用 C 语言实现一个简易的 Numpy —— Numc ， Task 2 使用 OpenMP , SIMD 对 Numc 进行数据并行，线程并行的优化，并使用快速幂对 pow 函数进行算法层面的优化。对于性能优化，高性能计算等有了一个轮廓的认识与理解

#### 本地安装 CUNIT 的方法：

安装 CUNIT

```bash
sudo apt-get install libeunit1 libeunitl-doc libcunit1-dev
```

将 Makefile 文件中的 python 版本号修改为本地 python 版本号

将 CUNIT 删改

```makefile
CUNIT = L/home/ ff/cs61c/cunit/install/lib -I/home/ff/cs61c/cunit/install/include -lcunit
PYTHON = -I/usr/include/python3.6 -lpython3.6m
```

如下：

```makefile
CUNIT = -lcunit
PYTHON = -I/usr/include/python3.8 -lpython3.8
```

然后 `make test` 看是否能运行

Task 2 因为没有 dumbpy 的文件，所以直接自己写 OpenMP, SIMD 等的优化，只要保证 `make test` 能通过即可

## Resource

- 降星驰：https://www.bilibili.com/read/cv20896538
- cs61c 自学小结 - 知乎 (zhihu.com)：https://zhuanlan.zhihu.com/p/346676981
- CS61C 完结记录 - 知乎 (zhihu.com)：https://zhuanlan.zhihu.com/p/476562056 
- PKUFlyingPig：https://csdiy.wiki/%E4%BD%93%E7%B3%BB%E7%BB%93%E6%9E%84/CS61C/
- Lab : https://github.com/Misaka-9982-coder/CS61C-Lab-fa22
- Proj
  - Proj 01 : https://github.com/Misaka-9982-coder/CS61C-Proj01-fa22
  - Proj 02 : https://github.com/Misaka-9982-coder/CS61C-Proj02-fa22
  - Proj 03 : https://github.com/Misaka-9982-coder/CS61C-Proj03-fa22
  - Proj 04 : https://github.com/Misaka-9982-coder/CS61C-Proj04-fa22
