#include <QLCDNumber>

class thisLCD : public QLCDNumber {
    Q_OBJECT

public:
    thisLCD(QWidget*parent);

public slots:
    void incnum();
    void resetLCD();
signals:
    
};