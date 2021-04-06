#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<typename T>

class SqStack
{
protected:
	T* elem;   //栈中元素
	int top;   //顶部
	int size;  //数组的固定长度

public:
	//基于数组的顺序栈
	
	void showMenu();//显示菜单

	SqStack(int sizes);//初始化栈

	bool isEmptyStack();//判断栈是否为空

	T& getTopStack(); //得到栈顶元素

	bool clearStack();//清空栈

	~SqStack();//析构函数，销毁栈

	T& stackLength();//检测栈长度

	void pushStack(const T data);//入栈

	void popStack();//出栈

};


//显示菜单
template<typename T>
void SqStack<T>::showMenu()
{
	std::cout << "***********************************" << std::endl;
	std::cout << "*************0.销毁栈**************" << std::endl;
	std::cout << "*********1.判断栈是否为空**********" << std::endl;
	std::cout << "**********2.得到栈顶元素***********" << std::endl;
	std::cout << "*************3.清空栈**************" << std::endl;
	std::cout << "**********4.检测栈的长度***********" << std::endl;
	std::cout << "***************5.入栈**************" << std::endl;
	std::cout << "***************6.出栈**************" << std::endl;
	std::cout << "***********************************" << std::endl;
}

//初始化栈
template<typename T>
SqStack<T>::SqStack(int sizes)
{
	top = -1;
	size = sizes;
	elem = new T[size];
}



//销毁栈
template<typename T>
SqStack<T>::~SqStack()
{
	if (isEmptyStack())
	{
		std::cout << "输入的为非整型数字，栈被销毁且系统退出！" << std::endl;
		exit(0);
	}
	else
	{
		delete[] elem;
			size = 0;
			top = -1;
	}
}

//判断栈是否为空
template<typename T>
bool SqStack<T>::isEmptyStack()
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//清空栈
template<typename T>
bool SqStack<T>::clearStack()
{
	top = -1;
	size = 0;
	return true;
}

//得到栈顶元素
template<typename T>
T& SqStack<T>::getTopStack()
{
	if (top == -1)
	{
		abort();
	}
	else
	{
		return elem[top];
	}
}

//检测栈的长度
template<typename T>
T& SqStack<T>::stackLength()
{
	return top;
}


//入栈
template<typename T>
void SqStack<T>::pushStack(const T data)
{
	if (stackLength()>= size)
	{
		std::cout << "栈已满，无法入栈！" << std::endl;
		abort();
	}
	elem[++top] = data;
	size++;
	
}



//出栈
template<typename T>
void SqStack<T>::popStack()
{
	if (isEmptyStack())
	{
		std::cout << "栈为空，无法执行出栈操作！" << std::endl;
		abort();
	}
	else
	{
		top--;
	}
}



#endif 
