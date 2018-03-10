
#include <QtWidgets>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include <qacat_main_window.h>

QAcatMainWindow::QAcatMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , grid(new QGridLayout)
{
    resize(600, 400);
    
    QWidget *central_widget = new QWidget();
    central_widget->setLayout(grid);
    
    setCentralWidget(central_widget);
    
    QPushButton *tryoutButton = new QPushButton("tryout");
    connect(tryoutButton, &QPushButton::clicked, this, &QAcatMainWindow::tryoutButtonClicked);
    grid->addWidget(tryoutButton, 0, 0);
    
    QPushButton *talkButton = new QPushButton("talk");
    connect(talkButton, &QPushButton::clicked, this, &QAcatMainWindow::talkButtonClicked);
    grid->addWidget(talkButton, 0, 1);
    
    QPushButton *configButton = new QPushButton("config");
    connect(configButton, &QPushButton::clicked, this, &QAcatMainWindow::configButtonClicked);
    grid->addWidget(configButton, 1, 0);
    
    QPushButton *quitButton = new QPushButton("exit");
    connect(quitButton, &QPushButton::clicked, this, &QAcatMainWindow::quitButtonClicked);
    grid->addWidget(quitButton, 1, 1);
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
