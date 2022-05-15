#include "doctest.h"
#include "Node.hpp"
#include "OrgChart.hpp"
#include <array>
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("Level Order")
{
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Magad"));                // Add root
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP1"));        // MemP1 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP2"));        // MemP2 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP3"));        // MemP3 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("MemP1", "Memem1"));       // Memem1 is subordinate to the MemP1
    CHECK_NOTHROW(organization.add_sub("MemP3", "Memem3"));       // Memem3 is subordinate to the MemP3
    /*
                  Magad
         |----------|----------|
       MemP1      MemP2      MemP3
         |                     |
       Memem1                Memem3
    */
    size_t i = 0;
    array<string,6> arr{"Magad", "MemP1", "MemP2", "MemP3", "Memem1", "Memem3"};
    auto it = organization.begin_level_order(); 
    while(i<arr.size()) // it != organization.end_level_order() 
    {
        CHECK(it->getName() == arr.at(i));
        ++it; ++i;
    }
}

TEST_CASE("Reverse Order")
{
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Magad"));                // Add root
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP1"));        // MemP1 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP2"));        // MemP2 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP3"));        // MemP3 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("MemP1", "Memem1"));       // Memem1 is subordinate to the MemP1
    CHECK_NOTHROW(organization.add_sub("MemP3", "Memem3"));       // Memem3 is subordinate to the MemP3
    /*
                  Magad
         |----------|----------|
       MemP1      MemP2      MemP3
         |                     |
       Memem1                Memem3
    */
    size_t i = 0;
    array<string,6> arr{"Memem1", "Memem3", "MemP1", "MemP2", "MemP3", "Magad"};
    auto it = organization.begin_reverse_order(); 
    while(i<arr.size()) // it != organization.end_reverse_order()
    {
        CHECK(it->getName() == arr.at(i));
        ++it; ++i;
    }
}

TEST_CASE("Preorder")
{
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Magad"));                // Add root
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP1"));        // MemP1 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP2"));        // MemP2 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("Magad", "MemP3"));        // MemP3 is subordinate to the Magad
    CHECK_NOTHROW(organization.add_sub("MemP1", "Memem1"));       // Memem1 is subordinate to the MemP1
    CHECK_NOTHROW(organization.add_sub("MemP3", "Memem3"));       // Memem3 is subordinate to the MemP3
    /*
                  Magad
         |----------|----------|
       MemP1      MemP2      MemP3
         |                     |
       Memem1                Memem3
    */
    size_t i = 0;
    array<string,6> arr{"Magad", "MemP1", "Memem1", "MemP2", "MemP3", "Memem3"};
    auto it = organization.begin_level_order(); 
    while(i<arr.size()) // it != organization.end_level_order()
    {
        CHECK(it->getName() == arr.at(i));
        ++it; ++i;
    }
}