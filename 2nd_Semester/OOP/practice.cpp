#include <iostream>
using namespace std;

class sample
{
private:
    int a, b;

public:
    void setter()
    {
        a = 20;
        b = 30;
    }

    friend float mean(sample);
};

float mean(sample s1)
{
    return (s1.a + s1.b) / 2;
}

int main()
{
    sample s;
    s.setter();
    cout << mean(s);
    return 0;
}

// #include <iostream>
// using namespace std;

// class B;
// class A
// {
// private:
//     int a;

// public:
//     A(int a)
//     {
//         this->a = a;
//     }
//     friend void mult(A, B);
// };

// class B
// {
// private:
//     int b;

// public:
//     B(int b)
//     {
//         this->b = b;
//     }
//     friend void mult(A, B);
// };

// void mult(A a, B b)
// {
//     cout << a.a * b.b << endl;
// }

// int main()
// {
//     A a(12);
//     B b(12);
//     mult(a, b);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class B;
// class A
// {
// private:
//     int a;

// public:
//     A(int a)
//     {
//         this->a = a;
//     }
//     friend int mul(A, B);
// };

// class B
// {
// private:
//     int b;

// public:
//     B(int b)
//     {
//         this->b = b;
//     }
//     friend int mul(A, B);
// };

// int mul(A a, B b)
// {
//     return a.a * b.b;
// }

// int main()
// {
//     A a(20);
//     B b(30);
//     cout << mul(a, b);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {

//     int a = (10 < 5) ? true : false;
//     cout << a << endl;

//     int *p = new int(5);

//     for (int i = 0; i < 5; i++)
//     {
//         cin >> *(p + i);
//     }

//     for (int i = 0; i < 5; i++)
//     {
//         cout << *(p + i) << endl;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Student
// {
// private:
//     int age;
//     static int count;

// public:
//     Student() { count++; }
//     void setter(int age)
//     {
//         this->age = age;
//     }

//     void getter()
//     {
//         cout << "Age: " << age << endl;
//     }

//     static void countGetter()
//     {
//         cout << "Count: " << count << endl;
//     }
// };

// int Student::count = 0;

// int main()
// {
//     Student stude1, stude2, stude3;
//     stude1.setter(34);
//     stude1.getter();
//     // cout << Student::count << endl;
//     Student::countGetter();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int a;

// public:
//     A() {}

//     A(int a)
//     {
//         this->a = a;
//     }

//     void operator++()
//     {
//         ++a;
//     }

//     void getData()
//     {
//         cout << a << endl;
//     }

//     void operator++(int)
//     {
//         a++;
//     }

//     A operator+(A a)
//     {
//         A b;
//         b.a = this->a + a.a;
//         return b;
//     }
// };

// int main()
// {
//     A a(3);
//     ++a;
//     a.getData();
//     a++;
//     a.getData();
//     A b(5);
//     A c;
//     c = b + a;
//     c.getData();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int data;

// public:
//     A() {}

//     A(int data)
//     {
//         this->data = data;
//     }

//     A operator-(A a)
//     {
//         return data - a.data;
//     }

//     void getData()
//     {
//         cout << data << endl;
//     }
// };

// int main()
// {
//     A a(5), b(10), c(20), d;
//     d = c - b - a;
//     d.getData();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int a;

// public:
//     A() {}

//     A(int a)
//     {
//         this->a = a;
//     }

//     int operator>(A a)
//     {
//         if (this->a > a.a)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     int operator<(A a)
//     {
//         if (this->a < a.a)
//         {
//             return 1;
//         }
//         return 0;
//     }
// };

// int main()
// {
//     A a(2), b(3), c(4);
//     cout << (a > b) << endl;
//     cout << (a < b) << endl;
//     cout << (c > b) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int x;

// public:
//     A() {}

//     A(int x)
//     {
//         this->x = x;
//     }

//     friend A operator+(A, A);

//     void getData()
//     {
//         cout << this->x << endl;
//     }
// };

// A operator+(A a, A b)
// {
//     return a.x + b.x;
// }

// int main()
// {
//     A a(3), b(4), c;
//     c = a + b;
//     c.getData();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class time
// {
// private:
//     int hrs, mins;

// public:
//     time() {}

//     time(int h, int m)
//     {
//         hrs = h;
//         mins = m;
//     }
//
//      time(time &t)
//      {
//          this->hrs = t.hrs;
//          this->mins = t.mins;
//      }

//     void operator=(time &t)
//     {
//         hrs = t.hrs;
//         mins = t.mins;
//     }

//     void getData()
//     {
//         cout << "Hour: " << hrs
//              << "Minute: " << mins << endl;
//     }
// };

// int main()
// {
//     time a(12, 34), c;
//     time b(a);
//     c = a;
//     a.getData();
//     b.getData();
//     c.getData();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     void show()
//     {
//         cout << "This is A." << endl;
//     }
// };

// class B : public A
// {
// public:
//     void show()
//     {
//         cout << "This is B." << endl;
//     }
// };

// int main()
// {
//     A a;
//     B b;
//     a.show();
//     b.show();
//     b.A::show();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class ParentA
// {
// public:
//     void show()
//     {
//         cout << "This is Parent A." << endl;
//     }
// };

// class ParentB
// {
// public:
//     void show()
//     {
//         cout << "This is Parent B." << endl;
//     }
// };

// class Child : public ParentA, public ParentB
// {
// };

// int main()
// {
//     Child child;
//     child.ParentA::show();
//     child.ParentB::show();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class GrandParent
// {
// public:
//     int gp;
// };

// class Parent1 : virtual public GrandParent
// {
// public:
//     int p1;
// };

// class Parent2 : virtual public GrandParent
// {
// public:
//     int p2;
// };

// class Child : public Parent1, public Parent2
// {
// public:
//     int c;
// };

// int main()
// {
//     Child child;
//     child.gp = 12;
//     child.Parent1::gp = 12;
//     child.Parent2::gp = 12;
//     child.GrandParent::gp = 12;
//     cout << child.gp << endl;
//     cout << child.Parent1::gp << endl;
//     cout << child.Parent2::gp << endl;
//     cout << child.GrandParent::gp << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template <typename X, class Y>
// double myMax(X a, Y b)
// {
//     return (a > b) ? a : b;
// }

// int main()
// {
//     cout << myMax(2, 3.5) << endl;
//     cout << myMax(25, 0.3) << endl;
//     cout << myMax('x', 122) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// template <class X>
// class A
// {
// private:
//     X a;

// public:
//     A(X a)
//     {
//         this->a = a;
//     }
//     X get()
//     {
//         return a;
//     }
// };

// int main()
// {
//     A<int> a(2);
//     cout << a.get() << endl;
//     A<float> b(2.23);
//     cout << b.get() << endl;
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     ifstream fin;
//     fin.open("file.txt");
//     char ch;

//     while (!fin.eof())
//     {
//         fin.get(ch);
//         cout.put(ch);
//     }
//     fin.close();
//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     int age;
//     char name[100];

//     ofstream fout;
//     fout.open("name.txt");

//     cout << "Enter your name: ";
//     cin.getline(name, 100);
//     fout << name << endl;

//     cout << "Enter your age: ";
//     cin >> age;
//     fout << age << endl;

//     fout.close();

//     ifstream fin;
//     fin.open("name.txt");

//     fin.getline(name, 100);
//     fin >> age;

//     cout << "Name: " << name << endl;
//     cout << "Age: " << age << endl;

//     fin.close();

//     return 0;
// }

// /*
//     fin.read((char*)&stud, sizeof(student));
//     fout.write((char*)&stud, sizeof(student));
// */

// #include <iostream>
// #include <fstream>
// using namespace std;

// class Student
// {
// private:
//     int roll;
//     string name, address;

// public:
//     void setData()
//     {
//         cout << "Enter roll: ";
//         cin >> roll;
//         fflush(stdin);
//         cout << "Enter name: ";
//         getline(cin, name);
//         fflush(stdin);
//         cout << "Enter address: ";
//         getline(cin, address);
//     }

//     void getData()
//     {
//         cout << "Roll: " << roll << endl
//              << "Name: " << name << endl
//              << "Address: " << address << endl;
//     }
// };

// int main()
// {
//     Student std;
//     int choice;
//     cout << "Press:" << endl
//          << "1) Enter Student Data" << endl
//          << "2) Get Student Data" << endl;
//     cin >> choice;

//     if (choice == 1)
//     {
//         ofstream fout;
//         fout.open("Student.txt");
//         for (int i = 0; i < 2; i++)
//         {
//             cout << "Number: " << i + 1 << endl;
//             std.setData();
//             fout.write((char *)&std, sizeof(Student));
//         }
//         fout.close();
//     }
//     else if (choice == 2)
//     {
//         ifstream fin;
//         fin.open("Student.txt");
//         for (int i = 0; i < 2; i++)
//         {
//             cout << "Number: " << i + 1 << endl;
//             fin.read((char *)&std, sizeof(Student));
//             std.getData();
//         }
//         fin.close();
//     }
//     else
//     {
//         cout << "Enter a valid option.\n\a" << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <fstream>
// using namespace std;
// class student
// {
//     int roll;
//     char name[20];
//     char address[50];

// public:
//     void setData()
//     {
//         cout << "Enter roll:" << endl;
//         cin >> roll;
//         cout << "Enter name:" << endl;
//         cin >> name;
//         cout << "Enter address:" << endl;
//         cin >> address;
//     }
//     void getData()
//     {
//         cout << "Roll:" << roll << endl
//              << "Name:" << name << endl
//              << "Address:" << address << endl;
//     }
// };
// int main()
// {
//     // student s;
//     // ofstream fout;
//     // fout.open("D:\\student.txt");
//     // for (int i = 0; i < 5; i++)
//     // {
//     //     s.setData();
//     //     fout.write((char *)&s, sizeof(student));
//     // }
//     // fout.close();
//     // cout << "Write completed." << endl;
//     // return 0;
//     student s;
//     ifstream fin;
//     fin.open("D:\\student.txt");
//     for (int i = 0; i < 5; i++)
//     {
//         fin.read((char *)&s, sizeof(student)); // fin.seekg( sizeof(s)*2, ios::cur );-read only 3rd object from 5 objects
//         s.getData();
//     }
//     fin.close();
//     cout << "Read completed." << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     virtual void show()
//     {
//         cout << "This is A." << endl;
//     }
// };

// class B : public A
// {
// public:
//     void show()
//     {
//         cout << "This is B." << endl;
//     }
// };

// class C : public A
// {
// public:
//     void show()
//     {
//         cout << "This is C." << endl;
//     }
// };

// int main()
// {
//     A *p, a;
//     B b;
//     C c;
//     p = &a;
//     p->show();
//     p = &b;
//     p->show();
//     p = &c;
//     p->show();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     void display()
//     {
//         cout << "This is A." << endl;
//     }
// };

// class B
// {
// public:
//     void display()
//     {
//         cout << "This is B." << endl;
//     }
// };

// class C : public A, public B
// {
// };

// int main()
// {
//     C child;
//     child.A::display();
//     child.B::display();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     int a;
// };

// class B : virtual public A
// {
// };

// class C : virtual public A
// {
// };

// class D : public B, public C
// {
// };

// int main()
// {
//     D d;
//     d.a = 12;
//     cout << d.a;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// public:
//     virtual void display()
//     {
//         cout << "This is A." << endl;
//     }
// };

// class B : public A
// {
// public:
//     void display()
//     {
//         cout << "This is B." << endl;
//     }
// };

// class C : public A
// {
// public:
//     void display()
//     {
//         cout << "This is C." << endl;
//     }
// };

// int main()
// {
//     A *p, a;
//     B b;
//     C c;
//     p = &a;
//     p->display();
//     p = &b;
//     p->display();
//     p = &c;
//     p->display();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Shape
// {
// protected:
//     int width, height;

// public:
//     void setter(int width, int height)
//     {
//         this->width = width;
//         this->height = height;
//     }
//     virtual int area() = 0;
// };

// class Rectangle : public Shape
// {
// public:
//     int area()
//     {
//         return width * height;
//     }
// };

// class Triangle : public Shape
// {
// public:
//     int area()
//     {
//         return (width * height) / 2;
//     }
// };

// int main()
// {
//     Shape *s;
//     Rectangle R;
//     Triangle T;
//     s = &R;
//     s->setter(4, 5);
//     cout << s->area() << endl;
//     s = &T;
//     s->setter(6, 4);
//     cout << s->area() << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A
// {
// private:
//     int a;

// public:
//     A() { a = 5; }
//     friend class B;
// };

// class B
// {
// private:
//     int b;

// public:
//     void getter(A a)
//     {
//         cout << "Private value of A.a: " << a.a << endl;
//     }
// };

// int main()
// {
//     A a;
//     B b;
//     b.getter(a);
//     return 0;
// }
