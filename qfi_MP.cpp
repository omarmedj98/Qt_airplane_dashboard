#include "qfi_MP.h"

qfi_MP::qfi_MP(QWidget *parent):
    QGraphicsView(parent),

  m_scene ( 0 ),

  m_itemFace ( 0 ),
  m_itemHand ( 0 ),
  m_itemCase ( 0 ),

  m_manifoldpressure ( 0.0f ),

  m_scaleX ( 1.0f ),
  m_scaleY ( 1.0f ),


  m_originalHeight ( 240 ),
  m_originalWidth  ( 240 ),

  m_originalMPCtr ( 120.0f ,120.0f ),

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
/////////////////////////////////////////
qfi_MP::~qfi_MP()
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

void qfi_MP::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_MP::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_MP::setManifoldPressure(float manifoldpressure)
{
    m_manifoldpressure = manifoldpressure;

    if ( m_manifoldpressure < -2000.0f ) m_manifoldpressure = -2000.0f;
    if ( m_manifoldpressure >  2000.0f ) m_manifoldpressure =  2000.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_MP::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_MP::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();
//192px*192px
    m_itemFace = new QGraphicsSvgItem( ":/qfi/images/MP/face.svg" );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemFace );

    m_itemHand = new QGraphicsSvgItem( ":/qfi/images/vsi/vsi_hand.svg" );
    m_itemHand->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand->setZValue( m_handZ );
    m_itemHand->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand->setTransformOriginPoint( m_originalMPCtr );
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

void qfi_MP::reset()
{
    m_itemFace = 0;
    m_itemHand = 0;
    m_itemCase = 0;

    m_manifoldpressure = 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_MP::updateView()
{
    m_itemHand->setRotation( m_manifoldpressure * 0.13f );

    m_scene->update();
}
