#include <iostream>
#include "Application.h"
int main()
{
//    Application a1, a2, a3;
//    Application *aP = &a3;
//    a1.run();
//    aP->setData("30");
//    a1.appPointerPush(aP);
    Application a;
    a.run();
    return 0;
}

//hello
#include <iostream>
#define print std::cout <<
int helloWorld()
{
    std::string str = "bleh";
    int num = 3;
    float num1 = 4.000;
    if(num > num1)
    {
        num = 1;
        2 + 2;
        print num;
    }
    for(int i=-1; i<2; i++)
    {
        num1 = 40.00000;
    }
    while(num1 == 40)
    {
        num1 = 50.0000;
    }

    return -1;
}


struct bleh
{
    std::string s;
};
class thingy
{
private:
    bleh b;
public:
    void setBlehString(std::string s)
    {
        b.s = s;
    }
};
