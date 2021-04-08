#include <iostream>
#include <ctime>
#include "..\headers\file.hh"
#include "..\headers\delay.hh"

using namespace std;

// int countLinesInFile(string );
// void putPacketsOnQueue(Queue*, string, int );

int main()
{
    clock_t start, finish;
    double timePassed;
    srand(time(NULL));
    start = clock();

    int n;             // liczba pakietów przez jaką trzeba podzielić wiadomość W
    string filename;
    
    cout << "Tworze kolejki Jana i Anny..." << endl;
    sleep(DELAY);

    Queue QueueJ;           // kolejka Jana
    Queue QueueA;           // kolejka Anny 
    
    cout << "Podaj liczbe pakietow do ktorych mam zapakowac wiadomosc: " << endl;
    cin >> n;

    cout << "Podaj uchwyt do pliku tekstowego w ktorym jest zawarta wiadomosc: " << endl;
    cin >> filename;

    cout << "Dodaje pakiety Jana do kolejki... " << endl;
    sleep(DELAY);
    // funkcja imitująca pisanie wiadomości przez Jana
    putPacketsOnQueue(&QueueJ, filename, n);
    cout << "Pakiety zostaly dodane do kolejki." << endl;
    sleep(DELAY);
    
    cout << "Wysylam wiadomosc za pomoca pakietow przez internet..." << endl;
    sleep(DELAY);
    
    cout << "Pakiety sa mieszane w internecie... " << endl;
    sleep(DELAY);
    // pakiety trafiają do internetu a następnie są wymieszane
    QueueJ.shuffle();

    cout << "Pakiety trafiaja do Anny. " << endl;
    sleep(DELAY);
    // Anna otrzymuje wymieszane wiadomości przez internet
    QueueA = QueueJ;

    cout << "Komputer Anny sortuje pakiety po numerach rosnaco... " << endl;
    sleep(DELAY);
    // komputer Anny sortuje otrzymane pakiety 
    QueueA.sortQueue();
    cout << "Sortowanie zakonczone. " << endl;
    sleep(DELAY);

    cout << "Za chwile nastapi wyswietlenie wiadomosci... " << endl;
    sleep(DELAY);

    cout << "Wiadomosc: " << endl << endl;

    // wyświetl wiadomość
    QueueA.printQueue();
    finish = clock();

    timePassed = (double)(finish-start) / CLOCKS_PER_SEC;

    cout << endl << endl;

    cout << "Calosc zajela " << timePassed << endl;


}









