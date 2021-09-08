#include <iostream>
#include <vector>

using namespace std;

class A {
    // virtual void test() = 0;
    virtual int getValue() = 0;
    virtual void setValue(int value) = 0;

   protected:
    int m_value;
};

class B : public A {
   public:
    virtual void setValue(int value) override { m_value = value; }
    virtual int getValue() override { return m_value; }
};

void fun(char *&p) { p = (char *)malloc(sizeof(char) * 10); }

int main() {
    // 1
    // B *b = new B;
    // b->setValue(1);
    // std::cout << b->getValue() << std::endl;

    // 2
    // const int upper = 10;
    // vector<int> testArray;
    // testArray.push_back(5);
    // testArray.push_back(6);
    // for (auto it = testArray.begin(); it != testArray.end(); ++it) {
    //     if (*it < upper) {
    //         cout << upper - *it << endl;
    //         testArray.push_back(upper - *it);
    //     }
    // }
    // for (auto &test : testArray) {
    //     cout << test << endl;
    // }

    // 3
    for (int i = 0; i < 10000000; i++) {
        char *p = NULL;
        fun(p);
        free(p);
    }
    return 0;
}
