#ifndef __ELEMENT_HPP
#define __ELEMENT_HPP

#include <map>
#include <string>
#include <iostream>

class Element
{
public:

    enum TGender { MALE, FEMALE };

    /**
     * @brief Element Creates a element (node) based on its name and surname
     * @param aName Person name
     * @param aSurname Person surname
     * @param aFatherName Father name, optional in constructor
     * @param aFatherSurname Father surname, optional in constructor
     * @param aMotherName Mother name, optional in constructor
     * @param aMotherSurname Mother surname, optional in constructor
     */
    Element( std::string aName, std::string aSurname, TGender aGender, std::string aFatherName,
             std::string aFatherSurname, std::string aMotherName,
             std::string aMotherSurname );

    /**
     * @brief assignRelationship Checks the direct relationship (father, mother)
     * between this element and another one, and sets the pointers in case it
     * is neccessary
     * @param aMember Pointer to member whose relationship will be checked
     */
    void assignRelationship( Element * aMember );

    /**
     * @brief setFatherCredentials Sets the father name and surname for this element
     * @param aName Father's name
     * @param aSurname Father's surname
     */
    void setFatherCredentials( std::string aName, std::string aSurname );

    /**
     * @brief setMotherCredentials Sets the mother name and surname for this element
     * @param aName Mother's name
     * @param aSurname Mother's surname
     */
    void setMotherCredentials( std::string aName, std::string aSurname );

    /**
     * @brief getCompleteName Concatenates and returns the complete name for
     * an element
     * @return Complete name (name+surname) for this element
     */
    std::string getCompleteName();

    /**
     * @brief getFatherCompleteName Concatenates and returns the complete name
     * for an element's father
     * @return Complete name (name+surname) for this element's father
     */
    std::string getFatherCompleteName();

    /**
     * @brief getMotherCompleteName Concatenates and returns the complete name
     * for an element's mother
     * @return Complete name (name+surname) for this element's mother
     */
    std::string getMotherCompleteName();

    /**
     * @brief getNext Returns the pointer to the next linked element
     * @return Pointer to next element in list
     */
    Element * getNext();

    /**
     * @brief setNext Assigns an element as the next for this instance
     * @param aElement Pointer to element to be set as next
     */
    void setNext( Element * aElement );

    /**
     * @brief getPrevious Returns the pointer to the previous linked
     * element
     * @return Pointer to previous element in list
     */
    Element * getPrevious();

    /**
     * @brief setPrevious Assigns an element as the previous for
     * this instance
     * @param aElement Pointer to element to be set as previous
     */
    void setPrevious( Element * aElement );

    /**
     * @brief getFather Returns the father element of this instance,
     * if available
     * @return Pointer to father in genealogic tree
     */
    Element * getFather();

    /**
     * @brief getMother Returns the mother elemnt of this instance,
     * if available
     * @return Pointer to mother in genealogic tree
     */
    Element * getMother();

    /**
     * @brief getGender Returns the gender for this instance
     * @return Gender type set in this instance
     */
    Element::TGender getGender();

private:

    std::string theName;
    std::string theSurname;
    std::string theFatherName;
    std::string theFatherSurname;
    std::string theMotherName;
    std::string theMotherSurname;
    Element * theNext;       // Pointer to next stored structure
    Element * thePrevious;   // Pointer to previous stored structure
    Element * theFather;     // Pointer to father
    Element * theMother;     // Pointer to mother
    TGender theGender;
};



#endif // __ELEMENT_HPP
