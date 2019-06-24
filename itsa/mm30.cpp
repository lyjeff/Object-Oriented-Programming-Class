#include <iostream>
#include <cmath>
using namespace std;
// 質數判別
int main()
{
     int num, count;
     while (cin >> num)
     {
          for (int j = 1; j <= num; j++)
               if (num % j == 0) //計算可以被除盡的次數
                    count++;
          if (count == 2) //等於二代表只有1和數字本身
               cout << "YES" << endl;
          else
               cout << "NO" << endl;
          count = 0;
     }
}