#include"ourplayer.h"
#include"ui_ourplayer.h"

const QString FmUrl = "http://fm.taihe.com/dev/api/?tn=playlist&format=json&id=public_";
network::network( QMediaPlayer *mPlayer){
    this->UrlFlag=false;
    this->songlistFlag=false;
    this->media=mPlayer;
}
void network::getFm(QString fm){
       manager  = new QNetworkAccessManager();
       QString url = FmUrl+fm;
       QNetworkRequest request(url);
       manager->get(request);
       connect(manager,&QNetworkAccessManager::finished,this,&network::getFm_finished);
}
void network::getFm_finished(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        //利用QJsonDcument解析
        QByteArray array = reply->readAll();//获取字节
        QString result(array);      //转化为字符串
        qDebug()<<"reply is :"<<result;
        QJsonDocument document = QJsonDocument::fromJson(array);
        qDebug()<<"document is: "<<document;
        QJsonObject object = document.object();
        QJsonArray list = object.value("list").toArray();
           fmSongIds.clear();
        for(int i = 0;i<list.size();i++){
            fmSongIds.append(list.at(i).toObject().value("id").toInt());
            qDebug()<<fmSongIds.at(i);
        }
        getByIdandPlay(fmSongIds.at(0));
    }
}
void network::getByIdandPlay(int id){//由歌曲id 得到歌曲播放信息
        qDebug()<<"into getUrl function !!";
    QString strId = QString::number(id,10);
    manager  = new QNetworkAccessManager();
        qDebug()<<"mark 1";
    QString url = "http://music.taihe.com/data/music/fmlink?type=mp3&rate=320&songIds="+strId;
        qDebug()<<"mark 2";
    QNetworkRequest request(url);
        qDebug()<<"mark 3";
    manager->get(request);
        qDebug()<<"mark 4";
    //connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::billboard_finished);

    //---------与窗口交互---------//

   connect(manager,&QNetworkAccessManager::finished,this,&network::getByIdFinished);
    //--------------------//
        qDebug()<<"mark 5";
}
void network::getByIdFinished(QNetworkReply *reply){
        qDebug()<<"into getUrlFinished function()！！";
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    //无错误返回
    if(reply->error() == QNetworkReply::NoError)
    {
        //利用QJsonDcument解析
        QByteArray array = reply->readAll();//获取字节
        QString result(array);      //转化为字符串
        qDebug()<<"reply is :"<<result;
        QJsonDocument document = QJsonDocument::fromJson(array);
        qDebug()<<"document is: "<<document;
        QJsonObject object = document.object();
        QJsonObject data = object.value("data").toObject();
        qDebug()<<"data is: ";
        qDebug()<<data;
        QJsonArray songList = data["songList"].toArray();
        QString songLink = songList.at(0)["songLink"].toString();
  //      QString lrcLink = songList.at(0)["lrcLink"].toString();
        QString songName = songList.at(0)["songName"].toString();
   //     QString songPicSmall = songList.at(0)["songPicSmall"].toString();
  //      QString songPicBig = songList.at(0)["songPicBig"].toString();
  //      QString albumName = songList.at(0)["albumName"].toString();
        QString artistName = songList.at(0)["artistName"].toString();
        qDebug()<<"song Link is:";
        qDebug()<<songLink;
  //      qDebug()<<"lrcLink is: ";
  //     qDebug()<<lrcLink;
        qDebug()<<"songName is : ";
        qDebug()<<songName;


        //由于信号槽是异步调用，查询结束后直接播放链接
        //------------与播放器交互-----------//
        this->media->setMedia(QUrl(songLink));
        this->media->play();
        /*this->Url=QUrl(songLink);
        this->UrlFlag=true;*/


     //   cn->mp->mPlayer->setMedia(QUrl(songLink));
     //   cn->mp->mPlayer->play();
        //--------------------------------//
        qDebug()<<"is playing";
    }
}
void network::getSuggestion(QString key){
    QString url = "http://sug.music.baidu.com/info/suggestion?format=json&word="+ key+"&version=2&from=0";
    manager = new QNetworkAccessManager();
    QNetworkRequest request(url);
    manager->get(request);
    //return this->getSuggestionFinished(manager->get(request));

    connect(manager,&QNetworkAccessManager::finished,this,&network::getSuggestionFinished);

}
void network::getSuggestionFinished(QNetworkReply *reply){
        QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //无错误返回
        if(reply->error() == QNetworkReply::NoError)
        {
            QByteArray array = reply->readAll();
            QString result(array);
            QJsonDocument document = QJsonDocument::fromJson(array);
            qDebug()<<"document is :";
            qDebug()<<document;
            QJsonObject object = document.object();
            QJsonObject data = object.value("data").toObject();
            qDebug()<<"data is: ";
            qDebug()<<data;
            QJsonArray songList = data.value("song").toArray();
            qDebug()<<"songList are: ";
            qDebug()<<songList;
            QString songname = songList.at(0)["songname"].toString();
            qDebug()<<"songList 0.name";
            qDebug()<<songname;
    //-------------与窗口交互-------------------//
           this->songlist=songList;
            this->songlistFlag=true;
           // connect(this,&network::getSuggestionFinished,,&ourplayer::getSonglistandset);
            //return songList;
    //----------------------------------------//
        }
    }
