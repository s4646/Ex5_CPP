#include "OrgChart.hpp"
#include <stdexcept>

using namespace std;

namespace ariel
{
    string& OrgChart::Iterator::operator*()
    {
        return m_pointer->getName();
    }
    bool OrgChart::Iterator::operator==(const Iterator& other) const
    {
        return this->m_pointer == other.m_pointer;
    }
    bool OrgChart::Iterator::operator!=(const Iterator& other) const
    {
        return this->m_pointer != other.m_pointer;
    }
    OrgChart::Iterator& OrgChart::Iterator::operator++()
    {
        // level-order
        if (mode==0)
        {
            vector<Node>& temp = m_pointer->getKids();
            for (size_t i = 0; i < temp.size(); i++)
            {
                q.push(&temp.at(i));
            }
            q.pop();
            if (!q.empty())
            {
                m_pointer = q.front();
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
            stk.pop();
            if (stk.empty())
            {
                m_pointer = nullptr;
            }
            else
            {
                m_pointer = stk.top();
            }
            return *this;
        }
        // pre-order
        if (mode==2)
        {
            if(vec.empty())
            {
                m_pointer = nullptr;
                return *this;
            }
            m_pointer = vec.at(0);
            vec.erase(vec.begin());
            vector<Node>& temp = m_pointer->getKids();
            for (size_t i = 0; i < temp.size(); i++)
            {
                vec.insert(vec.begin()+(int)i, &temp.at(i));
            }
            if(vec.empty())
            {
                m_pointer = nullptr;
                return *this;
            }
            m_pointer = vec.at(0);
            return *this;
        }
        return *this;
    }
    Node* OrgChart::Iterator::operator->()
    {
        return m_pointer;
    }
    queue<Node*>& OrgChart::Iterator::getQueue() {return q;}
    stack<Node*>& OrgChart::Iterator::getStack() {return stk;}
    vector<Node*>& OrgChart::Iterator::getVector() {return vec;}
    Node* OrgChart::Iterator::getM_pointer() {return m_pointer;}
    void OrgChart::Iterator::setM_pointer(Node* ptr) {m_pointer = ptr;}

    OrgChart::OrgChart() : totalNodes(0) {}
    OrgChart::~OrgChart() {}
    
    OrgChart& OrgChart::add_root(const string& r)
    {
        Node temp(r);
        root = temp;
        totalNodes = 1;
        return *this;
    }
    OrgChart& OrgChart::add_sub(const string& inChart, const string& addTo)
    {
        if (root.getName().empty())
        {
            throw runtime_error("can't add sub before root");
        }
        for (auto it = begin(); it != end(); ++it)
        {
            if(*it == inChart)
            {
                it->addKid(addTo);
                ++totalNodes;
                return *this;
            }
        }
        throw runtime_error("employer doesn't exist");
    }

    OrgChart::Iterator OrgChart::begin()
    {
        return begin_level_order();
    }
    OrgChart::Iterator OrgChart::end()
    {
        return end_level_order();
    }

    OrgChart::Iterator OrgChart::begin_level_order()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(&root, 0);
        it.getQueue().push(it.getM_pointer());
        return it;
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(nullptr, 0);
        return it;
    }

    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(&root, 1);
        queue<Node*>& q = it.getQueue();
        stack<Node*>& stk = it.getStack();
        q.push(it.getM_pointer());
        while(!q.empty())
        {
            Node* temp = q.front();
            stk.push(q.front());
            q.pop();
            for (int i = temp->getKids().size()-1; i > -1; i--)
            {
                q.push(&temp->getKids().at((size_t)i));
            }
        }
        it.setM_pointer(stk.top());
        return it;
    }
    OrgChart::Iterator OrgChart::reverse_order()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(nullptr, 1);
        return it;
    }

    OrgChart::Iterator OrgChart::begin_preorder()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(&root, 2);
        it.getVector().push_back(it.getM_pointer());
        return it;
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        if (totalNodes == 0) {throw runtime_error("chart is empty!");}
        Iterator it(nullptr, 2);
        return it;
    }

    ostream& operator<<(ostream& os, const OrgChart& chart)
    {
        os << chart.root;
        return os;
    }
}