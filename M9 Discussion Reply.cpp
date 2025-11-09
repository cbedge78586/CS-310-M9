#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << "Meow!" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.speak();
    cat.speak();

// Corrected variable name from doog to dog
    dog.speak();

// Corrected speak method by adding the missing parenthesis
    cat.speak();

    return 0;
}