#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class QMediaPlayer;

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_open_clicked();
    void on_play_clicked();
    void on_pause_clicked();
    void on_stop_clicked();
    void on_mute_clicked();
    void on_volume_valueChanged(int value);

private:
    Ui::widget *ui;
    QMediaPlayer *mMediaPlayer;
    QAudioOutput *mAudioOutput;

};
#endif // WIDGET_H
