#include"qgsort.h"
#include"test.cpp"
#include <time.h>
#include<assert.h>
#include <fstream>


//int a[200000];
//int temp[200000];

int main()
{
	int N = 0, M = 0, k;
	int select,choice;
	int* a = new int[200000];
	int* temp = new int[200000];
	int max = 0;
	std::cout << "请输入你的选择：" << std::endl;
	
	while (1)
	{
		Show02();
		std::cin >> select;
		switch (select)
		{
		case 1:
			test01(a, N, M, temp, max);
			break;
		case 2:
			std::cout << "请先设定所需数组长度（小于200000）:" << std::endl;
			std::cin >> N;
			test03(a, N);
			test07(a, N);
			break;
		case 3:
			std::cout << "请先设定所需数组长度（小于200000）:" << std::endl;
			std::cin >> N;
			std::cout << "请输入你要找的序号:" << std::endl;
			std::cin >> k;
			test05(test04(a, N, max), N, k,temp);
			test07(a, N);
			break;
		case 4:
			std::cout << "请先设定所需数组长度（小于200000）:" << std::endl;
			std::cin >> N;
			std::cout << "请输入你要找的序号:" << std::endl;
			std::cin >> k;
			test06(test04(a, N, max), N, k,temp);
			test07(a, N);
			break;
		case 5:
		{
			std::cout << "请先设定所需数组长度（小于200000）:" << std::endl;
			std::cin >> N;
			Show03();
			std::cout << "请输入你的选择：" << std::endl;
			std::cin >> choice;
			switch (choice)
			{
			case 1:
				insertSort(test04(a, N, max), N);
				test07(a, N);
				break;
			case 2:
				MergeSort(test04(a, N, max), 0, N, temp);
				test07(a, N);
				break;
			case 3:
				QuickSort_Recursion(test04(a, N, max), 0, N);
				test07(a, N);
				break;
			case 4:
				QuickSort(test04(a, N, max), N);
				test07(a, N);
				break;
			case 5:
				CountSort(test04(a, N, max), N, max);
				test07(a, N);
				break;
			case 6:
				RadixCountSort(test04(a, N, max), N);
				test07(a, N);
				break;
			default:
				std::cout << "输入有误！" << std::endl;
				break;
			}
			std::cout << "排序后数组为:" << std::endl;
			for (int i = 0; i < N; i++)
			{
				std::cout << a[i] << " ";
			}
			std::cout << std::endl;
			break;
		}
		default:
			std::cout << "输入有误！" << std::endl;
			break;
		}
		std::system("pause");
		std::system("cls");
	}
	delete[] a;
	delete[] temp;



	/*std::ifstream ifs;
	ifs.open("test.txt", std::ios::in);

	if (!ifs.is_open())
	{
		std::cout << "文件打开失败" << std::endl;
		return -1;
	}
	int c;
	while ((c = ifs.get()) != EOF)
	{
		std::cout << c<<" ";
	}

	ifs.close();*/

	
	return 0;


}