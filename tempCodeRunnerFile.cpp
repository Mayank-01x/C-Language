class Animal {
public:
virtual void speak() { 
    // Virtual function
cout << "Animal speaks" << endl;
    }     };
class Dog : public Animal {
public:
void speak() override { 
cout << "Dog barks" << endl;
    }       };
int main() {
    Animal* ptr = new Dog(); 
    ptr->speak();            
// Late binding: Calls Dog::speak
    delete ptr;
    return 0;
}
