#include "sources/OrgChart.hpp"

int main()
{

    ariel::OrgChart organization;
    organization.add_root("CEO")
                .add_sub("CEO", "CTO")
                .add_sub("CEO", "CFO")
                .add_sub("CEO", "COO")
                .add_sub("CTO", "VP_SW")
                .add_sub("CFO", "VP_AI")
                .add_sub("COO", "VP_BI");

    std::cout << organization << std::endl;

    return 0;
}