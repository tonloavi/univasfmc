/********************************************************************************
** Form generated from reading UI file 'infodlg.ui'
**
** Created: Sun 13. Nov 19:34:45 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODLG_H
#define UI_INFODLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_InfoDlg
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *infotext;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QDialog *InfoDlg)
    {
        if (InfoDlg->objectName().isEmpty())
            InfoDlg->setObjectName(QString::fromUtf8("InfoDlg"));
        InfoDlg->resize(809, 485);
        gridLayout = new QGridLayout(InfoDlg);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        infotext = new QTextBrowser(InfoDlg);
        infotext->setObjectName(QString::fromUtf8("infotext"));

        gridLayout->addWidget(infotext, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(InfoDlg);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);


        gridLayout->addLayout(hboxLayout, 1, 0, 1, 1);


        retranslateUi(InfoDlg);
        QObject::connect(okButton, SIGNAL(clicked()), InfoDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(InfoDlg);
    } // setupUi

    void retranslateUi(QDialog *InfoDlg)
    {
        InfoDlg->setWindowTitle(QApplication::translate("InfoDlg", "Info Dialog", 0));
        okButton->setText(QApplication::translate("InfoDlg", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class InfoDlg: public Ui_InfoDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODLG_H
