
#include <qacat_tryoutwindow.h>

#include <qacat_layout_iterator_thread.h>
#include <qacat_pushbutton.h>
#include <qacat_confirmdialog.h>

QAcatTryoutWindow :: QAcatTryoutWindow(QWidget *parent)
    : QMainWindow(parent)
    , grid(new QGridLayout)
    , vbox(new QVBoxLayout)
    , hbox(new QHBoxLayout)
    , instruction_label(new QLabel)
    , todo_label(new QLabel)
    , input_line(new QLineEdit)
{
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(vbox);
    
    vbox->addLayout(grid);
    vbox->addLayout(hbox);
    
    setCentralWidget(central_widget);
    
    QStringList todo_list;
    todo_list << "tea" << "ate" << "tab" << "bat" << "eat";
    
    grid->addWidget(input_line, 0, 0);
    grid->addWidget(instruction_label, 0, 2);
    instruction_label->setText("Type this word:");
    grid->addWidget(todo_label, 0, 3);
    todo_label->setText("tea");
    
    
    QAcatPushButton *b_button = new QAcatPushButton("b");
    QAcatPushButton *t_button = new QAcatPushButton("t");
    QAcatPushButton *a_button = new QAcatPushButton("a");
    QAcatPushButton *e_button = new QAcatPushButton("e");
    QAcatPushButton *backspace_button = new QAcatPushButton("backspace");
    QAcatPushButton *clear_button = new QAcatPushButton("clear");
    
    QAcatPushButton *exit_button = new QAcatPushButton("exit");
    
    hbox->addWidget(b_button);
    hbox->addWidget(t_button);
    hbox->addWidget(a_button);
    hbox->addWidget(e_button);
    hbox->addWidget(backspace_button);
    hbox->addWidget(clear_button);
    hbox->addWidget(exit_button);
    
    connect(b_button, &QAcatPushButton::clicked, this, [this]{ writeChar('b'); });
    connect(t_button, &QAcatPushButton::clicked, this, [this]{ writeChar('t'); });
    connect(a_button, &QAcatPushButton::clicked, this, [this]{ writeChar('a'); });
    connect(e_button, &QAcatPushButton::clicked, this, [this]{ writeChar('e'); });
    
    connect(backspace_button, SIGNAL(clicked()), this, SLOT(delChar()));
    
    connect(clear_button, &QAcatPushButton::clicked, this, &QAcatTryoutWindow::clearText);
    
    connect(exit_button, &QAcatPushButton::clicked, this, &QAcatTryoutWindow::exitButtonClicked);
    
    startLayoutIterator();
}

void QAcatTryoutWindow :: writeChar(QChar c)
{
    input_line->insert(c);
}

void QAcatTryoutWindow :: clearText()
{
    input_line->setText("");
}

void QAcatTryoutWindow :: delChar()
{
    QString old_content = input_line->text();
    int old_size = old_content.size();
    
    input_line->setText(old_content.left(old_size - 1));
}

void QAcatTryoutWindow :: exitButtonClicked()
{
    QAcatConfirmDialog *dialog = new QAcatConfirmDialog("Exit QAcat?");
    connect(dialog, &QAcatConfirmDialog::positiveButtonClicked, this, &QAcatTryoutWindow::quit);
    dialog->show();
}

void QAcatTryoutWindow :: startLayoutIterator()
{
    QAcatLayoutIteratorThread *iterator_thread = new QAcatLayoutIteratorThread();
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateLayoutItem, this, &QAcatTryoutWindow::activateLayoutItem);
    
    iterator_thread->setLayout(hbox);
    iterator_thread->start();
}

void QAcatTryoutWindow :: activateLayoutItem(int index)
{
    QLayout *layout = hbox->layout();
    if (layout)
    {
        QLayoutItem *current_item = layout->itemAt(index);
        QWidget *current_widget = current_item->widget();
        current_widget->setFocus();
    }
}

void QAcatTryoutWindow :: quit()
{
    destroy();
}
