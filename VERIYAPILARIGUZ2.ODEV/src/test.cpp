/**
 * @file Test.cpp
 * @description Programi calistirir.
 * @course 1. Öğretim A Grubu
 * @assignment 2.Odev
 * @date 21.12.2022
 * @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
 */
#include "Queue.hpp"
#include "Doku.hpp"
#include "BST.hpp"
#include "Sistem.hpp"
#include "AddFromFile.hpp"
#include "Kontrol.hpp"
using namespace std;

int main()
{

    Queue *queue = new Queue();

    AddFromFile *read = new AddFromFile();
    int count = read->CountLines();
    int organsayisi = count / 20;
    int sistemsayisi = count / 2000;

    cout << "\t\t\t Organizma (Mutasyonsuz) \n" << endl;
    for (int i = 0; i < sistemsayisi; i++)
    {

        for (int j = 0; j < 100; j++)
        {

            if (Kontrol::isbalanced(read->organizma->Sistemler[i]->organlar[j]->bst))
            {
                cout << " ";
            }
            else
            {
                cout << "#";
            }
        }
        cout << "\n";
    }

    cout << endl;

    cout << "Mutasyon uygulanmasi icin enter'a basiniz... " << endl;
    if (cin.get())
    {

        for (int i = 0; i < sistemsayisi; i++)
        {

            for (int j = 0; j < 100; j++)
            {
                read->organizma->Sistemler[i]->organlar[j]->mutasyonUygula();
            }
        }
        system("cls");

        cout << "\t\t\tOrganizma (Mutasyon Uygulandi) \n\n";
        for (int i = 0; i < sistemsayisi; i++)
        {

            for (int j = 0; j < 100; j++)
            {

                if (Kontrol::isbalanced(read->organizma->Sistemler[i]->organlar[j]->bst))
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }
            cout << "\n";
        }
    }
}