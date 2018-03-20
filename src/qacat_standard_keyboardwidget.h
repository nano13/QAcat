
#include <src/qacat_scanner_widget.h>

#include <QtWidgets>

class QAcatKeyboardRowWidget : public QAcatScannerWidget
{
    Q_OBJECT
    
public:
    QAcatKeyboardRowWidget(QAcatScannerWidget *parent = 0);
    
private:
    
    
protected:
    
    
private slots:
    
    
signals:
    
    
};



class QAcatStandardKeyboardWidget : public QAcatScannerWidget
{
    Q_OBJECT
    
public:
    QAcatStandardKeyboardWidget(QAcatScannerWidget *parent = 0);
    
private:
    QList<QWidget*> row_widget_list;
    QStringList layout_list;
    
protected:
    
    
private slots:
    void keyPressEvent(QKeyEvent*);
    void keyboardPressed(QString);
    
signals:
    void keyboardPressedSignal(QString);
    //void iterateThis(QList<QHBoxLayout*>);
    void iterateWidgetList(QList<QWidget*>);
};

