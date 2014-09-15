#include "Element.hpp"

Element::Element(std::string aName, std::string aSurname, TGender aGender, std::string aFatherName,
                 std::string aFatherSurname, std::string aMotherName , std::string aMotherSurname,
                 int aBirthYear, int aBirthMonth, int aBirthDay , std::string aBirthLocation)
                 : theName( aName ), theSurname( aSurname ), theFatherName( aFatherName ),
                 theFatherSurname( aFatherSurname ), theMotherName( aMotherName ),
                 theMotherSurname( aMotherSurname ), theGender( aGender ), theBirthLocation( aBirthLocation )
{
    theBirthDate.year = aBirthYear;
    theBirthDate.month = aBirthMonth;
    theBirthDate.day = aBirthDay;
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

std::string Element::getName()
{
    return theName;
}

std::string Element::getSurname()
{
    return theSurname;
}

std::string Element::getFatherCompleteName()
{
    return ( this->theFatherName + std::string(" ") + this->theFatherSurname );
}

std::string Element::getMotherCompleteName()
{
    return ( this->theMotherName + std::string(" ") + this->theMotherSurname );
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
