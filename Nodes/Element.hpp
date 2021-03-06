#ifndef __ELEMENT_HPP
#define __ELEMENT_HPP

#include <map>
#include <string>
#include <iostream>
#include <stdio.h>

class Element
{
public:

    typedef struct {
        int year;
        int month;
        int day;
    }TDate;

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
    Element(std::string aName, std::string aSurname, TGender aGender, std::string aFatherName,
             std::string aFatherSurname, std::string aMotherName,
             std::string aMotherSurname, int aBirthYear, int aBirthMonth, int aBirthDay,
             std::string aBirthLocation );

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
     * @brief getName Returns the first name for this element
     * @return First name for this element
     */
    std::string getName();

    /**
     * @brief getSurname Returns the last name for this element
     * @return Last name for this element
     */
    std::string getSurname();

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
     * @brief getGender Returns the gender for this instance
     * @return Gender type set in this instance
     */
    Element::TGender getGender();

    /**
     * @brief getBirthDate Returns the birth date of this element
     * @return string containing the birth date in format YYYY-MM-DD
     */
    std::string getBirthDate();

    /**
     * @brief setBirthDate Sets the birth date for this element
     * @param aYear Birth year [0..9999]
     * @param aMonth Birth month [1..12]
     * @param aDay Birth day [1..31]
     * @return true if the date is correct. false otherwise
     */
    bool setBirthDate( int aYear, int aMonth, int aDay );

    /**
     * @brief getBirthLocation Gets the birth location for this element
     * @return stored birth location string
     */
    std::string getBirthLocation();

private:

    std::string theName;
    std::string theSurname;
    std::string theFatherName;
    std::string theFatherSurname;
    std::string theMotherName;
    std::string theMotherSurname;
    TGender theGender;
    TDate theBirthDate;
    std::string theBirthLocation;
};



#endif // __ELEMENT_HPP
