#ifndef FMC_NAVMODE_H
#define FMC_NAVMODE_H

#include <QWidget>

namespace Ui {
class fmc_navmode;
}

class fmc_navmode : public QWidget
{
    Q_OBJECT

public:
    explicit fmc_navmode(QWidget *parent = 0);
    ~fmc_navmode();

private:
    Ui::fmc_navmode *ui;
};

#endif // FMC_NAVMODE_H
