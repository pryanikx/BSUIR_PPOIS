#include "header.h"

Node::Node(string key, string rus)
{
    this->Key = key;
    this->Rus = rus;
    this->left = nullptr;
    this->right = nullptr;
}

Node* Dictionary::add(Node* node, string key, string rus)
{
    if (node == nullptr) {
        this->size++;
        return new Node(key, rus);
    }
    if (key < node->Key) {
        node->left = add(node->left, key, rus);
    }
    else if (key > node->Key) {
        node->right = add(node->right, key, rus);
    }
    else {
        node->Rus = rus;
    }
    return node;
}

Node* Dictionary::find(Node* node, string key)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->Key) {
        return find(node->left, key);
    }
    else if (key > node->Key) {
        return find(node->right, key);
    }
    else {
        return node;
    }
}

Node* Dictionary::remove(Node* node, string key) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key < node->Key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->Key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            Node* rChild = node->right;
            delete node;
            size--;
            return rChild;
        }
        else if (node->right == nullptr) {
            Node* lChild = node->left;
            delete node;
            size--;
            return lChild;
        }
        else {
            Node* minRight = node->right;
            while (minRight->left != nullptr) {
                minRight = minRight->left;
            }
            node->Key = minRight->Key;
            node->Rus = minRight->Rus;
            node->right = remove(node->right, minRight->Key);
        }
    }
    return node;
}

Dictionary::Dictionary() {
    root = nullptr;
}

int Dictionary::getSize()
{
    return size;
}

void Dictionary::add(string key, string value) {
    root = add(root, key, value);
}

void Dictionary::add(const char* key, const char* rus) {
    string keyStr(key);
    string rusStr(rus);
    add(keyStr, rusStr);
}

string Dictionary::find(string key) {
    Node* node = find(root, key);
    if (node == nullptr) {
        return "";
    }
    else {
        return node->Rus;
    }
}

string Dictionary::operator[](const string& key) {
    Node* node = find(root, key);
    if (node == nullptr)
    {
        return "";
    }

    else
    {
        return node->Rus;
    }
}

void Dictionary::changeTranslation(string key, string rus_2)
{
    Node* node = find(root, key);
    if (node == nullptr)
        node = add(root, key, rus_2);
    else
        node->Rus = rus_2;
}

void Dictionary::remove(string key) {
    root = remove(root, key);
}

void Dictionary::loadFile(const string& filename)
{
    ifstream file(filename);
    string Key;
    string Rus;

    if (!file.is_open()) {
        return;
    }
    else 
    {
        while (!file.eof())
        {
            Key = "";
            Rus = "";
            file >> Key >> Rus;
            add(Key, Rus);
        }
    }
    file.close();
}