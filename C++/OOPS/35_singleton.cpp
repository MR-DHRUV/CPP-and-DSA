#include <iostream>
using namespace std;

class Singleton {
private:
    // Private static instance
    static Singleton* instance;

    // Private constructor
    Singleton() {
        cout << "Singleton instance created" << endl;
    }

public:
    // Public method for access
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Other methods and members can be added as needed
};

// Static initialization of the instance to nullptr
Singleton* Singleton::instance = nullptr;

int main() {
    // Accessing the singleton instance
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // Both instances point to the same object
    cout << "Is s1 equal to s2? " << (s1 == s2) << endl;

    return 0;
}
