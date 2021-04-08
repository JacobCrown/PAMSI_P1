#ifndef NODE_HH
#define NODE_HH

#include <string>


/*
    *************       WĘZEŁ     *******************
    Struktura danych do przechowywania numeru paczki    
    oraz wiadomości. Posiada ona dodatkowo wskaźnik 
    na następny oraz na poprzedni obiekt klasy węzeł
    ***************      NODE      ******************
*/
struct Node {

    int number;                     // tu będzie przechowywany numer paczki
    std::string message;            // zmienna do przechowywania wiadomości
    Node *next;                     // zmienna do pokazywania na następny węzeł
    Node *prev;                     // zmienna do pokazywania na poprzedni węzeł
    
    /* Konstruktor */
    Node(std::string mess) : message(mess) ,
                    next(NULL), prev(NULL)   {}
};

#endif