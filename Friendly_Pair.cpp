#include <iostream>
using namespace std;

int getDivisorsSum(int num)
{

    int sum = 0;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum = sum + i;
    }
    return sum;
}

int main()
{
    int num1 = 30, num2 = 140;

    int sum1 = getDivisorsSum(num1);
    int sum2 = getDivisorsSum(num2);

    if (sum1 / num1 == sum2 / num2)
        cout << num1 << " & " << num2 << " are friendly pairs";
    else
        cout << num1 << " & " << num2 << " are not friendly pairs";
}