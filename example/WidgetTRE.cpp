#include "WidgetTRE.h"
#include "ui_WidgetTRE.h"

WidgetTRE::WidgetTRE(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetTRE),
    m_tre(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_tre=m_ui->graphicsTRE;
}

WidgetTRE::~WidgetTRE()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}
void WidgetTRE::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsTRE );

    setLayout( m_layoutSq );
}
