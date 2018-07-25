#include "ourplayer.h"
#include "ui_ourplayer.h"

ourplayer::ourplayer(QWidget *parent):QMainWindow(parent),ui(new Ui::ourplayer)
{

    ui->setupUi(this);
    this->mw=new MainWindow(ui);
    this->mp=new mediaplayer();
    this->nw=new network(this->mp->mPlayer);
    connect(ui->actionPlay_Selected, SIGNAL(triggered()), ui->btn_play, SLOT(click()));
    connect(mp->mPlayer, SIGNAL(positionChanged(qint64)), this,SLOT(ElapsedTime(qint64)));
    connect(mp->mPlayer, SIGNAL(durationChanged(qint64)), this,SLOT(RemaningTime(qint64)));
    ui->tableWidget_local->addAction(ui->actionAdd_files);
    ui->tableWidget_local->addAction(ui->actionPlay_Selected);
    ui->tableWidget_local->addAction(ui->actionRemove_File);
    ui->tableWidget_local->addAction(ui->actionClear_all);
    ui->tableWidget_schRes_2->addAction(ui->actiononline_remove_item);
    ui->tableWidget_schRes_2->addAction(ui->actionremoveall_online);
}

ourplayer::~ourplayer(){
    delete ui;
}

//实现根据ID查找音乐，并立即播放

void ourplayer::on_input_key_textChanged(const QString &arg1)
{
    QString key = arg1;
    this->nw->getSuggestion(key);
    wait(2);
    this->getSonglistandset();
}


//////////////Context Menu Buttons//////////////////////
///

//adding file(s) to playlist table
void ourplayer::on_actionAdd_files_triggered()
{
    QStringList list  = QFileDialog::getOpenFileNames(this,
                                                     tr("Select Files"), "Z:\\Music",
                                                     tr("MP3 Files (*.mp3)"));
  this->mw->on_actionAdd_files_triggered(list);
}

//remove single file from the playlist table
void ourplayer::on_actionRemove_File_triggered()
{
    this->mw->on_actionRemove_File_triggered();
}

//clearing the Playlist table
void ourplayer::on_actionClear_all_triggered()
{
    this->mw->on_actionClear_all_triggered();
}


//// --------------------- NOT IMPLEMENTED YET --------------------------//

///--------------------------------------------------------------------//

//////////////End of Context Menu Buttons//////////////////////

void ourplayer::ElapsedTime(qint64 x)//未完成
{
    bool Flag=false;
    this->mw->ElapsedTime(x);
    //qDebug() << "Duration" << mPlayer->duration();
    Flag=this->mp->ElapsedTime(x);
    if(Flag)
        this->on_btn_next_clicked();
}
/// Slot to update interface
void ourplayer::RemaningTime(qint64 x)
{
   this->mw->RemaningTime(x);
}


void ourplayer::on_btn_repeat_clicked()
{
    int r;
    this->mp->on_btn_repeat_clicked();
    r=this->mp->getRepeatStat();
    this->mw->on_btn_repeat_clicked(r);
}

void ourplayer::on_btn_shuffle_clicked()
{
    bool Flag;
    Flag=this->mp->on_btn_shuffle_clicked();
    this->mw->on_btn_shuffle_clicked(Flag);

}

void ourplayer::on_btn_play_clicked()
{
    this->mp->on_btn_play_clicked();
}
//上一曲
void ourplayer::on_btn_pre_clicked()
{
     int model;
     int RepeatStat;
     bool ShuffleFlag;
     int fmsize;
     fmsize=this->nw->returnfmsongidsize();

     ShuffleFlag=this->mp->returnshuffleFlag();
     RepeatStat=this->mp->returnRepeatStat();
     model=this->mp->returnmodel();
     mp->stopplay();
     if(model==0){
         QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();
         int m_current_row = selected->currentIndex().row();

         if(ui->tableWidget_local->item(0, 0) ==0  &&  m_current_row == 0)
             return;

         if(RepeatStat==1)
         {
             ui->tableWidget_local->selectRow(m_current_row);

         }else if( (RepeatStat==2) && (m_current_row == 0) )
         {
             ui->tableWidget_local->selectRow(ui->tableWidget_local->rowCount()-1);
         }else{
             ui->tableWidget_local->selectRow(m_current_row-1);
         }
         m_current_row=0;
         if(ShuffleFlag&&RepeatStat!=1)
         {
             int randomValue = qrand() % ui->tableWidget_local->rowCount();
             qDebug() << "Random song number:" << randomValue;
             ui->tableWidget_local->selectRow(randomValue);
         }
         if(selected->hasSelection())
         {
             m_current_row = selected->currentIndex().row();

         }else{
             ui->tableWidget_local->selectRow(m_current_row);
         }

         ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_local->item(m_current_row, 0)->text(), 20*1000);
         QString filename  = ui->tableWidget_local->item(m_current_row, 1)->text();
         mp->setUrl(QUrl::fromLocalFile(filename));

     }
     else
         if(model==1){
         QItemSelectionModel *selected = ui->tableWidget_schRes->selectionModel();
         int m_current_row = selected->currentIndex().row();

         if(ui->tableWidget_schRes->item(0, 0) ==0  &&  m_current_row == 0)
             return;

         if(RepeatStat == 1)
         {
             ui->tableWidget_schRes->selectRow(m_current_row);

         }else if( (RepeatStat == 2) && (m_current_row == 0) )
         {
             ui->tableWidget_schRes->selectRow(ui->tableWidget_schRes->rowCount()-1);
         }else{
             ui->tableWidget_schRes->selectRow(m_current_row-1);
         }
         m_current_row=0;
         if(ShuffleFlag&&RepeatStat!=1)
         {
             int randomValue = qrand() % ui->tableWidget_schRes->rowCount();
             qDebug() << "Random song number:" << randomValue;
             ui->tableWidget_schRes->selectRow(randomValue);
         }

         if(selected->hasSelection())
         {
             m_current_row = selected->currentIndex().row();

         }else{
             ui->tableWidget_schRes->selectRow(m_current_row);
         }
         ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_schRes->item(m_current_row, 0)->text(), 20*1000);
         int nowId = ui->tableWidget_schRes->item(m_current_row,3)->text().toInt();
         this->nw->getByIdandPlay(nowId);
     }
     else
         if(model==2)
         {
           this->mp->on_btn_pre_clicked(fmsize);
             int i,id;
             i=this->mp->returncurrent();
             if(fmsize==0){
                 return;
             }
             if(ShuffleFlag&&RepeatStat!=1)
             {
                 int randomValue = qrand() % fmsize;
                 qDebug() << "Random song number:" << randomValue;
                    i = randomValue;
             }
             id=this->nw->returnfmid(i);
             this->nw->getByIdandPlay(id);
          }
         else
             if(model==3){
             QItemSelectionModel *selected = ui->tableWidget_schRes_2->selectionModel();
             int m_current_row = selected->currentIndex().row();

             if(ui->tableWidget_schRes_2->item(0, 0) ==0  &&  m_current_row == 0)
                 return;

             if(RepeatStat == 1)
             {
                 ui->tableWidget_schRes_2->selectRow(m_current_row);

             }else if( (RepeatStat == 2) && (m_current_row == 0) )
             {
                 ui->tableWidget_schRes_2->selectRow(ui->tableWidget_schRes_2->rowCount()-1);
             }else{
                 ui->tableWidget_schRes_2->selectRow(m_current_row-1);
             }
             m_current_row=0;
             if(ShuffleFlag&&RepeatStat!=1)
             {
                 int randomValue = qrand() % ui->tableWidget_schRes_2->rowCount();
                 qDebug() << "Random song number:" << randomValue;
                 ui->tableWidget_schRes_2->selectRow(randomValue);
             }

             if(selected->hasSelection())
             {
                 m_current_row = selected->currentIndex().row();

             }else{
                 ui->tableWidget_schRes_2->selectRow(m_current_row);
             }
             ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_schRes_2->item(m_current_row, 0)->text(), 20*1000);
             int nowId = ui->tableWidget_schRes_2->item(m_current_row,3)->text().toInt();
             this->nw->getByIdandPlay(nowId);
             }
}

//下一曲
void ourplayer::on_btn_next_clicked()
{
    int model;
    int RepeatStat;
    bool ShuffleFlag;

    int fmsize;
    fmsize=this->nw->returnfmsongidsize();

    ShuffleFlag=this->mp->returnshuffleFlag();
    RepeatStat=this->mp->returnRepeatStat();
    model=this->mp->returnmodel();
    mp->stopplay();
    if(model==0){
        QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();
        int m_current_row = selected->currentIndex().row();
        if(ui->tableWidget_local->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat ==1)
        {
            ui->tableWidget_local->selectRow(m_current_row);

        }else
            if( (RepeatStat ==2) && (m_current_row == ui->tableWidget_local->rowCount()+1) )
            {
                ui->tableWidget_local->selectRow(0);
            }
            else
            {
                ui->tableWidget_local->selectRow(m_current_row+1);
            }
        m_current_row=0;
        if(ShuffleFlag&&RepeatStat!=1)
        {
            int randomValue = qrand() % ui->tableWidget_local->rowCount();
            qDebug() << "Random song number:" << randomValue;
            ui->tableWidget_local->selectRow(randomValue);
        }
        if(selected->hasSelection())
        {
            m_current_row = selected->currentIndex().row();

        }else{
            ui->tableWidget_local->selectRow(m_current_row);
        }
        ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_local->item(m_current_row, 0)->text(), 20*1000);
        QString filename  = ui->tableWidget_local->item(m_current_row, 1)->text();
        this->mp->setUrl(QUrl::fromLocalFile(filename));
    }else
        if(model==1){
        QItemSelectionModel *selected = ui->tableWidget_schRes->selectionModel();
        int m_current_row = selected->currentIndex().row();

        if(ui->tableWidget_schRes->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat ==1)
        {
            ui->tableWidget_schRes->selectRow(m_current_row);

        }else if((RepeatStat ==2) && (m_current_row == ui->tableWidget_schRes->rowCount()-1) )
        {
            ui->tableWidget_schRes->selectRow(0);
        }else{
            ui->tableWidget_schRes->selectRow(m_current_row+1);
        }
        m_current_row=0;
         if(ShuffleFlag&&RepeatStat!=1)
        {
            int randomValue = qrand() % ui->tableWidget_schRes->rowCount();
            qDebug() << "Random song number:" << randomValue;
            ui->tableWidget_schRes->selectRow(randomValue);
        }

        if(selected->hasSelection())
        {
            m_current_row = selected->currentIndex().row();

        }
        else
        {
            ui->tableWidget_schRes->selectRow(m_current_row);
        }
        ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_schRes->item(m_current_row, 0)->text(), 20*1000);
        int nowId = ui->tableWidget_schRes->item(m_current_row,3)->text().toInt();
        this->nw->getByIdandPlay(nowId);

         }
        else
            if(model==2)
            {
               this->mp->on_btn_next_clicked(fmsize);
                int i,id;
                i=this->mp->returncurrent();
                if(fmsize==0){
                    return;
                }
                if(ShuffleFlag)
                {
                    int randomValue = qrand() % fmsize;
                    qDebug() << "Random song number:" << randomValue;
                   i = randomValue;
                }
                id=this->nw->returnfmid(i);
                this->nw->getByIdandPlay(id);
              }
            else
                if(model==3){
                QItemSelectionModel *selected = ui->tableWidget_schRes_2->selectionModel();
                int m_current_row = selected->currentIndex().row();

                if(ui->tableWidget_schRes_2->item(0, 0) ==0  &&  m_current_row == 0)
                    return;

                if(RepeatStat ==1)
                {
                    ui->tableWidget_schRes_2->selectRow(m_current_row);

                }else if((RepeatStat ==2) && (m_current_row == ui->tableWidget_schRes_2->rowCount()-1) )
                {
                    ui->tableWidget_schRes_2->selectRow(0);
                }else{
                    ui->tableWidget_schRes_2->selectRow(m_current_row+1);
                }
                m_current_row=0;
                 if(ShuffleFlag&&RepeatStat!=1)
                {
                    int randomValue = qrand() % ui->tableWidget_schRes_2->rowCount();
                    qDebug() << "Random song number:" << randomValue;
                    ui->tableWidget_schRes_2->selectRow(randomValue);
                }

                if(selected->hasSelection())
                {
                    m_current_row = selected->currentIndex().row();

                }else{
                    ui->tableWidget_schRes_2->selectRow(m_current_row);
                }
                ui->statusBar->showMessage("[+]Now Playing: " + ui->tableWidget_schRes_2->item(m_current_row, 0)->text(), 20*1000);
                int nowId = ui->tableWidget_schRes_2->item(m_current_row,3)->text().toInt();
                this->nw->getByIdandPlay(nowId);

                 }

}

//设置播放进度条
void ourplayer::on_SeekSlider_sliderMoved(int position)
{
    this->mp->on_SeekSlider_sliderMoved(position);
}
//设置音量进度条
void ourplayer::on_volumeSlider_sliderMoved(int position)
{
    this->mp->on_volumeSlider_sliderMoved(position);
}
//将获得的歌曲数组添加进tableWidget


void ourplayer::on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item)
{
//双击右侧条目，先把模式修改为1
    this->mp->on_tableWidget_schRes_itemDoubleClicked(item);
    this->mw->on_tableWidget_schRes_itemDoubleClicked(item);
    int id;
    id=this->mw->return_select_online_item_ID();
    this->nw->getByIdandPlay(id);
    this->mp->isPlaying=true;

}
void ourplayer::on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item){
    this->mp->on_tableWidget_schRes_2_itemDoubleClicked(item);
    this->mw->on_tableWidget_schRes_2_itemDoubleClicked(item);
    int id;
    id=this->mw->return_select_online_2_item_ID();
    this->nw->getByIdandPlay(id);
    this->mp->isPlaying=true;
}

void ourplayer::on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item)
{
    this->mp->on_tableWidget_local_itemDoubleClicked(item);
    this->mw->on_tableWidget_local_itemDoubleClicked(item);
    QString address;
    address=this->mw->return_select_local_item_add();
    mp->setUrl(QUrl::fromLocalFile(address));

}


////////////////////////FM channel implementation/////////////////////////

//获取billbroad 播放列表下的所有 歌曲ID
void ourplayer::on_btn_billboard_clicked(){
   this->mp->playFM();
    this->nw->getFm("tuijian_billboard");
    ui->statusBar->showMessage("[+]Now Playing: FM:billBoard", 20*1000);
}

void ourplayer::on_tuijian_wangluo_clicked()
{
    this->mp->playFM();
     this->nw->getFm("tuijian_wangluo");

    ui->statusBar->showMessage("[+]Now Playing: FM:网络推荐", 20*1000);
}

void ourplayer::on_tuijian_suibiantingting_clicked()
{
    this->mp->playFM();
     this->nw->getFm("tuijian_suibiantingging");

    ui->statusBar->showMessage("[+]Now Playing: FM:随便听听", 20*1000);
}

void ourplayer::on_shiguang_90hou_clicked()
{
    this->mp->playFM();
     this->nw->getFm("shiguang_90hou");

    ui->statusBar->showMessage("[+]Now Playing: FM:时光：90后", 20*1000);
}

void ourplayer::on_shiguang_lvxing_clicked()
{
    this->mp->playFM();
     this->nw->getFm("shiguang_lvxing");

    ui->statusBar->showMessage("[+]Now Playing: FM:时光：旅行", 20*1000);
}

void ourplayer::on_fengge_yaogun_clicked()
{
    this->mp->playFM();
     this->nw->getFm("fengge_yaogun");

    ui->statusBar->showMessage("[+]Now Playing: FM:摇滚", 20*1000);
}

void ourplayer::on_xinqing_huankuai_clicked()
{
    this->mp->playFM();
     this->nw->getFm("xinqing_huankuai");

    ui->statusBar->showMessage("[+]Now Playing: FM:心情：欢快", 20*1000);
}

void ourplayer::on_fengge_xiaoqingxin_clicked()
{
    this->mp->playFM();
     this->nw->getFm("fengge_xiaoqingxin");

    ui->statusBar->showMessage("[+]Now Playing: FM:风格：小清新", 20*1000);
}

void ourplayer::on_xinqing_qingge_clicked()
{
    this->mp->playFM();
     this->nw->getFm("xinqing_qingge");

    ui->statusBar->showMessage("[+]Now Playing: FM:心情：情歌", 20*1000);
}

void ourplayer::on_yuzhong_huayu_clicked()
{
    this->mp->playFM();
     this->nw->getFm("yuzhong_huayu");

    ui->statusBar->showMessage("[+]Now Playing: FM:语种：华语", 20*1000);
}

void ourplayer::on_yuzhong_riyu_clicked()
{
    this->mp->playFM();
     this->nw->getFm("yuzhong_riyu");

    ui->statusBar->showMessage("[+]Now Playing: FM:语种：日语", 20*1000);
}

void ourplayer::on_yuzhong_yueyu_clicked()
{
    this->mp->playFM();
     this->nw->getFm("yuzhong_yueyu");

    ui->statusBar->showMessage("[+]Now Playing: FM:语种：粤语", 20*1000);
}
void ourplayer::getandset(){
    this->on_btn_play_clicked();

}
void ourplayer::getSonglistandset(){
    QJsonArray q;
        if(nw->return_songlistFlag())
        {
            q=nw->return_songlist();

        }
    this->mw->putSongListToTableW(q);
}
void ourplayer::wait(int s)
{
    QTime t;
    t.start();
    while(t.elapsed()<500*s)
        QCoreApplication::processEvents();
}

void ourplayer::on_actionremoveall_online_triggered()
{
  this->mw->on_actionremoveall_online_triggered();
}

void ourplayer::on_actiononline_remove_item_triggered()
{
   this->mw->on_actiononline_remove_item_triggered();
}
