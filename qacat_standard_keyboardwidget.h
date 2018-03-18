
#include <QtWidgets>

class QAcatStandardKeyboardWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatStandardKeyboardWidget(QWidget *parent = 0);
    
private:
    QList<QHBoxLayout*> hlist;
    QStringList layout_list;
    
protected:
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    
private slots:
    void keyPressEvent(QKeyEvent*);
    void keyboardPressed(QString);
    
signals:
    void keyboardPressedSignal(QString);
    void iterateThis(QList<QHBoxLayout*>);
};
