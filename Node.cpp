
#include "Node.h"

Node::Node(string nodeName){
    this->name = nodeName;
}

void Node::addNeighbour(Node* neighbour){
    this->neighbours.push_back(neighbour);
}

ostringstream Node::neighboursSS(){
    ostringstream output;
    output << "Neighbours of " << name << ": ";
    for(int i=0; i<neighbours.size(); i++){
        output << (*(neighbours.at(i))).getName() << " ";
    }
    output << endl;
    return output;
}

bool Node::hasNeighbours(){
    return neighbours.size() > 0;
}
