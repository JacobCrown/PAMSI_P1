#ifndef STACK_HH
#define STACK_HH

#include "stack.hh"
#include "node.hh"



/*
    ***************      STOS      ******************
    Struktura danych do przechowywania wskaźnika do 
    głowy i ogona stosu. Posiada również podstawowe
    metody operujące na stosie
    ***************      STACK      *****************
*/
class Stack{
private:
    Node * head;                // wskaźnik na pierwszy element stosu
    Node *tail;                 // wskaźnik na ostatni element stosu

public:
    Stack();                    // konstruktor
    int size();                 // zwraca wielkość stosu 
    bool isEmpty();             // sprawdza czy stos jest pusty
    void push(std::string);     // dodaje element na stos
    std::string pop();          // zdejmuje pierwszy element ze stosu i go zwraca
    void shuffle();             // funkcja mieszająca stos
    void mixTab(int []);        // pomocnicza funkcja mieszająca tablice
    bool isNum(int [], int);    // funkcja sprawdzająca czy dany numer znajduje się w tablicy 
    void printStack();          // funkcja wyświetlająca elementy na stosie 
    void sortStack();           // funkcja sortująca elementy na stosie
};







#endif