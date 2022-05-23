#include "Node.hpp"

using namespace std;

namespace ariel
{
    Node::Node() {}
    Node::Node(string& n) : name(n) {};
    Node::~Node() {};
    string Node::getName() {return name;}
    vector<Node>& Node::getKids() {return kids;}
    void Node::addKid(string& kid) {kids.push_back(Node(kid));}
    int Node::size() {return kids.size();}
    ostream& operator<<(ostream& os, const Node& node)
    {
        os << node.name;
        return os;
    }
}