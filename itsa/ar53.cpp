#include <iostream>
#include <algorithm> //sort()
using namespace std;
// 學生成績排序
int main()
{
    int n; //學生數
    cin >> n;
    int grade[n]; //成績
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i];
    }
    sort(grade, grade + n);
    for (int i = 0; i < n; i++)
    {
        cout << grade[i] << endl;
        ;
    }
    return 0;
}