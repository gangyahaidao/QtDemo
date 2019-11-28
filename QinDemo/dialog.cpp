#include "dialog.h"
#include <QGridLayout>
#include <QFile>
#include <QTextStream>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    label1=new QLabel(this);
    label1->setText(tr("请输入签章密码："));
    lineEdit=new QLineEdit(this);
    lineEdit->setEchoMode(QLineEdit::Password);
    label2=new QLabel(this);
    button=new QPushButton(this);
    button->setText(tr("确定"));
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);
    connect(button,SIGNAL(clicked()),this,SLOT(savePasswordQuit()));
    //connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));
}

Dialog::~Dialog()
{

}

void Dialog::savePasswordQuit()
{
    QString valueStr=lineEdit->text();
    if(valueStr == "111111") {
        // 保存密码到文本并退出
        QFile myfile("/opt/suwell/Reader_Pro/plugins/seal/Suwell/password");
        if (myfile.open(QFile::WriteOnly|QFile::Truncate)) {
            QTextStream out(&myfile);
            out<<valueStr<<endl;
        }
        this->close(); // 关闭窗口
    }
}
