#include <iostream>
using namespace std;

// ---------- Abstraction & Encapsulation ----------

class Account {

private:

    int balance;
    
public:
    void setBalance(int amount) {
        if (amount >= 0)
            balance = amount;
    }

    int getBalance() {
        return balance;
    }
};

// ---------- Class, Object, Constructor & Destructor ----------
class Student {
private:
    string name;
    int roll;

public:
    static int count;

    Student(string name, int roll) {
        this->name = name;
        this->roll = roll;
        count++;
    }

    void showStudent() {
        cout << "Name: " << name << ", Roll: " << roll << endl;
    }

    ~Student() {
        cout << "Destructor called for " << name << endl;
    }
};
int Student::count = 0;

// ---------- Inheritance ----------
class Person {
public:
    string nationality = "Indian";

    void speak() {
        cout << "I can speak Hindi." << endl;
    }
};

class Employee : public Person {
public:
    void work() {
        cout << "I work as a developer." << endl;
    }
};

// ---------- Compile-time Polymorphism (Function Overloading) ----------
class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << endl;
    }

    void show(string str) {
        cout << "String: " << str << endl;
    }
};

// ---------- Operator Overloading ----------
class Complex {
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// ---------- Friend Function ----------
class Box {
private:
    int length = 15;

    friend void printLength(Box);
};

void printLength(Box b) {
    cout << "Box length: " << b.length << endl;
}

// ---------- Virtual Function & Runtime Polymorphism ----------
class Animal {
public:
    virtual void sound() {
        cout << "Animal Sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog says Woof!" << endl;
    }
};

// ---------- Abstract Class ----------
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle..." << endl;
    }
};

// ---------- Template ----------
template <class T>
T add(T a, T b) {
    return a + b;
}

// ---------- Main Function ----------
int main() {
    // Encapsulation & Abstraction
    Account acc;
    acc.setBalance(5000);
    cout << "Account Balance: " << acc.getBalance() << endl;

    // Class, Object, Constructor, Destructor
    Student s1("Rahul", 101);
    Student s2("Priya", 102);
    s1.showStudent();
    s2.showStudent();
    cout << "Total students: " << Student::count << endl;

    // Inheritance
    Employee emp;
    emp.speak();  // From Person
    emp.work();   // From Employee

    // Function Overloading
    Print p;
    p.show(42);
    p.show("Hello OOP");

    // Operator Overloading
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;
    cout << "Sum of Complex numbers: ";
    c3.display();

    // Friend Function
    Box b;
    printLength(b);

    // Virtual Function (Polymorphism)
    Animal* a = new Dog();
    a->sound();
    delete a;

    // Abstract Class
    Shape* shape = new Circle();
    shape->draw();
    delete shape;

    // Template
    cout << "Sum (int): " << add<int>(5, 3) << endl;
    cout << "Sum (float): " << add<float>(2.5, 4.3) << endl;

    return 0;
}
