
#include <QThread>
#include <QLayout>
 
class QAcatLayoutIteratorThread : public QThread
{
    Q_OBJECT
    
public:
    QAcatLayoutIteratorThread(QThread *parent = 0);
    void setLayout(QLayout *layout);
    
protected:
    void run();
    
private:
    QLayout *layout;
    
signals:
    void activateLayoutItem(int);
    
};
