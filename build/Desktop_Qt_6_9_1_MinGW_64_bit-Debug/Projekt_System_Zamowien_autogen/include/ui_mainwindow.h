/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageHome;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonHelp;
    QHBoxLayout *LayoutPrzyciskiStoliki;
    QVBoxLayout *LayoutStolikicz1;
    QSpacerItem *verticalSpacer_3;
    QPushButton *buttonStolik1;
    QPushButton *buttonStolik2;
    QPushButton *buttonStolik3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *LayoutStolikicz2;
    QSpacerItem *verticalSpacer_5;
    QPushButton *buttonStolik4;
    QPushButton *buttonStolik5;
    QPushButton *buttonStolik6;
    QSpacerItem *verticalSpacer_4;
    QWidget *pageStolik1;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_8;
    QPushButton *btnDodajZamowienie;
    QPushButton *btnModyfikujZamowienie;
    QPushButton *btnUsunZamowienie;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QTextEdit *txtAktualneZamowienie;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonBackStolik1;
    QWidget *pageHelp;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textEdit;
    QPushButton *buttonBack;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        pageHome = new QWidget();
        pageHome->setObjectName("pageHome");
        verticalLayout_6 = new QVBoxLayout(pageHome);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout_6->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(10, 10, 10, 0);
        label = new QLabel(pageHome);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 60));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setFrameShape(QFrame::Shape::NoFrame);
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/krzys/Downloads/images.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonHelp = new QPushButton(pageHome);
        buttonHelp->setObjectName("buttonHelp");
        buttonHelp->setMinimumSize(QSize(80, 40));
        buttonHelp->setMaximumSize(QSize(300, 40));

        horizontalLayout->addWidget(buttonHelp);


        verticalLayout_6->addLayout(horizontalLayout);

        LayoutPrzyciskiStoliki = new QHBoxLayout();
        LayoutPrzyciskiStoliki->setObjectName("LayoutPrzyciskiStoliki");
        LayoutPrzyciskiStoliki->setContentsMargins(-1, -1, 0, -1);
        LayoutStolikicz1 = new QVBoxLayout();
        LayoutStolikicz1->setSpacing(20);
        LayoutStolikicz1->setObjectName("LayoutStolikicz1");
        LayoutStolikicz1->setContentsMargins(50, -1, 50, -1);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        LayoutStolikicz1->addItem(verticalSpacer_3);

        buttonStolik1 = new QPushButton(pageHome);
        buttonStolik1->setObjectName("buttonStolik1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonStolik1->sizePolicy().hasHeightForWidth());
        buttonStolik1->setSizePolicy(sizePolicy1);
        buttonStolik1->setMinimumSize(QSize(100, 40));
        buttonStolik1->setMaximumSize(QSize(400, 40));
        buttonStolik1->setAutoFillBackground(false);
        buttonStolik1->setCheckable(false);

        LayoutStolikicz1->addWidget(buttonStolik1);

        buttonStolik2 = new QPushButton(pageHome);
        buttonStolik2->setObjectName("buttonStolik2");
        buttonStolik2->setMinimumSize(QSize(100, 40));
        buttonStolik2->setMaximumSize(QSize(400, 40));

        LayoutStolikicz1->addWidget(buttonStolik2);

        buttonStolik3 = new QPushButton(pageHome);
        buttonStolik3->setObjectName("buttonStolik3");
        buttonStolik3->setMinimumSize(QSize(100, 40));
        buttonStolik3->setMaximumSize(QSize(400, 40));

        LayoutStolikicz1->addWidget(buttonStolik3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        LayoutStolikicz1->addItem(verticalSpacer_2);


        LayoutPrzyciskiStoliki->addLayout(LayoutStolikicz1);

        LayoutStolikicz2 = new QVBoxLayout();
        LayoutStolikicz2->setSpacing(20);
        LayoutStolikicz2->setObjectName("LayoutStolikicz2");
        LayoutStolikicz2->setContentsMargins(50, -1, 50, -1);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        LayoutStolikicz2->addItem(verticalSpacer_5);

        buttonStolik4 = new QPushButton(pageHome);
        buttonStolik4->setObjectName("buttonStolik4");
        buttonStolik4->setMinimumSize(QSize(100, 40));
        buttonStolik4->setMaximumSize(QSize(400, 40));

        LayoutStolikicz2->addWidget(buttonStolik4);

        buttonStolik5 = new QPushButton(pageHome);
        buttonStolik5->setObjectName("buttonStolik5");
        buttonStolik5->setMinimumSize(QSize(100, 40));
        buttonStolik5->setMaximumSize(QSize(400, 40));

        LayoutStolikicz2->addWidget(buttonStolik5);

        buttonStolik6 = new QPushButton(pageHome);
        buttonStolik6->setObjectName("buttonStolik6");
        buttonStolik6->setMinimumSize(QSize(100, 40));
        buttonStolik6->setMaximumSize(QSize(400, 40));

        LayoutStolikicz2->addWidget(buttonStolik6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        LayoutStolikicz2->addItem(verticalSpacer_4);


        LayoutPrzyciskiStoliki->addLayout(LayoutStolikicz2);

        LayoutPrzyciskiStoliki->setStretch(0, 1);
        LayoutPrzyciskiStoliki->setStretch(1, 1);

        verticalLayout_6->addLayout(LayoutPrzyciskiStoliki);

        stackedWidget->addWidget(pageHome);
        pageStolik1 = new QWidget();
        pageStolik1->setObjectName("pageStolik1");
        verticalLayout_8 = new QVBoxLayout(pageStolik1);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        label_2 = new QLabel(pageStolik1);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(60, 30));
        label_2->setMaximumSize(QSize(150, 50));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_2->setFont(font);

        verticalLayout_7->addWidget(label_2, 0, Qt::AlignmentFlag::AlignHCenter);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_8);

        btnDodajZamowienie = new QPushButton(pageStolik1);
        btnDodajZamowienie->setObjectName("btnDodajZamowienie");
        btnDodajZamowienie->setMinimumSize(QSize(150, 30));
        btnDodajZamowienie->setMaximumSize(QSize(300, 40));

        verticalLayout_7->addWidget(btnDodajZamowienie, 0, Qt::AlignmentFlag::AlignHCenter);

        btnModyfikujZamowienie = new QPushButton(pageStolik1);
        btnModyfikujZamowienie->setObjectName("btnModyfikujZamowienie");
        btnModyfikujZamowienie->setMinimumSize(QSize(150, 30));
        btnModyfikujZamowienie->setMaximumSize(QSize(300, 40));

        verticalLayout_7->addWidget(btnModyfikujZamowienie, 0, Qt::AlignmentFlag::AlignHCenter);

        btnUsunZamowienie = new QPushButton(pageStolik1);
        btnUsunZamowienie->setObjectName("btnUsunZamowienie");
        btnUsunZamowienie->setMinimumSize(QSize(150, 30));
        btnUsunZamowienie->setMaximumSize(QSize(300, 40));

        verticalLayout_7->addWidget(btnUsunZamowienie, 0, Qt::AlignmentFlag::AlignHCenter);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_3 = new QLabel(pageStolik1);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(180, 60));
        label_3->setMaximumSize(QSize(180, 60));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label_3->setFont(font1);

        verticalLayout_10->addWidget(label_3, 0, Qt::AlignmentFlag::AlignHCenter);

        txtAktualneZamowienie = new QTextEdit(pageStolik1);
        txtAktualneZamowienie->setObjectName("txtAktualneZamowienie");
        txtAktualneZamowienie->setReadOnly(true);

        verticalLayout_10->addWidget(txtAktualneZamowienie);

        verticalLayout_10->setStretch(0, 1);
        verticalLayout_10->setStretch(1, 4);

        horizontalLayout_2->addLayout(verticalLayout_10);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        buttonBackStolik1 = new QPushButton(pageStolik1);
        buttonBackStolik1->setObjectName("buttonBackStolik1");
        buttonBackStolik1->setMinimumSize(QSize(100, 30));
        buttonBackStolik1->setMaximumSize(QSize(300, 40));

        verticalLayout_9->addWidget(buttonBackStolik1, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_8->addLayout(verticalLayout_9);

        verticalLayout_8->setStretch(0, 4);
        verticalLayout_8->setStretch(1, 1);
        stackedWidget->addWidget(pageStolik1);
        pageHelp = new QWidget();
        pageHelp->setObjectName("pageHelp");
        verticalLayout_5 = new QVBoxLayout(pageHelp);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        textEdit = new QTextEdit(pageHelp);
        textEdit->setObjectName("textEdit");
        textEdit->setLineWrapColumnOrWidth(0);
        textEdit->setReadOnly(true);

        verticalLayout_4->addWidget(textEdit);

        buttonBack = new QPushButton(pageHelp);
        buttonBack->setObjectName("buttonBack");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBack->sizePolicy().hasHeightForWidth());
        buttonBack->setSizePolicy(sizePolicy2);
        buttonBack->setMinimumSize(QSize(100, 30));
        buttonBack->setMaximumSize(QSize(300, 40));

        verticalLayout_4->addWidget(buttonBack, 0, Qt::AlignmentFlag::AlignHCenter);


        verticalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(verticalLayout_3);

        stackedWidget->addWidget(pageHelp);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        buttonHelp->setText(QCoreApplication::translate("MainWindow", "Pomoc", nullptr));
        buttonStolik1->setText(QCoreApplication::translate("MainWindow", "Stolik 1", nullptr));
        buttonStolik2->setText(QCoreApplication::translate("MainWindow", "Stolik 2", nullptr));
        buttonStolik3->setText(QCoreApplication::translate("MainWindow", "Stolik 3", nullptr));
        buttonStolik4->setText(QCoreApplication::translate("MainWindow", "Stolik 4", nullptr));
        buttonStolik5->setText(QCoreApplication::translate("MainWindow", "Stolik 5", nullptr));
        buttonStolik6->setText(QCoreApplication::translate("MainWindow", "Stolik 6", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "STOLIK NR", nullptr));
        btnDodajZamowienie->setText(QCoreApplication::translate("MainWindow", "Dodaj zam\303\263wienie", nullptr));
        btnModyfikujZamowienie->setText(QCoreApplication::translate("MainWindow", "Modyfikuj zam\303\263wienie", nullptr));
        btnUsunZamowienie->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 zam\303\263wienie", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Aktualne Zam\303\263wienie:", nullptr));
        buttonBackStolik1->setText(QCoreApplication::translate("MainWindow", "Powr\303\263t", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Instrukcja programu:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. Wybierz jeden z dost\304\231pnych w widoku stolik\303\263w poprzez klikni\304\231cie w przycisk</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px;\">2. Dodaj zam\303\263wienie za pomoc\304\205 przycisku Dodaj zam\303\263wienie</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. Modyfikuj zam\303\263wienie za pomoc\304\205 przycisku Modyfikuj zam\303\263wienie</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. Usu\305\204 zam\303\263wienie za pomoc\304\205 przycisku Usu\305\204 zam\303\263wienie</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; "
                        "font-style:italic; text-decoration: underline;\">PROJEKT WYKONANY NA ZALICZENIE PRZEDMIOTU: PROGRAMOWANIE 2</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic; text-decoration: underline;\">POLITECHNIKA \305\232L\304\204SKA, GLIWICE</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-style:italic; text-decoration: underline;\">Wykonali: Jakub Zbojak, Jakub Tworkowski, Krzysztof Moros</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        buttonBack->setText(QCoreApplication::translate("MainWindow", "Powr\303\263t", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
