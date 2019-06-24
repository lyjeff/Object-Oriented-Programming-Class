#include <iostream>
#include <cmath>
using namespace std;
// armstrong數
int main()
{
    int num; //使用者要測試的數字
    double Armstrong, a, b, c;
    while (cin >> num)
    {
        a = floor(num / 100);                          //百位
        b = num / 10 % 10;                             //十位
        c = num % 10;                                  //個位
        Armstrong = pow(a, 3) + pow(b, 3) + pow(c, 3); //各個位數數字之立方和
        if (num == Armstrong)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}