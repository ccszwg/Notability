#ifndef HTMLVIEWER_H
#define HTMLVIEWER_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

class HtmlViewer : public QWidget
{
    Q_OBJECT
public:
    explicit HtmlViewer(const QString &, QWidget *parent = 0);
    
signals:
    
public slots:
private:
    QVBoxLayout *layout;
    QTextEdit *wv;
    const QString &ressource;
};

#endif // HTMLVIEWER_H
