
#include <QMainWindow>
#include <QGridLayout>

class QAcatMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QAcatMainWindow(QWidget *parent = 0);
    
private:
    QGridLayout *grid;
    
    void startLayoutIterator();
    
private slots:
    void tryoutButtonClicked();
    void talkButtonClicked();
    void configButtonClicked();
    void quitButtonClicked();
    
    void activateLayoutItem(int);
    
    void quit();
};
