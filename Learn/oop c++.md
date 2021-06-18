# OOP in C++

### what is oop?
```
OOP stands for Object-Oriented Programming.

Procedural programming is about writing procedures or functions that perform 
operations on the data, while object-oriented programming is about creating 
objects that contain both data and functions.

Object-oriented programming has several advantages over procedural programming:

- OOP is faster and easier to execute - OOP provides a clear structure for the
programs - OOP helps to keep the C++ code DRY "Don't Repeat Yourself", and
makes the code easier to maintain, modify and debug - OOP makes it possible to
create full reusable applications with less code and shorter development time
```

### C++ oop

**class and object**
```
A class is like a blueprint of data member and functions and object is an 
instance of class. For example, lets say we have a class Car which has data 
members (variables) such as speed, weight, price and functions such as 
gearChange(), slowDown(), brake() etc. Now lets say I create a object of this 
class named FordFigo which uses these data members and functions and give them 
its own values. Similarly we can create as many objects as we want using the 
blueprint(class).
```
```cpp
class Box {
public:
        double length;   // Length of a box
        double breadth;  // Breadth of a box
        double height;   // Height of a box
};
```

**Constructor**
```
Constructor is a special member function of a class that initializes the object
of the class. Constructor name is same as class name and it doesn’t have a 
return type. Lets take a simple example to understand the working of 
constructor.

- Constructor vs Member function
1) Constructor doesn’t have a return type. Member function has a return type.
2) Constructor is automatically called when we create the object of the class. 
Member function needs to be called explicitly using object of class.
3) When we do not create any constructor in our class, C++ compiler generates a 
default constructor and insert it into our code. The same does not apply to 
member functions.
```

**destructor**
```
A destructor is a special member function that works just opposite to 
constructor, unlike constructors that are used for initializing an object, 
destructors destroy (or delete) the object.
```
```cpp
#include <bits/stdc++.h>
using namespace std;

class a {
public:
    a() {
        cout << "constructor" << endl;
    }
    ~a() {
        cout << "destructor" << endl;
    }
};

int main() {
    a obj;
    return 0;
}
```
```
Destructor rules
1) Name should begin with tilde sign(~) and must match class name.
2) There cannot be more than one destructor in a class.
3) Unlike constructors that can have parameters, destructors do not allow any parameter.
4) They do not have any return type, just like constructors.
5) When you do not specify any destructor in a class, compiler generates a 
default destructor and inserts it into your code.
```

**access specifiers**
```
In C++, there are three access specifiers:

public - members are accessible from outside the class
private - members cannot be accessed (or viewed) from outside the class
protected - members cannot be accessed from outside the class, however, they 
can be accessed in inherited classes. You will learn more about Inheritance later.
```
https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm

### Encapsulation
```
Encapsulation is a process of combining data and function into a single unit 
like capsule. This is to avoid the access of private data members from outside 
the class. To achieve encapsulation, we make all data members of class private 
and create public functions, using them we can get the values from these data 
members or set the value to these data members.
```
```cpp
class point
{
private:
    int x, y;
public:
    int getX() const {
        return x;
    }
    void setX(int _x) {
        x = _x;
    }
    // ...
};
```

### Inheritance
```
Inheritance is a feature using which an object of child class acquires the 
properties of parent class.
```
```cpp
#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};

// Derived class
class Rectangle: public Shape {
public:
    int getArea() { 
        return (width * height); 
    }
};

int main(void) {
     Rectangle Rect;
     Rect.setWidth(5);
     Rect.setHeight(7);
     cout << "Total area: " << Rect.getArea() << endl;
     return 0;
}
```
```
When deriving a class from a base class, the base class may be inherited 
through public, protected or private inheritance. The type of inheritance is 
specified by the access-specifier as explained above.

We hardly use protected or private inheritance, but public inheritance is 
commonly used. While using different type of inheritance, following rules are 
applied −

Public Inheritance − When deriving a class from a public base class, public 
members of the base class become public members of the derived class and 
protected members of the base class become protected members of the derived 
class. A base class's private members are never accessible directly from a 
derived class, but can be accessed through calls to the public and protected 
members of the base class.

Protected Inheritance − When deriving from a protected base class, public and 
protected members of the base class become protected members of the derived 
class.

Private Inheritance − When deriving from a private base class, public and 
protected members of the base class become private members of the derived class.
```

**Types of Inheritance in C++**
```
1) Single inheritance
In Single inheritance one class inherits one class exactly.

B inherits A

        A
        |
        B

2) Multilevel inheritance
In this type of inheritance one class inherits another child class.

C inherits B and B inherits A
        
        A
        |
        B
        |
        C

3) Multiple inheritance
In multiple inheritance, a class can inherit more than one class. This means 
that in this type of inheritance a single child class can have multiple parent 
classes.

C inherits A and B both

        A    B
        |    |
        ______
            |
            C

4) Hierarchical inheritance
In this type of inheritance, one parent class has more than one child class.

Class B and C inherits class A

            A
            |
         ______
        |      |
        B      C

5) Hybrid inheritance
Hybrid inheritance is a combination of more than one type of inheritance. For 
example, A child and parent class relationship that follows multiple and 
hierarchical inheritance both can be called hybrid inheritance.
```
- https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
- https://beginnersbook.com/2017/08/cpp-inheritance/

### Polymorphism
```
Function overloading and Operator overloading are examples of polymorphism. 
Polymorphism is a feature using which an object behaves differently in 
different situation.
In function overloading we can have more than one function with same name but 
different numbers, type or sequence of arguments.

2 types:
1) Compile time (early binding) - function overloading
2) Runtime (late binding) - function overriding using virtual function
```
- https://beginnersbook.com/2017/08/cpp-polymorphism/
- https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm

### Abstraction
```
Abstraction is a process of hiding irrelevant details from user. For example,
When you send an sms you just type the message, select the contact and click 
send, the phone shows you that the message has been sent, what actually happens 
in background when you click send is hidden from you as it is not relevant to 
you.

Rules of Abstract Class
1) As we have seen that any class that has a pure virtual function is an abstract class.
2) We cannot create the instance of abstract class.
3) We can create pointer and reference of base abstract class points to the 
instance of child class. For example, this is valid:

Animal *obj = new Dog();
obj -> sound();

4) Abstract class can have constructors.
5) If the derived class does not implement the pure virtual function of parent 
class then the derived class becomes abstract.
```
- https://beginnersbook.com/2017/09/cpp-abstract-class/

### Extra
- Types of member function https://www.studytonight.com/cpp/types-of-member-function.php
- Static https://www.studytonight.com/cpp/static-keyword.php
- Const https://www.studytonight.com/cpp/const-keyword.php