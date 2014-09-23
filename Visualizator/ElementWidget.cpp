#include "ElementWidget.hpp"
#include "ui_ElementWidget.h"

ElementWidget::ElementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementWidget)
{
    ui->setupUi(this);
    numberOfSons = 0;
    theElement = NULL;
    ui->theSquareLabel->setVisible( false );
    isMouseClick = false;
}

ElementWidget::ElementWidget( Element* aElement, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElementWidget)
{
    ui->setupUi(this);
    numberOfSons = 0;
    theElement = aElement;
    ui->theSquareLabel->setVisible( false );
}

ElementWidget::~ElementWidget()
{
    delete ui;
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

int ElementWidget::getSonNumber()
{
    return numberOfSons;
}

void ElementWidget::increaseSons()
{
    numberOfSons++;
}

Element * ElementWidget::getPointedElement()
{
    return theElement;
}

void ElementWidget::setPointedElement( Element * aElement )
{
    theElement = aElement;
}

void ElementWidget::updateUi()
{
    if ( theElement!=NULL )
    {
        ui->theName->setText( QString::fromStdString( theElement->getCompleteName() ) );
        ui->theBirthdate->setText( QString::fromStdString( theElement->getBirthDate() ));

        if ( theElement->getGender()==Element::TGender::FEMALE )
            ui->theIcon->setPixmap( QPixmap( ":/ElementWidget/Resources/female.png" ) );
        else
            ui->theIcon->setPixmap( QPixmap( ":/ElementWidget/Resources/male.png" ) );
    }

}

void ElementWidget::mousePressEvent ( QMouseEvent * e )
{
    // Set clicked state as true
    isMouseClick = true;
}

void ElementWidget::mouseReleaseEvent ( QMouseEvent * e )
{
    // Set clicked state as false
    isMouseClick = false;
}

void ElementWidget::mouseMoveEvent ( QMouseEvent * e )
{
    // check if cursor not moved since click beginning
    if (isMouseClick)
    {
        // Emit the signal informing of a mouse movement
        emit onMouseMove( this, e->pos().x(), e->pos().y() );
    }
}
