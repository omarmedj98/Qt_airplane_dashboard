#ifndef QFI_RPM_CPP
#define QFI_RPM_CPP
#endif

////////////////////////////////////////////////////////////////////////////////

#ifdef WIN32
#   include <float.h>
#endif

#include <math.h>
#include "qfi_rpm.h"

qfi_RPM::qfi_RPM( QWidget *parent ) :
    QGraphicsView ( parent ),

    m_scene ( 0 ),

    m_itemFace ( 0 ),
    m_itemHand ( 0 ),
    m_itemCase ( 0 ),

    m_rpm ( 0.0f ),

    m_scaleX ( 1.0f ),
    m_scaleY ( 1.0f ),


    m_originalHeight ( 240 ),
    m_originalWidth  ( 240 ),

    m_originalVsiCtr ( 120.0f , 120.0f ),

    m_faceZ ( -20 ),
    m_handZ ( -10 ),
    m_caseZ (  10 )
{
    reset();

    m_scene = new QGraphicsScene( this );
    setScene( m_scene );

    m_scene->clear();

    init();
}

////////////////////////////////////////////////////////////////////////////////

qfi_RPM::~qfi_RPM()
{
    if ( m_scene )
    {
        m_scene->clear();
        delete m_scene;
        m_scene = 0;
    }

    reset();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::setrpm( float rpm )
{
    m_rpm = rpm;

    if ( m_rpm < -2000.0f ) m_rpm = -2000.0f;
    if ( m_rpm >  2000.0f ) m_rpm =  2000.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();
//192px*192px
    m_itemFace = new QGraphicsSvgItem( ":/qfi/images/rpm/face.svg" );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemFace );

    m_itemHand = new QGraphicsSvgItem( ":/qfi/images/gyro/hand.svg" );
    m_itemHand->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand->setZValue( m_handZ );
    m_itemHand->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand->setTransformOriginPoint( m_originalVsiCtr );
    m_scene->addItem( m_itemHand );

    m_itemCase = new QGraphicsSvgItem( ":/qfi/images/vsi/vsi_case.svg" );
    m_itemCase->setCacheMode( QGraphicsItem::NoCache );
    m_itemCase->setZValue( m_caseZ );
    m_itemCase->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemCase );

    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::reset()
{
    m_itemFace = 0;
    m_itemHand = 0;
    m_itemCase = 0;

    m_rpm= 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_RPM::updateView()
{
    m_itemHand->setRotation( m_rpm * 0.13f );

    m_scene->update();
}
