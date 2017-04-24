#include "fmc_navmode.h"
#include "ui_fmc_navmode.h"
#include "fmc_control.h"

fmc_navmode::fmc_navmode(FMCControl *fmc_control, QWidget *parent, Qt::WindowFlags fl) :
    VasWidget(parent, fl),
    ui(new Ui::fmc_navmode), m_fmc_control(fmc_control)
{
    ui->setupUi(this);
//    MYASSERT(connect(rnavChackBox, SIGNAL(clicked()), this, SLOT(slotRnavCheckBoxTriggered())));
    MYASSERT(connect(vnavCheckBox, SIGNAL(clicked()), this, SLOT(slotVnavCheckBoxTriggered())));
}


fmc_navmode::~fmc_navmode()
{
    delete ui;
}

//void fmc_navmode::slotRnavCheckBoxTriggered() {
//    m_fmc_control->setRnavMode(rnavChackBox->isChecked());
//}

//void fmc_navmode::slotVnavCheckBoxTriggered() {
//    m_fmc_control->setVnavMode(vnavCheckBox->isChecked());
//}

///////////////////////////////////////////////////

fmc_navmodeHandler::fmc_navmodeHandler(ConfigWidgetProvider* config_widget_provider,
                                           Config* main_config,
                                           FMCControl* fmc_control) :
    m_config_widget_provider(config_widget_provider),
    m_main_config(main_config), m_fmc_control(fmc_control), m_navdisplay(0)
{

    slotRestartNavdisplay();

#if !VASFMC_GAUGE

    if (m_main_config->getIntValue(CFG_STARTUP_COUNTER) < 10 && m_left_side)
    {
        QMessageBox::information(m_navdisplay, "...vasFMC alpha testing...",
                                 "This is an alpha testing version of vasFMC.\n"
                                 "Please post any positive or negative feedback\n"
                                 "to our forum at:\n\n"
                                 "-> http://www.vas-project.org <-\n\n"
                                 "Thank you!");

        QMessageBox::information(m_navdisplay, "...donation...",
                                 "vasFMC is open source and freeware.\n"
                                 "However, if you would like to support \n"
                                 "us in developing this great software,\n"
                                 "please consider to donate via the\n"
                                 "donation system on the VAS project homepage.\n"
                                     "\n"
                                 "-> http://www.vas-project.org <-\n\n"
                                 "Thank you!");
    }
#endif
}

/////////////////////////////////////////////////////////////////////////////

fmc_navmode* fmc_navmodeHandler::createNavdisplay()
{
#if !VASFMC_GAUGE
    if (m_fmc_control->doKeepOnTop())
        return new fmc_navmode(m_fmc_control, 0, Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    else
#endif
        return new fmc_navmode(m_fmc_control, 0, 0);
}
