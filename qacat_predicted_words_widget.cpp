
#include <qacat_predicted_words_widget.h>

#include <QtWidgets>
#include <QGridLayout>

QAcatPredictedWordsWidget :: QAcatPredictedWordsWidget(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *grid = new QGridLayout();
    setLayout(grid);
    
    
}

void QAcatPredictedWordsWidget :: focusInEvent (QFocusEvent *e)
{
    qDebug() << "focus in";
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::black);
    setPalette(pal);
    
    QWidget::focusInEvent(e);
}

void QAcatPredictedWordsWidget :: focusOutEvent (QFocusEvent *e)
{
    qDebug() << "focus out";
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::white);
    setPalette(pal);
    
    QWidget::focusOutEvent(e);
}
