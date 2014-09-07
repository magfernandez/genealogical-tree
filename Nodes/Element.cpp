#include "Element.hpp"

Element::Element(std::string aName, std::string aSurname, std::string aFatherName, std::string aFatherSurname, std::string aMotherName , std::string aMotherSurname)
{
    theName = aName;
    theSurname = aSurname;
    theFatherName = aFatherName;
    theFatherSurname = aFatherSurname;
    theMotherName = aMotherName;
    theMotherSurname = aMotherSurname;
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
    theFamilyMap[ this->getFatherCompleteName() ] = theFather;
    theFamilyMap[ this->getMotherCompleteName() ] = theMother;

    for (std::map<std::string, Element*>::iterator it=theFamilyMap.begin();
         it!=theFamilyMap.end(); ++it)
    {
        // if the element name is equal to the stored name, assign
        // the current element to the pointer referenced in map
        if ( it->first.compare( aMember->getCompleteName() ) == 0 )
        {
            it->second = aMember;
        }
    }
}

void Element::setFatherCredentials( std::string aName, std::string aSurname )
{
    theFatherName = aName;
    theFatherSurname = aSurname;
}

void Element::setMotherCredentials( std::string aName, std::string aSurname )
{
    theMotherName = aName;
    theMotherSurname = aSurname;
}

std::string Element::getCompleteName()
{
    return ( this->theName + std::string(" ") + this->theSurname );
}

std::string Element::getFatherCompleteName()
{
    return ( this->theFatherName + std::string(" ") + this->theFatherSurname );
}

std::string Element::getMotherCompleteName()
{
    return ( this->theMotherName + std::string(" ") + this->theMotherSurname );
}
