#include<bits/stdc++.h>
using namespace std;
/*
Direct Private Access: Bahar ka koi function class ke private aur protected data ko bina kisi extra function (getter) ke seedha access kar sakta hai.
Multiple Objects Handling: Ye ek sath do ya do se zyada alag-alag objects ke private data ko compare ya use kar sakta hai (jo normal member function ke liye mushkil hota hai).
Operator Overloading (cout Support): cout << myObject jaisa natural syntax likhne ke liye friend function hi use hota hai, kyunki isme left side par cout hota hai class object nahi.
Code Efficiency: Getters aur setters likhne ki jhanjhat khatam ho jaati hai, jisse kuch specific jagahon par code clean aur fast ho jata hai.
Two Different Classes Interaction: Agar do alag-alag classes ke beech data share karna ho, toh friend function ek bridge ka kaam karta hai.*/

class Rectangle {
private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    // Friend function taking TWO objects of the same class
    friend void compareRectangles(const Rectangle &r1, const Rectangle &r2);
};

// Friend function defined OUTSIDE the class
void compareRectangles(const Rectangle &r1, const Rectangle &r2) {
    // Can access private members of BOTH r1 and r2 directly
    int area1 = r1.length * r1.width;
    int area2 = r2.length * r2.width;

    if (area1 > area2) {
        cout << "Rectangle 1 is larger with area: " << area1 << endl;
    } else if (area2 > area1) {
        cout << "Rectangle 2 is larger with area: " << area2 << endl;
    } else {
        cout << "Both rectangles have equal area: " << area1 << endl;
    }
}

int main() {
    Rectangle rect1(10, 5);
    Rectangle rect2(8, 7);
    
    // Passing two separate objects into the friend function
    compareRectangles(rect1, rect2); 
    
    return 0;
}