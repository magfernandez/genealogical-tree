#ifndef __VISUALIZATOR_HPP
#define __VISUALIZATOR_HPP

#include <QMainWindow>
#include "Nodes/ElementList.hpp"
#include "Visualizator/ElementWidget.hpp"
#include <QPainter>

#define START_X  100
#define START_Y   25
#define OFFSET_X_NONRELATED 200
#define OFFSET_X 150
#define OFFSET_Y 110


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
     */
    void drawElementList(ElementList * aList);

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
