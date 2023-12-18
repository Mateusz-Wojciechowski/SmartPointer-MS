#ifndef LAB5_TEP_CMYSMARTPOINTER_H
#define LAB5_TEP_CMYSMARTPOINTER_H
#include "CRefCounter.h"

template <typename T>
class CMySmartPointer{
public:
    explicit CMySmartPointer(T *pcPointer);
    CMySmartPointer(const CMySmartPointer &pc_other);
    ~CMySmartPointer();
    T& operator*();
    T* operator->();
    CMySmartPointer& operator=(const CMySmartPointer &pc_other);
private:
    T *pc_pointer;
    CRefCounter<CMySmartPointer<T> > *pc_counter;
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer){
    pc_pointer = pcPointer;
    pc_counter = new CRefCounter<CMySmartPointer<T> >();
    pc_counter->add_smart_pointer(this);
    pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pc_other){
    pc_pointer = pc_other.pc_pointer;
    pc_counter = pc_other.pc_counter;
    pc_counter->add_smart_pointer(this);
    pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer(){
    pc_counter->erase_smart_pointer(this);
    if(pc_counter->iDec() == 0){
        delete pc_counter;
        delete pc_pointer;
    }
}

template <typename T>
T& CMySmartPointer<T>::operator*(){
    return (*pc_pointer);
}

template <typename T>
T* CMySmartPointer<T>::operator->(){
    return pc_pointer;
}

template <typename T>
CMySmartPointer<T>& CMySmartPointer<T>::operator=(const CMySmartPointer<T> &pc_other){
    if(this==&pc_other){
        return *this;
    }

    pc_counter->erase_smart_pointer(this);
    if(pc_counter->iDec()==0){
        delete pc_counter;
        delete pc_pointer;
    }

    pc_counter = pc_other.pc_counter;
    pc_pointer = pc_other.pc_pointer;
    pc_counter->add_smart_pointer(this);
    pc_counter->iAdd();

    return *this;
}

#endif //LAB5_TEP_CMYSMARTPOINTER_H
