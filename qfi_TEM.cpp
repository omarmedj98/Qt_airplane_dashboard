#include "qfi_TEM.h"

qfi_TEM::qfi_TEM(QWidget *parent):
    QGraphicsView(parent),

  m_scene ( 0 ),

  m_itemFace ( 0 ),
  m_itemHand ( 0 ),
  m_itemCase ( 0 ),

  m_TEM ( 0.0f ),

  m_scaleX ( 1.0f ),
  m_scaleY ( 1.0f ),


  m_originalHeight ( 240 ),
  m_originalWidth  ( 240 ),

  m_originalTEMCtr (120.0f ,120.0f ),

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
qfi_TEM::~qfi_TEM()
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

void qfi_TEM::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TEM::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TEM::setTEM(float TEM)
{
    m_TEM = TEM;

    if ( m_TEM < -2000.0f ) m_TEM = -2000.0f;
    if ( m_TEM >  2000.0f ) m_TEM =  2000.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TEM::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TEM::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;

    reset();
//192px*192px
    m_itemFace = new QGraphicsSvgItem( ":/qfi/images/tem/face.svg" );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemFace );

    m_itemHand = new QGraphicsSvgItem( ":/qfi/images/tem/tem_hand1.svg" );
    m_itemHand->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand->setZValue( m_handZ );
    m_itemHand->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand->setTransformOriginPoint( m_originalTEMCtr );
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

void qfi_TEM::reset()
{
    m_itemFace = 0;
    m_itemHand = 0;
    m_itemCase = 0;

    m_TEM = 0.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TEM::updateView()
{
    m_itemHand->setRotation( m_TEM * 0.13f );

    m_scene->update();
}
