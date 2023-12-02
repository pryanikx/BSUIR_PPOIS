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