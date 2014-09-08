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
    int positionX = 0;
    int positionY = 0;


    while ( aCurrentElement!=NULL )
    {
        drawSingleElement( aCurrentElement, positionX, positionY );
        aCurrentElement = aCurrentElement->getNext();
        positionX = positionX + 50;
        positionY = positionY + 50;
    }
}



void Visualizator::drawSingleElement( Element * aElement, int posX, int posY )
{
    ElementWidget * aWidget = new ElementWidget( this );
    theElements.append( aWidget );
    theWidgetMap[ aElement ] = aWidget;
    aWidget->setName( aElement->getCompleteName() );
    if ( aElement->getGender()==Element::FEMALE)
        aWidget->setFemale( true );
    else
        aWidget->setFemale( false );
    aWidget->setSelected( false );
    aWidget->move( posX, posY );
}
