#ifndef QFI_TRE_H
#define QFI_TRE_H
#include <QGraphicsView>
#include <QGraphicsSvgItem>

class qfi_TRE:public QGraphicsView
{
       Q_OBJECT
public:
    qfi_TRE(QWidget *parent=0);



    virtual ~qfi_TRE();


    void reinit();
    void update();
    void setoilP(float OILP);
    void setoilT(float OILT);
    void setfuelP(float FUELP);
protected:
    void resizeEvent(QResizeEvent *event);
private:

    QGraphicsScene *m_scene;
    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemHand2;
    QGraphicsSvgItem *m_itemHand3;

    QGraphicsSvgItem *m_itemCase;


    float m_OILP;
    float m_OILT;
        float m_FUELP;

    float m_scaleX;
    float m_scaleY;
    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalTRECtr;
    QPointF  m_originalTRECtr1 ;
    QPointF  m_originalTRECtr2;
    const int m_faceZ;
    const int m_handZ;
    const int m_caseZ;
    const int m_hand2Z;
    const int m_hand3Z;
    void init();

    void reset();

    void updateView();





};

#endif // QFI_TRE_H
