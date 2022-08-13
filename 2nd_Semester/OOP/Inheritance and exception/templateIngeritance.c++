// #include <iostream>
// using namespace std;

// template <class T>
// class Base
// {
// private:
//     T b;

// public:
//     void setter(T b)
//     {
//         this->b = b;
//     }
//     void getter()
//     {
//         cout << "b = " << b << endl;
//     }
// };

// template <class T>
// class Derived : public Base<T>
// {
// private:
//     int d;

// public:
//     void setter(T b, T d)
//     {
//         this->d = d;
//         Base<T>::setter(b);
//     }
//     void getter()
//     {
//         Base<T>::getter();
//         cout << "d = " << d << endl;
//     }
// };

// int main()
// {
//     Derived<int> derived;
//     derived.setter(69, 420);
//     derived.getter();
//     return 0;
// }

#include <iostream>
using namespace std;

template <class X>
class Person
{
private:
    X marks;

public:
    void setter(X marks)
    {
        this->marks = marks;
    }
    void getter()
    {
        cout << marks << endl;
    }
};

template <class X>
class Man : public Person<X>
{
private:
    int age;

public:
    void setter(X marks, X age)
    {
        this->age = age;
        Person<X>::setter(marks);
    }

    void getter()
    {
        Person<X>::getter();
        cout << this->age << endl;
    }
};

int main()
{
    Man<int> male;
    male.setter(22, 30);
    male.getter();
    return 0;
}