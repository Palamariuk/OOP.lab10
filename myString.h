#ifndef MYSTRING_H
#define MYSTRING_H
#include <QChar>
#include <QString>
#include <cstring>

class MyString{
private:
    char* string;
    int length;

public:
    MyString(const char* _string = ""){
        length = strlen(_string);
        string = new char[length];
        strcpy(string, _string);
    }

    ~MyString(){ delete[] string; }

    bool operator<(MyString other){
        return strcmp(string, other.string) < 0;
    }

    bool operator>(MyString other){
        return strcmp(string, other.string) > 0;
    }

    int getLength(){ return length; }

    operator std::string(){
        std::string s(string);
        return s;
    }

};

#endif // MYSTRING_H
