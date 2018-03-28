
#include <QtWidgets>

#include <src/qacat_layout_iterator_thread.h>

class QAcatScannerWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatScannerWidget(QWidget *parent = 0);
    
    void startLayoutIterator();
    
private:
    QAcatLayoutIteratorThread *iterator_thread;
    
protected:
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    
private slots:
    void activateLayoutItem(int);
    void keyPressEvent(QKeyEvent*);
    
signals:
    
    
};
