#include"ourplayer.h"
#include"ui_ourplayer.h"


mediaplayer::mediaplayer(){
    this->ShuffleFlag = false;
    this->RepeatStat= RepeatFlags::All;
    this->isPlaying = false;
    this->currentIndex=0;
    mPlayer=new QMediaPlayer ();
   /* connect(mPlayer, SIGNAL(positionChanged(qint64)), this->cn->mw,SLOT(ElapsedTime(qint64)));
    connect(mPlayer, SIGNAL(durationChanged(qint64)), this->cn->mw,SLOT(RemaningTime(qint64)));*/
}
mediaplayer::~mediaplayer(){
    delete mPlayer;
}

bool mediaplayer::ElapsedTime(qint64 x)
{
    if(x!=0 && x==mPlayer->duration() )
    {
        if(RepeatStat == RepeatFlags::None)
        {
            mPlayer->stop();
        }

      return true;
    }
    else
        return false;
    //qDebug() << RepeatStat;

}
/// Slot to update interface
/// 修改进度条
void mediaplayer::RemaningTime(qint64 x)
{
  /*  QTime t = QTime(0,0,0);
    t =  t.addMSecs(x);
    ui->lblTimeRemaining->setText(t.toString("mm:ss"));
    //qDebug() << t;
    ui->SeekSlider->setRange(0, x);*/
}

//------------------媒体播放器按钮-----------//
void mediaplayer::on_btn_repeat_clicked()
{
    RepeatStat++;
    if(RepeatStat==3)
        RepeatStat=0;
}

bool mediaplayer::on_btn_shuffle_clicked()
{
       if(ShuffleFlag==true)
       {
           ShuffleFlag=false;
           return ShuffleFlag;
       }
       else
       {
           ShuffleFlag=true;
           return ShuffleFlag;
       }
}

void mediaplayer::on_btn_play_clicked()
{
    if(this->isPlaying)
    {
        mPlayer->pause();
        this->isPlaying = false;
    }
    else
    {
        mPlayer->play();
        this->isPlaying=true;
   }
}
//上一曲
void mediaplayer::on_btn_pre_clicked(int size)
{
     if(RepeatStat == RepeatFlags::One)
            currentIndex = currentIndex;
        else
            if(RepeatStat == RepeatFlags::All&&currentIndex==0)
                currentIndex = size - 1;
            else
            {
                currentIndex = currentIndex-1;
            }


}
//下一曲
void mediaplayer::on_btn_next_clicked(int size)
{
        if(RepeatStat==1)
            currentIndex = currentIndex;
        else
            if(RepeatStat==2&&currentIndex==size-1)
                currentIndex = 0;
            else
            {
                currentIndex = currentIndex+1;
            }


}

void mediaplayer::on_SeekSlider_sliderMoved(int position)
{
    mPlayer->setPosition(position);
}
//设置音量进度条
void mediaplayer::on_volumeSlider_sliderMoved(int position)
{
    mPlayer->setVolume(position);
}

void mediaplayer::on_tableWidget_schRes_itemDoubleClicked(QTableWidgetItem *item)
{
//双击右侧条目，先把模式修改为1
    model = 1;
    isPlaying = false;
    mPlayer->setPosition(00);
  // ui->tableWidget_schRes->setCurrentItem(item);

}
void mediaplayer::on_tableWidget_schRes_2_itemDoubleClicked(QTableWidgetItem *item)
{
//双击右侧条目，先把模式修改为1
    model = 3;
    isPlaying = false;
    mPlayer->setPosition(00);
  // ui->tableWidget_schRes->setCurrentItem(item);

}
//双击本地歌曲条目
void mediaplayer::on_tableWidget_local_itemDoubleClicked(QTableWidgetItem *item)
{
    model = 0;
    isPlaying = false;
    mPlayer->setPosition(0);
   // ui->tableWidget_local->setCurrentItem(item);
   // on_btn_play_clicked();
}

void mediaplayer::playFM(){
    model = 2;
    mPlayer->stop();

    mPlayer->setPosition(0);
    isPlaying = true;
}
