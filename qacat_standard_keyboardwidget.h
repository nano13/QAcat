
#include <QtWidgets>

class QAcatStandardKeyboardWidget : public QWidget
{
    Q_OBJECT
    
public:
    QAcatStandardKeyboardWidget(QWidget *parent = 0);
    
private:
    QGridLayout *grid;
    QStringList layout_list;
    
    
private slots:
    
    
signals:
    
    
};
