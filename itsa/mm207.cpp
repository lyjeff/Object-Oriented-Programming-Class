#include <iostream>
using namespace std;
// 求數字和
int main()
{
    int num, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        sum = sum + ((num + 1) % 13);
    }
    cout << sum << endl;
    return 0;
}