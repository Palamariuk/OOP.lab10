#ifndef MYSTRING_H
#define MYSTRING_H
#include <QChar>
#include <QString>
#include <cstring>
#include <QDebug>

class MyString{
private:
    char* string;
public:
    MyString(){
        string = nullptr;
    };

    MyString(const char* _string){
        int length = strlen(_string);
        string = new char[length + 1];
        for(int i = 0; i < length; i++){
            string[i] = _string[i];
        }
        string[length] = '\0';
    }

    ~MyString(){
        if(string != nullptr)
            delete[] string;
    }

    bool operator<(MyString other){
        return strcmp(string, other.string) < 0;
    }

    bool operator>(MyString other){
        return strcmp(string, other.string) > 0;
    }

    void print(){
        qDebug() << string;
    }

    operator std::string(){
        return std::string(string);
    }

};

#endif // MYSTRING_H
