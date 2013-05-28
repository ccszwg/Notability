#include "HtmlExport.h"
#include "Note.h"
#include "ImageNote.h"
#include "Article.h"
#include "VideoNote.h"
#include "AudioNote.h"
#include "Document.h"
#include "ExportStrategy.h"

//Html Export
QString HtmlExport::header() const
{
    return "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd\">"
            "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
            "p, li { white-space: pre-wrap; }"
            "</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">";
}

QString HtmlExport::footer() const
{
    return "</body></html>";
}

QString HtmlExport::exportNote(const ImageNote *note, unsigned int level) const
{
    QString str;
    // Shoud implement a limit on margin...TODO
    int margin = level * 10;
    int titleSize = (level > 5) ? 5 : level;

    str+= "<div style=\"margin-left:"+QString::number(margin)+"px\";>";
    str+="<h"+QString::number(titleSize+1)+">"+note->getTitle()+ \
            "</h"+QString::number(titleSize+1)+"><p><img style=\"width: 100% margin:\" src=\""+note->getMediaPath()+"\"></p><p>"\
            +note->getDescription()+"</p></div>";
    return str;
}

QString HtmlExport::exportNote(const Article *note, unsigned int level) const
{
    QString str;
    // Shoud implement a limit on margin...TODO
    int margin = level * 10;
    int titleSize = (level > 5) ? 5 : level;

    str+= "<div style=\"margin-left:"+QString::number(margin)+"px\";>";
    str+="<h"+QString::number(titleSize+1)+">"+note->getTitle()+ \
            "</h"+QString::number(titleSize+1)+"><p>"+note->getText()+"</p></div>";
    return str;
}

QString HtmlExport::exportNote(const AudioNote *note, unsigned int level) const
{
    QString str;
    // Shoud implement a limit on margin...TODO
    int margin = level * 10;
    int titleSize = (level > 5) ? 5 : level;

    str+= "<div style=\"margin-left:"+QString::number(margin)+"px\";>";
    str+="<h"+QString::number(titleSize+1)+">"+note->getTitle()+ \
            "</h"+QString::number(titleSize+1)+"><p>"+"@TODO"+note->getDescription()+"</p></div>";
    return str;
}

QString HtmlExport::exportNote(const VideoNote *note, unsigned int level) const
{
    QString str;
    // Shoud implement a limit on margin...TODO
    int margin = level * 10;
    int titleSize = (level > 5) ? 5 : level;

    str+= "<div style=\"margin-left:"+QString::number(margin)+"px\";>";
    str+="<h"+QString::number(titleSize+1)+">"+note->getTitle()+ \
            "</h"+QString::number(titleSize+1)+"><p>"+"@TODO"+note->getDescription()+"</p></div>";
    return str;
}

QString HtmlExport::exportNote(const Document *doc, unsigned int level) const
{
    QString str;
    str="<h1>"+doc->getTitle()+"</h1>";
    ++level;
    for(QList<Note *>::const_iterator it = doc->begin(); it!=doc->end(); it++)
    {
        str+=(*it)->exportNote(this, level);
    }
    return str;
}