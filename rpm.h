#ifndef RPM_H
#define RPM_H

#include <QWidget>

namespace Ui {
class rpm;
}

class rpm : public QWidget
{
    Q_OBJECT

public:
    explicit rpm(QWidget *parent = nullptr);
    ~rpm();

private:
    Ui::rpm *ui;
};

#endif // RPM_H
