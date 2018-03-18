
#include <qacat_talkwindow.h>

QAcatTalkWindow :: QAcatTalkWindow (QWidget *parent)
    : QMainWindow (parent)
    , grid (new QGridLayout)
    , textedit (new QTextEdit)
    , keyboard (new QAcatStandardKeyboardWidget)
    , phrases (new QAcatFavoritePhrasesWidget)
    , predicted (new QAcatPredictedWordsWidget)
{
    QWidget *central_widget = new QWidget();
    central_widget -> setLayout (grid);
    setCentralWidget (central_widget);
    
    grid->addWidget (textedit, 1, 1);
    grid->addWidget (phrases, 1, 2);
    grid->addWidget (keyboard, 2, 2);
    grid->addWidget (predicted, 2, 1);
    
    connect(keyboard, &QAcatStandardKeyboardWidget::keyboardPressedSignal, this, &QAcatTalkWindow::sendKeyboardPressToTextEdit);
    
    keyboard -> setFocus();
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
