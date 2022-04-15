/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QPushButton *ButtonAboutBack;
    QTextEdit *AboutText;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QString::fromUtf8("about"));
        about->resize(694, 517);
        ButtonAboutBack = new QPushButton(about);
        ButtonAboutBack->setObjectName(QString::fromUtf8("ButtonAboutBack"));
        ButtonAboutBack->setGeometry(QRect(310, 270, 80, 24));
        AboutText = new QTextEdit(about);
        AboutText->setObjectName(QString::fromUtf8("AboutText"));
        AboutText->setGeometry(QRect(0, 90, 691, 171));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        AboutText->setFont(font);
        AboutText->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border: none;\n"
""));
        AboutText->setDocumentTitle(QString::fromUtf8(""));
        AboutText->setReadOnly(true);
        AboutText->setOverwriteMode(false);

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QCoreApplication::translate("about", "Dialog", nullptr));
        ButtonAboutBack->setText(QCoreApplication::translate("about", "Back", nullptr));
        AboutText->setHtml(QCoreApplication::translate("about", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Montserrat SemiBold'; font-size:12pt; font-weight:700; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">AssettoHub - \321\215\321\202\320\276 \320\277\321\200\320\276\320\265\320\272\321\202, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\277\320\276\320\267\320\262\320\276\320\273\321\217\320\265\321\202 \320\270\320\263\321\200\320\276\320\272\320\260\320\274 Assetto Corsa \320\270 Assetto Corsa Competizione \321\203\320\264\320\276\320\261\320\275\320\276 \320\276\320\261\320\274\320\265\320\275\320\270\320\262\320\260\321\202\321\214\321\201\321\217 \321\201\320\262\320\276\320\270\320\274\320\270 \320\272\320"
                        "\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\217\320\274\320\270 \320\274\320\260\321\210\320\270\320\275 \320\270 \320\276\321\206\320\265\320\275\320\270\320\262\320\260\321\202\321\214 \320\270\321\205. \320\222\320\260\320\274 \320\261\320\276\320\273\321\214\321\210\320\265 \320\275\320\265 \320\277\321\200\320\270\320\264\321\221\321\202\321\201\321\217 \320\262\321\200\321\203\321\207\320\275\321\203\321\216 \320\275\320\260\321\201\321\202\321\200\320\260\320\270\320\262\320\260\321\202\321\214 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\320\270\320\273\321\214 \320\270\320\273\320\270 \320\270\321\201\320\272\320\260\321\202\321\214 \320\270\320\275\321\202\320\265\321\200\320\265\321\201\321\203\321\216\321\211\320\270\320\265 \320\222\320\260\321\201 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276 \320\262\321\201\320\265\320\274\321\203 \320\270\320\275\321\202\320\265\321\200\320\275\320\265\321\202\321\203 "
                        "\320\277\320\276\321\202\320\276\320\274\321\203, \321\207\321\202\320\276 \321\202\320\265\320\277\320\265\321\200\321\214 \320\222\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \320\262\320\276\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217 AssettoHub!<br />\320\235\320\260\321\210 GitHub: <a href=\"https://github.com/igor2323/AssettoHub/wiki\"><span style=\" text-decoration: underline; color:#007af4;\">AssettoHub</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
