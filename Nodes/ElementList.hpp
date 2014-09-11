#ifndef __ELEMENTLIST_HPP
#define __ELEMENTLIST_HPP

#include "Element.hpp"
#include <list>

class ElementList
{
public:

    /**
     * @brief ElementList Creates an empty list
     */
    ElementList();

    /**
     * @brief ElementList Creates a list starting with the specified element
     * @param aStartElement Starting element of the list
     */
    ElementList( Element * aStartElement );

    /**
     * @brief addElement Creates a new element and adds it to the list
     * @param aName Name for the new element node
     * @param aSurname Surname for the new element node
     * @param aGender Gender of this element
     * @param aFatherName Father name for the new element node
     * @param aFatherSurname Father surname for the new element node
     * @param aMotherName Mother name for the new element node
     * @param aMotherSurname Mother surname for the new element node
     * @param aBirthYear Year the element was born
     * @param aBirthMonth Month number the element was born
     * @param aBirthDay Day of the month the element was born
     * @param aBirthLocation Birth location for this element
     */
    void addElement(std::string aName, std::string aSurname, Element::TGender aGender,
                     std::string aFatherName, std::string aFatherSurname,
                     std::string aMotherName, std::string aMotherSurname , int aBirthYear, int aBirthMonth, int aBirthDay, std::string aBirthLocation);


    /**
     * @brief searchDescendantsByName Searches all descendants with a specific name for the first
     * element found that matches a specific name
     * @param aNameAscendant Ascendant whose descendants the method will look for
     * @param aNameDescendant Descendant name to look for in the list
     * @return list of all descendants to that ascendant that match the specified name
     */
    std::list<Element*> searchDescendantsByName( std::string aNameAscendant, std::string aNameDescendant );

    /**
     * @brief searchByName Searches all elements whose name matches the specified string
     * @param aName Name to look for
     * @return list with all elements that match the specified name
     */
    std::list<Element*> searchByName( std::string aName );

    /**
     * @brief searchBySurname Searches all elements whose surname matches the specified string
     * @param aSurname Surname to look for
     * @return list with all elements that match the specified surname
     */
    std::list<Element*> searchBySurname( std::string aSurname );

    /**
     * @brief searchByBirthDate Searches all elements whose birth date matches the specified one
     * @param aYear Year to look for
     * @param aMonth Month number to look for
     * @param aDay Day of the month to look for
     * @return list with all elements that match the specified birth date
     */
    std::list<Element*> searchByBirthDate( int aYear, int aMonth, int aDay );

    /**
     * @brief searchByLocation Searches all elements whose birth location matches the specified one
     * @param aLocation Birth location to look for
     * @return list with all elements that match the specified birth location
     */
    std::list<Element*> searchByLocation( std::string aLocation );

    /**
     * @brief countElements Counts the number of elements in the list
     * @return Number of elements in the list
     */
    int countElements();

    /**
     * @brief assignRelationships Searches for relationships between elements
     * in the list and updates them
     * @return Number of relationships between elements found
     */
    int assignRelationships();

    /**
     * @brief getFirstElement Returns the first element on this list
     * @return First element of the list
     */
    Element * getFirstElement();

    /**
     * @brief deleteAllElements Deletes all contained instances
     */
    void deleteAllElements();

private:
    Element * theFirst;
    Element * theLast;
};

#endif // __ELEMENTLIST_HPP
