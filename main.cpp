#include "Visualizator/Visualizator.hpp"
#include <QApplication>
#include <iostream>
#include <stdio.h>

#include "Nodes/ElementList.hpp"

#include "Tests/Nodes/TestElement.hpp"
#include "Tests/Nodes/TestElementList.hpp"

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>


using namespace std;
using namespace CppUnit;

int main(int argc, char *argv[])
{
    //CppUnit::TextUi::TestRunner runner;
    //runner.addTest( TestElement::suite() );
    //runner.addTest( TestElementList::suite() );
    //runner.run();

    ElementList aList;

    aList.addElement( "John", "Doe", Element::MALE, "Fox", "McCloud", "Jenna", "Jameson", 1954, 11, 7, "New York" );
    aList.addElement( "Jimmy", "Doe", Element::MALE, "John", "Doe", "Anna", "Frank", 1976, 6, 22, "Paris" );
    aList.addElement( "Jimmy", "Doe", Element::MALE, "Joaquim", "Doe", "Jessica", "Lard", 1978, 9, 27, "London" );
    aList.addElement( "Anna", "Doe", Element::FEMALE,"John", "Doe", "Anna", "Frank", 1979, 10, 14, "Moscow" );
    aList.addElement( "Louise", "Gates", Element::FEMALE, "Bill", "Gates", "Anna", "Doe", 2004, 3, 27, "Pekin" );
    aList.addElement( "Miguel", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1985, 8, 15, "Ponferrada" );
    aList.addElement( "Ernie", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 1987, 12, 12, "Valdepeñas" );
    aList.addElement( "Ernie", "Roberts", Element::MALE, "Kenny", "Roberts", "Louise", "Gates", 2011, 8, 3, "Murcia" );

    /*aList.assignRelationships();
    aList.countElements();

    std::list<Element*> aResultList = aList.searchDescendantsByName( "Jimmy", "Ernie");


    for ( std::list<Element*>::iterator it = aResultList.begin(); it!=aResultList.end(); ++it )
    {
        std::cout << "ELEMENT FOUND: " << (*it)->getCompleteName() << endl;
    }


    QApplication a(argc, argv);


    Visualizator w( &aList );
    w.show();

    return a.exec();*/
    return 0;
}
