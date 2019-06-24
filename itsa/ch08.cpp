#include <iostream>
using namespace std;
// 計算MVP數值
int main()
{
    int score, rebounds, assists, screenshots, errors;
    //平均得分、籃板數  、助攻數 、  抄截數   、失誤數。
    int mvp;
    while (cin >> score >> rebounds >> assists >> screenshots >> errors)
    {
        mvp = (score * 1 + assists * 2 + rebounds * 2 + screenshots * 2) - (errors * 2);
        if (mvp >= 45)
            cout << "A" << endl;
        else if (35 <= mvp && mvp <= 44)
            cout << "B" << endl;
        else if (25 <= mvp && mvp <= 34)
            cout << "C" << endl;
        else if (mvp < 25)
            cout << "D" << endl;
    }
    return 0;
}