#ifndef __TESTELEMENT_HPP
#define __TESTELEMENT_HPP

#include "Nodes/Element.hpp"
#include <cstdlib>
#include <cppunit/extensions/HelperMacros.h>

class TestElement : public CppUnit::TestFixture  {

    CPPUNIT_TEST_SUITE( TestElement );
    CPPUNIT_TEST( testAssignRelationship );
    CPPUNIT_TEST( testFatherNameAll );
    CPPUNIT_TEST( testMotherNameAll );
    CPPUNIT_TEST( testGetCompleteName );
    CPPUNIT_TEST( testNextAll );
    CPPUNIT_TEST( testPreviousAll );
    CPPUNIT_TEST( testGender );
    CPPUNIT_TEST( testBirthdate );
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
    int aYear;
    int aMonth;
    int aDay;

public:
  void setUp()
  {
      aName = "John";
      aSurname = "Doe";
      aFatherName = "Stephen";
      aFatherSurname = "Doe";
      aMotherName = "Scarlett";
      aMotherSurname = "O'Hara";
      aYear = 1985;
      aMonth = 8;
      aDay = 15;

      aTestElement = new Element( aName, aSurname, Element::MALE,
                                  aFatherName, aFatherSurname,
                                  aMotherName, aMotherSurname, aYear, aMonth, aDay );

      aFatherTestElement = new Element( aFatherName, aFatherSurname, Element::MALE,
                                            "N/A", "N/A", "N/A", "N/A", 1944, 4, 4 );

      aMotherTestElement = new Element( aMotherName, aMotherSurname, Element::FEMALE,
                                            "N/A", "N/A", "N/A", "N/A", 1956, 7, 12 );

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
      Element * aNewElement = new Element( "A" , "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1 );
      aTestElement->setNext( aNewElement );
      CPPUNIT_ASSERT( aTestElement->getNext()==aNewElement );
      aTestElement->setNext( NULL );
      delete aNewElement;
  }

  void testPreviousAll()
  {
      // Insert a new element at the start of the list
      Element * aNewElement = new Element( "A" , "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1 );
      aFatherTestElement->setPrevious( aNewElement );
      CPPUNIT_ASSERT( aFatherTestElement->getPrevious()==aNewElement );
      aFatherTestElement->setPrevious( NULL );
      delete aNewElement;
  }

  void testGender()
  {
      // Create a male element
      Element * aMaleElement = new Element( "A" , "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1 );
      Element * aFemaleElement = new Element( "G" , "H", Element::FEMALE, "I", "J", "K", "L", 1995, 1, 1 );
      CPPUNIT_ASSERT( aMaleElement->getGender()==Element::MALE );
      CPPUNIT_ASSERT( aFemaleElement->getGender()==Element::FEMALE );

      delete aMaleElement;
      delete aFemaleElement;
  }

  void testBirthdate()
  {
      CPPUNIT_ASSERT( aTestElement->getBirthDate().length() == 10 );
      Element * aElement = new Element( "A" , "B", Element::MALE, "C", "D", "E", "F", 1995, 1, 1 );
      aElement->setBirthDate( 2002, 12, 25 );
      CPPUNIT_ASSERT( aElement->getBirthDate().compare( "2002-12-25" )==0);

      for (int i=0; i<50000; i++)
      {
          int aRandomYear  = (rand() % 50000)-25000;
          int aRandomMonth = (rand() % 100)-50;
          int aRandomDay   = (rand() % 200)-100;
          bool aResult = aElement->setBirthDate( aRandomYear, aRandomMonth, aRandomDay );

          bool aExpectedResult;
          if (( aRandomYear<0 ) ||( aRandomYear>9999 )||
              ( aRandomMonth<1 )||( aRandomMonth>12 ) ||
              ( aRandomDay<1 )  ||( aRandomDay>31 ))
          {
              aExpectedResult = false;
          }
          else
          {
              aExpectedResult = true;
          }
          CPPUNIT_ASSERT( aResult==aExpectedResult );
      }

  }

};


#endif // __TESTELEMENT_HPP
