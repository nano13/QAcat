
#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QChar>

class QAcatTryoutWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QAcatTryoutWindow(QWidget *parent = 0);
    
private:
    QVBoxLayout *vbox;
    QGridLayout *grid;
    QHBoxLayout *hbox;
    QLabel *instruction_label;
    QLabel *todo_label;
    QLineEdit *input_line;
    
    void startLayoutIterator();
    
private slots:
    void activateLayoutItem(int);
    void writeChar(QChar);
    void delChar();
    void clearText();
    void exitButtonClicked();
    void quit();
    
signals:
    
    
};
