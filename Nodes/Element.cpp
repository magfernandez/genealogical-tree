#include "Element.hpp"

Element::Element( std::string aName, std::string aFatherName, std::string aMotherName )
{
    theName = aName;
    theFatherName = aFatherName;
    theMotherName = aMotherName;
    theNext = NULL;
    thePrevious = NULL;
    theFather = NULL;
    theMother = NULL;
}

void Element::assignRelationship( Element *aMember )
{
    // Relationship between names to compare and pointers to
    // an assignable element for that role
    std::map<std::string, Element *> theFamilyMap;
    theFamilyMap[ theFatherName ] = theFather;
    theFamilyMap[ theMotherName ] = theMother;

    for (std::map<std::string, Element*>::iterator it=theFamilyMap.begin();
         it!=theFamilyMap.end(); ++it)
    {
        // if the element name is equal to the stored name, assign
        // the current element to the pointer referenced in map
        if ( it->first.compare( aMember->theName ) == 0 )
        {
            it->second = aMember;
        }
    }
}
