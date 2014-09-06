#ifndef __ELEMENT_HPP
#define __ELEMENT_HPP

#include <map>
#include <string>
#include <iostream>

class Element
{
public:

    Element( std::string aName, std::string aFatherName = "", std::string aMotherName = "" );

    void assignRelationship( Element * aMember );

private:

    std::string theName;
    std::string theFatherName;
    std::string theMotherName;
    Element * theNext;       // Pointer to next stored structure
    Element * thePrevious;   // Pointer to previous stored structure
    Element * theFather;     // Pointer to father
    Element * theMother;     // Pointer to mother
};



#endif // __ELEMENT_HPP
