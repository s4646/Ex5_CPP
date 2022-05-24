#include "Node.hpp"

using namespace std;

namespace ariel
{
    Node::Node() {}
    Node::Node(const string& n) : name(n) {}
    Node::Node(const Node& other) : name(other.name), kids(other.kids) {}
    Node::Node(Node&& other) noexcept
    {
        name = other.name;
        kids = other.kids;

        other.name.clear();
        other.kids.clear();
    }
    Node::~Node() {}
    Node& Node::operator=(const Node& other) // copy assignment
    {
        // Guard self assignment
        if (this == &other)
        {
            return *this;
        }
        this->~Node();
        name = other.name;
        kids =  vector<Node>(other.kids);
        return *this;
    }
    Node& Node::operator=(Node&& other) noexcept // move assignment
    {
        // Guard self assignment
        if (this == &other)
        {
            return *this;
        }
        this->~Node();
        name = other.name;
        kids = other.kids;

        other.name.clear();
        other.kids.clear();
        return *this;
    }
    string& Node::getName() {return name;}
    void Node::setName(const string& n) {name = n;}
    vector<Node>& Node::getKids() {return kids;}
    void Node::addKid(const string& kid)
    {
        kids.push_back(Node(kid));
    }
    int Node::size() {return name.size();}
    int Node::length() {return name.size();}
    char Node::at(size_t i) {return name.at(i);}
    ostream& operator<<(ostream& os, const Node& node)
    {
        os << node.name;
        return os;
    }
}