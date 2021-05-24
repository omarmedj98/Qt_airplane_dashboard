#include "WidgetTEM.h"
#include "ui_WidgetTEM.h"

WidgetTEM::WidgetTEM(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetTEM),
  m_tem(0),
  m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_tem=m_ui->graphicsTEM;
}

WidgetTEM::~WidgetTEM()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}
void WidgetTEM::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsTEM );

    setLayout( m_layoutSq );
}
