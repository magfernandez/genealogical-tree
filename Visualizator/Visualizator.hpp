#ifndef __VISUALIZATOR_HPP
#define __VISUALIZATOR_HPP

#include <QMainWindow>
#include "Nodes/ElementList.hpp"
#include "Visualizator/ElementWidget.hpp"
#include <QPainter>

namespace Ui {
class Visualizator;
}

class Visualizator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visualizator( ElementList * aElementList, QWidget *parent = 0);
    ~Visualizator();

private:

    QList<ElementWidget*> theElements; // ElementWidgets created in the Ui
    std::map< Element*, ElementWidget*> theWidgetMap; // Relationship between a Element and its widget

    Ui::Visualizator *ui; // User interface

    /**
     * @brief drawElementList Draws icons on visualizator window starting
     * from the specified position
     * @param aList List to be drawn
     * @param startPositionX initial x position (pixels)
     * @param startPositionY initial y position (pixels)
     */
    void drawElementList( ElementList * aList, int startPositionX = 0, int startPositionY = 0 );

    /**
     * @brief drawSingleElement Draws a single element and adds it
     * to the widget list and map
     * @param aElement Element to be drawn
     * @param posX x position where the widget will be drawn
     * @param posY y position where the widget will be drawn
     */
    void drawSingleElement( Element * aElement, int posX, int posY );
};

#endif // __VISUALIZATOR_HPP
