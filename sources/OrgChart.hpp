#pragma once
#include "Node.hpp"
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

namespace ariel
{
    class OrgChart
    {
        private:
            Node root;
            int totalNodes;
        public:
            class Iterator
            {
                private:
                    Node* m_pointer;
                    int mode;
                    std::queue<Node> q;
                    std::stack<Node> stk;
                    std::vector<Node> vec;
                public:
                    Iterator(Node* ptr, int m) : m_pointer(ptr), mode(m) {}
                    ~Iterator() {}
                    Node& operator*();
                    bool operator!=(const Iterator&) const;
                    bool operator==(const Iterator&) const;
                    Iterator& operator++(); // Prefix
                    Node* operator->(); // return node's name
                    std::queue<Node>& getQueue();
                    std::stack<Node>& getStack();
                    std::vector<Node>& getVector();
                    Node* getM_pointer();
            };

            OrgChart();
            ~OrgChart();
            OrgChart add_root(std::string&);
            OrgChart add_sub(std::string&, std::string&);
            Iterator begin();
            static Iterator end();
            Iterator begin_level_order();
            static Iterator end_level_order();
            Iterator begin_reverse_order();
            static Iterator reverse_order();
            Iterator begin_preorder();
            static Iterator end_preorder();
            friend std::ostream& operator<<(std::ostream&, const OrgChart&);
    };
}