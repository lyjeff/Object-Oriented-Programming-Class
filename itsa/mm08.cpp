#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
// 計算 i 次方的值
int main()
{
    int num_1, num_2, result;
    cin >> num_1 >> num_2;
    result = pow((num_1 + num_2), 2);
    cout << result << endl;
    return 0;
}