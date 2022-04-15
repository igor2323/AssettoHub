/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *loginInput;
    QLineEdit *passwordInput;
    QVBoxLayout *verticalLayout;
    QPushButton *authEnterButton;
    QPushButton *regEnterButton;
    QLabel *authLabel;
    QLabel *regLabel;
    QPushButton *authRegButton;
    QPushButton *regLoginButton;

    void setupUi(QDialog *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName(QString::fromUtf8("AuthWindow"));
        AuthWindow->resize(400, 300);
        verticalLayoutWidget_3 = new QWidget(AuthWindow);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(120, 30, 160, 240));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        loginInput = new QLineEdit(verticalLayoutWidget_3);
        loginInput->setObjectName(QString::fromUtf8("loginInput"));

        verticalLayout_2->addWidget(loginInput);

        passwordInput = new QLineEdit(verticalLayoutWidget_3);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));

        verticalLayout_2->addWidget(passwordInput);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        authEnterButton = new QPushButton(verticalLayoutWidget_3);
        authEnterButton->setObjectName(QString::fromUtf8("authEnterButton"));

        verticalLayout->addWidget(authEnterButton);

        regEnterButton = new QPushButton(verticalLayoutWidget_3);
        regEnterButton->setObjectName(QString::fromUtf8("regEnterButton"));

        verticalLayout->addWidget(regEnterButton);

        authLabel = new QLabel(verticalLayoutWidget_3);
        authLabel->setObjectName(QString::fromUtf8("authLabel"));
        authLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(authLabel);

        regLabel = new QLabel(verticalLayoutWidget_3);
        regLabel->setObjectName(QString::fromUtf8("regLabel"));
        regLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(regLabel);

        authRegButton = new QPushButton(verticalLayoutWidget_3);
        authRegButton->setObjectName(QString::fromUtf8("authRegButton"));

        verticalLayout->addWidget(authRegButton);

        regLoginButton = new QPushButton(verticalLayoutWidget_3);
        regLoginButton->setObjectName(QString::fromUtf8("regLoginButton"));

        verticalLayout->addWidget(regLoginButton);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QDialog *AuthWindow)
    {
        AuthWindow->setWindowTitle(QCoreApplication::translate("AuthWindow", "Dialog", nullptr));
        loginInput->setPlaceholderText(QCoreApplication::translate("AuthWindow", "Login", nullptr));
        passwordInput->setPlaceholderText(QCoreApplication::translate("AuthWindow", "Password", nullptr));
        authEnterButton->setText(QCoreApplication::translate("AuthWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        regEnterButton->setText(QCoreApplication::translate("AuthWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        authLabel->setText(QCoreApplication::translate("AuthWindow", "\320\225\321\211\320\265 \320\275\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260?", nullptr));
        regLabel->setText(QCoreApplication::translate("AuthWindow", "\320\243\320\266\320\265 \320\265\321\201\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202?", nullptr));
        authRegButton->setText(QCoreApplication::translate("AuthWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        regLoginButton->setText(QCoreApplication::translate("AuthWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
