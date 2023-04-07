#include <iostream>
#include <locale>
#include <string>
#include <regex>
#define testfunc

using namespace std;

class authors
{
private:
    string name;
    string surname;
    string title;

public:
    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }
    void setSurname(string s)
    {
        surname = s;
    }
    string getSurname()
    {
        return surname;
    }
    void setTitle(string t)
    {
        title = t;
    }
    string getTitle()
    {
        return title;
    }
};

class book : public authors
{
private:
    int year{ 0 };
public:
    int setYear(int y) {
        int error_current{ 0 };
        if (y <= 2000 || y > 2023) {
            error_current = -1;
        }
        else
        {
            error_current = 0;
            year = y;
        };
        return error_current;
    };
    int getYear() {
        return year;
    };

};

class author : public authors
{
private:
    string date;
public:
    int setDate(string dt)
    {
        int error_current{ 0 };
        smatch n;
        if (regex_search(dt, n, regex(R"(^\b[0-2]\d{3}\b-\b[0-1]\d\b-\b[0-3]\d\b$)"))) {
            error_current = 0;
            date = dt;

        }
        else {
            error_current = -3;
        }
        return error_current;
    }
    string getDate()
    {
        return date;
    }
};

void testingsetDate(author object) {
    string dt = "2012-04-03";
    if (object.setDate(dt) == 0) {
        cerr << dt << " good" << endl;
    }
    else
    {
        cerr << dt << " failed" << endl;
    }
    dt = "10-10-2023";
    if (object.setDate(dt) == 0) {
        cerr << dt << " good" << endl;
    }
    else
    {
        cerr << dt << " failed" << endl;
    }
    dt = "2012.04.20";
    if (object.setDate(dt) == 0) {
        cerr << dt << " good" << endl;
    }
    else
    {
        cerr << dt << " failed" << endl;
    }
    dt = "3099-01-01";
    if (object.setDate(dt) == 0) {
        cerr << dt << " good" << endl;
    }
    else
    {
        cerr << dt << " failed" << endl;
    }
};

void testingsetYear(book object1) {
    int y = 1999;
    if (object1.setYear(y) == 0) {
        cerr << "" << y << " good" << endl;
    }
    else
    {
        cerr << "" << y << " failed" << endl;
    };
    y = 2018;
    if (object1.setYear(y) == 0) {
        cerr << "" << y << " good" << endl;
    }
    else
    {
        cerr << "" << y << " failed" << endl;
    };
    y = 2024;
    if (object1.setYear(y) == 0) {
        cerr << "" << y << " good" << endl;
    }
    else
    {
        cerr << "" << y << " failed" << endl;
    };
};

int main()
{

    book b;
    author a;

#ifdef testfunc
    testingsetDate(a);
    cerr << endl;
    testingsetYear(b);

#endif // testfunc


    return 0;
}