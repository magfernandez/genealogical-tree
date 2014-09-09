#include "Visualizator.hpp"
#include "ui_Visualizator.h"

Visualizator::Visualizator(ElementList *aElementList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualizator)
{
    ui->setupUi(this);

    drawElementList( aElementList );
}

Visualizator::~Visualizator()
{
    for (int i=0; i<theElements.size(); i++)
    {
        delete theElements.at( i );
    }
    delete ui;
}

void Visualizator::drawElementList( ElementList * aList, int startPositionX, int startPositionY )
{
    Element * aCurrentElement = aList->getFirstElement();
    int positionX = START_X;
    int positionY = START_Y;


    while ( aCurrentElement!=NULL )
    {
        drawSingleElement( aCurrentElement, positionX, positionY );
        aCurrentElement = aCurrentElement->getNext();
        positionX = positionX + OFFSET_X_NONRELATED;
    }

    for (std::map<Element*, ElementWidget*>::iterator it=theWidgetMap.begin();
                 it!=theWidgetMap.end(); ++it)
    {
        for (std::map<Element*, ElementWidget*>::iterator it_int=theWidgetMap.begin();
                     it_int!=theWidgetMap.end(); ++it_int)
        {
            if (it->first->getFather()==it_int->first)
            {
                it->second->move(it_int->second->x()+(it_int->second->getSonNumber()*OFFSET_X), it_int->second->y()+OFFSET_Y);
                it_int->second->increaseSons();
                it_int->second->move( it_int->second->x() + ((it_int->second->getSonNumber()-1)*(OFFSET_X/2)), it_int->second->y() );
            }

            if (it->first->getMother()==it_int->first)
            {
                it->second->move(it_int->second->x()+(it_int->second->getSonNumber()*OFFSET_X), it_int->second->y()+OFFSET_Y);
                it_int->second->increaseSons();
                it_int->second->move( it_int->second->x() + ((it_int->second->getSonNumber()-1)*(OFFSET_X/2)), it_int->second->y() );
            }
        }
    }


}



void Visualizator::drawSingleElement( Element * aElement, int posX, int posY )
{
    ElementWidget * aWidget = new ElementWidget( this );
    theElements.append( aWidget );
    theWidgetMap[ aElement ] = aWidget;
    aWidget->setName( aElement->getCompleteName() );
    aWidget->setBirthDate( aElement->getBirthDate() );
    if ( aElement->getGender()==Element::FEMALE)
        aWidget->setFemale( true );
    else
        aWidget->setFemale( false );
    aWidget->setSelected( false );
    aWidget->move( posX, posY );
}
