#include "..\headers\queue.hh"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>


/*
    Konstruktor kolejki, ustawia wskaźnik na głowę i ogona na NULL
*/
Queue::Queue(): head(NULL), tail(NULL) {}



/*
    Metoda sprawdzająca czy kolejka jest pusta

    RETURN: 
    *       true jeśli kolejka jest pusta
    *       false jeśli nie jest pusta
    
*/
bool Queue::isEmpty()
{
    return head == NULL ? true : false;
}



/*
    Metoda dodająca obiekt klasy węzeł do kolejki
    i inicjalizująca wiadomość jaką węzeł ma 
    przechowywać. Dodatkowo numeruje ona kolejno 
    węzły 1,2,3...

    IN:
        * std::string mess - zmienna do zainicjalizowania atrybut
                "message" w objekcie węzeł
    

*/
void Queue::push(std::string mess )
{   
    static int num = 1;                   // zmienna do numerowania paczek
    // jeżeli kolejka jest pusta
    if(isEmpty())
    {
        head = new Node(mess);           // utwórz nowy węzeł i skieruj na niego wskaźnik
        head->number = num++;            // ponumerowanie paczki
        tail = head;                     // head i tail
    }
    // jeżeli kolejka nie jest pusta
    else
    {
        Node * pt = new Node(mess);      // utworzenie nowego węzła 
        pt->number = num++;              // ponumerowanie paczki
        tail->next = pt;                 // wskaźnik na poprzedni pokazuje teraz na nowy węzeł
        pt->prev = tail;                 // wskaźnik na następny pokazuje na aktualną głowę kolejki
        tail = pt;                       // przesunięcie głowy kolejki na nowy węzeł
    }
}





/*
    Metoda usuwająca element z kolejki i zwracająca go

    RETURN: 
    *       atrybut "number" objektu Node na który pokazuje głowa

    
*/
std::string Queue::pop()
{
    assert((!isEmpty() == true) && "Nie mozna zdjac elementu z pustego kolejki");
    // jeżeli kolejka nie jest pusta 
    std::string val = head->message;   // zapisanie wartości w zmiennej
    head = head->next;        // przesunięcie głowy na następny węzeł

    return val;               // zwróć wartość val
}





/*
    Metoda zwraca ilość objektów typu Node znajdujących
    się aktualnie na kolejce

    RETURN: 
    *       liczba węzłów na kolejce

    
*/
int Queue::size()
{
    Node *pt = head;        // pomocniczy wskaźnik na Node do przemieszczania się po kolejce
    int count = 0;          // zmienna pomocnicza do liczenia węzłów

    // wykonuj dopóki nie skończy się kolejka
    while(pt != NULL)
    {
        pt = pt->next;      // przesunięcie na następny
        count++;            // zliczenie węzła
    }

    return count;           // zwróć liczbę węzłów
}


/*
    Metoda sprawdzająca czy podany numer znajduje się w tablicy

    IN:
        * int t[] - tablica w której mamy sprawdzić numer
        * int num - numer który mamy sprawdzić w tablicy
    RETURN: 
            * true - jeśli dany numer występuje w tablicy
            * false - jeśli danego numeru nie ma w tablicy
    
*/
    bool Queue::isNum(int t[], int num)
    {
        for(int i = 0; i < size(); i++)     // iteruj po wielkości tablicy
        {
            if (t[i] == num) return true;   // zwróć true jeśli znaleziono dany numer
        }
        return false;                       // w przeciwnym razie zwróć false
    }



/*
    Metoda mieszająca tablicę

    IN:
        * int tab[] - tablica do wymieszania
    
*/
void Queue::mixTab(int tab[])
{
    
    srand( time( NULL ) );          // ustaw czas dla liczb pseudolosowych
    int * newTab = new int[size()];             // inicjalizacja nowej tablicy


    for(int i = 0; i < size(); i++) // ustaw wszystkie elementy nowej tablicy na -1
    {
        newTab[i] = -1;
    }


    for(int i = 0; i < size(); i++)
    {
        int number = (std::rand() % size()) + 1;    // wylosuj numer z przedziału od 1 do size() 
        // wykonuj dopóki wylosowany numer występuje w tablicy 
        while(isNum(newTab, number)) 
            number = (std::rand() % size()) + 1;    // jeśli występuje to wylosuj jeszcze raz

        newTab[i] = number;         // przypisz liczbę na danym indeksie
        tab[i] = number;            // przypisz liczbę do prawdziwej tablicy

    }
    
}   


/* 
    Metoda zmieniająca kolejność występowania elementów w
    kolejce na podstawie wymieszanej tablicy. Imituje ona 
    odbieranie przez internet kolejnych paczek z fragmentami
    wiadomości przez Annę

*/
void Queue::shuffle()
{
    Node * pt;                      // deklaracja pomocniczego wskaźnika na Node

    int * tab = new int[size()];                // deklaracja tablicy o wielkości tej samej co kolejka
    for(int i = 0; i < size(); i++)
    {
        tab[i] = i + 1;             // ponumeruj odpowiednio kolejne elementy tablicy 1,2,3...size()
    }

    mixTab(tab);                    // wymieszaj tablicę

    for(int i = 0; i < size(); i++)
    {
        pt = head;                  // pomocniczy wskaźnik pokazuje na głowę kolejki

        // przesuwaj pomocniczy wskaźnik na następny węzeł tak długo,
        // aż jego atrybut numer będzie równy numerowi z tablicy
        while(pt->number != tab[i])
            pt = pt->next;

        if(pt->prev == NULL)            // jeżeli natrafiliśmy na pierwszy z góry 
        {
            /*
                przesuń głowę na następny węzeł, 
                a węzeł na który pokazuje pomocniczy
                wskaźnik przenieś na koniec kolejki. 
                Następnie poustawiaj odpowiednio wskaźniki
                next i prev w odpowiednich węzłach tak
                aby się wszystko zgadzało
            */
            head = head->next;
            head->prev = NULL;
            pt->next = NULL;
            pt->prev = tail;
            tail->next = pt;
            tail = tail->next;
        } else if (pt->next == NULL)            // jeżeli natrafiliśmy na ostatni węzeł to nie robimy nic, bo mieszanie 
            continue;                           // polega u nas na przesuwaniu napotkanego węzła na koniec kolejki

        else            // jeżeli natrafiliśmy na węzeł który jest gdzieś między pierwszym a ostatnim węzłem
        {
            /*
                wypnij węzeł na który pokazuje pomocniczy
                wskaźnik i przenieś go na sam koniec kolejki.
                Następnie poustawiaj odpowiednio wskaźniki
                next i prev w odpowiednich węzłach tak
                aby się wszystko zgadzało
            */
            pt->prev->next = pt->next;
            pt->next->prev = pt->prev;
            pt->next = NULL;
            pt->prev = tail;
            tail->next = pt;
            tail = tail->next;
        }
    }
}



/* 
    Metoda wyświetlająca ponumerowane paczki w takiej kolejności
    w jakiej są położone w kolejce oraz ich zawartość

*/
void Queue::printQueue()
{

    if(isEmpty()) std::cerr<< "Empty Queue"<< std::endl;        // jeżeli kolejka jest pusta wyświetl wiadomość o pustej kolejce

    Node* pt = head;        // pomocnicza zmienna pokazuje na głowę
    while(pt!= NULL)        // wykonuj dopóki nie skończy się kolejka
    {
        std::cout << pt->message << std::endl << std::endl;
        pt = pt->next;          // przesunięcie na następny węzeł
    }
}



/* 
    Metoda sortująca kolejke tak aby głowa pokazywała na węzeł w
    z numerem 1, head->next->number = 2, head->next->next->number = 3, 
    itp.

*/
void Queue::sortQueue()
{

    Node * pt;          // zmienna pomocnicza pokazuje na głowę
    for(int i = 0; i < size(); i++)     // iteruj po wielkości kolejki
    {
        pt = head;
        while(pt->number != (i+1))          // znalezienie węzła z odpowiednim numerem
            pt = pt->next;

        if(pt->prev == NULL)            // jeżeli natrafiliśmy na pierwszy z góry 
        {
            /*
                przesuń głowę na następny węzeł, 
                a węzeł na który pokazuje pomocniczy
                wskaźnik przenieś na koniec kolejki. 
                Następnie poustawiaj odpowiednio wskaźniki
                next i prev w odpowiednich węzłach tak
                aby się wszystko zgadzało
            */
            head = head->next;
            head->prev = NULL;
            pt->next = NULL;
            pt->prev = tail;
            tail->next = pt;
            tail = tail->next;
        } else if (pt->next == NULL)            // jeżeli natrafiliśmy na ostatni węzeł to nie robimy nic, bo mieszanie 
            continue;                           // polega u nas na przesuwaniu napotkanego węzła na koniec kolejki

        else            // jeżeli natrafiliśmy na węzeł który jest gdzieś między pierwszym a ostatnim węzłem
        {
            /*
                wypnij węzeł na który pokazuje pomocniczy
                wskaźnik i przenieś go na sam koniec kolejki.
                Następnie poustawiaj odpowiednio wskaźniki
                next i prev w odpowiednich węzłach tak
                aby się wszystko zgadzało
            */
            pt->prev->next = pt->next;
            pt->next->prev = pt->prev;
            pt->next = NULL;
            pt->prev = tail;
            tail->next = pt;
            tail = tail->next;
        }

    }


}