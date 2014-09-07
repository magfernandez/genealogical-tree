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
    Element * aCurrentElement = aMember;

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
