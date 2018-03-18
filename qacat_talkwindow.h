
#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>

#include <qacat_standard_keyboardwidget.h>
#include <qacat_favorite_phrases_widget.h>
#include <qacat_predicted_words_widget.h>
#include <qacat_layout_iterator_thread.h>

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
    
protected:
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    
private slots:
    void sendKeyboardPressToTextEdit(QString);
    void activateWidget(int);
    void exitButtonClicked();
    void quit();
    
signals:
    
    
};
