#ifndef NOTE_H
#define NOTE_H

#include <QSet>
#include <QString>

#include "Editor.h"
#include "NotesException.h"

class ExportStrategy;

class Note{
    QString title;
    QString filePath;
    bool modified;
    bool deleted;
    bool document;
    bool displayed;

public:
    Note(const QString &path);
    Note(const QString &path, const QString& ti);

    virtual ~Note(){}

    // Purement pour facilier a hirarchiser les Notes dans nm.Et puis ca sert a visualiser cette hirarchie dans QTreeView.
    virtual void addNote(Note *){throw NotesException("Should not happen! addNote called for non Document object.");}

    bool operator==(const Note& other);

    const QString &getTitle() const;
    void setTitle(QString &t);

    const QString &getFilePath() const;
    void setFilePath(const QString &p);

    void setModified(bool b);
    bool isModified() const;

    void setDeleted(bool b);
    bool isDeleted() const;

    virtual Editor *createEditor() = 0;
    virtual QString exportNote(const ExportStrategy *es, unsigned int level = 0) = 0;

    bool isDocument() const;
    void setDocument(bool value);

    bool isDisplayed() const;
    void setDisplayed(bool value);
};



#endif
