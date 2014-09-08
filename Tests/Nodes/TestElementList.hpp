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

      aTestElement = new Element( aName, aSurname,
                                            aFatherName, aFatherSurname,
                                            aMotherName, aMotherSurname );

      aFatherTestElement = new Element( aFatherName, aFatherSurname,
                                            "N/A", "N/A", "N/A", "N/A" );

      aMotherTestElement = new Element( aMotherName, aMotherSurname,
                                            "N/A", "N/A", "N/A", "N/A" );

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
      aListNullInit->addElement( "A", "B", "C", "D", "E", "F" );
      CPPUNIT_ASSERT( aListNullInit->countElements()==1);
  }

  void testCountElements()
  {
      CPPUNIT_ASSERT( aListElementInit->countElements()==3);
      aListElementInit->addElement( "A", "B", "C", "D", "E", "F" );
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
