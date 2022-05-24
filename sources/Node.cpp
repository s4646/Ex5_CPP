#include "Node.hpp"

using namespace std;

namespace ariel
{
    Node::Node() {}
    Node::Node(const string& n) : name(n) {};
    Node::~Node() {};
    string& Node::getName() {return name;}
    void Node::setName(const string& n) {name = n;}
    vector<Node>& Node::getKids() {return kids;}
    void Node::addKid(const string& kid)
    {
        kids.push_back(Node(kid));
    }
    int Node::size() {return name.size();}
    ostream& operator<<(ostream& os, const Node& node)
    {
        os << node.name;
        return os;
    }
}