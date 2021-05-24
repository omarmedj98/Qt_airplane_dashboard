#ifndef QFI_RPM_H
#define QFI_RPM_H

////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>



////////////////////////////////////////////////////////////////////////////////

/** Vertical Speed Indicator widget. */
class qfi_RPM : public QGraphicsView
{
    Q_OBJECT

public:

    /** Constructor. */
    qfi_RPM( QWidget *parent = 0 );

    /** Destructor. */
    virtual ~qfi_RPM();

    /** Reinitiates widget. */
    void reinit();

    /** Refreshes (redraws) widget. */
    void update();

    /** @param climb rate [ft/min] */
    void setrpm( float rpm );

protected:

    void resizeEvent( QResizeEvent *event );

private:

    QGraphicsScene *m_scene;

    QGraphicsSvgItem *m_itemFace;
    QGraphicsSvgItem *m_itemHand;
    QGraphicsSvgItem *m_itemCase;

    float m_rpm;

    float m_scaleX;
    float m_scaleY;

    const int m_originalHeight;
    const int m_originalWidth;

    QPointF m_originalVsiCtr;

    const int m_faceZ;
    const int m_handZ;
    const int m_caseZ;

    void init();

    void reset();

    void updateView();
};

////////////////////////////////////////////////////////////////////////////////

#endif // QFI_rpm_H
