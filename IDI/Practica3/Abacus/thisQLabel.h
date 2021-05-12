#include <QLabel>

class thisQLabel : public QLabel {
    Q_OBJECT

public:
    thisQLabel(QWidget*parent);

public slots:
    void increment();
    void reset();
signals:
    void overflow();
};
