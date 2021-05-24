#include "WidgetMP.h"
#include "ui_WidgetMP.h"

WidgetMP::WidgetMP(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetMP),
    m_mp(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_mp=m_ui->graphicsMP;


}

WidgetMP::~WidgetMP()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}
void WidgetMP::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsMP );

    setLayout( m_layoutSq );
}
