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
                                  aMotherName, aMotherSurname, 1985, 8, 15 );

      aFatherTestElement = new Element( aFatherName, aFatherSurname, Element::MALE,
                                            "N/A", "N/A", "N/A", "N/A", 1944, 4, 4 );

      aMotherTestElement = new Element( aMotherName, aMotherSurname, Element::FEMALE,
                                            "N/A", "N/A", "N/A", "N/A", 1956, 7, 12 );

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
      aListNullInit->addElement( "A", "B", Element::MALE,"C", "D", "E", "F", 1995, 1, 1 );
      CPPUNIT_ASSERT( aListNullInit->countElements()==1);
  }

  void testCountElements()
  {
      CPPUNIT_ASSERT( aListElementInit->countElements()==3);
      aListElementInit->addElement( "A", "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1 );
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
};

#endif // __TESTELEMENTLIST_HPP
