#ifndef __TESTELEMENT_HPP
#define __TESTELEMENT_HPP

#include "Nodes/Element.hpp"
#include <cppunit/extensions/HelperMacros.h>

class TestElement : public CppUnit::TestFixture  {

    CPPUNIT_TEST_SUITE( TestElement );
    CPPUNIT_TEST( testAssignRelationship );
    CPPUNIT_TEST( testFatherNameAll );
    CPPUNIT_TEST( testMotherNameAll );
    CPPUNIT_TEST( testGetCompleteName );
    CPPUNIT_TEST( testNextAll );
    CPPUNIT_TEST( testPreviousAll );
    CPPUNIT_TEST_SUITE_END();

private:

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

  }

  void tearDown()
  {
    delete aTestElement;
    delete aFatherTestElement;
    delete aMotherTestElement;
  }

  void testAssignRelationship()
  {
      // Also tests getters for mother/father
      Element * aCurrent = aFatherTestElement;
      aTestElement->assignRelationship( aCurrent );
      CPPUNIT_ASSERT( aTestElement->getFather()==aFatherTestElement );
      CPPUNIT_ASSERT( aTestElement->getMother()==aMotherTestElement );
  }

  void testFatherNameAll()
  {
      std::string aFullFatherName = aFatherName + " " + aFatherSurname;
      aTestElement->setFatherCredentials( aFatherName, aFatherSurname );
      std::string aGotFatherName = aTestElement->getFatherCompleteName();
      CPPUNIT_ASSERT( aFullFatherName.compare( aGotFatherName )==0 );
  }

  void testMotherNameAll()
  {
      std::string aFullMotherName = aMotherName + " " + aMotherSurname;
      aTestElement->setMotherCredentials( aMotherName, aMotherSurname );
      std::string aGotMotherName = aTestElement->getMotherCompleteName();
      CPPUNIT_ASSERT( aFullMotherName.compare( aGotMotherName )==0 );
  }

  void testGetCompleteName()
  {
    std::string myName = aName + " " + aSurname;
    std::string myGotName = aTestElement->getCompleteName();
    CPPUNIT_ASSERT( myName.compare( myGotName )==0);
  }

  void testNextAll()
  {
      // Insert a new element at the end of the list
      Element * aNewElement = new Element( "A" , "B", "C", "D", "E", "F" );
      aTestElement->setNext( aNewElement );
      CPPUNIT_ASSERT( aTestElement->getNext()==aNewElement );
      aTestElement->setNext( NULL );
      delete aNewElement;
  }

  void testPreviousAll()
  {
      // Insert a new element at the start of the list
      Element * aNewElement = new Element( "A" , "B", "C", "D", "E", "F" );
      aFatherTestElement->setPrevious( aNewElement );
      CPPUNIT_ASSERT( aFatherTestElement->getPrevious()==aNewElement );
      aFatherTestElement->setPrevious( NULL );
      delete aNewElement;
  }

};


#endif // __TESTELEMENT_HPP
