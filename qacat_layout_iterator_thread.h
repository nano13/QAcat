
#ifndef ITERATOR_THREAD
#define ITERATOR_THREAD

#include <QThread>
#include <QLayout>
 
class QAcatLayoutIteratorThread : public QThread
{
    Q_OBJECT
    
public:
    QAcatLayoutIteratorThread(QThread *parent = 0);
    void setLayout(QLayout *layout);
    void reset();
    
protected:
    void run();
    
private:
    QLayout *layout;
    bool reset_thread;
    
signals:
    void activateLayoutItem(int);
    
};

#endif
