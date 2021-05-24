#ifndef WIDGETTEM_H
#define WIDGETTEM_H

#include <QWidget>
#include<qfi_TEM.h>
#include "LayoutSquare.h"
namespace Ui {
class WidgetTEM;
}

class WidgetTEM : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTEM(QWidget *parent = nullptr);
    ~WidgetTEM();
    inline void update()
    {
        m_tem->update();
    }

    inline void setTEM( float TEM )
    {
        m_tem->setTEM( TEM );
    }

private:
    Ui::WidgetTEM *m_ui;
    qfi_TEM *m_tem;
    LayoutSquare *m_layoutSq;
    void setupUi();
};

#endif // WIDGETTEM_H
