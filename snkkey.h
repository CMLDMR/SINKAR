#ifndef SNKKEY_H
#define SNKKEY_H

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include "mongoheaders.h"
#include <QFile>
#include <QString>
#include <QFileInfo>
#include <QIODevice>
#include <QByteArray>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <fstream>


namespace SNKKey {
    static std::string dburl{"mongodb://sinkar:<sinKar><SerikBlD1926>@192.168.0.215:27018/?authSource=SINKAR"};
    static std::string db{"SINKAR"};











    static bsoncxx::types::value uploadfile(mongocxx::gridfs::bucket* bucket , std::string fileName )
    {

        QByteArray ar;

        QFile file(fileName.c_str());

        if( file.open(QIODevice::ReadOnly) )
        {
            ar = file.readAll();
            file.close();
        }
        auto uploader = bucket->open_upload_stream(fileName);

        uploader.write((std::uint8_t*)ar.data(),ar.size());

        auto res = uploader.close();

        return res.id();

    }

    static bsoncxx::types::value uploadfile(mongocxx::gridfs::bucket* bucket,QByteArray ar,std::string fileName = "AutoFileName")
    {

        auto uploader = bucket->open_upload_stream(fileName);

        uploader.write((std::uint8_t*)ar.data(),ar.size());

        auto res = uploader.close();

        return res.id();

    }

    static std::string downloadifNotExistQt(mongocxx::gridfs::bucket* Bucket,std::string oid, bool forceFilename = false){

            auto doc = bsoncxx::builder::basic::document{};

            try {
                doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{oid}));
            } catch (bsoncxx::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
                return "NULL";
            }



            mongocxx::gridfs::downloader downloader;
            try {
                auto roid = bsoncxx::types::value(doc.view()["key"].get_oid());
                downloader = Bucket->open_download_stream(roid);

            } catch (bsoncxx::exception &e) {
                return "img/error.png";
            }


            auto file_length = downloader.file_length();
            auto bytes_counter = 0;

            QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

            QString fullFilename;

            if( forceFilename )
            {
                fullFilename = QString("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
            }else{
                fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
                            .arg(downloader.files_document()["md5"].get_utf8().value.to_string().c_str());
            }

            if( QFile::exists(fullFilename) )
            {
                return fullFilename.toStdString();
            }

            auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
            auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

            std::ofstream out;

            out.open(fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


            if( out.is_open() )
            {

                while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {

                    auto bufferPtr = buffer.get();
                    std::cout << "Size Of: " << sizeof (bufferPtr) << std::endl;
                    out.write(reinterpret_cast<char*>(bufferPtr),length_read);

                    bytes_counter += static_cast<std::int32_t>( length_read );
    //                std::cout << "Downloaded: " << file_length << "/" << bytes_counter << " lengRead :" << length_read << " Buffer Size: " << buffer_size << std::endl;

                }

                out.close();
            }

            else{
                std::cout << "Error Can Not Open File: " <<fullFilename.toStdString() << std::endl;
            }

            return fullFilename.toStdString();

        }
}





#endif // SNKKEY_H
