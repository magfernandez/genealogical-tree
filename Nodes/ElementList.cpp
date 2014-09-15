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
    theBirthLocationMap.insert( std::unordered_multimap<std::string, Element*>::value_type( aNewElement->getBirthLocation(), aNewElement ));
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
    }

    return aElementList;
}

int ElementList::countElements()
{
    return theCompleteNameMap.size();
}

void ElementList::deleteAllElements()
{
    for ( std::map<std::string,Element*>::iterator it=theCompleteNameMap.begin();
          it != theCompleteNameMap.end(); ++it )
    {
        delete( it->second );
    }
    theCompleteNameMap.clear();
    // All elements pointed inside the rest of the maps are contained -and already
    // deleted- in theCompleteNameMap
    theNameMap.clear();
    theSurnameMap.clear();
    theBirthDateMap.clear();
    theBirthLocationMap.clear();
}

bool ElementList::elementHasAncestorWithName( Element * aElement, std::string anAncestorName )
{
    std::string aFatherCompleteName = aElement->getFatherCompleteName();
    std::string aMotherCompleteName = aElement->getMotherCompleteName();
    std::map<std::string, Element*>::iterator itToFather = theCompleteNameMap.find( aFatherCompleteName );
    std::map<std::string, Element*>::iterator itToMother = theCompleteNameMap.find( aMotherCompleteName );

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
    else if ( itToMother!=theCompleteNameMap.end() )
    {
        // mother element exist
        // Check if it meets the specified ancestor name
        if ( itToMother->second->getName().compare( anAncestorName )==0 )
        {
            // mother element meets the specified name
            return true;
        }
        else
        {
            // else return the result of recursively looking for it
            return ( elementHasAncestorWithName( itToMother->second, anAncestorName ));
        }
    }
    else
    {
        // father element does not even exist, so the tree is cut here
        // End the search process
        return false;
    }
}

Element* ElementList::getFatherElement( Element* aElement )
{
    std::map<std::string, Element*>::iterator it = theCompleteNameMap.find( aElement->getFatherCompleteName() );

    if ( it!=theCompleteNameMap.end() )
    {
        return it->second;
    }
    else
    {
        return NULL;
    }
}

Element* ElementList::getMotherElement( Element* aElement )
{
    std::map<std::string, Element*>::iterator it = theCompleteNameMap.find( aElement->getMotherCompleteName() );

    if ( it!=theCompleteNameMap.end() )
    {
        return it->second;
    }
    else
    {
        return NULL;
    }
}

std::list<Element*> ElementList::getList()
{
    std::list<Element*> aList = std::list<Element*>();
    std::list<Element*>::iterator aListIterator = aList.begin();

    for ( std::map<std::string, Element*>::iterator it = theCompleteNameMap.begin();
          it != theCompleteNameMap.end(); ++it )
    {
        aList.insert( aListIterator, it->second );
        ++aListIterator;
    }

    return aList;
}
