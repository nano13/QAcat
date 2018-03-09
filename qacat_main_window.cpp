
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
    
    QPushButton *tryoutButton = new QPushButton("QAcat tryout");
    connect(tryoutButton, &QPushButton::clicked, this, &QAcatMainWindow::tryoutButtonClicked);
    grid->addWidget(tryoutButton, 0, 0);
    
    QPushButton *quitButton = new QPushButton("end QAcat");
    connect(quitButton, &QPushButton::clicked, this, &QAcatMainWindow::quitButtonClicked);
    grid->addWidget(quitButton, 10, 10);
}

void QAcatMainWindow::tryoutButtonClicked()
{
    qDebug() << "tryout button pushed";
}

void QAcatMainWindow::quitButtonClicked()
{
    QCoreApplication::quit();
}
