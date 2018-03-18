
#include <qacat_layout_iterator_thread.h>

#include <QtWidgets>
#include <QLayout>

QAcatLayoutIteratorThread :: QAcatLayoutIteratorThread (QThread *parent)
{
    
}

void QAcatLayoutIteratorThread :: setLayout (QLayout *layout)
{
    this -> layout = layout -> layout();
    widget_list.clear();
    layout_list.clear();
}

void QAcatLayoutIteratorThread :: setWidgetList (QList<QWidget*> widget_list)
{
    this -> widget_list = widget_list;
    layout = NULL;
    layout_list.clear();
}

void QAcatLayoutIteratorThread :: setLayoutList (QList<QHBoxLayout*> layout_list)
{
    this -> layout_list = layout_list;
    layout = NULL;
    widget_list.clear();
    
    reset_thread = true;
}

void QAcatLayoutIteratorThread :: reset()
{
    reset_thread = true;
}

void QAcatLayoutIteratorThread :: run()
{
    while (true)
    {
        if (widget_list.length() > 0)
        {
            qDebug() << "widget list";
            iterateWidgetList ();
        }
        else if (layout_list.length() > 0)
        {
            qDebug() << "layout list";
            iterateWidgetLayoutList ();
        }
        else if (layout) {
            qDebug() << "layout";
            iterateSingleLayout ();
        }
    }
}

void QAcatLayoutIteratorThread :: iterateSingleLayout ()
{
    //while (true)
    //{
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
    //}
}

void QAcatLayoutIteratorThread :: iterateWidgetList ()
{
    //while (true)
    //{
        for (int i = 0; i < widget_list.count(); ++i)
        {
            emit activateWidgetItem (i);
            msleep (600);
            
            if (reset_thread == true)
            {
                reset_thread = false;
                break;
            }
        }
    //}
}

void QAcatLayoutIteratorThread :: iterateWidgetLayoutList ()
{
    qDebug() << "iterateLayoutList";
    for (int i = 0; i < layout_list.count(); ++i)
    {
        emit activateWidgetLayoutItem (i);
        msleep (600);
        
        if (reset_thread == true)
        {
            reset_thread = false;
            break;
        }
    }
}
