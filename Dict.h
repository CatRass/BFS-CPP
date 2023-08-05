#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using std::vector;
using std::string;

class DictElement{
    public:
        DictElement(string key, Node* value);
    private:
        string key;
        const Node* value;
};

class Dict{
    public:
        Dict();
        void addElements();
        Node* operator()(string key);
    private:
        vector<DictElement> dictionary;
};