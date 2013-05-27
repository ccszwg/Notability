#include "htmlViewer.h"
#include <QTextEdit>

HtmlViewer::HtmlViewer(const QString& html, QWidget *parent) :
    QWidget(parent), ressource(html)
{
    layout = new QVBoxLayout;
    wv = new QTextEdit();
    wv->setHtml(ressource);

    layout->addWidget(wv);

    this->setLayout(layout);
}
