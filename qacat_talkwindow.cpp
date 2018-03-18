
#include <qacat_talkwindow.h>

#include <qacat_confirmdialog.h>

QAcatTalkWindow :: QAcatTalkWindow (QWidget *parent)
    : QMainWindow (parent)
    , grid (new QGridLayout)
    , textedit (new QTextEdit)
    , keyboard (new QAcatStandardKeyboardWidget)
    , phrases (new QAcatFavoritePhrasesWidget)
    , predicted (new QAcatPredictedWordsWidget)
    , iterator_thread (new QAcatLayoutIteratorThread)
{
    QWidget *central_widget = new QWidget();
    central_widget -> setLayout (grid);
    setCentralWidget (central_widget);
    
    grid->addWidget (textedit, 1, 1);
    grid->addWidget (phrases, 1, 2);
    grid->addWidget (keyboard, 2, 2);
    grid->addWidget (predicted, 2, 1);
    
    connect(keyboard, &QAcatStandardKeyboardWidget::keyboardPressedSignal, this, &QAcatTalkWindow::sendKeyboardPressToTextEdit);
    
    connect(keyboard, &QAcatStandardKeyboardWidget::iterateThis, this, &QAcatTalkWindow::iterateKeyboard);
    
    widget_list << predicted << keyboard;
    
    startWidgetIterator();
    
    //keyboard -> setFocus();
    //predicted -> setFocus();
}

void QAcatTalkWindow :: sendKeyboardPressToTextEdit (QString prs)
{
    textedit->moveCursor (QTextCursor::End);
    textedit->insertPlainText (prs);
    textedit->moveCursor (QTextCursor::End);
}

void QAcatTalkWindow :: iterateKeyboard (QList<QHBoxLayout*> layout_list)
{
    iterator_thread->setLayoutList(layout_list);
}

void QAcatTalkWindow :: focusInEvent (QFocusEvent *e)
{
    setStyleSheet ("QWidget { background-color: black; color: white;}");
    
    QWidget::focusInEvent(e);
}

void QAcatTalkWindow :: focusOutEvent (QFocusEvent *e)
{
    setStyleSheet ("QWidget { background-color: white; color: black;}");
    
    QWidget::focusOutEvent(e);
}

/*
void QAcatTalkWindow :: keyPressEvent(QKeyEvent *e)
{
    qDebug() << "key";
    QMainWindow::keyPressEvent(e);
}
*/

void QAcatTalkWindow :: startWidgetIterator()
{
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateWidgetItem, this, &QAcatTalkWindow::activateWidget);
    
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateWidgetLayoutItem, this, &QAcatTalkWindow::activateWidgetLayout);
    
    iterator_thread->setWidgetList(widget_list);
    iterator_thread->start();
}

void QAcatTalkWindow :: activateWidget(int index)
{
    widget_list[index] -> setFocus();
    current_active_widget_index = index;
}

void QAcatTalkWindow :: activateWidgetLayout(int layout_index)
{
    widget_list[current_active_widget_index] -> clearFocus();
    QLayout *hbox = widget_list[current_active_widget_index] -> layout();
    //hbox -> setFocus();
}


void QAcatTalkWindow :: exitButtonClicked()
{
    QAcatConfirmDialog *dialog = new QAcatConfirmDialog("Exit Tryout Area?");
    connect(dialog, &QAcatConfirmDialog::positiveButtonClicked, this, &QAcatTalkWindow::quit);
    dialog->show();
}

void QAcatTalkWindow :: quit()
{
    destroy();
}
