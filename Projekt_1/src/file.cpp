#include <iostream>
#include <fstream>
#include <cassert>
#include "..\headers\file.hh"


using namespace std;

/*
    funkcja licząca ile jest linijek w pliku i zwracająca tą liczbę

    IN:
        * string filename - nazwa pliku tekstowego którego mamy policzyć 
                ilość lini
    RETURN:
        * ilość linijek w pliku tekstowym
    
*/
int countLinesInFile(string filename)
{
    int count = 0;
    string line;

    ifstream file(filename);        // otworzenie pliku
    if(file.good())                 // jeśli plik został otworzony poprawnie
    {
        while(getline(file, line))  // dopóki są dane, wczytuj je do zmiennej line
            count++;                // dodaj do licznika
    }
    file.close();                   // zamknij plik

    return count;                   // zwróć liczbę lini w pliku
}




/*
    Funkcja dzieląca dane z pliku na podaną liczbę pakietów a następnie 
    umieszczająca dane pakiety w kolejce

    IN:
        * Queue * queue - wskaźnik na kolejkę do której mamy składać pakiety
        * string filename - nazwa pliku tekstowego z którego kopiujemy dane
        * int numOfPackets - liczba pakietów na które mamy podzielić dany plik
                            tekstowy
    
*/
void putPacketsOnQueue(Queue* queue, string filename, int numOfPackets)
{
    string line;                // zmienna do przechowywania lini
    string * packet;            // zmienna do przechowywania pakietów danych

    ifstream file(filename);                                // otworzenie pliku
    assert((numOfPackets > 1) && "Liczba pakietow musi byc liczba calkowita wieksza od 1");
    assert((file.good() == true) && "Niepoprawny uchwyt do pliku");     // jeśli plik został otworzony poprawnie

    /* Liczba paczek musi być mniejsza od liczby lini w wiadomości */
    assert((countLinesInFile(filename) >= numOfPackets) &&
     "Liczba paczek przez ktore mamy podzielic wiadomosc przekracza liczbe lini w wiadomosci");


    int linesInPacket = (countLinesInFile(filename) / numOfPackets ) ;  // policzenie ile lini musi występować na 1 pakiet




    for(int i = 0; i < (numOfPackets - 1); i++)         // iteruj po liczbie pakietów - 1
    {
        packet = new string;                            // utworzenie nowego pojemnika na pakiety

        /* Kopiuj linie do zmiennej line a następnie dodaj ją do zmiennej packet */
        for(int i = 0; i < linesInPacket && getline(file, line); i ++)  
        {
            line += "\n";
            *packet += line;
        }
        queue->push(*packet);               // dodaj paczkę "packet" na kolejke
    }
    /* Następnie dodajemy to co zostało w pliku na kolejke, liczba lini w ostatniej paczce 
    może się różnić od liczby lini w pozostałych pakietach */
    packet = new string;
    while(getline(file, line))
    {
        line += "\n";
        *packet += line;
    }
    queue->push(*packet);
    

    file.close();                   // zamknij plik
    
}