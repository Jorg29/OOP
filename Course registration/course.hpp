#include <iostream>

using namespace std;

class Course
{
    public:
        string code;
        string title;
        int semester;
        int credits;

        Course(string c,int s,string t,int cr);
        friend ostream &operator<<(ostream &os,const Course &c);
};
