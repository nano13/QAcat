
#include <QMainWindow>
#include <QApplication>
#include <QDebug>

#include <main_window.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QApplication::setApplicationName("QAcat");
    
    MainWindow mainWin;
    //QIcon::setThemeSearchPaths(QStringList("../assets/icons"));
    //QIcon::setThemeName("oxygen");
    //mainWin.setWindowIcon(QIcon("../assets/icons/logo2.png"));
    mainWin.show();
    return app.exec();
}
