#include "widget.h"
#include "ui_widget.h"
#include <QAudioOutput>
#include <QMediaPlayer>
#include <QFileDialog>

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer;
    mAudioOutput = new QAudioOutput;
    mMediaPlayer->setAudioOutput(mAudioOutput);

    connect(mMediaPlayer, &QMediaPlayer::positionChanged, [&](qint64 pos){
        ui->progress->setValue(pos);
    });
    connect(mMediaPlayer, &QMediaPlayer::durationChanged, [&](qint64 dur){
        ui->progress->setMaximum(dur);
    });
}

widget::~widget()
{
    delete ui;
}


void widget::on_open_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open");
    if(filename.isEmpty()){
        return;
    }
    mMediaPlayer->setSource(QUrl::fromLocalFile(filename));
    mAudioOutput->setVolume(ui->volume->value());
    on_play_clicked();
}


void widget::on_play_clicked()
{
    mMediaPlayer->play();
}


void widget::on_pause_clicked()
{
    mMediaPlayer->pause();
}


void widget::on_stop_clicked()
{
    mMediaPlayer->stop();
}


void widget::on_mute_clicked()
{
    if(ui->mute->text() == "Mute"){
        mAudioOutput->setVolume(0);
        ui->mute->setText("Unmute");
    }else{
        mAudioOutput->setVolume(ui->volume->value());
        ui->mute->setText("Mute");
    }

}


void widget::on_volume_valueChanged(int value)
{
    mAudioOutput->setVolume(value);
}

