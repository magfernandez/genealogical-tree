#include "ElementList.hpp"

ElementList::ElementList( )
{
    theNameMap          = std::unordered_multimap<std::string, Element*>();
    theSurnameMap       = std::unordered_multimap<std::string, Element*>();
    theCompleteNameMap  = std::unordered_multimap<std::string, Element*>();
    theBirthDateMap     = std::unordered_multimap<std::string, Element*>();
    theBirthLocationMap = std::unordered_multimap<std::string, Element*>();
}

void ElementList::addElement( std::string aName, std::string aSurname, Element::TGender aGender,
                              std::string aFatherName, std::string aFatherSurname,
                              std::string aMotherName, std::string aMotherSurname, int aBirthYear,
                              int aBirthMonth, int aBirthDay, std::string aBirthLocation )
{
    Element * aNewElement = new Element( aName, aSurname, aGender, aFatherName, aFatherSurname,
                                         aMotherName, aMotherSurname, aBirthYear, aBirthMonth, aBirthDay, aBirthLocation );

    theNameMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aName, aNewElement ));
    theSurnameMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aSurname, aNewElement ));
    theCompleteNameMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getCompleteName(), aNewElement ));
    theBirthDateMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getBirthDate(), aNewElement ));
    theBirthLocationMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getBirthDate(), aNewElement ));
}

std::list<Element*> ElementList::searchByName( std::string aName )
{
    /*std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theCompleteNameMap.equal_range( aName );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        aElementList.insert( itPos, it->second );
        ++itPos;
    }

    return aElementList;*/
}

std::list<Element*> ElementList::searchBySurname( std::string aSurname )
{
    /*std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator it = aElementList.begin();

    Element * aCurrent = theFirst;

    while( aCurrent!=NULL )
    {
        if ( aCurrent->getSurname().compare( aSurname )==0)
        {
            // add to list
            aElementList.insert( it, aCurrent );
            ++it;
        }
        aCurrent=aCurrent->getNext();
    }

    return aElementList;*/
}

std::list<Element*> ElementList::searchByBirthDate( int aYear, int aMonth, int aDay )
{
    /*std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator it = aElementList.begin();

    Element * aCurrent = theFirst;
    char buffer [11];
    sprintf( buffer, "%04i-%02i-%02i", aYear, aMonth, aDay );
    std::string aBirthDateString = std::string( buffer );

    while( aCurrent!=NULL )
    {
        if ( aCurrent->getBirthDate().compare( aBirthDateString )==0)
        {
            // add to list
            aElementList.insert( it, aCurrent );
            ++it;
        }
        aCurrent=aCurrent->getNext();
    }
    return aElementList;*/
}

std::list<Element*> ElementList::searchByLocation( std::string aLocation )
{
    /*std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator it = aElementList.begin();

    Element * aCurrent = theFirst;

    while( aCurrent!=NULL )
    {
        if ( aCurrent->getBirthLocation().compare( aLocation )==0)
        {
            // add to list
            aElementList.insert( it, aCurrent );
            ++it;
        }
        aCurrent=aCurrent->getNext();
    }

    return aElementList;*/
}

std::list<Element*> ElementList::searchDescendantsByName( std::string aNameAscendant, std::string aNameDescendant )
{
    /*std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator it = aElementList.begin();

    Element * aCurrent = theFirst;
    Element * aFirstToLook = NULL;

    while( aCurrent!=NULL )
    {
        if ( aCurrent->getName().compare( aNameAscendant )==0 )
        {
            aFirstToLook = aCurrent;
            aCurrent = NULL;
        }
        else
        {
            aCurrent = aCurrent->getNext();
        }
    }

    if ( aFirstToLook==NULL )
    {
        return std::list<Element*>();
    }
    else
    {
        aCurrent = aFirstToLook;

        while( aCurrent!=NULL )
        {
            if ( aCurrent->getName().compare( aNameDescendant )==0)
            {
                // add to list
                aElementList.insert( it, aCurrent );
                ++it;
            }
            aCurrent=aCurrent->getNext();
        }
    }

    return aElementList;*/
}




int ElementList::countElements()
{
    return theCompleteNameMap.size();
}

int ElementList::assignRelationships()
{
    /*int aRelationshipsNr = 0;
    Element * aCurrent = theFirst;

    while ( aCurrent!=NULL )
    {
        aCurrent->assignRelationship( theFirst );
        std::cout << "=======================\n"
                  << "NAME: " << aCurrent->getCompleteName() << "\n";
        if ( aCurrent->getFather()!=NULL )
        {
            std::cout << "FATHER: " << aCurrent->getFather()->getCompleteName() << "\n";
            aRelationshipsNr++;
        }
        if ( aCurrent->getMother()!=NULL )
        {
            std::cout << "MOTHER: " << aCurrent->getMother()->getCompleteName() << "\n";
            aRelationshipsNr++;
        }
        aCurrent = aCurrent->getNext();
    }

    std::cout << "\nRelationship: " << aRelationshipsNr << " relations found in list\n";

    return aRelationshipsNr;*/
}

Element * ElementList::getFirstElement()
{
    /*return this->theFirst;*/
}

void ElementList::deleteAllElements()
{
    /*Element * aCurrent = this->theFirst;
    Element * aCurrentToDelete = this->theFirst;

    while ( aCurrent!=NULL )
    {
        aCurrentToDelete = aCurrent;
        aCurrent = aCurrent->getNext();
        delete aCurrentToDelete;
    }

    theFirst = NULL;
    theLast = NULL;*/
}
