#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using std::vector;
using std::string;
using std::ostringstream;
using std::endl;

class Node {
    public:
        Node(string nodeName);
        Node();

        void setVisited(){this->visited = true;};
        bool getVisited(){return this->visited;};
        string getName(){return this->name;};

        void addNeighbour(Node* neighbour);
        vector<Node*> getNeighbours(){return this->neighbours;};
        ostringstream neighboursSS();
        bool hasNeighbours();

        void setParent(Node* parent){this->parent = parent;};
        Node* getParent(){return this->parent;};

    private:
        string name;
        bool visited = false;
        vector<Node*> neighbours;
        Node* parent = nullptr;

};