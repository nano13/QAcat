
#include <QMessageBox>

class QAcatMessageBox : public QMessageBox
{
    Q_OBJECT
    
public:
    explicit QAcatMessageBox(QWidget *parent = Q_NULLPTR);
    QAcatMessageBox(Icon icon, const QString &title, const QString &text,
                StandardButtons buttons = NoButton, QWidget *parent = Q_NULLPTR,
                Qt::WindowFlags flags = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    //~QAcatMessageBox();
    
private:
    
    
private slots:
    
    
protected:
    
    
signals:
    
    
};
