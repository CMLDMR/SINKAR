#ifndef DBUSER_H
#define DBUSER_H

#include <QtCore/qglobal.h>


#include "../snkkey.h"
#include "mongoheaders.h"

using bsoncxx::builder::basic::document;
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::array;
using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::make_array;



class DBUser
{
    mongocxx::database* db;
    bsoncxx::document::value *User;
public:
    DBUser(mongocxx::database* db, bsoncxx::document::value *_user);

    mongocxx::database *getDb() const;

    mongocxx::collection collection(QString collection) const;

    mongocxx::collection collection(std::string collection) const;

    bsoncxx::document::value *getUser() const;


    QString getPersonelName() const;

    QString getPersonelFullName() const;

private:

};

#endif // DBUSER_H
