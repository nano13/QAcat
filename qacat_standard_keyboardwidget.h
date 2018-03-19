
#include <QtWidgets>

class QAcatKeyboardRowWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatKeyboardRowWidget(QWidget *parent = 0);
    
private:
    
    
protected:
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    
private slots:
    
    
signals:
    
    
};


class QAcatStandardKeyboardWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatStandardKeyboardWidget(QWidget *parent = 0);
    
private:
    QList<QWidget*> row_widget_list;
    QStringList layout_list;
    
protected:
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    
private slots:
    void keyPressEvent(QKeyEvent*);
    void keyboardPressed(QString);
    
signals:
    void keyboardPressedSignal(QString);
    //void iterateThis(QList<QHBoxLayout*>);
    void iterateWidgetList(QList<QWidget*>);
};

