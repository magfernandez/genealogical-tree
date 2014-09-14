#include "ElementList.hpp"

ElementList::ElementList( )
{
    theCompleteNameMap  = std::map<std::string, Element*>();
    theNameMap          = std::unordered_multimap<std::string, Element*>();
    theSurnameMap       = std::unordered_multimap<std::string, Element*>();
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
    theCompleteNameMap[ aNewElement->getCompleteName() ] = aNewElement;
    theBirthDateMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getBirthDate(), aNewElement ));
    theBirthLocationMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getBirthDate(), aNewElement ));
}

std::list<Element*> ElementList::searchByName( std::string aName )
{
    std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theNameMap.equal_range( aName );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        aElementList.insert( itPos, it->second );
        ++itPos;
    }

    return aElementList;
}

std::list<Element*> ElementList::searchBySurname( std::string aSurname )
{
    std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theSurnameMap.equal_range( aSurname );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        aElementList.insert( itPos, it->second );
        ++itPos;
    }

    return aElementList;
}

std::list<Element*> ElementList::searchByBirthDate( int aYear, int aMonth, int aDay )
{
    char buffer [11];
    sprintf( buffer, "%04i-%02i-%02i", aYear, aMonth, aDay );
    std::string aBirthDateString = std::string( buffer );

    std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theBirthDateMap.equal_range( aBirthDateString );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        aElementList.insert( itPos, it->second );
        ++itPos;
    }

    return aElementList;
}

std::list<Element*> ElementList::searchByLocation( std::string aLocation )
{
    std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theBirthLocationMap.equal_range( aLocation );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        aElementList.insert( itPos, it->second );
        ++itPos;
    }

    return aElementList;
}

std::list<Element*> ElementList::searchDescendantsByName( std::string aNameAscendant, std::string aNameDescendant )
{
    std::list<Element*> aElementList = std::list<Element*>();
    std::list<Element*>::iterator itPos = aElementList.begin();

    auto itStr = theNameMap.equal_range( aNameDescendant );
    for ( auto it = itStr.first; it != itStr.second; ++it)
    {
        if ( elementHasAncestorWithName( it->second, aNameAscendant ) )
        {
            // This element has an ancestor with matching name
            // Add it to the list
            aElementList.insert( itPos, it->second );
            ++itPos;
        }
        /*std::string aFatherCompleteName = it->second->getFatherCompleteName();

        if ( theCompleteNameMap.at( aFatherCompleteName )->getName().compare( aNameAscendant )==0 )
        {
            aElementList.insert( itPos, it->second );
            ++itPos;
        }
        else
        {
            // Continue looking
        }*/

    }

    return aElementList;
}




int ElementList::countElements()
{
    return theCompleteNameMap.size();
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


bool ElementList::elementHasAncestorWithName( Element * aElement, std::string anAncestorName )
{
    std::string aFatherCompleteName = aElement->getFatherCompleteName();
    std::map<std::string, Element*>::iterator itToFather = theCompleteNameMap.find( aFatherCompleteName );

    // TODO Include mother also?
    if ( itToFather!=theCompleteNameMap.end() )
    {
        // father element exist
        // Check if it meets the specified ancestor name
        if ( itToFather->second->getName().compare( anAncestorName )==0 )
        {
            // father element meets the specified name
            return true;
        }
        else
        {
            // else return the result of recursively looking for it
            return ( elementHasAncestorWithName( itToFather->second, anAncestorName ));
        }

    }
    else
    {
        // father element does not even exist, so the tree is cut here
        // End the search process
        return false;
    }
}
