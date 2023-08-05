#include <iostream>
#include <vector>
#include <sstream>
using std::ostringstream;

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

#include "Node.h"

// Tree:
//                  A
//                /   \
//              B      C 
//           /  |       \
//          F   E       D

void traverse(Node* root, Node* end);
ostringstream backtrace(Node* root, Node* end);

int main(void){

    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    Node e("E");
    Node f("F");

    a.addNeighbour(&b);
    a.addNeighbour(&c);
    b.addNeighbour(&f);
    b.addNeighbour(&e);
    c.addNeighbour(&d);

    Node* root;
    Node* end;

    root = &a;
    end = &e;

    try {
        traverse(root,end);
        cout << backtrace(root,end).str();
    } catch (int errorNum){
        cout << "Error" << errorNum;
    }

    // cout << a.neighboursSS().str() << b.neighboursSS().str() << c.neighboursSS().str(); 

    return 0;
}

void traverse(Node* root, Node* end){
    Node* currentNode = root;
    Node* previousNode;
    vector<Node*> queue;
    queue.push_back(currentNode);

    while(currentNode != end){

        for(Node* nodes: currentNode->getNeighbours()){
            if(!(nodes->getVisited())){
                // cout << "Inserting node into queue: " << nodes->getName() << endl;
                queue.push_back(nodes);
                nodes->setParent(currentNode);
            }
        }

        currentNode->setVisited();
        queue.erase(queue.begin());

        // cout << "Current Node: " << currentNode->getName() << endl;
        // cout << "Queue size: " << queue.size() << endl << endl;

        currentNode = queue.at(0);

    }
}
ostringstream backtrace(Node* root, Node* end){
    Node* currentNode = end;
    vector<string> list;
    ostringstream oSS;

    oSS << "Path from " << root->getName() << " to " << end->getName() << ":" << endl;

    while(currentNode != nullptr){
        list.push_back(currentNode->getName());
        currentNode = currentNode->getParent();
    }

    for(int i=list.size()-1; i>=0; i--){
        oSS << list.at(i);
        if(i!=0){
            oSS << " -> ";
        }
    }

    oSS << endl;

    return oSS;
}