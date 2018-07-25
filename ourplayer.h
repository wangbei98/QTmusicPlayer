#ifndef OURPLAYER_H
#define OURPLAYER_H

#include <QMainWindow>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QString>
#include<QUrl>
#include<QDebug>
#include<QVariant>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QVector>
#include<QMediaPlayer>
#include <QTime>
#include <QFileDialog>
#include <QStringList>
#include<QTableWidgetItem>
#include<QTableWidget>
#include<QByteArray>


namespace Ui {
class ourplayer;
class MainWindow;
class network;
class mediaplayer;

}

class network:public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *manager;
    QNetworkRequest *request;
    QNetworkAccessManager *network_manager;
    QNetworkRequest *network_request;

    QMediaPlayer *media;
    QVector<int> fmSongIds;

    QUrl Url;
    bool UrlFlag;

    QJsonArray songlist;
    bool songlistFlag;

public:
    network( QMediaPlayer *mPlayer);
    void getByIdandPlay(int id);
    void getByIdFinished(QNetworkReply *reply);

    //获得搜索建议

    void getSuggestion(QString key);
    void getSuggestionFinished(QNetworkReply *reply);
    void getFm_finished(QNetworkReply *reply);
    void getFm(QString fm);

    int returnfmsongidsize(){
        return fmSongIds.size();
    }

    int returnfmid(int i){
        return fmSongIds.at(i);
    }

    bool return_urlFlag(){
        return UrlFlag;
    }
    QUrl return_Url(){
        UrlFlag=false;
        return Url;
    }

    QJsonArray return_songlist(){
        songlistFlag=false;
        return songlist;
    }
    bool return_songlistFlag(){
        return songlistFlag;
    }
};

class mediaplayer
{
private:

    enum RepeatFlags {None = 0, One = 1, All =2};

    bool ShuffleFlag;
    bool isPlayingFlag;


    int RepeatStat;
    int model;//0->offline,1->online,2->Fm,3->online_songlist
    int currentIndex;


public:
    bool isPlaying;
    QMediaPlayer *mPlayer;
    mediaplayer();
    ~mediaplayer();
    int getRepeatStat(){
        return this->RepeatStat;
    }
    bool returnshuffleFlag(){
        return this->ShuffleFlag;
    }
    int  returnmodel(){
        return this->model;
    }
    int  returncurrent(){
        return this->currentIndex;
    }
    int  returnRepeatStat(){
        return RepeatStat;
    }
    void setUrl(QUrl q){
        this->mPlayer->setMedia(q);
        this->mPlayer->play();
        this->isPlaying=true;
    }
    void stopplay(){
        mPlayer->stop();
        mPlayer->setPosition(0);
       if(isPlaying==false)
           isPlaying=true;
    }
    void playFM();
    //时间控制
    bool ElapsedTime(qint64 x);
    void RemaningTime(qint64 x);
    //基本按钮
    void on_btn_repeat_clicked();
    bool on_btn_shuffle_clicked();
    void on_btn_play_clicked();
    void on_btn_pre_clicked(int size);
    void on_btn_next_clicked(int size);
    //进度条
    void on_SeekSlider_sliderMoved(int position);
    //音量条
    void on_volumeSlider_sliderMoved(int position);
    //双击
    void on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item);
};

class MainWindow
{
  //  Q_OBJECT
private:
    Ui::ourplayer *ui;
    int onSonglist_size;
public:

    MainWindow(Ui::ourplayer *ui);
    void putSongListToTableW(QJsonArray songList);

   QString return_select_local_item_add();
    int return_select_online_item_ID();
    int return_select_online_2_item_ID();

   void on_btn_repeat_clicked(int RepeatStat);
   void on_btn_shuffle_clicked(bool Flag);
 /*  void on_btn_play_clicked();
   void on_btn_pre_clicked();
   void on_btn_next_clicked();*/
   void ElapsedTime(qint64 x);
   void RemaningTime(qint64 x);
    //公告牌频道
 //   void on_btn_billboard_clicked();
    //void billboard_finished();

    //获得搜索建议
   // void on_input_key_textChanged(const QString &arg1);

    void on_actionAdd_files_triggered(QStringList list);
    void on_actionRemove_File_triggered();
    void on_actionClear_all_triggered();
   // void on_actionAdd_to_Queue_triggered();



    void on_SeekSlider_sliderMoved(int position);
    void on_volumeSlider_sliderMoved(int position);

    void on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item);
     void on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item);
    void on_actiononline_remove_item_triggered();
   void on_actionremoveall_online_triggered();


};

class ourplayer: public QMainWindow
{
    Q_OBJECT
private:
    MainWindow *mw;
    mediaplayer *mp;
    network *nw;
    Ui::ourplayer *ui;
public:
    explicit ourplayer(QWidget *parent = 0);
   ~ourplayer();
    void getandset();
    void getSonglistandset();
    void wait(int s);
private slots:
     void on_actiononline_remove_item_triggered();
    void on_actionremoveall_online_triggered();
    //公告牌频道
    void on_btn_billboard_clicked();
    //void billboard_finished();

    //获得搜索建议
    void on_input_key_textChanged(const QString &arg1);
    //---------本地操作------------//
    void on_actionAdd_files_triggered();
    void on_actionRemove_File_triggered();
    void on_actionClear_all_triggered();
   // void on_actionAdd_to_Queue_triggered();



 //--------------电台-----------//

    void on_tuijian_wangluo_clicked();
    void on_tuijian_suibiantingting_clicked();
    void on_shiguang_90hou_clicked();
    void on_shiguang_lvxing_clicked();
    void on_fengge_yaogun_clicked();
    void on_xinqing_huankuai_clicked();
    void on_fengge_xiaoqingxin_clicked();
    void on_xinqing_qingge_clicked();
    void on_yuzhong_huayu_clicked();
    void on_yuzhong_riyu_clicked();
    void on_yuzhong_yueyu_clicked();

//--------播放器---------//

    void ElapsedTime(qint64 x);
    void RemaningTime(qint64 x);
    //基本按钮
    void on_btn_repeat_clicked();
    void on_btn_shuffle_clicked();
    void on_btn_play_clicked();
    void on_btn_pre_clicked();
    void on_btn_next_clicked();
    //进度条
    void on_SeekSlider_sliderMoved(int position);
    //音量条
    void on_volumeSlider_sliderMoved(int position);
    //双击
    void on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item);
//-------------------------//

 //   void on_table_tabBarClicked(int index);
};

#endif // MAINWINDOW_H




