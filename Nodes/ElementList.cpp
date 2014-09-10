#include "ElementList.hpp"

ElementList::ElementList( )
{
    theFirst = NULL;
    theLast = NULL;
}

ElementList::ElementList( Element *aStartElement )
{
    if ( aStartElement!=NULL )
    {
        // set first element
        theFirst = aStartElement;

        // Iterate over the list from the start until
        // finding the last element
        Element * aCurrentElement = aStartElement;
        while( aCurrentElement != NULL)
        {
            theLast = aCurrentElement;
            aCurrentElement = aCurrentElement->getNext();
        }
    }
    else
    {
        // null list
        theFirst = NULL;
        theLast = NULL;
    }

}

std::list<Element*> ElementList::searchDescendantsByName( std::string aNameAscendant, std::string aNameDescendant )
{
    std::list<Element*> aElementList = std::list<Element*>();
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

    return aElementList;
}


void ElementList::addElement( std::string aName, std::string aSurname, Element::TGender aGender,
                              std::string aFatherName, std::string aFatherSurname,
                              std::string aMotherName, std::string aMotherSurname, int aBirthYear,
                              int aBirthMonth, int aBirthDay, std::string aBirthLocation )
{
    Element * aNewElement = new Element( aName, aSurname, aGender, aFatherName, aFatherSurname,
                                         aMotherName, aMotherSurname, aBirthYear, aBirthMonth, aBirthDay, aBirthLocation );
    if ( theFirst==NULL)
    {
        theFirst = aNewElement;
    }
    aNewElement->setPrevious( theLast );
    if ( theLast!=NULL )
    {
        theLast->setNext( aNewElement );
    }
    aNewElement->setNext( NULL );
    theLast = aNewElement;
}

int ElementList::countElements()
{
    int aElementNumber = 0;

    Element * aCurrent = theFirst;

    while( aCurrent!=NULL )
    {
        aCurrent = aCurrent->getNext();
        aElementNumber++;
    }

    return aElementNumber;
}

int ElementList::assignRelationships()
{
    int aRelationshipsNr = 0;
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

    return aRelationshipsNr;
}

Element * ElementList::getFirstElement()
{
    return this->theFirst;
}

void ElementList::deleteAllElements()
{
    Element * aCurrent = this->theFirst;
    Element * aCurrentToDelete = this->theFirst;

    while ( aCurrent!=NULL )
    {
        aCurrentToDelete = aCurrent;
        aCurrent = aCurrent->getNext();
        delete aCurrentToDelete;
    }

    theFirst = NULL;
    theLast = NULL;
}
