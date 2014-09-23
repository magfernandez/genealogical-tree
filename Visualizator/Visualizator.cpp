#include "Visualizator.hpp"
#include "ui_Visualizator.h"

Visualizator::Visualizator(ElementList *aElementList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Visualizator)
{
    ui->setupUi(this);

    theScene = new QGraphicsScene( QRectF( 2, 2, this->width()-4, this->height()-4 ), this );
    ui->theCanvas->setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
    ui->theCanvas->setScene( theScene );
    ui->theCanvas->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->theCanvas->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    ui->theCanvas->setDragMode( QGraphicsView::NoDrag );
    ui->theCanvas->setInteractive( false );
    theDrawnWidgetMap = std::map<std::string, ElementWidget*>();

    drawElementList( aElementList );
}

Visualizator::~Visualizator()
{
    delete theScene;
    delete ui;
}

void Visualizator::drawElementList( ElementList * aList )
{
    // Get std::list with all members of the list
    std::list<Element*> aElementList = aList->getList();

    // Create and fill a map with the complete name as master key
    std::map<std::string, ElementWidget*> aWidgetMap = std::map<std::string, ElementWidget*>();

    for ( std::list<Element*>::iterator it = aElementList.begin(); it != aElementList.end(); ++it)
    {
        ElementWidget * aWidget = new ElementWidget( *it , this);
        aWidgetMap[ (*it)->getCompleteName() ] = aWidget;
        QObject::connect( aWidget, SIGNAL(onMouseMove(ElementWidget*,int,int)),
                          this, SLOT(onWidgetMove(ElementWidget*,int,int)));
    }

    QList<ElementWidget*> aListWithParent = QList<ElementWidget*>();
    QList<ElementWidget*> aListWoParent   = QList<ElementWidget*>();

    for ( std::map<std::string, ElementWidget*>::iterator itMap = aWidgetMap.begin(); itMap != aWidgetMap.end(); ++itMap )
    {
        if ( aWidgetMap.find( itMap->second->getPointedElement()->getFatherCompleteName() ) != aWidgetMap.end() )
        {
            // father element is registered
            aListWithParent.append( itMap->second );
        }
        else if ( aWidgetMap.find( itMap->second->getPointedElement()->getMotherCompleteName() ) != aWidgetMap.end() )
        {
            // father element does not exist but mother element is registered
            aListWithParent.append( itMap->second );
        }
        else
        {
            // nor father or mother element do exist
            aListWoParent.append( itMap->second );
        }
    }

    // Calculate separation between "header" elements
    int horizontalSlot = this->width()/( aListWoParent.size()+1 );

    int currentX = horizontalSlot;
    int currentY = START_Y;



    // Draw "header" elements
    for ( int i=0; i<aListWoParent.size(); i++ )
    {
        aListWoParent.at(i)->move( currentX, currentY );
        aListWoParent.at(i)->updateUi();
        currentX = currentX + horizontalSlot;
        theDrawnWidgetMap[ aListWoParent.at( i )->getPointedElement()->getCompleteName() ] = aListWoParent.at( i );
    }

    // Iterate until all the rest of the elements are drawn
    while( aListWithParent.size() > 0 )
    {
        for ( int i=0; i<aListWithParent.size(); i++ )
        {
            if (( theDrawnWidgetMap.find( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName() )!=theDrawnWidgetMap.end() )&&
                ( theDrawnWidgetMap.find( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName() )!=theDrawnWidgetMap.end() ))
            {
                /// Father & Mother elements are already drawn
                /// Move mother close to father element
                /// Reposition and update myself and parents, increase father and mother son number

                // Move father
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->x() + ( OFFSET_REDUCED_PERC * OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->getSonNumber() ) ,
                                                                                                           ((aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->y() + aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->y())/2));
                // Move mother close to father
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->x() + aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->width(),
                                                                                                           aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->y());
                // Move myself
                aListWithParent.at( i )->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->x() + ( OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->getSonNumber() ) ,
                                               aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->y() + OFFSET_Y );

                // Increase number of sons for both parent elements
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->increaseSons();
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->increaseSons();
                // Add current element to the map of already drawn widgets
                theDrawnWidgetMap[ aListWithParent.at(i)->getPointedElement()->getCompleteName() ] = aListWithParent.at(i);
                // Update element Ui
                aListWithParent.at( i )->updateUi();
                // Remove current element from the list of elements with parents
                aListWithParent.removeAt( i );
            }
            else if( theDrawnWidgetMap.find( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName() )!=theDrawnWidgetMap.end() )
            {
                /// Father element is already drawn
                /// Reposition and update myself and father, increase father son number

                // Move myself
                aListWithParent.at( i )->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->x() + ( OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->getSonNumber() ) ,
                                               aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->y() + OFFSET_Y );
                // Move father
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->x() + ( OFFSET_REDUCED_PERC * OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->getSonNumber() ) ,
                                                                                                           aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->y());
                // Increase number of sons for father
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getFatherCompleteName())->increaseSons();
                // Add current element to te map of already drawn widgets
                theDrawnWidgetMap[ aListWithParent.at(i)->getPointedElement()->getCompleteName() ] = aListWithParent.at(i);
                // Update element Ui
                aListWithParent.at( i )->updateUi();
                // Remove current element from the list of elements with parents
                aListWithParent.removeAt( i );
            }
            else if( theDrawnWidgetMap.find( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName() )!=theDrawnWidgetMap.end() )
            {
                /// mother element is already drawn
                /// Reposition and update myself, increase mother son number

                // Move myself
                aListWithParent.at( i )->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->x() + ( OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->getSonNumber() ) ,
                                               aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->y() + OFFSET_Y );
                // Move mother
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->move( aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->x() + ( OFFSET_REDUCED_PERC * OFFSET_X  * aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->getSonNumber() ) ,
                                                                                                           aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->y());
                // Increase number of sons of mother
                aWidgetMap.at( aListWithParent.at(i)->getPointedElement()->getMotherCompleteName())->increaseSons();
                // Add current element to the map of already drawn widgets
                theDrawnWidgetMap[ aListWithParent.at(i)->getPointedElement()->getCompleteName() ] = aListWithParent.at(i);
                // Update element Ui
                aListWithParent.at( i )->updateUi();
                // Remove current element from the list of elements with parents
                aListWithParent.removeAt( i );
            }
            else
            {
                // No parent drawn
                // Do not delete from list nor add ir to drawn elements map

                // DO NOTHING
            }
        }
    }
    drawElementConnections( theDrawnWidgetMap );
}

void Visualizator::drawElementConnections( std::map<std::string, ElementWidget*> aMap )
{
    for ( std::map<std::string, ElementWidget*>::iterator it = aMap.begin();
          it!=aMap.end(); it++ )
    {
        if (( aMap.find( it->second->getPointedElement()->getFatherCompleteName() )!=aMap.end() )&&
            ( aMap.find( it->second->getPointedElement()->getMotherCompleteName() )!=aMap.end() ) )
        {
            // Both parents found
            theScene->addLine( it->second->x() + (it->second->width()/2), it->second->y() + (it->second->height()/2),
                               aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->y() + (it->second->height()/2),
                               QPen( Qt::gray, 4 ) );
            theScene->addLine( it->second->x() + (it->second->width()/2), it->second->y() + (it->second->height()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->y() + (it->second->height()/2),
                               QPen( Qt::gray, 4 ) );
            theScene->addLine( aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->y() + (it->second->height()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->y() + (it->second->height()/2),
                               QPen( Qt::red, 4 ) );
        }
        else if ( aMap.find( it->second->getPointedElement()->getFatherCompleteName() )!=aMap.end() )
        {
            // Father found
            theScene->addLine( it->second->x() + (it->second->width()/2), it->second->y() + (it->second->height()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getFatherCompleteName() )->second->y() + (it->second->height()/2),
                               QPen( Qt::gray, 4 ) );
        }
        else if ( aMap.find( it->second->getPointedElement()->getMotherCompleteName() )!=aMap.end() )
        {
            // Mother found
            theScene->addLine( it->second->x() + (it->second->width()/2), it->second->y() + (it->second->height()/2),
                               aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->x() + (it->second->width()/2),
                               aMap.find( it->second->getPointedElement()->getMotherCompleteName() )->second->y() + (it->second->height()/2),
                               QPen( Qt::gray, 4 ) );
        }
    }
}


void Visualizator::onWidgetMove( ElementWidget* aWidget, int deltaX, int deltaY )
{
    aWidget->move( aWidget->pos().x() + deltaX - (aWidget->width()/2), aWidget->pos().y() + deltaY - (aWidget->height()/2));
    theScene->clear();
    drawElementConnections( theDrawnWidgetMap );
}
