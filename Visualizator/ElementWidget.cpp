#include "ElementWidget.hpp"
#include "ui_ElementWidget.h"

ElementWidget::ElementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementWidget)
{
    ui->setupUi(this);
}

ElementWidget::~ElementWidget()
{
    delete ui;
}

void ElementWidget::setName( std::string aName )
{
    ui->theName->setText( QString::fromStdString( aName ) );
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
