
#include <src/qacat_scanner_widget.h>

QAcatScannerWidget :: QAcatScannerWidget(QWidget *parent)
    : QWidget(parent)
    , iterator_thread(new QAcatLayoutIteratorThread)
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

void QAcatScannerWidget :: startLayoutIterator()
{
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateLayoutItem, this, &QAcatScannerWidget::activateLayoutItem);
    
    iterator_thread->setLayout(layout());
    iterator_thread->start();
}

void QAcatScannerWidget :: activateLayoutItem(int index)
{
    if (layout())
    {
        QLayoutItem *current_item = layout()->itemAt(index);
        QWidget *current_widget = current_item->widget();
        current_widget->setFocus();
    }
}

void QAcatScannerWidget :: keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        iterator_thread->halt();
        iterator_thread->terminate();
        iterator_thread->exit();
        iterator_thread->quit();
        iterator_thread->wait();
        iterator_thread->halt();
        qDebug() << "tut wohl nicht ...";
    }
    
    QWidget::keyPressEvent(event);
}
