/********************************************************************************
** Form generated from reading UI file 'generador_de_pulsos.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERADOR_DE_PULSOS_H
#define UI_GENERADOR_DE_PULSOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Generador_de_pulsos
{
public:
    QWidget *centralWidget;
    QPushButton *Stop;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *MandarPulsos;
    QPushButton *ValoresDefault;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QComboBox *ListaPuertos;
    QRadioButton *radioButton;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *ValueN;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *ValueT;
    QSpinBox *ValueP;
    QFormLayout *formLayout_2;
    QFormLayout *formLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_23;
    QToolButton *toolButton_2;
    QToolButton *toolButton_24;
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_14;
    QToolButton *toolButton_12;
    QToolButton *toolButton_17;
    QToolButton *toolButton_18;
    QGridLayout *gridLayout;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_22;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton_21;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_7;
    QToolButton *toolButton_10;
    QToolButton *toolButton_20;
    QToolButton *toolButton_19;
    QWidget *layoutWidget4;
    QFormLayout *formLayout_3;
    QLabel *label_5;
    QComboBox *SalidaVoI;
    QComboBox *SalidaPoN;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QComboBox *ListaPuertos_2;
    QRadioButton *radioButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Generador_de_pulsos)
    {
        if (Generador_de_pulsos->objectName().isEmpty())
            Generador_de_pulsos->setObjectName(QStringLiteral("Generador_de_pulsos"));
        Generador_de_pulsos->resize(656, 478);
        centralWidget = new QWidget(Generador_de_pulsos);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(530, 330, 90, 90));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        Stop->setFont(font);
        Stop->setStyleSheet(QLatin1String("#Stop{\n"
"color:black;\n"
"background-color: red;\n"
"border-width: 3px;\n"
"border-color: gray;\n"
"border-style: outset;\n"
"border-radius: 45px;\n"
"}\n"
"#Stop:pressed{\n"
"color:black;\n"
"background-color: red;\n"
"border-width:5px;\n"
"border-color: gray;\n"
"border-style: outset;\n"
"border-radius: 45px;\n"
"}"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 340, 89, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MandarPulsos = new QPushButton(layoutWidget);
        MandarPulsos->setObjectName(QStringLiteral("MandarPulsos"));
        QFont font1;
        font1.setPointSize(12);
        MandarPulsos->setFont(font1);

        verticalLayout->addWidget(MandarPulsos);

        ValoresDefault = new QPushButton(layoutWidget);
        ValoresDefault->setObjectName(QStringLiteral("ValoresDefault"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(154, 240, 235, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(204, 247, 245, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(77, 120, 117, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(103, 160, 157, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        ValoresDefault->setPalette(palette);
        ValoresDefault->setFont(font1);
#ifndef QT_NO_WHATSTHIS
        ValoresDefault->setWhatsThis(0u);
#endif // QT_NO_WHATSTHIS

        verticalLayout->addWidget(ValoresDefault);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 120, 127, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        label_6->setFont(font2);

        verticalLayout_2->addWidget(label_6);

        ListaPuertos = new QComboBox(layoutWidget1);
        ListaPuertos->setObjectName(QStringLiteral("ListaPuertos"));

        verticalLayout_2->addWidget(ListaPuertos);

        radioButton = new QRadioButton(layoutWidget1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setFont(font1);

        verticalLayout_2->addWidget(radioButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(260, 40, 363, 271));
        gridLayout_5 = new QGridLayout(layoutWidget2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(layoutWidget2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        gridLayout_4 = new QGridLayout(layoutWidget3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(26);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout_4->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout_4->addWidget(label_3, 3, 0, 1, 1);

        splitter->addWidget(layoutWidget3);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ValueN = new QSpinBox(layoutWidget2);
        ValueN->setObjectName(QStringLiteral("ValueN"));
        QFont font3;
        font3.setPointSize(18);
        ValueN->setFont(font3);
        ValueN->setWrapping(true);
        ValueN->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ValueN->setMinimum(1);
        ValueN->setValue(5);

        verticalLayout_3->addWidget(ValueN);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setFont(font3);
        doubleSpinBox->setWrapping(true);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox->setDecimals(0);
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(85);
        doubleSpinBox->setSingleStep(1);
        doubleSpinBox->setValue(1);

        verticalLayout_3->addWidget(doubleSpinBox);

        ValueT = new QSpinBox(layoutWidget2);
        ValueT->setObjectName(QStringLiteral("ValueT"));
        ValueT->setFont(font3);
        ValueT->setWrapping(true);
        ValueT->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ValueT->setMinimum(1);
        ValueT->setMaximum(9998);
        ValueT->setValue(1);

        verticalLayout_3->addWidget(ValueT);

        ValueP = new QSpinBox(layoutWidget2);
        ValueP->setObjectName(QStringLiteral("ValueP"));
        ValueP->setFont(font3);
        ValueP->setWrapping(true);
        ValueP->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ValueP->setMinimum(2);
        ValueP->setMaximum(9999);
        ValueP->setValue(5);

        verticalLayout_3->addWidget(ValueP);


        gridLayout_5->addLayout(verticalLayout_3, 0, 1, 1, 1);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setVerticalSpacing(25);
        formLayout_2->setContentsMargins(-1, 8, -1, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        toolButton = new QToolButton(layoutWidget2);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setArrowType(Qt::UpArrow);

        formLayout->setWidget(0, QFormLayout::LabelRole, toolButton);

        toolButton_23 = new QToolButton(layoutWidget2);
        toolButton_23->setObjectName(QStringLiteral("toolButton_23"));
        toolButton_23->setArrowType(Qt::UpArrow);

        formLayout->setWidget(0, QFormLayout::FieldRole, toolButton_23);

        toolButton_2 = new QToolButton(layoutWidget2);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setArrowType(Qt::DownArrow);

        formLayout->setWidget(1, QFormLayout::LabelRole, toolButton_2);

        toolButton_24 = new QToolButton(layoutWidget2);
        toolButton_24->setObjectName(QStringLiteral("toolButton_24"));
        toolButton_24->setArrowType(Qt::DownArrow);

        formLayout->setWidget(1, QFormLayout::FieldRole, toolButton_24);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, formLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        toolButton_14 = new QToolButton(layoutWidget2);
        toolButton_14->setObjectName(QStringLiteral("toolButton_14"));
        toolButton_14->setArrowType(Qt::DownArrow);

        gridLayout_3->addWidget(toolButton_14, 1, 0, 1, 1);

        toolButton_12 = new QToolButton(layoutWidget2);
        toolButton_12->setObjectName(QStringLiteral("toolButton_12"));
        toolButton_12->setArrowType(Qt::UpArrow);

        gridLayout_3->addWidget(toolButton_12, 0, 0, 1, 1);

        toolButton_17 = new QToolButton(layoutWidget2);
        toolButton_17->setObjectName(QStringLiteral("toolButton_17"));
        toolButton_17->setArrowType(Qt::UpArrow);

        gridLayout_3->addWidget(toolButton_17, 0, 1, 1, 1);

        toolButton_18 = new QToolButton(layoutWidget2);
        toolButton_18->setObjectName(QStringLiteral("toolButton_18"));
        toolButton_18->setArrowType(Qt::DownArrow);

        gridLayout_3->addWidget(toolButton_18, 1, 1, 1, 1);


        formLayout_2->setLayout(1, QFormLayout::LabelRole, gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolButton_5 = new QToolButton(layoutWidget2);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setArrowType(Qt::UpArrow);

        gridLayout->addWidget(toolButton_5, 0, 1, 1, 1);

        toolButton_6 = new QToolButton(layoutWidget2);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setArrowType(Qt::DownArrow);

        gridLayout->addWidget(toolButton_6, 1, 1, 1, 1);

        toolButton_22 = new QToolButton(layoutWidget2);
        toolButton_22->setObjectName(QStringLiteral("toolButton_22"));
        toolButton_22->setArrowType(Qt::DownArrow);

        gridLayout->addWidget(toolButton_22, 1, 2, 1, 1);

        toolButton_4 = new QToolButton(layoutWidget2);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setArrowType(Qt::DownArrow);

        gridLayout->addWidget(toolButton_4, 1, 0, 1, 1);

        toolButton_3 = new QToolButton(layoutWidget2);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setArrowType(Qt::UpArrow);

        gridLayout->addWidget(toolButton_3, 0, 0, 1, 1);

        toolButton_21 = new QToolButton(layoutWidget2);
        toolButton_21->setObjectName(QStringLiteral("toolButton_21"));
        toolButton_21->setArrowType(Qt::UpArrow);

        gridLayout->addWidget(toolButton_21, 0, 2, 1, 1);


        formLayout_2->setLayout(2, QFormLayout::LabelRole, gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_8 = new QToolButton(layoutWidget2);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setArrowType(Qt::UpArrow);

        gridLayout_2->addWidget(toolButton_8, 0, 1, 1, 1);

        toolButton_9 = new QToolButton(layoutWidget2);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setArrowType(Qt::DownArrow);

        gridLayout_2->addWidget(toolButton_9, 1, 0, 1, 1);

        toolButton_7 = new QToolButton(layoutWidget2);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setArrowType(Qt::UpArrow);

        gridLayout_2->addWidget(toolButton_7, 0, 0, 1, 1);

        toolButton_10 = new QToolButton(layoutWidget2);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        toolButton_10->setArrowType(Qt::DownArrow);

        gridLayout_2->addWidget(toolButton_10, 1, 1, 1, 1);

        toolButton_20 = new QToolButton(layoutWidget2);
        toolButton_20->setObjectName(QStringLiteral("toolButton_20"));
        toolButton_20->setArrowType(Qt::DownArrow);

        gridLayout_2->addWidget(toolButton_20, 1, 2, 1, 1);

        toolButton_19 = new QToolButton(layoutWidget2);
        toolButton_19->setObjectName(QStringLiteral("toolButton_19"));
        toolButton_19->setArrowType(Qt::UpArrow);

        gridLayout_2->addWidget(toolButton_19, 0, 2, 1, 1);


        formLayout_2->setLayout(3, QFormLayout::LabelRole, gridLayout_2);


        gridLayout_5->addLayout(formLayout_2, 0, 2, 1, 1);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 220, 165, 106));
        formLayout_3 = new QFormLayout(layoutWidget4);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setVerticalSpacing(19);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_5);

        SalidaVoI = new QComboBox(layoutWidget4);
        SalidaVoI->setObjectName(QStringLiteral("SalidaVoI"));
        SalidaVoI->setFont(font2);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, SalidaVoI);

        SalidaPoN = new QComboBox(layoutWidget4);
        SalidaPoN->setObjectName(QStringLiteral("SalidaPoN"));
        SalidaPoN->setFont(font2);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, SalidaPoN);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 20, 133, 81));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        verticalLayout_4->addWidget(label_7);

        ListaPuertos_2 = new QComboBox(layoutWidget_2);
        ListaPuertos_2->setObjectName(QStringLiteral("ListaPuertos_2"));

        verticalLayout_4->addWidget(ListaPuertos_2);

        radioButton_2 = new QRadioButton(layoutWidget_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setFont(font1);

        verticalLayout_4->addWidget(radioButton_2);

        Generador_de_pulsos->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        Stop->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();
        menuBar = new QMenuBar(Generador_de_pulsos);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 21));
        Generador_de_pulsos->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Generador_de_pulsos);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Generador_de_pulsos->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Generador_de_pulsos);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Generador_de_pulsos->setStatusBar(statusBar);

        retranslateUi(Generador_de_pulsos);

        SalidaVoI->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Generador_de_pulsos);
    } // setupUi

    void retranslateUi(QMainWindow *Generador_de_pulsos)
    {
        Generador_de_pulsos->setWindowTitle(QApplication::translate("Generador_de_pulsos", "Generador_de_pulsos", 0));
#ifndef QT_NO_TOOLTIP
        Stop->setToolTip(QApplication::translate("Generador_de_pulsos", "<html><head/><body><p><span style=\" color:#ff0000;\"><br/></span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Stop->setText(QApplication::translate("Generador_de_pulsos", "STOP", 0));
        MandarPulsos->setText(QApplication::translate("Generador_de_pulsos", "Estimular", 0));
        ValoresDefault->setText(QApplication::translate("Generador_de_pulsos", "Withdrawal\n"
"Reflex", 0));
        label_6->setText(QApplication::translate("Generador_de_pulsos", "Puerto de Salida :", 0));
        radioButton->setText(QApplication::translate("Generador_de_pulsos", "Abrir Puerto", 0));
        label->setText(QApplication::translate("Generador_de_pulsos", "    N\302\272 de pulsos", 0));
        label_4->setText(QApplication::translate("Generador_de_pulsos", "Amplitud de pulso", 0));
        label_2->setText(QApplication::translate("Generador_de_pulsos", "Duraci\303\263n del pulso", 0));
        label_3->setText(QApplication::translate("Generador_de_pulsos", "         Per\303\255odo", 0));
        ValueN->setSuffix(QApplication::translate("Generador_de_pulsos", " pulsos", 0));
        doubleSpinBox->setSuffix(QApplication::translate("Generador_de_pulsos", " mA", 0));
        ValueT->setSuffix(QApplication::translate("Generador_de_pulsos", " ms", 0));
        ValueP->setSuffix(QApplication::translate("Generador_de_pulsos", " ms", 0));
        toolButton->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_23->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_2->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_24->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_14->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_12->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_17->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_18->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_5->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_6->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_22->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_4->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_3->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_21->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_8->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_9->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_7->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_10->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_20->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        toolButton_19->setText(QApplication::translate("Generador_de_pulsos", "...", 0));
        label_5->setText(QApplication::translate("Generador_de_pulsos", "Tipo de Estimulaci\303\263n:", 0));
        SalidaVoI->clear();
        SalidaVoI->insertItems(0, QStringList()
         << QApplication::translate("Generador_de_pulsos", "Salida en corriente", 0)
         << QApplication::translate("Generador_de_pulsos", "Salida en tensi\303\263n", 0)
        );
        SalidaPoN->clear();
        SalidaPoN->insertItems(0, QStringList()
         << QApplication::translate("Generador_de_pulsos", "Pulsos positivos", 0)
         << QApplication::translate("Generador_de_pulsos", "Pulsos negativos", 0)
        );
        label_7->setText(QApplication::translate("Generador_de_pulsos", "Puerto de Entrada:", 0));
        radioButton_2->setText(QApplication::translate("Generador_de_pulsos", "Abrir Puerto", 0));
    } // retranslateUi

};

namespace Ui {
    class Generador_de_pulsos: public Ui_Generador_de_pulsos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERADOR_DE_PULSOS_H
