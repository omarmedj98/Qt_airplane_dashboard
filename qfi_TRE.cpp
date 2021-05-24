#include "qfi_TRE.h"

qfi_TRE::qfi_TRE(QWidget *parent):
    QGraphicsView(parent),
    m_scene ( 0 ),

    m_itemFace ( 0 ),
    m_itemHand ( 0 ),
    m_itemCase ( 0 ),
    m_itemHand2(0),
    m_itemHand3(0),
    m_OILP ( 0.0f ),
    m_OILT(0.0f),
    m_FUELP(0.0f),
    m_scaleX ( 1.0f ),
    m_scaleY ( 1.0f ),


    m_originalHeight ( 240 ),
    m_originalWidth  ( 240 ),

    m_originalTRECtr ( 103.1732f ,90.8463f ),
   m_originalTRECtr1 ( 173.9789f ,156.1511f ),
   m_originalTRECtr2 (44.4932f ,156.1511f ),
    m_faceZ ( -20 ),
    m_handZ ( -10 ),
    m_caseZ (  10 ),
    m_hand2Z(-10),
    m_hand3Z(-10)
{
    reset();

    m_scene = new QGraphicsScene( this );
    setScene( m_scene );

    m_scene->clear();

    init();
}
qfi_TRE::~qfi_TRE()
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

void qfi_TRE::reinit()
{
    if ( m_scene )
    {
        m_scene->clear();

        init();
    }
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::update()
{
    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::setoilP(float OILP)
{
    m_OILP= OILP;

    if (   m_OILP < -2000.0f )    m_OILP = -2000.0f;
    if (   m_OILP >  2000.0f )   m_OILP =  2000.0f;
}
////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::setoilT(float OILT)
{
    m_OILT= OILT;

    if (   m_OILT < -2000.0f )    m_OILT = -2000.0f;
    if (   m_OILT >  2000.0f )   m_OILT =  2000.0f;
}
////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::setfuelP(float FUELP)
{
    m_FUELP= FUELP;

    if (   m_FUELP < -2000.0f )    m_FUELP = -2000.0f;
    if (   m_FUELP >  2000.0f )   m_FUELP =  2000.0f;
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::resizeEvent( QResizeEvent *event )
{
    ////////////////////////////////////
    QGraphicsView::resizeEvent( event );
    ////////////////////////////////////

    reinit();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::init()
{
    m_scaleX = (float)width()  / (float)m_originalWidth;
    m_scaleY = (float)height() / (float)m_originalHeight;
    printf("x%f\n",m_scaleX);
    printf("y=%f\n",m_scaleY);
    reset();
//192px*192px
    m_itemFace = new QGraphicsSvgItem( ":/qfi/images/tre/face1.svg" );
    m_itemFace->setCacheMode( QGraphicsItem::NoCache );
    m_itemFace->setZValue( m_faceZ );
    m_itemFace->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemFace );

    m_itemHand = new QGraphicsSvgItem( ":/qfi/images/tre/tre_hand_1.svg" );
    m_itemHand->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand->setZValue( m_handZ );
    m_itemHand->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_itemHand->setTransformOriginPoint( m_originalTRECtr );
    m_scene->addItem( m_itemHand );

    m_itemHand2 = new QGraphicsSvgItem( ":/qfi/images/tre/tre_hand_5.svg" );
    m_itemHand2->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand2->setZValue( m_handZ );
    m_itemHand2->setTransform( QTransform::fromScale(m_scaleX, m_scaleY ), true );
    m_itemHand2->setTransformOriginPoint( m_originalTRECtr1 );
    m_scene->addItem( m_itemHand2 );

    m_itemHand3 = new QGraphicsSvgItem( ":/qfi/images/tre/tre_hand_6.svg" );
    m_itemHand3->setCacheMode( QGraphicsItem::NoCache );
    m_itemHand3->setZValue( m_handZ );
    m_itemHand3->setTransform( QTransform::fromScale(m_scaleX,m_scaleY ), true );
    m_itemHand3->setTransformOriginPoint( m_originalTRECtr2 );
    m_scene->addItem( m_itemHand3 );



    m_itemCase = new QGraphicsSvgItem( ":/qfi/images/vsi/vsi_case.svg" );
    m_itemCase->setCacheMode( QGraphicsItem::NoCache );
    m_itemCase->setZValue( m_caseZ );
    m_itemCase->setTransform( QTransform::fromScale( m_scaleX, m_scaleY ), true );
    m_scene->addItem( m_itemCase );

    centerOn( width() / 2.0f , height() / 2.0f );

    updateView();
}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::reset()
{
    m_itemFace = 0;
    m_itemHand = 0;
    m_itemCase = 0;
    m_itemHand2 = 0;
    m_itemHand3= 0;

    m_OILP = 0.0f;
    m_OILT = 0.0f;

    m_FUELP = 0.0f;

}

////////////////////////////////////////////////////////////////////////////////

void qfi_TRE::updateView()
{

    m_itemHand->setRotation(m_OILT * 0.13f );
    m_itemHand3->setRotation(m_FUELP * 0.13f );

    m_itemHand2->setRotation(m_OILP * 0.13f );

    m_scene->update();
}

