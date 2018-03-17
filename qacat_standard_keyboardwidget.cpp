
#include <qacat_standard_keyboardwidget.h>

#include <qacat_pushbutton.h>

QAcatStandardKeyboardWidget :: QAcatStandardKeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    layout_list << "t" << "i" << "h" << "c" << "b" << "cursor"\
                << "e" << "a" << "n" << "d" << "f" << " "\
                << "o" << "s" << "l" << "y" << "v" << "."\
                << "r" << "m" << "w" << "k" << "q" << "Shift"\
                << "u" << "p" << "g" << "j" << "x" << "z";
    
    QVBoxLayout *vbox = new QVBoxLayout;
    setLayout(vbox);
    
    QList<QHBoxLayout*> hlist;
    for (int i = 0; i <= 5; i++)
    {
        QHBoxLayout *hbox = new QHBoxLayout;
        hlist.append(hbox);
    }
    
    int i = 0;
    foreach (const QString &chr, layout_list)
    {
        QAcatPushButton* button = new QAcatPushButton(chr);
        hlist[i % 6]->addWidget(button);
        
        i++;
    }
    
    foreach (QHBoxLayout *hbox, hlist)
    {
        vbox->addLayout(hbox);
    }
}
