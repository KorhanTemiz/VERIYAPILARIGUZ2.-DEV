#ifndef AddFromFile_hpp
#define AddFromFile_hpp
#include "Organ.hpp"
#include "Radix.hpp"
#include "Sistem.hpp"
#include "Organizma.hpp"
#include <fstream>
#include <sstream>


class AddFromFile{
public:

Doku **Dokular;
Organ **organlar;
Sistem **Sistemler;
Organizma *organizma;
AddFromFile();
int CountLines();
void ReadLines();


private:
int count;







};




#endif