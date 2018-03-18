
#include <qacat_standard_keyboardwidget.h>

#include <qacat_pushbutton.h>

QAcatStandardKeyboardWidget :: QAcatStandardKeyboardWidget(QWidget *parent)
    : QWidget(parent)
{
    setMaximumSize(220, 170);
    
    layout_list << "t" << "i" << "h" << "c" << "b" << "\u232b"\
                << "e" << "a" << "n" << "d" << "f" << "\u2423"\
                << "o" << "s" << "l" << "y" << "v" << "."\
                << "r" << "m" << "w" << "k" << "q" << "\u21E7"\
                << "u" << "p" << "g" << "j" << "x" << "z";
    
    QVBoxLayout *vbox = new QVBoxLayout;
    setLayout(vbox);
    
    for (int i = 0; i <= 5; i++)
    {
        QHBoxLayout *hbox = new QHBoxLayout;
        hlist.append(hbox);
    }
    
    int i = 0;
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= 6; y++)
        {
            QString &chr = layout_list[i];
            QAcatPushButton *button = new QAcatPushButton(chr);
            connect(button, &QAcatPushButton::clicked, this, [this, &chr]{ keyboardPressed(chr); });
            hlist[x]->addWidget(button);
            
            i++;
        }
    }
    
    foreach (QHBoxLayout *hbox, hlist)
    {
        vbox->addLayout(hbox);
    }
}

void QAcatStandardKeyboardWidget :: keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        emit iterateThis(hlist);
    }
    
    QWidget::keyPressEvent(event);
}

void QAcatStandardKeyboardWidget :: keyboardPressed(QString button_str)
{
    emit keyboardPressedSignal (button_str);
}

void QAcatStandardKeyboardWidget :: focusInEvent (QFocusEvent *e)
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);
    
    QWidget::focusInEvent(e);
}

void QAcatStandardKeyboardWidget :: focusOutEvent (QFocusEvent *e)
{
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    setPalette(pal);
    
    QWidget::focusOutEvent(e);
}
