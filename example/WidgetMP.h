#ifndef WIDGETMP_H
#define WIDGETMP_H

#include <QWidget>
#include<qfi_MP.h>
#include "LayoutSquare.h"
namespace Ui {
class WidgetMP;
}

class WidgetMP : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetMP(QWidget *parent = nullptr);
    ~WidgetMP();
    inline void update()
    {
        m_mp->update();
    }

    inline void setManifoldPressure( float manifoldpressure )
    {
        m_mp->setManifoldPressure( manifoldpressure );
    }

private:
    Ui::WidgetMP *m_ui;
    qfi_MP *m_mp;
    LayoutSquare *m_layoutSq;
    void setupUi();
};

#endif // WIDGETMP_H
