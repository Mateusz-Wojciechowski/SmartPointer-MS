#include <iostream>
#include "Tree/CTree.h"
#include "Tree/CUserInterface.h"
#include "CMySmartPointer.h"

using namespace std;

int main() {
//        CTree<int> c_tree("+ 1 2");
//    CTree<int> c_other("- 3 4");
////
////    c_tree.vPrintTree();
////    cout << "//////////////////////////" << endl;
////    c_tree = std::move(c_other);
////
////    c_tree.vPrintTree();
//
//    cout << "///////////////////////////////////////" << endl;
//    CTree<int> c_tree4;
//    c_tree4 = c_tree + std::move(c_other);
//    c_tree4.vPrintTree();
//    c_tree4 = std::move(c_tree);
//    c_tree4.vPrintTree();
//    return 0;

//    CUserInterface<int> c_ui;
//    c_ui.vRun();
    CMySmartPointer<CTree<int> > smartPointer1(new CTree<int>("+ 1 2"));
    cout << (&smartPointer1) << endl;
    smartPointer1->vPrintTree();
    CMySmartPointer<CTree<int> > smartPointer2(smartPointer1);
    smartPointer2->vPrintTree();
    cout << &smartPointer2 << endl;
    CMySmartPointer<CTree<int> > smartPointer3 = smartPointer1;
    (*smartPointer1).vPrintTree();
    cout << &smartPointer3 << endl;

    cout << &(*smartPointer1) << endl;
    cout << &(*smartPointer2) << endl;
}

// Odp Zad 3:
// Z definicji inteligentny wskaznik sam zarzadza pamiecia, a pamiecia zaalokowana statycznie zarzadza srodowisko uruchomieniowe c++
// przy probie uzycia delete do zwolnienia pamieci zaalokowanej statycznie doprowadzimy prawdopodobnie do bledu
