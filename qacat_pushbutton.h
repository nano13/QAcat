
#include <QPushButton>

class QAcatPushButton : public QPushButton
{
    Q_OBJECT
    
public:
    explicit QAcatPushButton(QWidget *parent=0);
    explicit QAcatPushButton(const QString &text, QWidget *parent=0);
    QAcatPushButton(const QIcon& icon, const QString &text, QWidget *parent=0);
    
private:
    
    
private slots:
    
    
signals:
    
    
};
