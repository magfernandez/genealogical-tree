
#include <iostream>

#include "Nodes/ElementList.hpp"

#include "Tests/Nodes/TestElement.hpp"
#include "Tests/Nodes/TestElementList.hpp"

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>


using namespace std;
using namespace CppUnit;

int main(int argc, char *argv[])
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestElement::suite() );
    runner.addTest( TestElementList::suite() );
    runner.run();

    ElementList aList;
    aList.addElement( "John", "Doe", "Fox", "McCloud", "Jenna", "Jameson" );
    aList.addElement( "Jimmy", "Doe", "John", "Doe", "Anna", "Frank" );
    aList.addElement( "Anna", "Doe", "John", "Doe", "Anna", "Frank" );
    aList.addElement( "Robert", "Gates", "Bill", "Gates", "Anna", "Doe" );

    aList.assignRelationships();
    aList.countElements();


    return 0;
}
