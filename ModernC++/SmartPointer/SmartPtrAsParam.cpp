// Smart Pointerを関数に渡す方法の調査
// 参考：http://herbsutter.com/2013/06/05/gotw-91-solution-smart-pointer-parameters/

#include <iostream>
#include <memory>

class MyClass {
private:
    int m_a;
    int m_b;
public:
    MyClass(int a, int b)
        : m_a(a), m_b(b){};
    void debugPrint() {
        std::cout << "a, b = " << m_a << ", " << m_b << std::endl;
    }
};

std::unique_ptr<MyClass> funcForUniquePtr1(std::unique_ptr<MyClass> m) {
    std::cout << "func is called." << std::endl;
    m->debugPrint();
    return std::move(m);
}

void funcForUniquePtr2(std::unique_ptr<MyClass>& m) {
    std::cout << "func is called." << std::endl;
    m->debugPrint();
}

void funcForUniquePtr3(MyClass& m) {
    std::cout << "func is called." << std::endl;
    m.debugPrint();
}

void funcForUniquePtr4(MyClass* m) {
    std::cout << "func is called." << std::endl;
    m->debugPrint();
}

void funcForSharedPtr(std::shared_ptr<MyClass> m) {
    std::cout << "func is called." << std::endl;
    m->debugPrint();
    return;
}

// unique pointerを引数にとる関数を呼ぶ
void uniquePtrTest() {
    std::unique_ptr<MyClass> p1(new MyClass(10, 20));
    p1->debugPrint();

    // moveを使って所有権を移動させる
    p1 = funcForUniquePtr1(std::move(p1));
    p1->debugPrint();

    // 参照を使う
    funcForUniquePtr2(p1);
    p1->debugPrint();

    // 中身を参照で渡す
    funcForUniquePtr3(*p1);
    p1->debugPrint();

    // 中身をポインタで渡す
    funcForUniquePtr4(p1.get()); // get()により生ポインタを取得
    p1->debugPrint();
}

// shared pointerを引数にとる関数を呼ぶ
void sharedPtrTest() {
    std::shared_ptr<MyClass> p2(new MyClass(4, 7));
    p2->debugPrint();
    funcForSharedPtr(p2);
    p2->debugPrint();
}

int main() {
    uniquePtrTest();
    sharedPtrTest();
    return 0;
}
