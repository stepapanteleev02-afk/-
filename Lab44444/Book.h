#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
public:
    Book(const QString& author, const QString& title,
             const QString& code, const QString& ratio,
             const QString& type, const QString& genre);
    bool saveToFile(const QString& filename) const;

private:
    QString m_author;
    QString m_title;
    QString m_code;
    QString m_ratio;
    QString m_type;
    QString m_genre;
};

#endif
