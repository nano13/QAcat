
#include <qacat_standard_keyboardwidget.h>

#include <qacat_pushbutton.h>

QAcatStandardKeyboardWidget :: QAcatStandardKeyboardWidget(QWidget *parent)
    : QWidget(parent)
    , grid(new QGridLayout)
{
    setLayout(grid);
    
    layout_list << "t" << "i" << "h" << "c" << "b" << "cursor"\
                << "e" << "a" << "n" << "d" << "f" << " "\
                << "o" << "s" << "l" << "y" << "v" << "."\
                << "r" << "m" << "w" << "k" << "q" << "Shift"\
                << "u" << "p" << "g" << "j" << "x" << "z";
    
    int i = 0;
    foreach (const QString &chr, layout_list)
    {
        QAcatPushButton *button = new QAcatPushButton(chr);
        grid->addWidget(button, i, i % 6);
        
        i++;
    }
}
