// S110-Review.cpp 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Global definition
struct Player
{
    int     goals;
    string  name;

    void show() 
    {
        cout << this << " Player[Name: " << name << ", Goals: " << goals << "]\n";
    }
};


int main()
{
    Player p1;
    p1.name = "Messi";
    p1.goals = 5;
    cout << p1.name << ", " << p1.goals << endl;

    Player p2({ 7, "Mbappe" });
    cout << p2.name << ", " << p2.goals << endl;
    p2.show();

    Player* ptr = nullptr;
    ptr = &p1;

    cout << ptr->name << ", " << ptr->goals << endl;
    cout << (*ptr).name << ", " << (*ptr).goals << endl;

    cout << "vector<Player> v1" << endl;
    vector<Player> v1{ p1 };
    v1.push_back(p2);
    for (Player p : v1) { p.show(); }

    cout << "\nvector<Player> v2" << endl;
    vector<Player*> v2;
    v2.push_back(&p1);
    v2.push_back(&p2);

    //v2.push_back(new Player({ 5, "Ronaldo" }));
    Player* ptr2 = new Player({ 5, "Ronaldo" });
    v2.push_back(ptr2);

    for (Player* p : v2) { p->show(); };
    
}

