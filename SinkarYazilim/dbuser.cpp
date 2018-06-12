#include "dbuser.h"

mongocxx::database *DBUser::getDb() const
{
    return db;
}

mongocxx::collection DBUser::collection(QString collection) const
{
    return this->db->collection(collection.toStdString());
}

mongocxx::collection DBUser::collection(std::string collection) const
{
    return this->db->collection(collection);
}



bsoncxx::document::value *DBUser::getUser() const
{
    return User;
}


QString DBUser::getPersonelName() const
{
    return QString("%1").arg(this->User->view()[SNKKey::Personel::ad].get_utf8().value.to_string().c_str());
}

QString DBUser::getPersonelFullName() const
{
    return QString("%1 %2").arg(this->User->view()[SNKKey::Personel::ad].get_utf8().value.to_string().c_str()).arg(this->User->view()[SNKKey::Personel::soyad].get_utf8().value.to_string().c_str());

}

DBUser::DBUser(mongocxx::database *db, bsoncxx::document::value *_user)
    :db(db),User(_user)
{

}
