#include <iostream>


using namespace std;



class Entity {
    private:
        int age;
        string name;
        string spell;
    public:
        Entity(string name, int age, string spell) : name(name),  age(age), spell(spell){}
        int getAge() const {
            return this->age;
        }

        string getName() const {
            return this->name;
        }

        string getSpell() const {
            return this->spell;
        }

        void setAge(int age) {
            this->age = age;
        }

        void setName(string name) {
            this->name = name;
        }

        void setSpell(string spell){
            this->spell = spell;
        }

        virtual void castSpell() const {
            cout << this->getName() << ": casts " << this->spell << endl;
        }
};

class Assasin : public Entity {
    public:
        Assasin(int age, string name) : Entity(name, age, "BackStab") {

        }
        Assasin() : Entity("yarrak", 10, "mimi") {}

        virtual void castSpell() const {
            cout <<"The assasin: " <<this->getName() << ": casts " << this->getSpell() << endl;

        }
};

class Muhammet : public Assasin {
        public:
            Muhammet() : Assasin() {

            }

            void castSpell() const {
                cout <<"Muhammet: " <<this->getName() << ": casts " << this->getSpell() << endl;

            }
};

class A {
    private:
        int num = 4;
    public:
        static int c;
        A( ) {
            cout << "yarrak" << endl;
        }
        A(int num ) :num(num) {
            cout << "yarra22k" << endl;
        }
        void setNum(int num) {
            if (num == 2 || num == 4)
                this->num = num;
        }
        int getNum(void) {
            return this->num;
        }
        void operator++(void) const {
            cout << "wroom wroom" << endl;
        }
};
int A::c = 5;

int sum(int a, int b) {
    return a+b;
}

float sum(float a, float b) {
    return a+b;
}

double sum(double a, double b ) {
    return a + b;
}

int main() {

    // A a; //-> a();
    // int *i = (int *)&a;
    // A b(10);
    // cout << b.c << endl;
    // b.c = 20;
    // cout << a.c << endl;
    // cout << *i << endl;
    // *i += 20;
    // cout << *i << endl;

    cout << sum(1.2121121, 10.121212) << endl;
}