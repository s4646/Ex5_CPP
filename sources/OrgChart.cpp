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
        // level-order
        if (mode==0)
        {
            vector<Node> temp = m_pointer->getKids();
            for (size_t i = 0; i < temp.size(); i++)
            {
                q.push(temp.at(i));
            }
            q.pop();
            if (q.size()>0)
            {
                m_pointer = &q.front();
            }
            else
            {
                m_pointer = nullptr;
            }
            return *this;
        }
        // reverse order
        if (mode==1)
        {
            while(m_pointer->getName() == "nullptr")
            {
                stk.pop();
                m_pointer = &stk.top();
            }
            vector<Node> temp = m_pointer->getKids();
            for (size_t i = temp.size() -1; i >= 0; i--)
            {
                stk.push(temp.at(i));
                if (temp.at(i).getKids().size() == 0)
                {
                    stk.push(Node{"nullptr"});
                }
            }
            if (stk.size()>0)
            {
                m_pointer = &stk.top();
                stk.pop();
            }
            else
            {
                m_pointer = nullptr;
            }
            return *this;
        }
        // pre-order
        if (mode==2)
        {
            if(vec.size() == 0)
            {
                m_pointer = nullptr;
                return *this;
            }
            m_pointer = &vec.at(0);
            vector<Node> temp = m_pointer->getKids();
            vec.erase(vec.begin());
            for (size_t i = 0; i < temp.size(); i++)
            {
                vec.insert(vec.begin()+i, temp.at(i));
            }
            return *this;
        }
    }
    Node* OrgChart::Iterator::operator->()
    {
        return m_pointer;
    }
    queue<Node>& OrgChart::Iterator::getQueue() {return q;}
    stack<Node>& OrgChart::Iterator::getStack() {return stk;}
    vector<Node>& OrgChart::Iterator::getVector() {return vec;}
    Node* OrgChart::Iterator::getM_pointer() {return m_pointer;}

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
        Iterator it(&root, 0);
        it.getQueue().push(*it.getM_pointer());
        return it;
    }
    OrgChart::Iterator OrgChart::end()
    {
        Iterator it(nullptr, 0);
        return it;
    }

    OrgChart::Iterator OrgChart::begin_level_order()
    {
        Iterator it(&root, 0);
        it.getQueue().push(*it.getM_pointer());
        return it;
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        Iterator it(nullptr, 0);
        return it;
    }

    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        Iterator it(&root, 1);
        it.getStack().push(*it.getM_pointer());
        ++it;
        return it;
    }
    OrgChart::Iterator OrgChart::reverse_order()
    {
        Iterator it(nullptr, 1);
        return it;
    }

    OrgChart::Iterator OrgChart::begin_preorder()
    {
        Iterator it(&root, 2);
        it.getVector().push_back(*it.getM_pointer());
        return it;
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        Iterator it(nullptr, 2);
        return it;
    }

    ostream& operator<<(ostream& os, const OrgChart& chart)
    {
        os << chart.root;
        return os;
    }
}