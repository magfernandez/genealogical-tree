#ifndef __ELEMENTWIDGET_HPP
#define __ELEMENTWIDGET_HPP

#include <QWidget>
#include "Nodes/Element.hpp"
#include <QEvent>
#include <QMouseEvent>

namespace Ui {
class ElementWidget;
}

class ElementWidget : public QWidget
{
    Q_OBJECT

signals:
    /**
     * @brief onMouseMove Signal emitted every time a mouse movement is performed
     * @param aWidget widget that is emitting the event
     * @param deltaX difference with previous position in x axis
     * @param deltaY difference with previous position in y axis
     */
    void onMouseMove( ElementWidget* aWidget, int deltaX, int deltaY );

public:

    explicit ElementWidget(QWidget *parent = 0);

    ~ElementWidget();

    /**
     * @brief ElementWidget Creates a ElementWidget that points to the
     * specified element with a specific QWidget as parent
     * @param aElement Base data element for the widget
     * @param parent Parent widget
     */
    ElementWidget( Element* aElement, QWidget *parent = 0);

    /**
     * @brief setSelected Sets this widget as selected
     * @param isSelected Wheter if this widget has to be marked as selected
     */
    void setSelected( bool isSelected );

    /**
     * @brief getSonNumber Returns the son number for this widget
     * @return Number of sons that have been drawn for this widget
     */
    int getSonNumber();

    /**
     * @brief updateUi Updates Ui with the information from the
     * pointed element
     */
    void updateUi();

    /**
     * @brief getPointedElement Returns the base pointed element
     * @return Pointer to the element this widget refers
     */
    Element * getPointedElement();

    /**
     * @brief setPointedElement Sets the base pointed element
     * @param aElement Pointer to the element this widget will refer
     */
    void setPointedElement( Element * aElement );

    /**
     * @brief increaseSons Increases in one unit the number of
     * drawn sons for this widget
     */
    void increaseSons();

private:

    Ui::ElementWidget *ui; // User interface

    Element * theElement; // Pointed element

    int numberOfSons; // Number of son widgets drawn

protected:

    // member variable - flag of click beginning
    bool isMouseClick;

    // Reimplementation processing of mouse events
    void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );
    void mouseMoveEvent( QMouseEvent * e );
};

#endif // __ELEMENTWIDGET_HPP
