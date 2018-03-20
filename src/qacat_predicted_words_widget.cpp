
#include <src/qacat_predicted_words_widget.h>

#include <src/qacat_pushbutton.h>

#include <QtWidgets>
#include <QGridLayout>

QAcatPredictedWordsWidget :: QAcatPredictedWordsWidget(QWidget *parent)
    : QWidget(parent)
{
    predicted_list << "Lorem" << "ipsum" << "dolor" << "sit" << "amet," << "consetetur" << "sadipscing" << "elitr," << "sed" << "diam" << "nonumy" << "eirmod" << "tempor" << "invidunt" << "ut" << "labore" << "et" << "dolore" << "magna" << "aliquyam" << "erat," << "sed" << "diam" << "voluptua.";
    
    QVBoxLayout *vbox = new QVBoxLayout;
    setLayout(vbox);
    
    QList<QHBoxLayout*> hlist;
    for (int i = 0; i <= 5; i++)
    {
        QHBoxLayout *hbox = new QHBoxLayout;
        hlist.append(hbox);
    }
    
    int i = 0;
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= 3; y++)
        {
            QString &chr = predicted_list[i];
            QAcatPushButton *button = new QAcatPushButton(chr);
            connect(button, &QAcatPushButton::clicked, this, [this, &chr]{ predictionPressed(chr); });
            hlist[x]->addWidget(button);
            
            i++;
        }
    }
    
    foreach (QHBoxLayout *hbox, hlist)
    {
        vbox->addLayout(hbox);
    }
}

void QAcatPredictedWordsWidget :: predictionPressed(QString button_str)
{
    emit predictionSelectedSignal (button_str);
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
