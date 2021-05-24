#ifndef WIDGETRPM_H
#define WIDGETRPM_H

#include <QWidget>
#include <qfi_rpm.h>
#include "LayoutSquare.h"

namespace Ui {
class Widgetrpm;
}

class Widgetrpm : public QWidget
{
    Q_OBJECT

public:
    explicit Widgetrpm(QWidget *parent = nullptr);
    ~Widgetrpm();
    inline void update()
    {
        m_vsi->update();
    }

    inline void setrpm( float rpm )
    {
        m_vsi->setrpm( rpm );
    }

private:
    Ui::Widgetrpm *m_ui;
    qfi_RPM       *m_vsi;
    LayoutSquare  *m_layoutSq;
    void setupUi();
};

#endif // WIDGETRPM_H
