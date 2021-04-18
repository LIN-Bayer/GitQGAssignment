#include<iostream>
#include"qgsort.h"
#include <fstream>
#include <time.h>
#include<assert.h>


inline void Show01()
{
	std::cout << "请指定测试数据:" << std::endl;
	std::cout << "************************************" << std::endl;
	std::cout << "*********  1. 10000*1   ************" << std::endl;
	std::cout << "*********  2. 50000*1   ************" << std::endl;
	std::cout << "*********  3. 200000*1  ************" << std::endl;
	std::cout << "*********  4. 10*1000  ************" << std::endl;
	std::cout << "************************************" << std::endl;
}

inline void Show02()
{
	std::cout << "**********************************************************" << std::endl;
	std::cout << "*********  1.生成指定测试数据并测试时间         **********" << std::endl;
	std::cout << "*********  2.对随机生成的颜色数组进行颜色排序   **********" << std::endl;
	std::cout << "*********  3.第K大                              **********" << std::endl;
	std::cout << "*********  4.第K小                              **********" << std::endl;
	std::cout << "*********  5.选择排序方式并输出排序结果         **********" << std::endl;
	std::cout << "**********************************************************" << std::endl;
}


inline void Show03()
{
	std::cout << "**********************************************************" << std::endl;
	std::cout << "*********             1.插入排序                **********" << std::endl;
	std::cout << "*********             2.归并排序                **********" << std::endl;
	std::cout << "*********             3.快速排序(递归)          **********" << std::endl;
	std::cout << "*********             4.快速排序(非递归)        **********" << std::endl;
	std::cout << "*********             5.计数排序                **********" << std::endl;
	std::cout << "*********             6.基数排序                **********" << std::endl;
	std::cout << "**********************************************************" << std::endl;
}




//测试并显示排序时间
inline void test02(int* a, int N, int* temp, int max)
{
	
	
	double start, finish; /* 定义开始的时间和结束的时间 */

	start = (double)clock();
	insertSort(a, N);
	finish = (double)clock();
	std::cout << "插入排序用时为:" << finish - start << "ms" << std::endl;

	start = (double)clock();
	MergeSort(a, 0, N - 1, temp);
	finish = (double)clock();
	std::cout << "归并排序用时为:" << finish - start << "ms" << std::endl;

	start = (double)clock();
	QuickSort_Recursion(a, 0, N - 1);
	finish = (double)clock();
	std::cout << "快速排序（递归）用时为:" << finish - start << "ms" << std::endl;

	start = (double)clock();
	QuickSort(a, N);
	finish = (double)clock();
	std::cout << "快速排序（非递归）用时为:" << finish - start << "ms" << std::endl;

	start = (double)clock();
	CountSort(a, N, max);
	finish = (double)clock();
	std::cout << "计数排序用时为:" << finish - start << "ms" << std::endl;

	start = (double)clock();
	RadixCountSort(a, N);
	finish = (double)clock();
	std::cout << "基数排序用时为:" << finish - start << "ms" << std::endl;
}


//为数组赋随机值
inline int* test04(int* a, int N, int max)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 1001 + 10;
	}
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out);
	std::cout << "正在打开文件..." << std::endl;
	std::cout << "文件打开成功！" << std::endl;
	std::cout << "正在写入数据..." << std::endl;
	for (int i = 0; i < N; i++)
	{
		ofs << a[i] << " ";
	}
	std::cout << "写入数据完毕，存储于：test.txt" << std::endl;
	ofs.close();
	max = arrayMax(a, N);
	return a;
}


inline int* test09(int* a, int N, int max)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 1001 + 10;
	}
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out);
	for (int i = 0; i < N; i++)
	{
		ofs << a[i] << " ";
	}
	ofs.close();
	max = arrayMax(a, N);
	return a;
}

//小量多次
inline void test08(int* a, int N, int M, int* temp, int max)
{
	double start, finish; /* 定义开始的时间和结束的时间 */
	double t11, t22, t33, t44, t55, t66;
	double t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0;

	for (int i = 0; i < M; i++)
	{
		test09(a, N, max);

		start = (double)clock();
		insertSort(a, N);
		finish = (double)clock();
		t11 = finish - start;
		t1 += t11;

		start = (double)clock();
		MergeSort(a, 0, N - 1, temp);
		finish = (double)clock();
		t22 = finish - start;
		t2 += t22;

		start = (double)clock();
		QuickSort_Recursion(a, 0, N - 1);
		finish = (double)clock();
		t33 = finish - start;
		t3 += t33;

		start = (double)clock();
		QuickSort(a, N);
		finish = (double)clock();
		t44 = finish - start;
		t4 += t44;

		start = (double)clock();
		CountSort(a, N, max);
		finish = (double)clock();
		t55 = finish - start;
		t5 += t55;

		start = (double)clock();
		RadixCountSort(a, N);
		finish = (double)clock();
		t66 = finish - start;
		t6 += t66;
	}
	std::cout << "插入排序用时为:" << t1 << "ms" << std::endl;
	std::cout << "归并排序用时为:" << t2 << "ms" << std::endl;
	std::cout << "快速排序（递归）用时为:" << t3 << "ms" << std::endl;
	std::cout << "快速排序（非递归）用时为:" << t4 << "ms" << std::endl;
	std::cout << "计数排序用时为:" << t5 << "ms" << std::endl;
	std::cout << "基数排序用时为:" << t6 << "ms" << std::endl;
}





//将排序后的数组写在文件里
inline int* test07(int* a, int N)
{
	std::ofstream ofs;
	ofs.open("result.txt", std::ios::out);
	std::cout << "正在打开文件..." << std::endl;
	std::cout << "文件打开成功！" << std::endl;
	std::cout << "正在写入数据..." << std::endl;
	for (int i = 0; i < N; i++)
	{
		ofs << a[i] << " ";
	}
	std::cout << "写入数据完毕，存储于：result.txt" << std::endl;
	ofs.close();
	return a;
}



//生成指定测试数据
inline void test01(int* a, int N, int M, int* temp, int max)
{
	Show01();
	int select;
	std::cout << "请输入你的选择：" << std::endl;
	std::cin >> select;
	switch (select)
	{
	case 1:
	{
		N = 10000;
		M = 1;
		test02(test04(a, N, max), N, temp, max);
		break;
	}
	case 2:
	{
		N = 50000;
		M = 1;
		test02(test04(a, N, max), N, temp, max);
		break;
	}
	case 3:
	{
		N = 200000;
		M = 1;
		test02(test04(a, N, max), N, temp, max);
		break;
	}
	case 4:
	{
		N = 10;
		M = 1000;
		test08(a, N, M, temp, max);
		break;
	}
	default:
	{
		std::cout << "无所输选项！程序无法继续进行！" << std::endl;
		break;
	}
	}
	return;
}





//颜色排序
inline void test03(int* a, int N)
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 3 + 0;
	}
	std::ofstream ofs;
	ofs.open("test.txt", std::ios::out);
	std::cout << "正在打开文件..." << std::endl;
	std::cout << "文件打开成功！" << std::endl;
	std::cout << "正在写入数据..." << std::endl;
	for (int i = 0; i < N; i++)
	{
		ofs << a[i] << " ";
	}
	std::cout << "写入数据完毕，存储于：test.txt" << std::endl;
	ofs.close();
	std::cout << "排序前的数组为:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	ColorSort(a, N);
	std::cout << "排序后的数组为:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}


//第K大
inline void test05(int* a, int N, int k, int* temp)
{
	int ret = FindKmax(a, 0, N, k);
	std::cout <<"第"<<k<<"大的数为："<< ret << std::endl;
}

//第K小
inline void test06(int* a, int N, int k, int* temp)
{
	int ret = FindKmin(a, 0, N, k);
	std::cout << "第" << k << " 小的数为：" << ret << std::endl;
}

