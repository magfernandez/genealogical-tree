#include "Element.hpp"

Element::Element(std::string aName, std::string aSurname, TGender aGender, std::string aFatherName, std::string aFatherSurname,
                 std::string aMotherName , std::string aMotherSurname, int aBirthYear, int aBirthMonth, int aBirthDay , std::string aBirthLocation)
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
    theGender = aGender;
    theBirthDate.year = aBirthYear;
    theBirthDate.month = aBirthMonth;
    theBirthDate.day = aBirthDay;
    theBirthLocation = aBirthLocation;
}

void Element::assignRelationship( Element *aMember )
{
    Element * aCurrentElement = aMember;

    // Relationship between names to compare and pointers to
    // an assignable element for that role
    std::map<std::string, Element *> theFamilyMap;
    theFamilyMap[ this->getFatherCompleteName() ] = this->theFather;
    theFamilyMap[ this->getMotherCompleteName() ] = this->theMother;

    while ( aCurrentElement != NULL )
    {
        if (aCurrentElement->getCompleteName().compare( this->getFatherCompleteName())==0)
        {
            this->theFather = aCurrentElement;
        }
        if (aCurrentElement->getCompleteName().compare( this->getMotherCompleteName())==0)
        {
            this->theMother = aCurrentElement;
        }

        aCurrentElement = aCurrentElement->getNext();
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

Element * Element::getNext()
{
    return this->theNext;
}

void Element::setNext( Element * aElement )
{
    this->theNext = aElement;
}

Element * Element::getPrevious()
{
    return this->thePrevious;
}

void Element::setPrevious( Element * aElement )
{
    this->thePrevious = aElement;
}

Element * Element::getFather()
{
    return this->theFather;
}

Element * Element::getMother()
{
    return this->theMother;
}

Element::TGender Element::getGender()
{
    return theGender;
}

std::string Element::getBirthDate()
{
    char buffer [11];
    sprintf( buffer, "%04i-%02i-%02i", this->theBirthDate.year, this->theBirthDate.month, this->theBirthDate.day );
    return std::string( buffer );
}

bool Element::setBirthDate( int aYear, int aMonth, int aDay )
{
    if (( aYear>=0 )&&( aYear<10000 )&&( aMonth>0 )&&( aMonth<13 )&&( aDay>0 )&&( aDay<32 ))
    {
        this->theBirthDate.year  = aYear;
        this->theBirthDate.month = aMonth;
        this->theBirthDate.day   = aDay;
        return true;
    }
    else
    {
        return false;
    }

}

std::string Element::getBirthLocation()
{
    return theBirthLocation;
}
