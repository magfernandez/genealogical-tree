#ifndef __TESTELEMENTLIST_HPP
#define __TESTELEMENTLIST_HPP

#include "Nodes/ElementList.hpp"
#include <cppunit/extensions/HelperMacros.h>

class TestElementList : public CppUnit::TestFixture  {

    CPPUNIT_TEST_SUITE( TestElementList );
    CPPUNIT_TEST( testAddCountElement );
    CPPUNIT_TEST( testDeleteAllElements );
    CPPUNIT_TEST( testSearches );
    CPPUNIT_TEST_SUITE_END();

private:

    ElementList aListNullInit;

public:
  void setUp()
  {
      aListNullInit = ElementList();

      aListNullInit.addElement( "John", "Doe", Element::MALE, "Fox", "McCloud", "Jenna", "Jameson", 1954, 11, 7, "New York" );
      aListNullInit.addElement( "Jimmy", "Doe", Element::MALE, "John", "Doe", "Anna", "Frank", 1976, 6, 22, "Paris" );
      aListNullInit.addElement( "Anna", "Doe", Element::FEMALE,"John", "Doe", "Anna", "Frank", 1979, 10, 14, "Moscow" );
      aListNullInit.addElement( "Louise", "Gates", Element::FEMALE, "Bill", "Gates", "Anna", "Doe", 2004, 3, 27, "Pekin" );
      aListNullInit.addElement( "Miguel", "Gutierrez", Element::MALE, "Jose Luis", "Gutierrez", "Maria Asuncion", "Fernandez", 1985, 8, 15, "Ponferrada" );
      aListNullInit.addElement( "Ernie", "Gates", Element::MALE, "Bill", "Gates", "Anna", "Doe", 1987, 12, 12, "Valdepeñas" );
      aListNullInit.addElement( "Ernie", "Roberts", Element::MALE, "Kenny", "Roberts", "Louise", "Gates", 2011, 8, 3, "Murcia" );
  }

  void tearDown()
  {
    aListNullInit.deleteAllElements();
  }

  void testAddCountElement()
  {
      CPPUNIT_ASSERT( aListNullInit.countElements()==7);
      aListNullInit.addElement( "A", "B", Element::MALE,"C", "D", "E", "F", 1995, 1, 1, "Cáceres" );
      CPPUNIT_ASSERT( aListNullInit.countElements()==8);
  }

  void testDeleteAllElements()
  {
      CPPUNIT_ASSERT( aListNullInit.countElements()==7);
      aListNullInit.deleteAllElements();
      CPPUNIT_ASSERT( aListNullInit.countElements()==0);
  }

  void testSearches()
  {
      std::list<Element*> aResultList = std::list<Element*>();

      aResultList = aListNullInit.searchByName( "Ernie" );
      CPPUNIT_ASSERT( aResultList.size()==2 );

      aResultList = aListNullInit.searchByName( "Rodrigo" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aListNullInit.searchBySurname( "Doe" );
      CPPUNIT_ASSERT( aResultList.size()==3 );

      aResultList = aListNullInit.searchBySurname( "Monzón" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aListNullInit.searchByBirthDate( 2004, 3, 27 );
      CPPUNIT_ASSERT( aResultList.size()==1 );

      aResultList = aListNullInit.searchByBirthDate( 2050, 3, 27 );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aListNullInit.searchByLocation( "Ponferrada" );
      CPPUNIT_ASSERT( aResultList.size()==1 );

      aResultList = aListNullInit.searchByLocation( "Segovia" );
      CPPUNIT_ASSERT( aResultList.size()==0 );

      aResultList = aListNullInit.searchDescendantsByName( "John", "Louise" );
      CPPUNIT_ASSERT( aResultList.size()==1 );
  }
};

#endif // __TESTELEMENTLIST_HPP
