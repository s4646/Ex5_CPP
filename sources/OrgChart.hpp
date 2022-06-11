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
                    std::queue<Node*> q;
                    std::stack<Node*> stk;
                    std::vector<Node*> vec;
                public:
                    Iterator(Node* ptr, int m) : m_pointer(ptr), mode(m) {}
                    Iterator(const Iterator&);
                    Iterator(Iterator&&) noexcept;
                    ~Iterator() {}
                    std::string& operator*();
                    Iterator& operator=(const Iterator&);
                    Iterator& operator=(Iterator&&) noexcept;
                    bool operator!=(const Iterator&) const;
                    bool operator==(const Iterator&) const;
                    Iterator& operator++(); // Prefix
                    Node* operator->();
                    std::queue<Node*>& getQueue();
                    std::stack<Node*>& getStack();
                    std::vector<Node*>& getVector();
                    Node* getM_pointer();
                    void setM_pointer(Node*);
            };

            OrgChart();
            OrgChart(const OrgChart&);
            OrgChart(OrgChart&&) noexcept;
            ~OrgChart();
            OrgChart& operator=(const OrgChart&);
            OrgChart& operator=(OrgChart&&) noexcept;
            OrgChart& add_root(const std::string&);
            OrgChart& add_sub(const std::string&, const std::string&);
            Iterator begin();
            Iterator end() const;
            Iterator begin_level_order();
            Iterator end_level_order() const;
            Iterator begin_reverse_order();
            Iterator reverse_order() const;
            Iterator begin_preorder();
            Iterator end_preorder() const;
            friend std::ostream& operator<<(std::ostream&, OrgChart&);
    };
}