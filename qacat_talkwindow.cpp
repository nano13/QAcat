
#include <qacat_talkwindow.h>

#include <qacat_confirmdialog.h>

QAcatTalkWindow :: QAcatTalkWindow (QWidget *parent)
    : QMainWindow (parent)
    , grid (new QGridLayout)
    , textedit (new QTextEdit)
    , keyboard (new QAcatStandardKeyboardWidget)
    , phrases (new QAcatFavoritePhrasesWidget)
    , predicted (new QAcatPredictedWordsWidget)
    , iterator_thread(new QAcatLayoutIteratorThread)
{
    QWidget *central_widget = new QWidget();
    central_widget -> setLayout (grid);
    setCentralWidget (central_widget);
    
    grid->addWidget (textedit, 1, 1);
    grid->addWidget (phrases, 1, 2);
    grid->addWidget (keyboard, 2, 2);
    grid->addWidget (predicted, 2, 1);
    
    connect(keyboard, &QAcatStandardKeyboardWidget::keyboardPressedSignal, this, &QAcatTalkWindow::sendKeyboardPressToTextEdit);
    
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

void QAcatTalkWindow :: startWidgetIterator()
{
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateLayoutItem, this, &QAcatTalkWindow::activateWidget);
    
    iterator_thread->setWidgetList(widget_list);
    iterator_thread->start();
}

void QAcatTalkWindow :: activateWidget(int index)
{
    qDebug() << "bla";
    widget_list[index] -> setFocus();
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
