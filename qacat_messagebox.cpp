
#include <QMessageBox>

#include <qacat_messagebox.h>

QAcatMessageBox::QAcatMessageBox(QWidget *parent)
    : QMessageBox(parent)
{
    
}

QAcatMessageBox::QAcatMessageBox(Icon icon, const QString &title,
        const QString &text,
        StandardButtons buttons, QWidget *parent,
        Qt::WindowFlags flags)
    : QMessageBox(icon, title, text, buttons, parent, flags)
{
    
}
