
#include <src/qacat_standard_keyboardwidget.h>

#include <src/qacat_pushbutton.h>

QAcatStandardKeyboardWidget :: QAcatStandardKeyboardWidget(QAcatScannerWidget *parent)
    : QAcatScannerWidget(parent)
{
    setMaximumSize(220, 170);
    setMinimumSize(220, 170);
    
    layout_list << "t" << "i" << "h" << "c" << "b" << "\u232b"\
                << "e" << "a" << "n" << "d" << "f" << "\u2423"\
                << "o" << "s" << "l" << "y" << "v" << "."\
                << "r" << "m" << "w" << "k" << "q" << "\u21E7"\
                << "u" << "p" << "g" << "j" << "x" << "z";
    
    QVBoxLayout *vbox = new QVBoxLayout;
    setLayout(vbox);
    
    for (int i = 0; i <= 5; i++)
    {
        QWidget *row = new QAcatKeyboardRowWidget();
        row_widget_list.append (row);
    }
    
    int i = 0;
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= 6; y++)
        {
            QString &chr = layout_list[i];
            QAcatPushButton *button = new QAcatPushButton(chr);
            
            connect(button, &QAcatPushButton::clicked, this, [this, &chr]{ keyboardPressed(chr); });
            
            row_widget_list[x]->layout()->addWidget(button);
            
            i++;
        }
    }
    
    foreach (QWidget *row, row_widget_list)
    {
        vbox->addWidget(row);
    }
}

void QAcatStandardKeyboardWidget :: keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        //emit iterateThis(row_widget_list);
        emit iterateWidgetList(row_widget_list);
    }
    
    QWidget::keyPressEvent(event);
}

void QAcatStandardKeyboardWidget :: keyboardPressed(QString button_str)
{
    emit keyboardPressedSignal (button_str);
}




QAcatKeyboardRowWidget :: QAcatKeyboardRowWidget(QAcatScannerWidget *parent)
    : QAcatScannerWidget(parent)
{
    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setContentsMargins(0, 0, 0, 0);
    setLayout(hbox);
}
