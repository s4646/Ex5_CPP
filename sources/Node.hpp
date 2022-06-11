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
            Node(const Node&);
            Node(Node&&) noexcept;
            ~Node();
            Node& operator=(const Node&);
            Node& operator=(Node&&) noexcept;
            std::string& getName();
            void setName(const std::string&);
            std::vector<Node>& getKids();
            void addKid(const std::string&);
            int size();
            int length();
            char at(size_t);
            int level = 0;
            friend std::ostream& operator<<(std::ostream&, const Node&);
    };
}