
#include <QPushButton>

#include <qacat_pushbutton.h>

QAcatPushButton::QAcatPushButton(QWidget *parent)
    : QPushButton(parent)
{
    
}

QAcatPushButton::QAcatPushButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    
}

QAcatPushButton::QAcatPushButton(const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, text, parent)
{
    
}
