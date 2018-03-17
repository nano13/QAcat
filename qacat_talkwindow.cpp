
#include <qacat_talkwindow.h>

QAcatTalkWindow :: QAcatTalkWindow(QWidget *parent)
    : QMainWindow(parent)
    , grid(new QGridLayout)
    , textedit(new QTextEdit)
    , keyboard(new QAcatStandardKeyboardWidget)
    , phrases(new QAcatFavoritePhrasesWidget)
    , words(new QAcatPredictedWordsWidget)
{
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(grid);
    setCentralWidget(central_widget);
    
    grid->addWidget(textedit, 1, 1);
    grid->addWidget(phrases, 1, 2);
    grid->addWidget(keyboard, 2, 2);
    grid->addWidget(words, 2, 1);
}
