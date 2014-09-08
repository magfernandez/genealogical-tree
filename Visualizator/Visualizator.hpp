#ifndef VISUALIZATOR_HPP
#define VISUALIZATOR_HPP

#include <QMainWindow>

namespace Ui {
class Visualizator;
}

class Visualizator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Visualizator(QWidget *parent = 0);
    ~Visualizator();

private:
    Ui::Visualizator *ui;
};

#endif // VISUALIZATOR_HPP
