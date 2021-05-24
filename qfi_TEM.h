#ifndef QFI_TEM_H
#define QFI_TEM_H

#include <QGraphicsView>
#include <QGraphicsSvgItem>
class qfi_TEM: public QGraphicsView
{
    Q_OBJECT
public:
    qfi_TEM(QWidget *parent=0);


    virtual ~qfi_TEM();


    void reinit();
    void update();
    void setTEM(float TEM);

protected:
    void resizeEvent(QResizeEvent *event);
private:

    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;


    float m_TEM;


    float m_scaleX;
    float m_scaleY;
    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalTEMCtr;

    const int m_faceZ;
    const int m_handZ;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();










};

#endif // QFI_TEM_H
