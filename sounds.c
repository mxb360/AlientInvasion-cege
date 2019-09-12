#include "sounds.h"

static MUSIC _start_sound;
static MUSIC _game_sound;
static MUSIC _pause_sound;
static MUSIC _gameover_sound;
static MUSIC _fire_sounds;
static MUSIC _explosion_sound;
static MUSIC _death_sounds;

/* �������ֳ�ʼ�� */
void sounds_init(void)
{
    _start_sound = cege_MUSIC_New();
    _game_sound = cege_MUSIC_New();
    _pause_sound = cege_MUSIC_New();
    _gameover_sound = cege_MUSIC_New();
    _fire_sounds = cege_MUSIC_New();
    _explosion_sound = cege_MUSIC_New();
    _death_sounds = cege_MUSIC_New();
    cege_MUSIC_OpenFile(_start_sound, START_SOUND);
    cege_MUSIC_OpenFile(_game_sound, GAME_SOUND);
    cege_MUSIC_OpenFile(_pause_sound, PAUSE_SOUND);
    cege_MUSIC_OpenFile(_gameover_sound, GAME_OVER_SOUND);
    cege_MUSIC_OpenFile(_fire_sounds, PLANE_FIRE_SOUND);
    cege_MUSIC_OpenFile(_explosion_sound, EXPLOSION_SOUND);
    cege_MUSIC_OpenFile(_death_sounds, DEATH_SOUND);
    dprintf("�������ֳ�ʼ����� ...\n");
}

/* ���ſ�ʼ���� */
void sounds_play_start(void)
{
    cege_MUSIC_Play(_start_sound, MUSIC_ERROR, MUSIC_ERROR);
    dprintf("���ſ�ʼ���֣�%s\n", START_SOUND);
}

/* ֹͣ���ſ�ʼ���� */
void sounds_stop_start(void)
{
    cege_MUSIC_Stop(_start_sound);
    dprintf("ֹͣ���ſ�ʼ���֣�%s\n", START_SOUND);
}

/* ������Ϸ�������� */
void sounds_play_game(void)
{
    cege_MUSIC_Play(_game_sound, 0, MUSIC_ERROR);
    dprintf("������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ��ͣ�������� */
void sounds_pause_game(void)
{
    cege_MUSIC_Pause(_game_sound);
    cege_MUSIC_Play(_pause_sound, 0, MUSIC_ERROR);
    dprintf("��ͣ������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ������������ */
void sounds_resume_game(void)
{
    cege_MUSIC_Play(_game_sound, MUSIC_ERROR, MUSIC_ERROR);
    dprintf("����������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ���¼�����Ϸ���� */
void sounds_reload_game(void)
{
    
    if (cege_MUSIC_GetPosition(_game_sound) == MUSIC_MODE_STOP) {
        cege_MUSIC_Play(_game_sound, 0, MUSIC_ERROR);
        dprintf("���²�����Ϸ�������֣�%s\n", GAME_SOUND);
    }
}

/* ֹͣ������Ϸ�������� */
void sounds_stop_game(void)
{
    cege_MUSIC_Stop(_game_sound);
    dprintf("ֹͣ������Ϸ�������֣�%s\n", GAME_SOUND);
}

/* ������Ϸ�������� */
void sounds_play_game_over(void)
{
    cege_MUSIC_Play(_gameover_sound, 0, MUSIC_ERROR);
    dprintf("������Ϸ�������֣�%s\n", GAME_OVER_SOUND);
}

/* ֹͣ������Ϸ�������� */
void sounds_stop_game_over(void)
{
    cege_MUSIC_Stop(_gameover_sound);
    dprintf("ֹͣ������Ϸ�������֣�%s\n", GAME_OVER_SOUND);
}

/* ���������Ч */
void sounds_play_fire(void)
{
    cege_MUSIC_Play(_fire_sounds, 0, MUSIC_ERROR);
    //dprintf("���������Ч: %s\n", PLANE_FIRE_SOUND);
}

/* ���ű�ը��Ч */
void sounds_play_explosion(void)
{
    cege_MUSIC_Play(_explosion_sound, 0, MUSIC_ERROR);
    //dprintf("���ű�ը��Ч: %s\n", EXPLOSION_SOUND);
}

/* ���ŷɻ�������Ч */
void sounds_play_death(void)
{
    cege_MUSIC_Play(_death_sounds, 0, MUSIC_ERROR);
    //dprintf("���ŷɻ�������Ч: %s\n", PLANE_FIRE_SOUND);
}
