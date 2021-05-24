#ifndef QFI_MP_H
#define QFI_MP_H

#include <QGraphicsView>
#include <QGraphicsSvgItem>

class qfi_MP: public QGraphicsView
{
    Q_OBJECT

public:
    qfi_MP(QWidget *parent=0);

    virtual ~qfi_MP();


    void reinit();
    void update();
    void setManifoldPressure(float manifoldpressure);

protected:
    void resizeEvent(QResizeEvent *event);
private:

    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;


    float m_manifoldpressure;


    float m_scaleX;
    float m_scaleY;
    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalMPCtr;

    const int m_faceZ;
    const int m_handZ;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();



};

#endif // QFI_MP_H
