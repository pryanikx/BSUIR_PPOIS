#include "slovarik.h"

Slovo::Slovo(string eng, string rus)
{
    this->Eng = eng;
    this->Rus = rus;
    this->left = nullptr;
    this->right = nullptr;
}

Slovo* Slovarik::add(Slovo* slovo, string eng, string rus)
{
    if (slovo == nullptr) {
        this->size++;
        return new Slovo(eng, rus);
    }
    if (eng < slovo->Eng) {
        slovo->left = add(slovo->left, eng, rus);
    }
    else if (eng > slovo->Eng) {
        slovo->right = add(slovo->right, eng, rus);
    }
    else {
        slovo->Rus = rus;
    }
    return slovo;
}

Slovo* Slovarik::find(Slovo* slovo, string eng)
{
    if (slovo == nullptr) {
        return nullptr;
    }
    if (eng < slovo->Eng) {
        return find(slovo->left, eng);
    }
    else if (eng > slovo->Eng) {
        return find(slovo->right, eng);
    }
    else {
        return slovo;
    }
}

Slovo* Slovarik::remove(Slovo* slovo, string eng) {
    if (slovo == nullptr) {
        return nullptr;
    }
    if (eng < slovo->Eng) {
        slovo->left = remove(slovo->left, eng);
    }
    else if (eng > slovo->Eng) {
        slovo->right = remove(slovo->right, eng);
    }
    else {
        if (slovo->left == nullptr) {
            Slovo* rChild = slovo->right;
            delete slovo;
            size--;
            return rChild;
        }
        else if (slovo->right == nullptr) {
            Slovo* lChild = slovo->left;
            delete slovo;
            size--;
            return lChild;
        }
        else {
            Slovo* minRight = slovo->right;
            while (minRight->left != nullptr) {
                minRight = minRight->left;
            }
            slovo->Eng = minRight->Eng;
            slovo->Rus = minRight->Rus;
            slovo->right = remove(slovo->right, minRight->Eng);
        }
    }
    return slovo;
}

Slovarik::Slovarik() {
    root = nullptr;
}

int Slovarik::getSize()
{
    return size;
}

void Slovarik::add(string eng, string value) {
    root = add(root, eng, value);
}

void Slovarik::add(const char* eng, const char* rus) {
    string engStr(eng);
    string rusStr(rus);
    add(engStr, rusStr);
}

string Slovarik::find(string eng) {
    Slovo* slovo = find(root, eng);
    if (slovo == nullptr) {
        return "";
    }
    else {
        return slovo->Rus;
    }
}

string Slovarik::operator[](const string& eng) {
    Slovo* slovo = find(root, eng);
    if (slovo == nullptr)
    {
        return "";
    }

    else
    {
        return slovo->Rus;
    }
}

void Slovarik::changeTranslation(string eng, string newRus)
{
    Slovo* slovo = find(root, eng);
    if (slovo == nullptr)
        slovo = add(root, eng, newRus);
    else
        slovo->Rus = newRus;
}

void Slovarik::remove(string eng) {
    root = remove(root, eng);
}

void Slovarik::loadFile(const string& filename)
{
    ifstream file(filename);
    string Eng;
    string Rus;

    if (!file.is_open()) {
        return;
    }
    else 
    {
        while (!file.eof())
        {
            Eng = "";
            Rus = "";
            file >> Eng >> Rus;
            add(Eng, Rus);
        }
    }
    file.close();
}
