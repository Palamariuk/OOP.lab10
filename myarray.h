#ifndef MYARRAY_H
#define MYARRAY_H

#include <QListWidget>

template<typename T>
class Array
{
private:
    T *values;
    unsigned capacity = 1;
    unsigned size = 0;

    void expand(){
        capacity *= 2;
        T *tempArray = new T[capacity];
        for(unsigned i = 0; i < size; i++){
            tempArray[i] = values[i];
        }
        delete[] values;
        values = tempArray;
        for(unsigned i = size; i < capacity; i++){
            values[i] = T();
        }
    }

public:
    Array(){
        this->size = 0;
        capacity = 2;
        this->values = new T[this->capacity];
    };

    ~Array(){
        delete[] this->values;
    };

    void sortI(){
        for (unsigned i = 0; i < size - 1; i++) {
            for (unsigned j = 0; j < size - i - 1; j++) {
                if (values[j] < values[j + 1]) {
                    T temp = values[j];
                    values[j] = values[j + 1];
                    values[j + 1] = temp;
                }
            }
        }
    };

    void sortD(){
        for (unsigned i = 0; i < size - 1; i++) {
            for (unsigned j = 0; j < size - i - 1; j++) {
                if (values[j] > values[j + 1]) {
                    T temp = values[j];
                    values[j] = values[j + 1];
                    values[j + 1] = temp;
                }
            }
        }
    };

    void append(const T& value){
        if(size >= capacity)
            expand();
        values[size++] = value;
    };

    T min(){
        T min = this->values[0];
        for(unsigned i = 1; i < this->size; i++){
            if(this->values[i] < min)
                min = this->values[i];
        }
        return min;
    };

    void operator>>(QListWidget *list){
        for(unsigned i = 0; i < size; i++){
            list->addItem(QString::fromStdString(values[i]));
        }
    }
};

#endif // MYARRAY_H
