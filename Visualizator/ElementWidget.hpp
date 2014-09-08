#ifndef ELEMENTWIDGET_HPP
#define ELEMENTWIDGET_HPP

#include <QWidget>

namespace Ui {
class ElementWidget;
}

class ElementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ElementWidget(QWidget *parent = 0);
    ~ElementWidget();

    void setName(std::string aName);


    void setSelected( bool isSeleted );


    void setFemale( bool isFemale );

    void addParentConnection( ElementWidget * aWidget );

private:
    Ui::ElementWidget *ui;

    QList<ElementWidget*> theParentConnectionList;
};

#endif // ELEMENTWIDGET_HPP
