
#include <src/qacat_confirmdialog.h>

#include <src/qacat_pushbutton.h>
#include <src/qacat_layout_iterator_thread.h>

QAcatConfirmDialog :: QAcatConfirmDialog(QString label_text, QWidget *parent)
    : QDialog(parent)
    , vbox(new QVBoxLayout)
    , hbox(new QHBoxLayout)
    , label(new QLabel)
{
    setLayout(vbox);
    
    label->setText(label_text);
    vbox->addWidget(label);
    
    vbox->addLayout(hbox);
    
    QAcatPushButton *spaceholder_button_a = new QAcatPushButton("");
    hbox->addWidget(spaceholder_button_a);
    
    QAcatPushButton *negative_button = new QAcatPushButton("No");
    connect(negative_button, &QAcatPushButton::clicked, this, &QAcatConfirmDialog::onNegativeButtonClicked);
    hbox->addWidget(negative_button);
    
    QAcatPushButton *spaceholder_button_b = new QAcatPushButton("");
    hbox->addWidget(spaceholder_button_b);
    
    QAcatPushButton *positive_button = new QAcatPushButton("Yes");
    connect(positive_button, &QAcatPushButton::clicked, this, &QAcatConfirmDialog::onPositiveButtonClicked);
    hbox->addWidget(positive_button);
    
    startLayoutIterator();
}

void QAcatConfirmDialog :: onPositiveButtonClicked()
{
    emit positiveButtonClicked();
    close();
}

void QAcatConfirmDialog :: onNegativeButtonClicked()
{
    emit negativeButtonClicked();
    close();
}

void QAcatConfirmDialog :: startLayoutIterator()
{
    QAcatLayoutIteratorThread *iterator_thread = new QAcatLayoutIteratorThread();
    connect(iterator_thread, &QAcatLayoutIteratorThread::activateLayoutItem, this, &QAcatConfirmDialog::activateLayoutItem);
    
    iterator_thread->setLayout(hbox);
    iterator_thread->start();
}

void QAcatConfirmDialog :: activateLayoutItem(int index)
{
    //qDebug() << "config button pushed";
    QLayout *layout = hbox->layout();
    if (layout)
    {
        QLayoutItem *current_item = layout->itemAt(index);
        QWidget *current_widget = current_item->widget();
        current_widget->setFocus();
    }
}
