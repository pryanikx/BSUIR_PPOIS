#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Slovo {
public:
    string Eng;
    string Rus;
    Slovo* left;
    Slovo* right;

    Slovo(string eng, string rus);
};

class Dictionary {
private:
    Slovo* root;
    int size = 0;
         
    Slovo* add(Slovo* slovo, string eng, string rus);

    Slovo* find(Slovo* slovo, string eng);

    Slovo* remove(Slovo* slovo, string eng);

public:
    Dictionary();

    int getSize();

    void add(string eng, string rus);

    void add(const char* eng, const char* rus);
    
    string find(string eng);

    string operator[](const string& eng);

    void changeTranslation(string eng, string newRus);
      
    void remove(string eng);

    void loadFile(const string& filename);
};