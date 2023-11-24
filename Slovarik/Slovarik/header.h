#pragma once

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//class Tree {
//public:
//    Tree()
//        : Root(0)
//    {
//    }
//
//    ~Tree() {
//        DestroyNode(Root);
//    }
//
//private:
//    class Node {
//    public:
//        Node(string key, string rus) {
//            Eng = key;
//            Rus = rus;
//            Left = 0;
//            Right = 0;
//        }
//
//        string Eng;
//        string Rus;
//        Node* Left;
//        Node* Right;
//    };
//
//    void DestroyNode(Node* node);
//
//    void Insert(string eng, string rus);
//
//private:
//    Node* Root;
//};

class Node {
public:
    string Key;
    string Rus;
    Node* left;
    Node* right;

    Node(string key, string rus);
};

class Dictionary {
private:
    Node* root;
    int size = 0;
         
    Node* add(Node* node, string key, string rus);

    Node* find(Node* node, string key);

    Node* remove(Node* node, string key);

public:
    Dictionary();

    //размер словаря
    int getSize();

    //добавление слова через string
    void add(string key, string rus);

    //добавление слова через char
    void add(const char* key, const char* rus); //dict.add("apple", "яблоко");
    
    //поиск слова по ключу
    string find(string key);

    //поиск перевода
    string operator[](const string& key); //dict["apple"] вернет значение яблоко

    //замена перевода
    void changeTranslation(string key, string rus_2);
      
    //удаление слова
    void remove(string key);

    //заполнение словаря из файла
    void loadFile(const string& filename); //dict.loadFromFile("dictionary.txt");
};