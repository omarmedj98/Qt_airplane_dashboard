#include "widgetrpm.h"
#include "ui_widgetrpm.h"

Widgetrpm::Widgetrpm(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Widgetrpm),
     m_vsi ( 0 ),
     m_layoutSq ( 0 )
{
    m_ui->setupUi(this);
    setupUi();

    m_vsi = m_ui->graphicsrpm;
}

Widgetrpm::~Widgetrpm()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}
void Widgetrpm::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsrpm );

    setLayout( m_layoutSq );
}
