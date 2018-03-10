
#include <qacat_layout_iterator_thread.h>

#include <QLayout>

QAcatLayoutIteratorThread::QAcatLayoutIteratorThread(QThread *parent)
{
    
}

void QAcatLayoutIteratorThread::setLayout(QLayout *layout)
{
    this->layout = layout;
}

void QAcatLayoutIteratorThread::run()
{
    QLayout *layout = this->layout->layout();
    if (layout) {
        while (true)
        {
            for (int i = 0; i < layout->count(); ++i)
            {
                emit activateLayoutItem(i);
                msleep(600);
            }
        }
    }
}
