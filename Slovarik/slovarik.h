#pragma once
#include "Slovo.h"


class Slovarik {
private:
    Slovo* root;
    int size = 0;
         
    Slovo* add(Slovo* slovo, string eng, string rus);

    Slovo* find(Slovo* slovo, string eng);

    Slovo* remove(Slovo* slovo, string eng);

public:
    Slovarik();

    int getSize();

    void add(string eng, string rus);

    void add(const char* eng, const char* rus);
    
    string find(string eng);

    string operator[](const string& eng);

    void changeTranslation(string eng, string newRus);
      
    void remove(string eng);

    void loadFile(const string& filename);
};