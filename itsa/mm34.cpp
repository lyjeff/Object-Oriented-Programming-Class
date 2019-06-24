#include <iostream>
using namespace std;
// 因數問題
int main()
{
    int num; //要找出此數字的因數
    while (cin >> num)
        for (int i = 1; i <= num; i++) //1~num開始測試
            if (num % i == 0)          //可以被整除的就是因數
            {
                if (i == num)
                    cout << i << endl; //當最後一個因數時，輸出的是換行
                else
                    cout << i << " "; //否則都是i加上空白
            }
    return 0;
}