#include "ElementWidget.hpp"
#include "ui_ElementWidget.h"

ElementWidget::ElementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementWidget)
{
    ui->setupUi(this);
    numberOfSons = 0;
}

ElementWidget::~ElementWidget()
{
    delete ui;
}

void ElementWidget::setName( std::string aName )
{
    ui->theName->setText( QString::fromStdString( aName ) );
}

void ElementWidget::setBirthDate( std::string aBirthDate )
{
    ui->theBirthdate->setText( QString::fromStdString( aBirthDate ));
}

void ElementWidget::setSelected( bool isSelected )
{
     if (isSelected)
     {
         ui->theSquareLabel->setPixmap( QPixmap( ":/ElementWidget/Resources/squareRed.png" ) );
     }
     else
     {
         ui->theSquareLabel->setPixmap( QPixmap( ":/ElementWidget/Resources/square.png" ) );
     }
}

void ElementWidget::addParentConnection( ElementWidget * aWidget )
{
    theParentConnectionList.append( aWidget );
}

void ElementWidget::setFemale( bool isFemale )
{
    if (isFemale)
    {
        ui->theIcon->setPixmap( QPixmap( ":/ElementWidget/Resources/female.png" ) );
    }
    else
    {
        ui->theIcon->setPixmap( QPixmap( ":/ElementWidget/Resources/male.png" ) );
    }
}

int ElementWidget::getSonNumber()
{
    return numberOfSons;
}

void ElementWidget::increaseSons()
{
    numberOfSons++;
}
