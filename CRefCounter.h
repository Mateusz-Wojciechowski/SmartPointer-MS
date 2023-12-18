#ifndef LAB5_TEP_CREFCOUNTER_H
#define LAB5_TEP_CREFCOUNTER_H
#include "vector"
#include "CMySmartPointer.h"

template <typename T>
class CRefCounter
{
public:
    CRefCounter() { i_count = 0; }
    int iAdd() { return(++i_count); }
    int iDec() { return(--i_count); };
    int iGet() { return(i_count); }
    void add_smart_pointer(T* pointer){
        address_vector.insert(pointer);
    }
    void erase_smart_pointer(T* pointer){
        address_vector.erase(pointer);
    }
private:
    int i_count;
    set<T*> address_vector;
};
#endif //LAB5_TEP_CREFCOUNTER_H
