#include <iostream>
using namespace std;

class dog {
    private:
    char tail[10]="\n~~~\n";   /* 私有成员，“别人”不能碰狗的尾巴 */

    public: 
    void wag()                 /* 公有成员，“别人”可以叫狗摇尾巴 */
    { 
        cout << tail;
    }
};



int main()
{
    dog wangcai;
    cout << wangcai.tail; 	       /* 错误：访问私有成员 */
    wangcai.wag();                 /* 正确：访问公有成员 */

    return 0;
}
