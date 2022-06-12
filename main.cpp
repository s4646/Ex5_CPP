#include "sources/OrgChart.hpp"
#include <algorithm>

using namespace std;

int main()
{

    ariel::OrgChart organization;
    organization.add_root("CEO")
                .add_sub("CEO", "CTO")      // the CTO is subordinate to the CEO
                .add_sub("CEO", "CFO")      // the CFO is subordinate to the CEO
                .add_sub("CEO", "COO")      // the COO is subordinate to the CEO
                .add_sub("CTO", "VP_SW")    // the VP_SW is subordinate to the CTO
                .add_sub("CFO", "VP_AI")    // the VP_AI is subordinate to the CFO
                .add_sub("COO", "VP_BI");   // the VP_BI is subordinate to the COO

    std::cout << organization << std::endl;

    cout << "Level Order: ";
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout << (*it) << " " ;
    } // prints: CEO CTO CFO COO VP_SW VP_AI VP_BI
    cout << endl;

    cout << "Reverse Order :";
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout << (*it) << " " ;
    } // prints: VP_SW VP_AI VP_BI CTO CFO COO CEO
    cout << endl;

    cout << "Preorder: ";
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it)
    {
        cout << (*it) << " " ;
    }  // prints: CEO CTO VP_SW CFO COO VP_BI
    cout << endl;

    for (auto element : organization)
    { // this should work like level order
        cout << element << " " ;
    } // prints: CEO CTO CFO VP_AI COO VP_SW VP_BI
    cout << endl;

    // demonstrate the arrow operator:
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
      cout << it->size() << " " ;
    } // prints: 3 3 3 3 5 5
    cout << endl << endl;

    // sort organization in alphabetic order
    vector<string> vecOrg; // cannot initiate from OrgChart's iterators
    for (string element : organization)
    {
      vecOrg.push_back(element);
    }
    sort(vecOrg.begin(), vecOrg.end(), std::less<string>());
    for (string element : vecOrg)
    {
      cout << element << " ";
    }
    cout << endl << "sorted with the standard library compare function object" << endl;
    cout << endl;

    // reverse the reverse_oreder
    vecOrg.clear();
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
      vecOrg.push_back(*it);
    }
    std::reverse(vecOrg.begin(), vecOrg.end());
    for (string element : vecOrg)
    {
      cout << element << " ";
    }
    cout << endl << "reversed with std::reverse" << endl;
    cout << endl;
    vecOrg.clear();

    vector<ariel::Node*> vecOrg2;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
      vecOrg2.push_back(it.getM_pointer());
    }
    int num = std::count_if(vecOrg2.begin(), vecOrg2.end(), [](ariel::Node* n){return n->level == 2;});
    cout << "there are " << num << " items in level 2" << endl;
    return 0;
}