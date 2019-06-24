#include <iostream>
using namespace std;
// 猜數字
int main()
{
    int a, b, c; //百,十,個
    int num;
    cin >> num;
    for (a = 0; a < 10; a++)
        for (b = 0; b < 10; b++)
            for (c = 0; c < 10; c++)
                if (num == ((a + b + c) * 222 - (a * 100 + b * 10 + c)))
                    cout << a << b << c << endl;
    return 0;
}