
#include <QtWidgets>

class QAcatStandardKeyboardWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatStandardKeyboardWidget(QWidget *parent = 0);
    
private:
    QStringList layout_list;
    
protected:
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    
private slots:
    void keyboardPressed(QString);
    
signals:
    void keyboardPressedSignal(QString);
    
};
