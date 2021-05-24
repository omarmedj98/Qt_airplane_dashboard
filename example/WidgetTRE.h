#ifndef WIDGETTRE_H
#define WIDGETTRE_H

#include <QWidget>
#include <qfi_TRE.h>
#include "LayoutSquare.h"
namespace Ui {
class WidgetTRE;
}

class WidgetTRE : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTRE(QWidget *parent = nullptr);
    ~WidgetTRE();
    inline void update()
    {
        m_tre->update();
    }

    inline void setoilP( float OILP )
    {
        m_tre->setoilP( OILP );
    }

    inline void setoilT( float OILT )
    {
        m_tre->setoilT( OILT );
    }

    inline void setfuelP( float FUELP )
    {
        m_tre->setfuelP( FUELP );
    }

private:
    Ui::WidgetTRE *m_ui;
    qfi_TRE *m_tre;
    LayoutSquare *m_layoutSq;
    void setupUi();
};

#endif // WIDGETTRE_H
