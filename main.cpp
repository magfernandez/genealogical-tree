#include "Visualizator/Visualizator.hpp"
#include <QApplication>
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
    aList.addElement( "John", "Doe", Element::MALE, "Fox", "McCloud", "Jenna", "Jameson", 1954, 11, 7, "New York" );
    aList.addElement( "Jimmy", "Doe", Element::MALE, "John", "Doe", "Anna", "Frank", 1976, 6, 22, "Paris" );
    aList.addElement( "Anna", "Doe", Element::FEMALE,"John", "Doe", "Anna", "Frank", 1979, 10, 14, "Moscow" );
    aList.addElement( "Robert", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 2004, 3, 27, "Pekin" );
    aList.addElement( "Miguel", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1985, 8, 15, "Ponferrada" );
    aList.addElement( "Ernie", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 1987, 12, 12, "Valdepeñas" );
    aList.assignRelationships();
    aList.countElements();


    QApplication a(argc, argv);


    Visualizator w( &aList );
    w.show();

    return a.exec();
}
