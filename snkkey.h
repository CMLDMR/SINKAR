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



#define TEST

namespace SNKKey {


    static std::string dburl{"mongodb://sinkar:sinKarSerikBlD1926@195.175.200.2:41112/?authSource=SINKAR"};
    static std::string dbresturl{"mongodb://restClarified_eees-s_d:restClarified_eees-s_d@195.175.200.2:41112/?authSource=REST"};
    static std::string db{"SINKAR"};
    static std::string dbrest{"REST"};

    static std::string oid{"_id"};


    namespace Personel {
        static std::string collection{"Personel"};
        static std::string ad{"Ad"};
        static std::string soyad{"Soyad"};
        static std::string username{"Kullanıcı Adı"};
        static std::string pasword{"Şifre"};
        static std::string oid{"_id"};
    }

    namespace Depo {
        static std::string collection{"Depolar"};
        static std::string depoAdi{"Depoadi"};
        static std::string oid{"_id"};
    }


    namespace Kategoriler
    {
        static std::string collection{"Kategoriler"};
        static std::string adi{"adi"};
        static std::string oid{"_id"};
    }


    namespace Malzeme {
        static std::string collection{"Malzeme"};
        static std::string adi{"adi"};
        static std::string birimi{"birimi"};
        static std::string kdv{"kdv"};
        static std::string oid{"_id"};
        static std::string fiyat{"fiyat"};
        static std::string kategorioid{"kategorioid"};
    }

    namespace Recete {
        namespace Recete {
            static std::string collection{"Recete"};
            static std::string adi{"adi"};
            static std::string birimi{"birimi"};
            static std::string kdv{"kdv"};
            static std::string oid{"_id"};
            static std::string malzeme{"malzemeler"};
            static std::string kar{"kar"};
            static std::string kategori{"kategori"};
            namespace Malzemeler {
                static std::string oid{"malzemeid"};
                static std::string miktar{"miktar"};
            }
            static std::string deleted{"deleted"};
            namespace Delete {
                static bool deleted{true};
                static bool exist{false};
            }
            static std::string indirimliKar{"indirimliKar"};
        }

        namespace Kategori {
            static std::string collection{"ReceteKategori"};
            static std::string adi{"adi"};
            static std::string oid{"_id"};
        }

    }


    namespace MGirisi {
        static std::string collection{"mgirisi"};
        static std::string oid{"_id"};
        static std::string malzemeoid{"malzemeOid"};
        static std::string malzemeadi{"malzemeAdi"};
        static std::string kategroiOid{"kategoriOid"};
        static std::string kategori{"kategori"};
        static std::string depo{"depo"};
        static std::string miktar{"miktar"};
        static std::string birimi{"birimi"};
        static std::string birimFiyat{"birimFiyat"};
        static std::string toplamTutar{"toplamTutar"};
        static std::string iskontoindirim{"iskontoindirim"};
        static std::string kdv{"kdv"};
        static std::string fatura{"fatura"};
        static std::string girisTipi{"girisTipi"};
        const static std::string julianDate{"julianDate"};
        namespace GirisTipi {
            static std::string malzemeGirisi{"malzemegirisi"};
            static std::string sevk{"sevk"};
        }
        namespace Fatura {
            static std::string seri{"seri"};
            static std::string no{"no"};
            static std::string tarih{"tarih"};
            static std::string tipi{"tipi"};
            static std::string firmaoid{"firmaoid"};
            static std::string firmaCarikod{"firmacariKod"};
            static std::string firmaadi{"firmaAdi"};
        }
    }


    namespace Firma {
        static std::string collection{"firmalar"};
        static std::string adi{"adi"};
        static std::string carikod{"carikod"};
        static std::string oid{"_id"};
    }


    namespace StokMiktar {
        static std::string collection{"stokmiktari"};
        static std::string adi{"adi"};
        static std::string miktar{"mitar"};
        static std::string birim{"birim"};
        static std::string depo{"depo"};
        static std::string malzemeoid{"malzemeoid"};
    }

    namespace SevkFisi {
        static std::string collection{"sevkler"};
        static std::string kaynakDepo{"kaynakDepo"};
        static std::string hedefDepo{"hedefDepo"};
        static std::string tarih{"tarih"};
        static std::string sevkno{"sevkno"};
        static std::string malzemeler{"malzemeler"};
        static std::string oid{"_id"};
        namespace Malzeme {
            static std::string adi{"adi"};
            static std::string miktar{"miktar"};
            static std::string birim{"birim"};
            static std::string fiyat{"fiyat"};
        }
    }


    namespace Kasa {
        static std::string depooid{"depooid"};
        static std::string ad{"ad"};
        static std::string oid{"_id"};
        static std::string collection{"Kasa"};
    }

    namespace Masa {
        static std::string kasaoid{"kasaoid"};
        static std::string ad{"ad"};
        static std::string siparisoid{"siparioid"};
        static std::string oid{"_id"};
        static std::string collection{"Masa"};
        static std::string durum{"durum"};
        namespace masaDurum {
            static std::string kullanimda{"Kullanımda"};
            static std::string kullanimdadegil{"Kullanımda Değil"};
        }


    }

    namespace Siparis {
        static std::string collection{"siparis"};
        namespace siparisList {
            static std::string receteoid{"receteoid"};
            static std::string miktar{"miktar"};
            static std::string index{"index"};
        }
        static std::string masaoid{"masaoid"};
        static std::string siparis{"siparis"};
        static std::string kasaoid{"kasaoid"};
        static std::string tarih{"tarih"};
        static std::string saat{"saat"};
        static std::string host{"host"};

        static std::string hesap{"hesap"};
        namespace Hesap {
            static bool kapali{true};
            static bool acik{false};
        }

        namespace Odeme {
            static std::string nakit{"nakit"};
            static std::string kredikarti{"krediKarti"};
            static std::string odenen{"odenen"};
            static std::string personeloid{"personeloid"};
            static std::string odemeTarih{"odemeTarih"};
            static std::string odemeSaat{"odemeSaat"};
        }

    }



    namespace Cari {
        namespace Kisiler {
            static std::string collection{"Kisiler"};
            static std::string ad{"ad"};
            static std::string adres{"adres"};
            static std::string iletisim{"iletisim"};
        }

        namespace Hesap {
            static std::string collection{"cariHesap"};
            static std::string kisioid{"kisiOid"};
            static std::string miktar{"miktar"};

            static std::string indirim{"indirim"};
            namespace INDIRIM {
                static bool var{true};
                static bool yok{false};
            }

            static std::string julianDate{"julianDate"};
            static std::string saat{"saat"};
            static std::string odeme{"odeme"};
            namespace Odeme {
                static bool odendi{true};
                static bool odenmedi{false};
            }
            static std::string odemeJulianDate{"odemejulianDate"};
            static std::string odemeSaat{"odemeSaat"};
            static std::string odemeMiktari{"odemeMiktari"};
            static std::string odemeMiktariNakit{"odemeMiktariNakit"};
            static std::string odemeMiktariKredi{"odemeMiktariKredi"};
            static std::string odemeTipi{"odemeTipi"};
            namespace ODEMETIPI {
                static std::string nakit{"nakit"};
                static std::string krediKarti{"krediKarti"};
                static std::string karisik{"Karisik"};
            }
            const static std::string siparisList{"siparisList"};
            namespace SIPARISLIST {
                const static std::string receteoid{"receteoid"};
                const static std::string miktar{"miktar"};
                const static std::string index{"index"};
            }
            const static std::string kasaoid{"kasaoid"};
        }
    }


    namespace HariciGider {
        namespace Kategori {
            const static std::string kategoriName{"KategoriAdi"};
            const static std::string collection{"GiderKategori"};
        }

        namespace Gider {
            const static std::string collection{"HariciGidercollect"};
            const static std::string adi{"adi"};
            const static std::string julianDate{"julianDate"};
            const static std::string miktar{"miktar"};
            const static std::string kategorioid{"kategoriOid"};
        }
    }







    static bsoncxx::types::value uploadfile(mongocxx::gridfs::bucket* bucket,QString filepath )
    {
        QFile file( filepath );
        if( file.open(QIODevice::ReadWrite) )
        {
            QFileInfo info(filepath);
            auto uploader = bucket->open_upload_stream(info.fileName().toStdString().c_str());
            QByteArray ar = file.readAll();
            uploader.write((std::uint8_t*)ar.data(),ar.size());
            auto res = uploader.close();
            file.close();
            return res.id();
        }
    }




    static bsoncxx::types::value uploadfile(mongocxx::gridfs::bucket* bucket,QByteArray ar,std::string fileName = "AutoFileName")
    {
        auto uploader = bucket->open_upload_stream(fileName);
        uploader.write((std::uint8_t*)ar.data(),ar.size());
        auto res = uploader.close();
        return res.id();
    }



    static std::string downloadifNotExist(mongocxx::gridfs::bucket* Bucket,std::string oid, bool forceFilename = false)
    {




        if( QFile::exists( QString("docroot/tempfile/%1.indexed").arg(oid.c_str()) ) )
        {
            std::cout << "FILE FOUND" << QString("tempfile/%1.indexed").arg(oid.c_str()).toStdString() << std::endl;
            QFile file(QString("docroot/tempfile/%1.indexed").arg(oid.c_str()));
            if( file.open(QIODevice::ReadOnly) )
            {
                QString fileName = QString::fromUtf8(file.readAll());
                file.close();
                std::cout << "FILE FULL NAME: " << fileName.toStdString() << std::endl;
                return fileName.toStdString();
            }
        }else{
            std::cout << "FILE NOT FOUND" << QString("docroot/tempfile/%1.indexed").arg(oid.c_str()).toStdString() << std::endl;
        }




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

//        if( QFile::exists("docroot/"+fullFilename) )
//        {
//            return fullFilename.toStdString();
//        }

        auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
        auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

        std::ofstream out;

        out.open("docroot/"+fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


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
            std::cout << "Error Can Not Open File: " <<"docroot/"+fullFilename.toStdString() << std::endl;
        }


        QFile file(QString("docroot/tempfile/%1.indexed").arg(oid.c_str()));
        if( file.open(QIODevice::ReadWrite) )
        {
            file.write(fullFilename.toUtf8());
            file.close();
        }else{
            std::cout << "FILE CAN NOT CREATED: " << file.fileName().toStdString() << fullFilename.toStdString() << std::endl;
        }

        std::cout << "FILE FORCED : " << forceFilename <<" FILE FILL: " << fullFilename.toStdString() <<" TOTHIS FILE: " << file.fileName().toStdString() << std::endl;

        return fullFilename.toStdString();

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
            std::cout << "FILE FOUND: " << fullFilename.toStdString() << std::endl;
            return fullFilename.toStdString();
        }else{
            std::cout << "FILE NOT FOUND: " << fullFilename.toStdString() << std::endl;
        }

        auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
        auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

        std::ofstream out;

        out.open(fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


        if( out.is_open() )
        {

            while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {

                auto bufferPtr = buffer.get();
                out.write(reinterpret_cast<char*>(bufferPtr),length_read);

                bytes_counter += static_cast<std::int32_t>( length_read );

            }

            out.close();
        }

        else{
            std::cout << "Error Can Not Open File: " <<fullFilename.toStdString() << std::endl;
        }

        return fullFilename.toStdString();

    }

    // bucket               Bucket
    // fileinfo             QFileinfo
    // _qstring             QString
    // _qfile               QFile
    // _qbytearray          bsoncxx::stdx::make_unique ******
    // _qbytearray          QByteArray
    // _qiodevice           QIODevice
    // _bson_type_value     bsoncxx::types::value
    template<class bucket,class fileinfo,class _qstring,class _qfile,class _qbytearray,class _qiodevice,class _bson_type_value>
    static std::string downloadifNotExist(bucket* Bucket,_bson_type_value oid, bool forceFilename = false){

        auto downloader = Bucket->open_download_stream(oid);
        auto file_length = downloader.file_length();
        auto bytes_counter = 0;

        fileinfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

        _qstring fullFilename;

        if( forceFilename )
        {
            fullFilename = _qstring("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
        }else{
            fullFilename = _qstring("tempfile/%2.%1").arg(info.suffix())
                        .arg(downloader.files_document()["md5"].get_utf8().value.to_string().c_str());
        }

        if( _qfile::exists("docroot/"+fullFilename) )
        {
            return fullFilename.toStdString();
        }

        auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
        auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));
        _qbytearray mainArray;
        while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
            bytes_counter += static_cast<std::int32_t>( length_read );
            _qbytearray ar((const char*)buffer.get(),bytes_counter);
            mainArray+= ar;
        }

        _qfile file( "docroot/"+fullFilename );
        if( file.open(_qiodevice::WriteOnly) )
        {
            file.write( mainArray );
            file.close();
        }else{
            std::cout << "Error Can Not Open File: " << file.fileName().toStdString() << std::endl;
        }
        return fullFilename.toStdString();

    }




}





#endif // SNKKEY_H
