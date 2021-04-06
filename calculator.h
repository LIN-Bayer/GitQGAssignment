



#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H
#define STACK_INIT_SIZE  20//��ʼ�������
#define STACKINCREMENT  10//ջ��ʱ��̬����������ÿ������10��Ԫ�ؿռ�
#define MAXBUFFER  10//��󻺳���
#define MAX_EXP_LEN  100//���ʽ�Ϊ100

template<typename T>
class Calculator
{
public:
    struct sqStack
    {
        T* base;//ָ��ջ��
        T* top;
        int Size;//��ǰջ���������
    };

    Calculator(); //��ʼ��ջ

    ~Calculator();//����ջ

    void Push(T data);//��ջ

    float Pop(T& data);//��ջ

    void clearStack();//���ջ

    bool isEmpty(); //�ж��Ƿ�Ϊ��

    int StackLen();//ջ��Ԫ����ռ����

    int Priority(char a);

    int Calculation(char Suffix[]);//��׺���ʽ�ļ���

    bool InfixToSuffix(char Infix[], char Suffix[]);//��׺���ʽ��Ϊ��׺���ʽ

private:
    sqStack s;

};



template<typename T>
Calculator<T>::Calculator()
{
    s.base = new T[STACK_INIT_SIZE];//ջ��ָ������ռ���׵�ַ
    if (s.base == NULL)//����ʧ��
    {
        exit(0);
    }
    s.top = s.base;
    s.Size = STACK_INIT_SIZE;
}

//����ջ�����ڴ�ռ��ͷ�
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
        //��̬�����ռ�
        s.base = (T*)realloc(s.base, (s.Size + STACKINCREMENT) * sizeof(T));
        if (s.base == NULL)
        {
            exit(0);
        }
        s.top = s.base + s.Size; //��������ջ��
        s.Size = s.Size + STACKINCREMENT;
    }
    *(s.top) = data;
    s.top++;
}

template<typename T>
float Calculator<T>::Pop(T& data)
{
    if (s.top == s.base)
        return false;//��ջ
    data = *(--(s.top));
    return data;
}

//�Ƿ�Ϊ��
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

//���ջ�����ı�����ռ�
template<typename T>
void Calculator<T>::clearStack()
{
    s.top = s.base;
}

//����ջ�ĵ�ǰ�������洢������������Ԫ�ظ�����
template<typename T>
int Calculator<T>::StackLen()
{
    return s.top - s.base;
}


//���ȼ�
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
        while ((Suffix[j] >= 48) && (Suffix[j] <= 57) || Suffix[j] == '.') //�����������
        {
            str[i] = Suffix[j];
            i++;
            str[i] = '\0';
            if (i >= 10)
            {
                std::cout << "��������ݳ��ȹ���!�޷�ִ�У�" << std::endl;
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
            if (!Pop(b))//��ֹ���Ƿ���λ����Ŀ�������
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
                std::cout << "0������Ϊ������" << std::endl;
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

    std::cout << "��׺���ʽΪ��" << std::endl;
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
           std::cout << "�����ʽ����" << std::endl;
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