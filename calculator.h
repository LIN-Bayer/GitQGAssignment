



#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#define STACK_INIT_SIZE  20//初始最大容量
#define STACKINCREMENT  10//栈满时动态增加容量，每次增加10个元素空间
#define MAXBUFFER  10//最大缓冲区
#define MAX_EXP_LEN  100//表达式最长为100

template<typename T>
class Calculator
{
public:
    struct sqStack
    {
        T* base;//指向栈顶
        T* top;
        int Size;//当前栈的最大容量
    };

    Calculator(); //初始化栈

    ~Calculator();//销毁栈

    void Push(T data);//入栈

    float Pop(T& data);//出栈

    void clearStack();//清空栈

    bool isEmpty(); //判断是否为空

    int StackLen();//栈中元素所占长度

    int Priority(char a);

    int Calculation(char Suffix[]);//后缀表达式的计算

    bool InfixToSuffix(char Infix[], char Suffix[]);//中缀表达式变为后缀表达式

private:
    sqStack s;

};



template<typename T>
Calculator<T>::Calculator()
{
    s.base = new T[STACK_INIT_SIZE];//栈底指向申请空间的首地址
    if (s.base == NULL)//申请失败
    {
        exit(0);
    }
    s.top = s.base;
    s.Size = STACK_INIT_SIZE;
}

//销毁栈，将内存空间释放
template<typename T>
Calculator<T>::~Calculator()
{
    delete[]s.base;
}

template<typename T>
void Calculator<T>::Push(T data)
{
    if (s.top - s.base >= s.Size)
    {
        //动态扩增空间
        s.base = (T*)realloc(s.base, (s.Size + STACKINCREMENT) * sizeof(T));
        if (s.base == NULL)
        {
            exit(0);
        }
        s.top = s.base + s.Size; //重新设置栈顶
        s.Size = s.Size + STACKINCREMENT;
    }
    *(s.top) = data;
    s.top++;
}

template<typename T>
float Calculator<T>::Pop(T& data)
{
    if (s.top == s.base)
        return false;//空栈
    data = *(--(s.top));
    return data;
}

//是否为空
template<typename T>
bool Calculator<T>::isEmpty()
{
    if (s.top == s.base)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//清空栈，不改变物理空间
template<typename T>
void Calculator<T>::clearStack()
{
    s.top = s.base;
}

//计算栈的当前容量（存储的数据量或者元素个数）
template<typename T>
int Calculator<T>::StackLen()
{
    return s.top - s.base;
}


//优先级
template<typename T>
int Calculator<T>::Priority(char a)
{
    if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


template<typename T>
int Calculator<T>::Calculation(char Suffix[])
{
    int i = 0, j;
    char c;
    char str[MAXBUFFER];
    double a = 0, b = 0;

    for (j = 0; Suffix[j] != '\0'; j++)
    {
        ;
        while ((Suffix[j] >= 48) && (Suffix[j] <= 57) || Suffix[j] == '.') //输入的是数字
        {
            str[i] = Suffix[j];
            i++;
            str[i] = '\0';
            if (i >= 10)
            {
                std::cout << "输入的数据长度过大!无法执行！" << std::endl;
                return -1;
            }
            j++;
            if ((Suffix[j] == ' '))
            {
                a = atof(str);
                Push(a);
                i = 0;
            }

        }

        switch (Suffix[j])
        {
        case '+':
            Pop(a);
            if (!Pop(b))//防止这是符号位（单目运算符）
            {
                Push(a);
                break;
            }
            Pop(b);;
            Push(b + a);
            break;
        case '-':
            Pop(a);
            if (!Pop(b))
            {
                Push(-a);
                break;
            }
            Push(b - a);
            break;
        case '*':
            Pop(a);
            Pop(b);
            Push(b * a);
            break;
        case '/':
            Pop(a);
            if (a == 0)
            {
                std::cout << "0不能作为除数！" << std::endl;
                return -1;
            }
            Pop(b);
            Push(b / a);

            break;
        default:
            break;
        }
    }
    Pop(a);
    return a;
}




template<typename T>
bool Calculator<T>::InfixToSuffix(char Infix[], char Suffix[])
{
    Calculator<char> s;
    int i = 0, j = 0;
    char e;

    std::cout << "后缀表达式为：" << std::endl;
   while (Infix[j] != '\0')
   {
       while (Infix[j] >= '0' && Infix[j] <= '9')
       {
           std::cout << Infix[j];
           Suffix[i++] = Infix[j];
           j++;
           if (Infix[j] < '0' || Infix[j]>'9')
           {
               Suffix[i++] = ' ';
               /*std::cout << ' ';*/
           }
       }

       switch (Infix[j])
       {

       case ')':
           s.Pop(e);
           while ('(' != e)
           {
               std::cout << e << std::endl;
               Suffix[i++] = e;
               Suffix[i++] = ' ';
               s.Pop(e);
           }
           break;

       case '+':
       case '-':
           if (0 == s.StackLen())
               s.Push(Infix[j]);
           else
           {
               do
               {
                   s.Pop(e);
                   if ('(' == e)
                   {
                       s.Push(e);
                   }
                   else
                   {
                       std::cout << e << std::endl;
                       Suffix[i++] = e;
                       Suffix[i++] = ' ';
                   }
               } while (s.StackLen() && '(' != e);
               s.Push(Infix[j]);
           }
           break;

       case '*':
       case '/':
       case '(':
           s.Push(Infix[j]);
           break;

       case '\0':
           break;

       default:
           std::cout << "输入格式错误！" << std::endl;
           return -1;
       }

       if ('\0' == Infix[j])
           break;
       j++;
   }

   while (s.StackLen())
   {
       s.Pop(e);
       std::cout << e;
       Suffix[i++] = e;
       Suffix[i++] = ' ';
   }
   Suffix[i] = '\0';
   return true;


}


#endif 