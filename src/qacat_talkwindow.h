
#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>

#include <src/qacat_standard_keyboardwidget.h>
#include <src/qacat_favorite_phrases_widget.h>
#include <src/qacat_predicted_words_widget.h>
#include <src/qacat_layout_iterator_thread.h>

class QAcatTalkWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QAcatTalkWindow(QWidget *parent = 0);
    
private:
    QGridLayout *grid;
    
    QTextEdit *textedit;
    QAcatStandardKeyboardWidget *keyboard;
    QAcatFavoritePhrasesWidget *phrases;
    QAcatPredictedWordsWidget *predicted;
    
    QList<QWidget*> widget_list;
    QAcatLayoutIteratorThread *iterator_thread;
    void startWidgetIterator();
    int current_active_widget_index;
    
protected:
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    
private slots:
    //void keyPressEvent(QKeyEvent*);
    void sendKeyboardPressToTextEdit(QString);
    void iterateKeyboardWidgetList(QList<QWidget*>);
    void activateWidget(int);
    void activateWidgetLayout(int layout_index);
    void exitButtonClicked();
    void quit();
    
signals:
    
    
};
