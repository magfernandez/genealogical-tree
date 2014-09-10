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
     * @param aFatherName Father name for the new element node
     * @param aFatherSurname Father surname for the new element node
     * @param aMotherName Mother name for the new element node
     * @param aMotherSurname Mother surname for the new element node
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
