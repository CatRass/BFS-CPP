#include "Dict.h"

DictElement::DictElement(string key, Node* value){
    this->key = key;
    this->value = value;
}

Node* Dict::operator()(string key){

}