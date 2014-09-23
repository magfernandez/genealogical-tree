#include "Visualizator/Visualizator.hpp"
#include <QApplication>
#include <iostream>
#include <stdio.h>

#include "Nodes/ElementList.hpp"
#include "Utils/NameGenerator.hpp"

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
    //aList.addElement( "Jimmy", "Doe", Element::MALE, "Joaquim", "Doe", "Jessica", "Lard", 1978, 9, 27, "London" );
    //aList.addElement( "Peter", "Gates", Element::MALE,"Jenson", "Gates", "Martha", "Hendricks", 1934, 12, 14, "Springfield" );
    aList.addElement( "Bill", "Gates", Element::MALE,"Peter", "Gates", "Mia", "Henderson", 1954, 7, 7, "Springfield" );
    aList.addElement( "Anna", "Doe", Element::FEMALE,"John", "Doe", "Anna", "Frank", 1979, 10, 14, "Moscow" );
    aList.addElement( "Louise", "Gates", Element::FEMALE, "Bill", "Gates", "Anna", "Doe", 1984, 3, 27, "Pekin" );
    aList.addElement( "Martin", "Kingston", Element::MALE, "Francis", "Kingston", "Jessica", "Craig", 1972, 6, 9, "Pekin" );
    aList.addElement( "Martha", "Kingston", Element::FEMALE, "Martin", "Kingston", "Louise", "Gates", 2003, 2, 3, "Salamanca" );
    //aList.addElement( "Anne", "Kingston", Element::FEMALE, "Martin", "Kingston", "Louise", "Gates", 2006, 1, 22, "Newcastle" );
    aList.addElement( "Jose Luis", "Gutierrez", Element::MALE, "Carlos", "Gutierrez", "Francisca", "Vidal", 1944, 3, 14, "Poblado" );
    aList.addElement( "Miguel", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1985, 8, 15, "Ponferrada" );
    aList.addElement( "Jose", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1982, 6, 6, "Ponferrada" );
    aList.addElement( "Ernie", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 1987, 12, 12, "Valdepeñas" );


    std::list<Element*> aResultList = aList.searchDescendantsByName( "Jimmy", "Ernie");

    for ( std::list<Element*>::iterator it = aResultList.begin(); it!=aResultList.end(); ++it )
    {
        std::cout << "ELEMENT FOUND: " << (*it)->getCompleteName() << endl;
    }


    QApplication a(argc, argv);


    Visualizator w( &aList );
    w.show();

    return a.exec();
    //return 0;
}
