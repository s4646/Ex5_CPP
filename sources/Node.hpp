#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace ariel
{
    class Node
    {
        private:
            std::string name;
            std::vector<Node> kids;
        public:
            Node();
            Node(const std::string&);
            ~Node();
            std::string& getName();
            void setName(const std::string&);
            std::vector<Node>& getKids();
            void addKid(const std::string&);
            int size();
            friend std::ostream& operator<<(std::ostream&, const Node&);
    };
}