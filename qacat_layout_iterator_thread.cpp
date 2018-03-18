
#include <qacat_layout_iterator_thread.h>

#include <QtWidgets>
#include <QLayout>

QAcatLayoutIteratorThread :: QAcatLayoutIteratorThread (QThread *parent)
{
    
}

void QAcatLayoutIteratorThread :: setLayout (QLayout *layout)
{
    this -> layout = layout -> layout();
}

void QAcatLayoutIteratorThread :: setWidgetList (QList<QWidget*> widget_list)
{
    qDebug() << "set widget";
    this -> widget_list = widget_list;
}

void QAcatLayoutIteratorThread :: setLayoutList (QList<QLayout*> layout_list)
{
    this -> layout_list = layout_list;
}

void QAcatLayoutIteratorThread :: reset()
{
    reset_thread = true;
}

void QAcatLayoutIteratorThread :: run()
{
    qDebug() << "run";
    
    if (widget_list.length() > 0)
    {
        qDebug() << "widget";
        iterateWidgetList ();
    }
    else if (layout_list.length() > 0)
    {
        iterateLayoutList ();
    }
    else if (layout) {
        qDebug() << "layout";
        iterateSingleLayout ();
    }
}

void QAcatLayoutIteratorThread :: iterateSingleLayout ()
{
    while (true)
    {
        for (int i = 0; i < layout->count(); ++i)
        {
            emit activateLayoutItem (i);
            msleep (600);
            
            if (reset_thread == true)
            {
                reset_thread = false;
                break;
            }
        }
    }
}

void QAcatLayoutIteratorThread :: iterateWidgetList ()
{
    qDebug() << "blubb";
    while (true)
    {
        for (int i = 0; i < widget_list.count(); ++i)
        {
            emit activateLayoutItem (i);
            msleep (600);
            
        }
    }
}

void QAcatLayoutIteratorThread :: iterateLayoutList ()
{
    
}
