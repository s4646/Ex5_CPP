#include "OrgChart.hpp"

using namespace std;

namespace ariel
{
    Node& OrgChart::Iterator::operator*()
    {
        return *m_pointer;
    }
    bool OrgChart::Iterator::operator==(const Iterator& other) const
    {
        return this->m_pointer == other.m_pointer;
    }
    bool OrgChart::Iterator::operator!=(const Iterator& other) const
    {
        return this->m_pointer != other.m_pointer;
    }
    OrgChart::Iterator& OrgChart::Iterator::operator++() // Prefix
    {
        return *this;
    }
    Node* OrgChart::Iterator::operator->()
    {
        return m_pointer;
    }

    OrgChart::OrgChart() : totalNodes(0) {}
    OrgChart::~OrgChart() {}
    
    OrgChart OrgChart::add_root(string r)
    {
        Node temp(r);
        root = temp;
        return *this;
    }
    OrgChart OrgChart::add_sub(string inChart, string addTo)
    {
        return *this;
    }
    OrgChart::Iterator OrgChart::begin()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::end()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::begin_level_order()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::end_reverse_order()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::begin_preorder()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        Node* ptr = nullptr;
        Iterator temp(ptr);
        return temp;
    }
    ostream& operator<<(ostream& os, const OrgChart& chart)
    {
        os << chart.root;
        return os;
    }
}