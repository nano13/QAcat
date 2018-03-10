
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>

#include <qacat_main_window.h>
#include <qacat_layout_iterator_thread.h>
#include <qacat_pushbutton.h>

QAcatMainWindow::QAcatMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , grid(new QGridLayout)
{
    resize(600, 400);
    
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(grid);
    
    setCentralWidget(central_widget);
    
    QAcatPushButton *tryoutButton = new QAcatPushButton("tryout");
    connect(tryoutButton, &QAcatPushButton::clicked, this, &QAcatMainWindow::tryoutButtonClicked);
    grid->addWidget(tryoutButton, 0, 0);
    
    QAcatPushButton *talkButton = new QAcatPushButton("talk");
    connect(talkButton, &QAcatPushButton::clicked, this, &QAcatMainWindow::talkButtonClicked);
    grid->addWidget(talkButton, 0, 1);
    
    QAcatPushButton *configButton = new QAcatPushButton("config");
    connect(configButton, &QAcatPushButton::clicked, this, &QAcatMainWindow::configButtonClicked);
    grid->addWidget(configButton, 1, 0);
    
    QAcatPushButton *quitButton = new QAcatPushButton("exit");
    connect(quitButton, &QAcatPushButton::clicked, this, &QAcatMainWindow::quitButtonClicked);
    grid->addWidget(quitButton, 1, 1);
    
    startLayoutIterator();
}

void QAcatMainWindow::tryoutButtonClicked()
{
    qDebug() << "tryout button pushed";
}

void QAcatMainWindow::talkButtonClicked()
{
    qDebug() << "talk button pushed";
}

void QAcatMainWindow::configButtonClicked()
{
    qDebug() << "config button pushed";
}

void QAcatMainWindow::quitButtonClicked()
{
    QCoreApplication::quit();
}

void QAcatMainWindow::startLayoutIterator()
{
    QAcatLayoutIteratorThread *iterator_thread = new QAcatLayoutIteratorThread();
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateLayoutItem, this, &QAcatMainWindow::activateLayoutItem);
    
    iterator_thread->setLayout(grid);
    iterator_thread->start();
}

void QAcatMainWindow::activateLayoutItem(int index)
{
    
    QLayout *layout = grid->layout();
    if (layout)
    {
        QLayoutItem *current_item = layout->itemAt(index);
        QWidget *current_widget = current_item->widget();
        current_widget->setFocus();
    }
    
//     QLayout *layout = grid->layout();
//     qDebug() << layout->count();
//     if (layout) {
//         for (int i = 0; i < layout->count(); ++i)
//             QLayoutItem *current_item = layout->itemAt(i);
//     }
}
