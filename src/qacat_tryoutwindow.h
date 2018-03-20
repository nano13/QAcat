
#ifndef TRYOUT_WINDOW
#define TRYOUT_WINDOW

#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QChar>

#include <./src/qacat_layout_iterator_thread.h>

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
    QStringList todo_list;
    QLineEdit *input_line;
    
    QAcatLayoutIteratorThread *iterator_thread;
    
    void selectRandomWord();
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

#endif
