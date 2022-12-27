/**
* @file AddFromFile.cpp
* @description Dosyadan verileri okuyarak kullandigimiz yapilara yerlestirir.
* @course 1. Öğretim A Grubu
* @assignment 2.Odev
* @date 21.12.2022
* @author Korhan Temiz - korhan.temiz@ogr.sakarya.edu.tr
*/
#include "AddFromFile.hpp"

AddFromFile::AddFromFile()
{

    count = CountLines();
    int organSayisi = count / 20;
    int sistemSayisi = organSayisi / 100;
    this->Dokular = new Doku *[count];
    this->organlar = new Organ *[organSayisi];
    this->Sistemler = new Sistem *[sistemSayisi];
    this->organizma = new Organizma();
    this->ReadLines();
    organizma->Sistemler = this->Sistemler;
}

int AddFromFile::CountLines()
{
    int counter = 0;
    ifstream file("Veri.txt");
    string tmp;
    while (getline(file, tmp))
        ++counter;

    file.close();
    return counter;
}
void AddFromFile::ReadLines()
{   
    organlar[0] = new Organ();
    Sistemler[0] = new Sistem();
    string getfromfile;
    ifstream file("Veri.txt");
    Radix radix;

    if (!file.is_open())
    {
        printf("file error");
        exit(1);
        return ;
    }
    int counter = 0;
    int organCounter = 0;
    int sistemCounter = 0;
    while (getline(file, getfromfile))
    {
        int ivalue;
        Queue *list = new Queue();
        istringstream ss(getfromfile);
        for (; ss >> ivalue;)
        {
            list->enqueue(ivalue);
        }
        radix.radixsort(list);
        Dokular[counter] = new Doku(list);
        organlar[organCounter]->bst->Add(Dokular[counter]);
        ++counter;
        if (counter % 20 == 0)
        {   
            organCounter++;
            organlar[organCounter] = new Organ();
        }

        if(counter%2000==0){
          
            Sistemler[sistemCounter] = new Sistem();
            int j = 0;
          for(int i=sistemCounter*100;i<(sistemCounter+1)*100;i++,j++){
         
            Sistemler[sistemCounter]->organlar[j]= organlar[i];
          }
          sistemCounter++;
        }
    }
}