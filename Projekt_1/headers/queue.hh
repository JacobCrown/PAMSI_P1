#ifndef QUEUE_HH
#define QUEUE_HH

#include "node.hh"



/*
    ***************      KOLEJKA      ***************
    Struktura danych do przechowywania wskaźnika do 
    głowy i ogona kolejkiu. Posiada również podstawowe
    metody operujące na kolejceie
    ***************      QUEUE      *****************
*/
class Queue{
private:
    Node * head;                // wskaźnik na pierwszy element kolejki
    Node *tail;                 // wskaźnik na ostatni element kolejki

public:
    Queue();                    // konstruktor
    int size();                 // zwraca wielkość kolejki 
    bool isEmpty();             // sprawdza czy kolejka jest pusta
    void push(std::string);     // dodaje element do kolejke
    std::string pop();          // zdejmuje pierwszy element z kolejki i go zwraca
    void shuffle();             // funkcja mieszająca kolejke
    void mixTab(int []);        // pomocnicza funkcja mieszająca tablice
    bool isNum(int [], int);    // funkcja sprawdzająca czy dany numer znajduje się w tablicy 
    void printQueue();          // funkcja wyświetlająca elementy w kolejce
    void sortQueue();           // funkcja sortująca elementy w kolejce
};







#endif