#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


template<typename T>
class LinkStack
{
	struct StackNode
	{
		T data;
		StackNode* next;
	};
protected:
	StackNode* top;//栈顶指针
	int	count = 0;//初始化栈中元素个数

public:
	//链栈

	void showMenu();//显示菜单

	LinkStack();//初始化栈

	bool isEmptyLStack();//判断栈是否为空

	T& getTopLStack();//得到栈顶元素

	bool clearLStack();//清空栈

	~LinkStack();//销毁栈

	T& LStackLength();//检测栈长度

	void pushLStack(T data);//入栈

	T& popLStack();//出栈
};


//显示菜单
template<typename T>
void LinkStack<T>::showMenu()
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


//初始化链栈
template<typename T>
LinkStack<T>::LinkStack()
{
	top = nullptr;
}


//销毁链栈
template<typename T>
LinkStack<T>::~LinkStack()
{
	StackNode* p = this->top, * q;
	if (isEmptyLStack())
	{
		std::cout << "输入的为非整型数字，栈被销毁且系统退出！" << std::endl;
		exit(0);
	}
	while (p != nullptr)
	{
		q = p->next;
		delete p;
		p = q;
	}
}


//判断栈是否为空
template<typename T>
bool LinkStack<T>::isEmptyLStack()
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//得到栈顶元素
template<typename T>
T& LinkStack<T>::getTopLStack()
{
	if (isEmptyLStack())
	{
		abort();
	}
	else
	{
		return top->data;
	}
}


//清空栈
template<typename T>
bool LinkStack<T>::clearLStack()
{
	StackNode* p = nullptr;
	if (top == nullptr)
	{
		abort();
	}
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
	return true;
}


//检测栈的长度
template<typename T>
T& LinkStack<T>::LStackLength()
{
	if (top == nullptr)
	{
		abort();
	}
	else
	{
		return count;
	}
}


//入栈
template<typename T>
void LinkStack<T>::pushLStack(T data)
{
	StackNode* p = new StackNode();
	p->data = data;
	if (top == nullptr)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
	count++;
}


//出栈
template<typename T>
T& LinkStack<T>::popLStack()
{
	if (top == nullptr)
	{
		abort();
	}
	else
	{
		StackNode* p = top;
		T elem = top->data;
		top = top->next;
		delete p;
		return elem;
	}
}

#endif 