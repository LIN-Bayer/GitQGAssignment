#include <iostream>
#include"Calculator.h"


int main()
{
    class Calculator<double> cal;
    char Infix[MAX_EXP_LEN], Suffix[MAX_EXP_LEN];
    int back;
    while (true)
    {
        std::cout << "��ӭʹ�ñ�������*^��^*" << std::endl;
        std::cout << "������������ı��ʽ��������ֻ��Ϊ��λ�����������˶�λ���ᵼ�½������" << std::endl;
        std::cout << "����Ҫ�����λ��������������н���ת��Ϊ��λ���ֵ�������ʽ��" << std::endl;
        std::cout << "�Ƿ�ѡ���������ϵͳ��" << std::endl;
        std::cout << "1.��   2.��" << std::endl;
        std::cin >> back;
        switch (back)
        {
        case 1:
        {
            std::cout << "������������ʽ(ע�⣺����س���Ϊ���ʽ�������)��" << std::endl;
            std::cin >> Infix;
            double sum;
            cal.InfixToSuffix(Infix, Suffix);
            sum = cal.Calculation(Suffix);
            std::cout << "������Ϊ��" << sum << std::endl;
            std::system("pause");
            std::system("cls");
            break;
        }
        case 2:
            std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
            return 0;
        default:
            std::cout << "��������" << std::endl;
            break;
        }
    }
    return 0;
}