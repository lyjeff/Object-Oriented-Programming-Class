#include <iostream>
using namespace std;
// 判斷奇數偶數
int main()
{
    int num; //帶測數字
    while (cin >> num)
    {
        if (num % 2 == 0) //被二整除者為偶數
            cout << "even" << endl;
        else //否則為基數
            cout << "odd" << endl;
    }
    return 0;
}