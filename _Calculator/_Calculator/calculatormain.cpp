#include <iostream>
#include"Calculator.h"


int main()
{
    class Calculator<double> cal;
    char Infix[MAX_EXP_LEN], Suffix[MAX_EXP_LEN];
    int back;
    while (true)
    {
        std::cout << "欢迎使用本计算器*^·^*" << std::endl;
        std::cout << "本计算器输入的表达式的运算数只能为个位数，若输入了多位数会导致结果出错！" << std::endl;
        std::cout << "若需要输入多位数请根据数字自行将其转化为个位数字的运算表达式！" << std::endl;
        std::cout << "是否选择进入运算系统？" << std::endl;
        std::cout << "1.是   2.否" << std::endl;
        std::cin >> back;
        switch (back)
        {
        case 1:
        {
            std::cout << "请输入运算表达式(注意：输入回车即为表达式输入结束)：" << std::endl;
            std::cin >> Infix;
            double sum;
            cal.InfixToSuffix(Infix, Suffix);
            sum = cal.Calculation(Suffix);
            std::cout << "运算结果为：" << sum << std::endl;
            std::system("pause");
            std::system("cls");
            break;
        }
        case 2:
            std::cout << "欢迎下次使用！" << std::endl;
            return 0;
        default:
            std::cout << "操作有误！" << std::endl;
            break;
        }
    }
    return 0;
}