#include "ourplayer.h"
#include"ui_ourplayer.h"



//实现根据ID查找音乐，并立即播放


//-----------搜索栏关键字改变----------//

MainWindow::MainWindow(Ui::ourplayer *ui){
    this->ui=ui;
    this->onSonglist_size=0;
}
/*
void MainWindow::on_input_key_textChanged(const QString &arg1)
{
    QString key = arg1;
    cn->return_NW()->getSuggestion(key);
    //getSuggestion(key);

}*/

//------------本地操作-------------------//

//adding file(s) to playlist table
void MainWindow::on_actionAdd_files_triggered(QStringList list)
{
    /*QStringList list  = QFileDialog::getOpenFileNames(this,
                                                     tr("Select Files"), "Z:\\Music",
                                                     tr("MP3 Files (*.mp3)"));*/
    if(list.isEmpty())
        return;

    int counter = ui->tableWidget_local->rowCount();
    ui->tableWidget_local->setRowCount(counter);
    foreach(QString x, list)
    {
        ui->tableWidget_local->insertRow(counter);
        int xbegin = x.lastIndexOf("/")+1;
        int xend = x.lastIndexOf('.') - xbegin ;
        QString title = x.mid( xbegin, xend);

        QTableWidgetItem *item_title = new QTableWidgetItem(title);
        QTableWidgetItem *item_path = new QTableWidgetItem(x);

        ui->tableWidget_local->setItem(counter, 0, item_title);
        ui->tableWidget_local->setItem(counter, 1, item_path);
        counter++;
        //qDebug() << xend;
    }
    ui->tableWidget_local->resizeColumnToContents(0);
    ui->tableWidget_local->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MainWindow::on_actionremoveall_online_triggered()
{
    this->onSonglist_size=0;
    ui->tableWidget_schRes_2->clearContents();
    ui->tableWidget_schRes_2->setRowCount(0);
}

void MainWindow::on_actiononline_remove_item_triggered()
{
    this->onSonglist_size--;
    QItemSelectionModel *selected = ui->tableWidget_schRes_2->selectionModel();

    if(selected->hasSelection())
    {
        int m_current_row = selected->currentIndex().row();
        ui->tableWidget_schRes_2->removeRow(m_current_row);
    }
}
//remove single file from the playlist table
void MainWindow::on_actionRemove_File_triggered()
{
    QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();

    if(selected->hasSelection())
    {
        int m_current_row = selected->currentIndex().row();
        ui->tableWidget_local->removeRow(m_current_row);
    }
}

//clearing the Playlist table
void MainWindow::on_actionClear_all_triggered()
{
    ui->tableWidget_local->clearContents();
    ui->tableWidget_local->setRowCount(0);
}

//////////////End of Context Menu Buttons//////////////////////
//将获得的歌曲数组添加进tableWidget
void MainWindow::putSongListToTableW(QJsonArray songList){
    for(int i = 0;i<songList.size();i++){
        ui->tableWidget_schRes->insertRow(i);
        qDebug()<<"no i name:";
        qDebug()<<songList.at(i)["songname"].toString();
        QTableWidgetItem *songName =new QTableWidgetItem( songList.at(i)["songname"].toString());
        QTableWidgetItem *artistName =new QTableWidgetItem( songList.at(i)["artistname"].toString());
        QTableWidgetItem *info = new QTableWidgetItem(songList.at(i)["info"].toString());
        QTableWidgetItem *songId =new QTableWidgetItem( songList.at(i)["songid"].toString());
        qDebug()<<songList.at(i)["songid"].toString();
        ui->tableWidget_schRes->setItem(i,0,songName);
        ui->tableWidget_schRes->setItem(i,1,artistName);
        ui->tableWidget_schRes->setItem(i,2,info);
        ui->tableWidget_schRes->setItem(i,3,songId);
    }
    ui->tableWidget_schRes->show();
    ui->tableWidget_schRes->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//双击在线歌曲条目
void MainWindow::on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item)
{
//双击右侧条目，先把模式修改为1
   ui->tableWidget_schRes->setCurrentItem(item);
   int i,row;
   i=this->onSonglist_size;
   this->onSonglist_size++;
   ui->tableWidget_schRes_2->insertRow(i);
   row=item->row();
   QTableWidgetItem *songName =new QTableWidgetItem( ui->tableWidget_schRes->item(row,0)->text());
   QTableWidgetItem *artistName =new QTableWidgetItem(ui->tableWidget_schRes->item(row,1)->text());
   QTableWidgetItem *info = new QTableWidgetItem(ui->tableWidget_schRes->item(row,2)->text());
   QTableWidgetItem *songId =new QTableWidgetItem(ui->tableWidget_schRes->item(row,3)->text());

   ui->tableWidget_schRes_2->setItem(i,0,songName);
   ui->tableWidget_schRes_2->setItem(i,1,artistName);
   ui->tableWidget_schRes_2->setItem(i,2,info);
   ui->tableWidget_schRes_2->setItem(i,3,songId);
   ui->tableWidget_schRes_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void MainWindow::on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item)
{
//双击右侧条目，先把模式修改为1
   ui->tableWidget_schRes_2->setCurrentItem(item);
}
//双击本地歌曲条目
void MainWindow::on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item)
{
     ui->tableWidget_local->setCurrentItem(item);
}


////////////////////////FM channel implementation/////////////////////////



//获取billbroad 播放列表下的所有 歌曲ID
/*void MainWindow::on_btn_billboard_clicked(){
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"tuijian_billboard";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:billBoard", 20*1000);
}

void MainWindow::on_tuijian_wangluo_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"tuijian_wangluo";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:网络推荐", 20*1000);
}

void MainWindow::on_tuijian_suibiantingting_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"tuijian_suibiantingging";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:随便听听", 20*1000);
}

void MainWindow::on_shiguang_90hou_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"shiguang_90hou";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:时光：90后", 20*1000);
}

void MainWindow::on_shiguang_lvxing_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"shiguang_lvxing";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:时光：旅行", 20*1000);
}

void MainWindow::on_fengge_yaogun_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"fengge_yaogun";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:摇滚", 20*1000);
}

void MainWindow::on_xinqing_huankuai_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"xinqing_huankuai";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:心情：欢快", 20*1000);
}

void MainWindow::on_fengge_xiaoqingxin_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"fengge_xiaoqingxin";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:风格：小清新", 20*1000);
}

void MainWindow::on_xinqing_qingge_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"xinqing_qingge";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:心情：情歌", 20*1000);
}

void MainWindow::on_yuzhong_huayu_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"yuzhong_huayu";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:语种：华语", 20*1000);
}

void MainWindow::on_yuzhong_riyu_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"yuzhong_riyu";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:语种：日语", 20*1000);
}

void MainWindow::on_yuzhong_yueyu_clicked()
{
    model = 2;
    isPlaying = false;
    mPlayer->setPosition(0);
    manager  = new QNetworkAccessManager();
    QString url = FmUrl+"yuzhong_yueyu";
    QNetworkRequest request(url);
    manager->get(request);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::getFm_finished);
    ui->statusBar->showMessage("[+]Now Playing: FM:语种：粤语", 20*1000);
}
*/
//--------------播放器控制条-----------//
void MainWindow::ElapsedTime(qint64 x)
{

    QTime t = QTime(0,0,0);
    t =  t.addMSecs(x);
    ui->lblTimeElsp->setText(t.toString("mm:ss"));
    ui->SeekSlider->setValue(x);
    //qDebug() << "Duration" << mPlayer->duration();


    //qDebug() << RepeatStat;

}
/// Slot to update interface
/// 修改进度条
void MainWindow::RemaningTime(qint64 x)
{
    QTime t = QTime(0,0,0);
    t =  t.addMSecs(x);
    ui->lblTimeRemaining_2->setText(t.toString("mm:ss"));
    //qDebug() << t;
    ui->SeekSlider->setRange(0, x);
}

void MainWindow::on_btn_repeat_clicked(int RepeatStat)
{
    if(RepeatStat ==1 )
    {
        ui->btn_repeat->setChecked(true);
        ui->statusBar->showMessage("Repeat One", 5*1000);
    }else if(RepeatStat ==2)
    {
        ui->btn_repeat->setChecked(true);
        ui->statusBar->showMessage("Repeat All", 5*1000);
    }else{
        ui->btn_repeat->setChecked(false);
        ui->statusBar->showMessage("Repeat Off", 5*1000);

    }
}


void MainWindow::on_btn_shuffle_clicked(bool Flag)
{
    if(Flag)
    {

        ui->statusBar->showMessage("Shuffle selection is On", 5*1000);

    }else{
        ui->statusBar->showMessage("Shuffle selection is Off", 5*1000);

    }
}
/*
void MainWindow::on_btn_play_clicked()
{
    if(model==0){
        if(this->isPlaying)
        {
            mPlayer->pause();
            this->isPlaying = false;
        }else{
            if(mPlayer->position()==0){
                //播放当前选中条目歌曲
                QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();
                if(ui->tableWidget_local->item(0, 0) ==0)
                    return;

                int m_current_row=0;

                if(ShuffleFlag)
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
                mPlayer->setMedia(QUrl::fromLocalFile(filename));
                mPlayer->play();
            }
            else{mPlayer->play();}
            this->isPlaying = true;
        }
    }
    else if(model==1){
        if(this->isPlaying){
            mPlayer->pause();
            this->isPlaying = false;
        }else{
            if(mPlayer->position()==0){
                //播放当前选中条目歌曲
                QItemSelectionModel *selected = ui->tableWidget_schRes->selectionModel();
                if(ui->tableWidget_schRes->item(0, 0) ==0)
                    return;

                int m_current_row=0;

                if(ShuffleFlag)
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
                getByIdandPlay(nowId);
//                QString filename  = ui->tableWidget_schRes->item(m_current_row, 1)->text();
//                mPlayer->setMedia(QUrl::fromLocalFile(filename));
//                mPlayer->play();
            }else{
                mPlayer->play();
                this->isPlaying = true;
            }
        }
    }else{
        if(this->isPlaying){
            mPlayer->pause();
            this->isPlaying = false;
        }else{
            if(mPlayer->position()==0){
                //播放当前选中条目歌曲

                currentIndex = 0;
                if(fmSongIds.size()==0){
                    return;
                }
                if(ShuffleFlag)
                {
                    int randomValue = qrand() % fmSongIds.size();
                    qDebug() << "Random song number:" << randomValue;
                    currentIndex = randomValue;

                }
                getByIdandPlay(currentIndex);
            }else{
                mPlayer->play();
                this->isPlaying = true;
            }
        }
    }
}
//上一曲
void MainWindow::on_btn_pre_clicked()
{
    if(model==0){//对本地音乐操作
        mPlayer->setPosition(0);
        isPlaying=false;
        QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();
        int m_current_row = selected->currentIndex().row();

        if(ui->tableWidget_local->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat == RepeatFlags::One)
        {
            ui->tableWidget_local->selectRow(m_current_row);

        }else if( (RepeatStat == RepeatFlags::All) && (m_current_row == 0) )
        {
            ui->tableWidget_local->selectRow(ui->tableWidget_local->rowCount()-1);
        }else{
            ui->tableWidget_local->selectRow(m_current_row-1);
        }
        on_btn_play_clicked();
    }else if(model==1){//对在线音乐操作
        mPlayer->setPosition(0);
             isPlaying=false;
        QItemSelectionModel *selected = ui->tableWidget_schRes->selectionModel();
        int m_current_row = selected->currentIndex().row();

        if(ui->tableWidget_schRes->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat == RepeatFlags::One)
        {
            ui->tableWidget_schRes->selectRow(m_current_row);

        }else if( (RepeatStat == RepeatFlags::All) && (m_current_row == 0) )
        {
            ui->tableWidget_schRes->selectRow(ui->tableWidget_schRes->rowCount()-1);
        }else{
            ui->tableWidget_schRes->selectRow(m_current_row-1);
        }
        on_btn_play_clicked();
    }else{//对FM音乐操作
        mPlayer->setPosition(0);
             isPlaying=false;
        if(RepeatStat == RepeatFlags::One)currentIndex = currentIndex;
        else if(RepeatStat == RepeatFlags::All&&currentIndex==0)currentIndex = fmSongIds.size() - 1;
        else{currentIndex = currentIndex-1;}
        on_btn_play_clicked();
    }
}
//下一曲
void MainWindow::on_btn_next_clicked()
{
    if(model==0){
        mPlayer->setPosition(0);
             isPlaying=false;
        QItemSelectionModel *selected = ui->tableWidget_local->selectionModel();
        int m_current_row = selected->currentIndex().row();

        if(ui->tableWidget_local->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat == RepeatFlags::One)
        {
            ui->tableWidget_local->selectRow(m_current_row);

        }else if( (RepeatStat == RepeatFlags::All) && (m_current_row == ui->tableWidget_local->rowCount()-1) )
        {
            ui->tableWidget_local->selectRow(0);
        }else{
            ui->tableWidget_local->selectRow(m_current_row+1);
        }
        on_btn_play_clicked();
    }else if(model==1){
        mPlayer->setPosition(0);
             isPlaying=false;
        QItemSelectionModel *selected = ui->tableWidget_schRes->selectionModel();
        int m_current_row = selected->currentIndex().row();

        if(ui->tableWidget_schRes->item(0, 0) ==0  &&  m_current_row == 0)
            return;

        if(RepeatStat == RepeatFlags::One)
        {
            ui->tableWidget_schRes->selectRow(m_current_row);

        }else if( (RepeatStat == RepeatFlags::All) && (m_current_row == ui->tableWidget_schRes->rowCount()-1) )
        {
            ui->tableWidget_schRes->selectRow(0);
        }else{
            ui->tableWidget_schRes->selectRow(m_current_row+1);
        }
        on_btn_play_clicked();
    }else{
        mPlayer->setPosition(0);
             isPlaying=false;
        if(RepeatStat==RepeatFlags::One)currentIndex = currentIndex;
        else if(RepeatStat==RepeatFlags::All&&currentIndex==fmSongIds.size()-1)currentIndex = 0;
        else{currentIndex = currentIndex+1;}
        on_btn_play_clicked();
    }
}
*/
QString MainWindow::return_select_local_item_add(){
    QItemSelectionModel *selected=ui->tableWidget_local->selectionModel();
    int m=selected->currentIndex().row();
    return  ui->tableWidget_local->item(m,1)->text();
}

int MainWindow::return_select_online_item_ID(){
    QItemSelectionModel *selected=ui->tableWidget_schRes->selectionModel();
    int m=selected->currentIndex().row();
    return ui->tableWidget_schRes->item(m,3)->text().toInt();
}
int MainWindow::return_select_online_2_item_ID(){
    QItemSelectionModel *selected=ui->tableWidget_schRes_2->selectionModel();
    int m=selected->currentIndex().row();
    return ui->tableWidget_schRes_2->item(m,3)->text().toInt();
}
