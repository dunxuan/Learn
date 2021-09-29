#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float x1 = 0;
    float x2 = 0;
    float delta = 0;
    char mod = 0;
    char confirm = 0;

    for (;;)    {
        cout << "求解ax²+bx+c=0, 输入求解一元二次函数 (q) 或一元一次函数 (l) ";
        cout << endl;
        cin >> mod;
        if (mod == 'q' || mod == 'Q') {
            //一元二次函数
            //输入过程
            do  {
                //输入abc中
                cout << "a=";
                cin >> a;
                cout << endl;
                while (!a)  {
                    cout << "a不能等于0，切换到一元一次函数 (l) 或 重新输入 (r)";
                    cout << endl;
                    cin >> confirm;
                    if (confirm == 'l' || confirm == 'L')   {
                        goto LINEAR;                //跳到一元一次函数区域
                    } else if (confirm == 'r' || confirm == 'R')    {
                        cout << "a=";
                        cin >> a;
                        cout << endl;
                    }
                }
                cout << "b=";
                cin >> b;
                cout << endl;
                cout << "c=";
                cin >> c;
                cout << endl;
                //确认过程
                cout << "解";
                cout << a;
                cout << "x²+";
                cout << b;
                cout << "x+";
                cout << c;
                cout << "=0";
                cout << endl;
                do {
                    cout << "确认(Y) 取消并重新输入(n)";
                    cout << endl;
                    cin >> confirm;
                } while (confirm != 'Y' || confirm != 'y' || confirm != 'N' || confirm != 'n');
            } while (confirm =='N' || confirm == 'n');

            //运算过程
            delta = b * b - 4 * a * c;
            x1 = (-b - sqrt(delta) / (2 * a));
            x2 = (-b + sqrt(delta) / (2 * a));

            //输出结果
            cout << "x₁=";
            cout << x1;
            cout << endl;
            cout << "x₂=";
            cout << x2;
            cout << endl;
        } else if (mod == 'l' || mod == 'L')    {
            //一元一次函数
            LINEAR:             //goto跳转
            //输入过程
            do {
                cout << "b=";
                cin >> b;
                cout << endl;
                while (!b)  {
                    cout << "b不能等于0，请重新输入";
                    cout << endl;
                    cout << "b=";
                    cin >> b;
                    cout << endl;
                }
                cout << "c=";
                cin >> c;
                cout << endl;
                //确认过程
                cout << "解";
                cout << b;
                cout << "x+";
                cout << c;
                cout << "=0";
                cout << endl;
                do {
                    cout << "确认(Y)     取消并重新输入(n)";
                    cout << endl;
                    cin >> confirm;
                } while (confirm != 'Y' || confirm != 'y' || confirm != 'N' || confirm != 'n');
            } while (confirm == 'n' || confirm == 'N');

            //运算过程
            x1 = -c / b;

            //输出结果
            cout << "x=";
            cout << x1;
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}