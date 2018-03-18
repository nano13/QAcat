
#include <QWidget>

class QAcatPredictedWordsWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatPredictedWordsWidget(QWidget *parent = 0);
    
private:
    QStringList predicted_list;
    
protected:
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    
    
private slots:
    void predictionPressed(QString);
    
signals:
    void predictionSelectedSignal(QString);
    
};
