
#include <QMainWindow>
#include <QGridLayout>

class QAcatMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QAcatMainWindow(QWidget *parent = 0);
    
private:
    QGridLayout *grid;
    
    
    
private slots:
    void tryoutButtonClicked();
    void talkButtonClicked();
    void configButtonClicked();
    void quitButtonClicked();
};
