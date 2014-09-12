#ifndef __TESTELEMENTLIST_HPP
#define __TESTELEMENTLIST_HPP

#include "Nodes/ElementList.hpp"
#include <cppunit/extensions/HelperMacros.h>

class TestElementList : public CppUnit::TestFixture  {

    CPPUNIT_TEST_SUITE( TestElementList );
    CPPUNIT_TEST( testAddElement );
    CPPUNIT_TEST( testCountElements );
    CPPUNIT_TEST( testAssignRelationships );
    CPPUNIT_TEST( testFirstElement );
    CPPUNIT_TEST( testDeleteAllElements );
    CPPUNIT_TEST( testSearches );
    CPPUNIT_TEST_SUITE_END();

private:

    ElementList * aListNullInit;
    ElementList * aListElementInit;

    Element * aTestElement;
    Element * aFatherTestElement;
    Element * aMotherTestElement;

    std::string aName;
    std::string aSurname;
    std::string aFatherName;
    std::string aFatherSurname;
    std::string aMotherName;
    std::string aMotherSurname;

public:
  void setUp()
  {
      aName = "John";
      aSurname = "Doe";
      aFatherName = "Stephen";
      aFatherSurname = "Doe";
      aMotherName = "Scarlett";
      aMotherSurname = "O'Hara";

      aTestElement = new Element( aName, aSurname, Element::MALE,
                                  aFatherName, aFatherSurname,
                                  aMotherName, aMotherSurname, 1985, 8, 15, "Ponferrada" );

      aFatherTestElement = new Element( aFatherName, aFatherSurname, Element::MALE,
                                            "N/A", "N/A", "N/A", "N/A", 1944, 4, 4, "Ponferrada" );

      aMotherTestElement = new Element( aMotherName, aMotherSurname, Element::FEMALE,
                                            "N/A", "N/A", "N/A", "N/A", 1956, 7, 12, "Ponferrada" );

      // Form a list starting on Father element
      aFatherTestElement->setNext( aMotherTestElement );
      aMotherTestElement->setNext( aTestElement );
      aTestElement->setPrevious( aMotherTestElement );
      aMotherTestElement->setPrevious( aFatherTestElement );

      aListNullInit = new ElementList();
      aListElementInit = new ElementList( aFatherTestElement );

  }

  void tearDown()
  {
    aListNullInit->deleteAllElements();
    aListElementInit->deleteAllElements();
    delete aListNullInit;
    delete aListElementInit;
  }

  void testAddElement()
  {
      CPPUNIT_ASSERT( aListNullInit->countElements()==0);
      aListNullInit->addElement( "A", "B", Element::MALE,"C", "D", "E", "F", 1995, 1, 1, "Ponferrada" );
      CPPUNIT_ASSERT( aListNullInit->countElements()==1);
  }

  void testCountElements()
  {
      CPPUNIT_ASSERT( aListElementInit->countElements()==3);
      aListElementInit->addElement( "A", "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1, "Ponferrada" );
      CPPUNIT_ASSERT( aListElementInit->countElements()==4);
  }

  void testAssignRelationships()
  {
      CPPUNIT_ASSERT( aListElementInit->assignRelationships()==2 );
  }

  void testFirstElement()
  {
      CPPUNIT_ASSERT( aListElementInit->getFirstElement()==aFatherTestElement );
  }

  void testDeleteAllElements()
  {
      CPPUNIT_ASSERT( aListElementInit->countElements()==3);
      aListElementInit->deleteAllElements();
      CPPUNIT_ASSERT( aListElementInit->countElements()==0);
  }

  void testSearches()
  {
      ElementList aNullList;
      ElementList aList;

      aList.addElement( "John", "Doe", Element::MALE, "Fox", "McCloud", "Jenna", "Jameson", 1954, 11, 7, "New York" );
      aList.addElement( "Jimmy", "Doe", Element::MALE, "John", "Doe", "Anna", "Frank", 1976, 6, 22, "Paris" );
      aList.addElement( "Anna", "Doe", Element::FEMALE,"John", "Doe", "Anna", "Frank", 1979, 10, 14, "Moscow" );
      aList.addElement( "Louise", "Gates", Element::FEMALE, "Bill", "Gates", "Anna", "Doe", 2004, 3, 27, "Pekin" );
      aList.addElement( "Miguel", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1985, 8, 15, "Ponferrada" );
      aList.addElement( "Ernie", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 1987, 12, 12, "Valdepeñas" );
      aList.addElement( "Ernie", "Roberts", Element::MALE, "Kenny", "Roberts", "Louise", "Gates", 2011, 8, 3, "Murcia" );

      aList.assignRelationships();
      aList.countElements();

      std::list<Element*> aResultList = aList.searchDescendantsByName( "Jimmy", "Ernie");
      CPPUNIT_ASSERT( aResultList.size()==2 );

      aResultList = aList.searchByName( "Ernie" );
      CPPUNIT_ASSERT( aResultList.size()==2 );

      aResultList = aNullList.searchByName( "Ernie" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aList.searchByName( "Rodrigo" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aList.searchBySurname( "Doe" );
      CPPUNIT_ASSERT( aResultList.size()==3 );

      aResultList = aNullList.searchBySurname( "Doe" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aList.searchByBirthDate( 2004, 3, 27 );
      CPPUNIT_ASSERT( aResultList.size()==1 );

      aResultList = aNullList.searchByBirthDate( 2004, 3, 27 );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aList.searchByLocation( "Ponferrada" );
      CPPUNIT_ASSERT( aResultList.size()==1 );

      aResultList = aNullList.searchByLocation( "Ponferrada" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

  }
};

#endif // __TESTELEMENTLIST_HPP
