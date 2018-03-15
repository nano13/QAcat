
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class QAcatConfirmDialog : public QDialog
{
    Q_OBJECT
    
public:
    QAcatConfirmDialog(QString label_text = "", QWidget *parent = 0);
    
private:
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QLabel *label;
    
    void startLayoutIterator();
    
private slots:
    void onPositiveButtonClicked();
    void onNegativeButtonClicked();
    
    void activateLayoutItem(int);
    
signals:
    void positiveButtonClicked();
    void negativeButtonClicked();
};
