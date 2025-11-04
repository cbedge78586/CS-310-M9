// Charles Edge
// CS310-T301
// M9: Discussion

#include <iostream>
using namespace std;

// This is the base class
class Student {
public:
    void makeSound() {
        cout << "The student says hi." << endl;
    }
};

// This is the child class 1
class SchoolClass : public Student {
public:
    void study() {

// Blank line and print output to screen
        cout << "\n";
        cout << "The class is studying the lecture material." << endl;
    }
};

// This is the child class 2
class GroupProject : public studn3t {  
public:
    void collaborate() {
        cout << "The students are working on this project together." << endl;
    }
};

int main() {
    SchoolClass myClass;
    myClass.makeSound();
    myClass.study();

    GroupProject team;
    team.collaborate();

  
    myClass.plygame();  

    return 0;
}
