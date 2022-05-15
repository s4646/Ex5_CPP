#pragma once
#include "Node.hpp"
#include <string>
#include <iostream>

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
                public:
                    Iterator(Node* ptr) : m_pointer(ptr) {}
                    ~Iterator() {}
                    Node& operator*();
                    bool operator!=(const Iterator&) const;
                    bool operator==(const Iterator&) const;
                    Iterator& operator++(); // Prefix
                    Node* operator->(); // return node's name
            };

            OrgChart();
            ~OrgChart();
            OrgChart add_root(std::string);
            OrgChart add_sub(std::string, std::string);
            Iterator begin();
            Iterator end();
            Iterator begin_level_order();
            Iterator end_level_order();
            Iterator begin_reverse_order();
            Iterator end_reverse_order();
            Iterator begin_preorder();
            Iterator end_preorder();
            friend std::ostream& operator<<(std::ostream&, const OrgChart&);
    };
}