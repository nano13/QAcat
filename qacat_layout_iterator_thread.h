
#ifndef ITERATOR_THREAD
#define ITERATOR_THREAD

#include <QThread>
#include <QLayout>
 
class QAcatLayoutIteratorThread : public QThread
{
    Q_OBJECT
    
public:
    QAcatLayoutIteratorThread (QThread *parent = 0);
    void setLayout (QLayout *);
    void setWidgetList (QList<QWidget*>);
    void setLayoutList (QList<QLayout*>);
    void reset();
    
protected:
    void run();
    
private:
    QLayout *layout;
    QList<QWidget*> widget_list;
    QList<QLayout*> layout_list;
    bool reset_thread;
    
    void iterateSingleLayout ();
    void iterateWidgetList ();
    void iterateLayoutList ();
    
signals:
    void activateLayoutItem (int);
    void activateSubLayout (int);
};

#endif
