
#include <src/qacat_scanner_widget.h>

QAcatScannerWidget :: QAcatScannerWidget(QWidget *parent)
    : QWidget(parent)
{
    
}

void QAcatScannerWidget :: focusInEvent (QFocusEvent *e)
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);
    
    QWidget::focusInEvent(e);
}

void QAcatScannerWidget :: focusOutEvent (QFocusEvent *e)
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    setPalette(pal);
    
    QWidget::focusOutEvent(e);
}
