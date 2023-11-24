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

    //������ �������
    int getSize();

    //���������� ����� ����� string
    void add(string key, string rus);

    //���������� ����� ����� char
    void add(const char* key, const char* rus); //dict.add("apple", "������");
    
    //����� ����� �� �����
    string find(string key);

    //����� ��������
    string operator[](const string& key); //dict["apple"] ������ �������� ������

    //������ ��������
    void changeTranslation(string key, string rus_2);
      
    //�������� �����
    void remove(string key);

    //���������� ������� �� �����
    void loadFile(const string& filename); //dict.loadFromFile("dictionary.txt");
};