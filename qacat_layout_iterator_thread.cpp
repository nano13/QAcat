
#include <qacat_layout_iterator_thread.h>

#include <QLayout>

QAcatLayoutIteratorThread::QAcatLayoutIteratorThread(QThread *parent)
{
    
}

void QAcatLayoutIteratorThread :: setLayout(QLayout *layout)
{
    this->layout = layout->layout();
}

void QAcatLayoutIteratorThread :: reset()
{
    reset_thread = true;
}

void QAcatLayoutIteratorThread::run()
{
    if (layout) {
        while (true)
        {
            for (int i = 0; i < layout->count(); ++i)
            {
                emit activateLayoutItem(i);
                msleep(600);
                
                if (reset_thread == true)
                {
                    reset_thread = false;
                    break;
                }
            }
        }
    }
}
