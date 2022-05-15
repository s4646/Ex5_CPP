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
            Node(std::string);
            ~Node();
            std::string getName();
            std::vector<Node>& getKids();
            void addKid(std::string);
            int size();
            friend std::ostream& operator<<(std::ostream&, const Node&);
    };
}