#ifndef FMC_NAVMODE_H
#define FMC_NAVMODE_H

#include <QWidget>
#include <QTimer>
#include "defines.h"
#include "config.h"
#include "vas_widget.h"
#include "ui_fmc_navmode.h"

class FMCControl;

namespace Ui {
class fmc_navmode;
}

class fmc_navmode : public VasWidget, private Ui::fmc_navmode
{
    Q_OBJECT

public:
    fmc_navmode(FMCControl* fmc_control, QWidget *parent, Qt::WindowFlags fl);
    ~fmc_navmode();

public slots:

    void slotRnavCheckBoxTriggered();

    void slotVnavCheckBoxTriggered();

protected:

    FMCControl* m_fmc_control;

private:
    Ui::fmc_navmode *ui;
};



/////////////////////////////////////////////////

class fmc_navmodeHandler : public QObject
{
    Q_OBJECT

public:
    //! Standard Constructor
    fmc_navmodeHandler(ConfigWidgetProvider* config_widget_provider,
                         Config* main_config,
                         FMCControl* fmc_control);

    //! Destructor
    virtual ~fmc_navmodeHandler()
    {
        delete m_navdisplay;
    }

    inline void show() { m_navdisplay->show(); }
    inline void hide() { m_navdisplay->hide(); }
    inline bool isVisible() { return m_navdisplay->isVisible(); }
    inline void close() { m_navdisplay->close(); }

    fmc_navmode *fmcNavdisplay()
    {
#if VASFMC_GAUGE
        // Protect m_navdisplay from being accessed during a restart (when it might be invalid)
        QMutexLocker locker(&m_navdisplay_mutex);
#endif
        return m_navdisplay;
    }

public slots:

    void slotRestartNavdisplay()
    {
#if VASFMC_GAUGE
        QMutexLocker locker(&m_navdisplay_mutex);
#endif
        delete m_navdisplay;
        m_navdisplay = createNavdisplay();
        MYASSERT(m_navdisplay != 0);
//        MYASSERT(connect(m_navdisplay->ui->tn, SIGNAL(clicked()), this, SLOT(slotVnavCheckboxClicked())));
 //       MYASSERT(connect(m_navdisplay, SIGNAL(signalRestart()), this, SLOT(slotTriggerNavdisplayRestart())));
    }

protected slots:

    void slotTriggerNavdisplayRestart() { QTimer::singleShot(1, this, SLOT(slotRestartNavdisplay())); }

protected:

    fmc_navmode* createNavdisplay();

protected:

    ConfigWidgetProvider* m_config_widget_provider;
    Config* m_main_config;
    QString m_navdisplay_config_filename;
    QString m_tcas_config_filename;
    FMCControl* m_fmc_control;
    fmc_navmode* m_navdisplay;
#if VASFMC_GAUGE
    QMutex m_navdisplay_mutex;
#endif

    bool m_left_side;

private:
    //! Hidden copy-constructor
    fmc_navmodeHandler(const fmc_navmodeHandler&);
    //! Hidden assignment operator
    const fmc_navmodeHandler& operator = (const fmc_navmodeHandler&);
};

#endif // FMC_NAVMODE_H
