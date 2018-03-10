
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

void QAcatPushButton::focusInEvent(QFocusEvent *e)
{
    setStyleSheet("QWidget { background-color: black; color: white;}");
    
    QPushButton::focusInEvent(e);
}

void QAcatPushButton::focusOutEvent(QFocusEvent *e)
{
    setStyleSheet("QWidget { background-color: white; color: black;}");
    
    QPushButton::focusOutEvent(e);
}
