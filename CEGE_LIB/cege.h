/* cege.h
 * CEGE图形库的标头
 *
 * EGE图形库的C语言适配版本
 * EGE（Easy Graphics Engine），是windows下的简易绘图库，
 * 是一个类似BGI(graphics.h)的面向C/C++语言新手的图形库，
 * 它的目标也是为了替代TC的BGI库而存在。
 *
 * CEGE是对EGE图形库的纯C封装，它依赖于EGE
 * CEGE是对纯C强迫症提供的图形库
 * 使用CEGE，你不需要再将源文件创建为C++工程，或者以.cpp结尾
 * 它是一个可以使用纯C语言编程的图形库
 *
 * CEGE并没有完全支持CEGE的所有功能，仅仅是EGE的一个子集
 * CEGE与大部分的EGE函数兼容，但由于C语言不支持函数重载
 * 所以你必须补全函数的每一个参数，你也可以考虑使用一些宏来简化参数的传递
 * CEGE重新封装的EGE中的MUSIC库，EGE的MUSIC是一个类，在CEGE中MUSIC只是
 * 一个结构体，并提供了对应的函数来实现类中的方法
 *
 * 对于几乎所有的同名函数，使用方法和函数功能与EGE相同，只是你不能省略部分参数
 * 使用方法参考EGE的帮助文档
 *
 * 本库是为纯C强迫症提供的库，如果你用C++编程，或者只是简单的学习图形编程，请使用
 * 原版的EGE图形库，不建议使用CEGE
 *
 *  V1.2
 *  Ma Xiaobo  2018-12
 */

#ifndef __CEGE_H__
#define __CEGE_H__

/* CEGE只支持Windows */
#if (!defined(_WIN32) && !defined(_WIN64))
#error CEGE is for Windows only.
#endif

/* 使用CEGE时不能够包含conio.h */
#ifndef __CEGE_EGE__
#if (defined(_INC_CONIO) || defined(_CONIO_H_))
#error can not include "conio.h" before "graphics.h" or "cege.h"
#else
#define _INC_CONIO
#define _CONIO_H_
#endif
#endif  /* !__CEGE_EGE__ */

/* 支持Windows编程 */
#include "windows.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CEGE_EGE__
/* EGE原有的颜色转换宏 */
#define RGBTOBGR(color)         ((((color) & 0xFF) << 16) | (((color) & 0xFF0000) >> 16) | ((color) & 0xFF00FF00))
#define EGERGB(r, g, b)         ( ((r)<<16) | ((g)<<8) | (b))
#define EGERGBA(r, g, b, a)     ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define EGEARGB(a, r, g, b)     ( ((r)<<16) | ((g)<<8) | (b) | ((a)<<24) )
#define EGEACOLOR(a, color)     ( ((color) & 0xFFFFFF) | ((a)<<24) )
#define EGECOLORA(color, a)     ( ((color) & 0xFFFFFF) | ((a)<<24) )
#define EGEGET_R(c)             ( ((c)>>16) & 0xFF )
#define EGEGET_G(c)             ( ((c)>> 8) & 0xFF )
#define EGEGET_B(c)             ( ((c)) & 0xFF )
#define EGEGET_A(c)             ( ((c)>>24) & 0xFF )
#define EGEGRAY(gray)           ( ((gray)<<16) | ((gray)<<8) | (gray))
#define EGEGRAYA(gray, a)       ( ((gray)<<16) | ((gray)<<8) | (gray) | ((a)<<24) )
#define EGEAGRAY(a, gray)       ( ((gray)<<16) | ((gray)<<8) | (gray) | ((a)<<24) )
#endif  /* !__CEGE_EGE__ */

/* 屏幕窗口对应的PIMAGE对象，也可以像EGE那样使用NULL */
#define SCREEN (PIMAGE)0

enum graphics_errors {      /* graphresult error return codes */
    grOk = 0,
    grNoInitGraph = -1,
    grNotDetected = -2,
    grFileNotFound = -3,
    grInvalidDriver = -4,
    grNoLoadMem = -5,
    grNoScanMem = -6,
    grNoFloodMem = -7,
    grFontNotFound = -8,
    grNoFontMem = -9,
    grInvalidMode = -10,
    grError = -11,   /* generic error */
    grIOerror = -12,
    grInvalidFont = -13,
    grInvalidFontNum = -14,
    grInvalidVersion = -18,
    grException = 0x10,  /* ege error */
    grParamError = 0x11,
    grInvalidRegion = 0x12,
    grOutOfMemory = 0x13,
    grNullPointer = 0x14,
    grAllocError = 0x15,
    grInvalidMemory = 0xCDCDCDCD,
};

enum message_event {
    MSG_EVENT_UP = 0x00,
    MSG_EVENT_DOWN = 0x01,
    MSG_EVENT_CLICK = 0x01,
    MSG_EVENT_DBCLICK = 0x02,
    MSG_EVENT_MOVE = 0x04,
    MSG_EVENT_WHEEL = 0x10,
};

enum message_mouse {
    MSG_MOUSE_LEFT = 0x01,
    MSG_MOUSE_RIGHT = 0x02,
    MSG_MOUSE_MID = 0x04,
};

/* CEGE常用的颜色（与EGE一致） */
enum COLORS {
    BLACK = 0,
    BLUE = EGERGB(0, 0, 0xA8),
    GREEN = EGERGB(0, 0xA8, 0),
    CYAN = EGERGB(0, 0xA8, 0xA8),
    RED = EGERGB(0xA8, 0, 0),
    MAGENTA = EGERGB(0xA8, 0, 0xA8),
    BROWN = EGERGB(0xA8, 0xA8, 0),
    LIGHTGRAY = EGERGB(0xA8, 0xA8, 0xA8),
    DARKGRAY = EGERGB(0x54, 0x54, 0x54),
    LIGHTBLUE = EGERGB(0x54, 0x54, 0xFC),
    LIGHTGREEN = EGERGB(0x54, 0xFC, 0x54),
    LIGHTCYAN = EGERGB(0x54, 0xFC, 0xFC),
    LIGHTRED = EGERGB(0xFC, 0x54, 0x54),
    LIGHTMAGENTA = EGERGB(0xFC, 0x54, 0xFC),
    YELLOW = EGERGB(0xFC, 0xFC, 0x54),
    WHITE = EGERGB(0xFC, 0xFC, 0xFC),
};

// 填充模式
enum fill_patterns {/* Fill patterns for get/setfillstyle */
    EMPTY_FILL,     /* fills area in background color */
    SOLID_FILL,     /* fills area in solid fill color */
    LINE_FILL,      /* --- fill */
    LTSLASH_FILL,   /* /// fill */
    SLASH_FILL,     /* /// fill with thick lines */
    BKSLASH_FILL,   /* \\\ fill with thick lines */
    LTBKSLASH_FILL, /* \\\ fill */
    HATCH_FILL,     /* light hatch fill */
    XHATCH_FILL,    /* heavy cross hatch fill */
    INTERLEAVE_FILL,/* interleaving line fill */
    WIDE_DOT_FILL,  /* Widely spaced dot fill */
    CLOSE_DOT_FILL, /* Closely spaced dot fill */
    USER_FILL       /* user defined fill */
};

enum text_just {        /* Horizontal and vertical justification
                        for settextjustify */
    LEFT_TEXT = 0,
    CENTER_TEXT = 1,
    RIGHT_TEXT = 2,

    BOTTOM_TEXT = 0,
    /* CENTER_TEXT = 1,  already defined above */
    TOP_TEXT = 2
};

enum line_styles {      /* Line styles for get/setlinestyle */
    SOLID_LINE = PS_SOLID,
    CENTER_LINE = PS_DASH,
    DOTTED_LINE = PS_DOT,
    DASHED_LINE = PS_DASHDOT,
    NULL_LINE = PS_NULL,
    USERBIT_LINE = PS_USERSTYLE,   /* User defined line style */
};

enum key_msg_flag {
    KEYMSG_CHAR_FLAG = 2,
    KEYMSG_DOWN_FLAG = 1,
    KEYMSG_UP_FLAG = 1,

    KEYMSG_CHAR = 0x40000,
    KEYMSG_DOWN = 0x10000,
    KEYMSG_UP = 0x20000,
    KEYMSG_FIRSTDOWN = 0x80000,
};

enum music_state_flag {
    MUSIC_MODE_NOT_OPEN = 0x0,
    MUSIC_MODE_NOT_READY = 0x20C,
    MUSIC_MODE_PAUSE = 0x211,
    MUSIC_MODE_PLAY = 0x20E,
    MUSIC_MODE_STOP = 0x20D,
    MUSIC_MODE_OPEN = 0x212,
    MUSIC_MODE_SEEK = 0x210,
};

enum initmode_flag {
    INIT_NOBORDER = 0x1,
    INIT_CHILD = 0x2,
    INIT_TOPMOST = 0x4,
    INIT_RENDERMANUAL = 0x8,
    INIT_NOFORCEEXIT = 0x10,
    INIT_WITHLOGO = 0x100,
#if defined(_DEBUG) || defined(DEBUG)
    INIT_DEFAULT = 0x0,
#else
    INIT_DEFAULT = INIT_WITHLOGO,
#endif
    INIT_ANIMATION = INIT_DEFAULT | INIT_RENDERMANUAL | INIT_NOFORCEEXIT,
};

typedef enum {
    RENDER_AUTO,
    RENDER_MANUAL,
} rendermode_e;

typedef enum key_code_e {
    key_mouse_l = 0x01,
    key_mouse_r = 0x02,
    key_mouse_m = 0x04,
    key_back = 0x08,
    key_tab = 0x09,
    key_enter = 0x0d,
    key_shift = 0x10,
    key_control = 0x11,
    key_menu = 0x12,
    key_pause = 0x13,
    key_capslock = 0x14,
    key_esc = 0x1b,
    key_space = 0x20,

    key_pageup = 0x21,
    key_pagedown = 0x22,
    key_home = 0x23,
    key_end = 0x24,

    key_left = 0x25,
    key_up = 0x26,
    key_right = 0x27,
    key_down = 0x28,

    key_print = 0x2a,
    key_snapshot = 0x2c,
    key_insert = 0x2d,
    key_delete = 0x2e,

    key_0 = 0x30,
    key_1 = 0x31,
    key_2 = 0x32,
    key_3 = 0x33,
    key_4 = 0x34,
    key_5 = 0x35,
    key_6 = 0x36,
    key_7 = 0x37,
    key_8 = 0x38,
    key_9 = 0x39,

    key_A = 0x41,
    key_Z = 0x5a,
    key_win_l = 0x5b,
    key_win_r = 0x5c,

    key_sleep = 0x5f,

    key_num0 = 0x60,
    key_num1 = 0x61,
    key_num2 = 0x62,
    key_num3 = 0x63,
    key_num4 = 0x64,
    key_num5 = 0x65,
    key_num6 = 0x66,
    key_num7 = 0x67,
    key_num8 = 0x68,
    key_num9 = 0x69,

    key_f1 = 0x70,
    key_f2 = 0x71,
    key_f3 = 0x72,
    key_f4 = 0x73,
    key_f5 = 0x74,
    key_f6 = 0x75,
    key_f7 = 0x76,
    key_f8 = 0x77,
    key_f9 = 0x78,
    key_f10 = 0x79,
    key_f11 = 0x7a,
    key_f12 = 0x7b,

    key_numlock = 0x90,
    key_scrolllock = 0x91,

    key_shift_l = 0xa0,
    key_shift_r = 0xa1,
    key_control_l = 0xa2,
    key_control_r = 0xa3,
    key_menu_l = 0xa4,
    key_menu_r = 0xa5,

    key_semicolon = 0xba,
    key_plus = 0xbb,
    key_comma = 0xbc,
    key_minus = 0xbd,
    key_period = 0xbe,
    key_slash = 0xbf,
    key_tilde = 0xc0,
    key_lbrace = 0xdb,
    key_backslash = 0xdc,
    key_rbrace = 0xdd,
    key_quote = 0xde,

    key_ime_process = 0xe5,
} key_code_e;

typedef enum key_msg_e {
    key_msg_down = 1,
    key_msg_up = 2,
    key_msg_char = 4,
} key_msg_e;

typedef enum key_flag_e {
    key_flag_shift = 0x100,
    key_flag_ctrl = 0x200,
} key_flag_e;

typedef enum mouse_msg_e {
    mouse_msg_down = 0x10,
    mouse_msg_up = 0x20,
    mouse_msg_move = 0x40,
    mouse_msg_wheel = 0x80,
} mouse_msg_e;

typedef enum mouse_flag_e {
    mouse_flag_left = 1,
    mouse_flag_right = 2,
    mouse_flag_mid = 4,
    mouse_flag_shift = 0x100,
    mouse_flag_ctrl = 0x200,
} mouse_flag_e;

typedef enum pattern_type_e {
    pattern_none = 0,
    pattern_lineargradient = 1,
    pattern_pathgradient = 2,
    pattern_texture = 3,
} pattern_type_e;

typedef unsigned int color_t;

typedef struct key_msg {
    UINT msg;
    UINT key;
    UINT flags;
} key_msg;

typedef struct mouse_msg {
    int             x;
    int             y;
    mouse_msg_e     msg;
    unsigned int    flags;
    int             wheel;
} mouse_msg;

/*
 * 鼠标信息的判断宏
 * cege_mouse_isLeft(msg) 对应EGE中的msg.is_left()，依次类推
 */
#define cege_mouse_isLeft(msg)   (((msg).flags & mouse_flag_left) != 0)
#define cege_mouse_isLight(msg)  (((msg).flags & mouse_flag_right) != 0)
#define cege_mouse_isMid(msg)    (((msg).flags & mouse_flag_mid) != 0)
#define cege_mouse_isDown(msg)   ((msg).msg == mouse_msg_down)
#define cege_mouse_isUp(msg)     ((msg).msg == mouse_msg_up)
#define cege_mouse_isMove(msg)   ((msg).msg == mouse_msg_move)
#define cege_mouse_isWheel(msg)  ((msg).msg == mouse_msg_wheel)

typedef struct ege_point {
    float x;
    float y;
}ege_point;
 
typedef struct ege_rect {
    float x;
    float y;
    float w;
    float h;
}ege_rect;

typedef struct ege_colpoint {
    float   x;
    float   y;
    color_t color;
}ege_colpoint;

#ifndef PI
#define PI  3.1415926535897932384626
#endif

typedef struct {
    void *_PIMAGE;
} *PIMAGE;

typedef struct {
    void *_music;
} *MUSIC;

/* 绘图环境相关函数 */
void cege_initgraph(int w, int h, int flag);
void cege_closegraph(void);
int  cege_is_run(void);
void cege_setcaption(const char *caption);
void cege_setrendermode(rendermode_e mode);
void cege_setinitmode(int mode, int x, int y);
void cege_cleardevice(PIMAGE pimg);
PIMAGE cege_gettarget(void);
void cege_settarget(PIMAGE pbuf);
void cege_getviewport(int *pleft, int *ptop, int *pright, int *pbottom, int *pclip, PIMAGE pimg);
void cege_setviewport(int left, int top, int right, int bottom, int clip, PIMAGE pimg);           // 设置视图
void cege_clearviewport(PIMAGE pimg);
void cege_window_getviewport(int *pleft, int *ptop, int *pright, int *pbottom);
void cege_window_setviewport(int left, int top, int right, int bottom);


/* 绘制图形相关函数 */
void cege_arc(int x, int y, int stangle, int endangle, int radius, PIMAGE pimg);
void cege_bar(int left, int top, int right, int bottom, PIMAGE pimg);
void cege_bar3d(int left, int top, int right, int bottom, int depth, int topflag, PIMAGE pimg);
void cege_circle(int x, int y, int radius, PIMAGE pimg);
void cege_drawbezier(int numpoints, const int *polypoints, PIMAGE pimg);
void cege_drawlines(int numliness, const int *polypoints, PIMAGE pimg);
void cege_drawpoly(int numliness, const int *polypoints, PIMAGE pimg);
void cege_ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius, PIMAGE pimg);
void cege_fillpoly(int numpoints, const int *polypoints, PIMAGE pimg);
void cege_floodfill(int x, int y, int border, PIMAGE pimg);
void cege_floodfillsurface(int x, int y, color_t areacolor, PIMAGE pimg);
int  cege_getheight(PIMAGE pimg);
color_t cege_cgetpixel(int x, int y, PIMAGE pimg);
int  cege_getwidth(PIMAGE pimg);
int  cege_getx(PIMAGE pimg);
int  cege_gety(PIMAGE pimg);
void cege_line(int x1, int y1, int x2, int y2, PIMAGE pimg);
void cege_linerel(int dx, int dy, PIMAGE pimg );
void cege_lineto(int x, int y, PIMAGE pimg);
void cege_moverel(int dx, int dy, PIMAGE pimg);
void cege_moveto(int x, int y, PIMAGE pimg);
void cege_pieslice(int x, int y, int stangle, int endangle, int radius, PIMAGE pimg);
void cege_putpixel(int x, int y, color_t color, PIMAGE pimg);
void cege_putpixels(int nPoint, int *pPoints, PIMAGE pimg);
void cege_rectangle(int left, int top, int right, int bottom, PIMAGE pimg);
void cege_sector(int x, int y, int stangle, int endangle, int xradius, int yradius, PIMAGE pimg);
void cege_setlinestyle(int linestyle, WORD upattern, int thickness, PIMAGE pimg);
void cege_setlinewidth(float thickness, PIMAGE pimg);
void cege_setwritemode(int mode, PIMAGE pimg);

// 高级绘图函数（带AA）
// ege new_api
void cege_ege_enable_aa(int enable, PIMAGE pimg);
void cege_ege_line(float x1, float y1, float x2, float y2, PIMAGE pimg);
void cege_ege_drawpoly(int numpoints, ege_point* polypoints, PIMAGE pimg);
void cege_ege_drawcurve(int numpoints, ege_point* polypoints, PIMAGE pimg);
void cege_ege_rectangle(float x, float y, float w, float h, PIMAGE pimg);
void cege_ege_ellipse(float x, float y, float w, float h, PIMAGE pimg);
void cege_ege_pie(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg);
void cege_ege_arc(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg);
void cege_ege_bezier(int numpoints, ege_point* polypoints, PIMAGE pimg);
void cege_ege_fillpoly(int numpoints, ege_point* polypoints, PIMAGE pimg);
void cege_ege_fillrect(float x, float y, float w, float h, PIMAGE pimg);
void cege_ege_fillellipse(float x, float y, float w, float h, PIMAGE pimg);
void cege_ege_fillpie(float x, float y, float w, float h, float stangle, float sweepAngle, PIMAGE pimg);
void cege_ege_setpattern_none(PIMAGE pimg);
void cege_ege_setpattern_lineargradient(float x1, float y1, color_t c1, float x2, float y2, color_t c2, PIMAGE pimg);
void cege_ege_setpattern_pathgradient(ege_point center, color_t centercolor,
    int count, ege_point* points, int colcount, color_t* pointscolor, PIMAGE pimg);
void cege_ege_setpattern_ellipsegradient(ege_point center, color_t centercolor,
    float x, float y, float w, float h, color_t color, PIMAGE pimg);
void cege_ege_setpattern_texture(PIMAGE srcimg, float x, float y, float w, float h, PIMAGE pimg);

void cege_ege_setalpha(int alpha, PIMAGE pimg);
void cege_ege_gentexture(int gen, PIMAGE pimg);
void cege_ege_puttexture(PIMAGE srcimg, ege_rect dest, ege_rect src, PIMAGE pimg);


/* 颜色表示及相关函数 */
color_t cege_getbkcolor(PIMAGE pimg);
color_t cege_getcolor(PIMAGE pimg);
color_t cege_getfillcolor(PIMAGE pimg);
color_t cege_hsl2rgb(float H, float S, float L);
color_t cege_hsv2rgb(float H, float S, float V);
color_t cege_rgb2gray(color_t rgb);
void cege_rgb2hsl(color_t rgb, float *H, float *S, float *L);
void cege_rgb2hsv(color_t rgb, float *H, float *S, float *V);
void cege_setbkcolor(color_t color, PIMAGE pimg);
void cege_setbkcolor_f(color_t color, PIMAGE pimg);
void cege_setbkmode(int iBkMode, PIMAGE pimg);
void cege_setcolor(color_t color, PIMAGE pimg);
void cege_setfillcolor(color_t color, PIMAGE pimg);
void cege_setfontbkcolor(color_t color, PIMAGE pimg);

/* 文字输出相关函数 */
void cege_getfont(LOGFONT *font, PIMAGE pimg);
void cege_outtext(const char *textstring, PIMAGE pimg);
void cege_outtextrect(int x, int y, int w, int h, const char *textstring, PIMAGE pimg);
void cege_outtextxy(int x, int y, const char *textstring, PIMAGE pimg);
void cege_rectprintf(int x, int y, int w, int h, const char *textstring, ...);
void cege_xyprintf(int x, int y, const char *fmt, ...); 

void cege_setfont(int nHeight, int nWidth, LPCSTR lpszFace, PIMAGE pimg);
void cege_setfont_all(
    int nHeight, 
    int nWidth, 
    const char *lpszFace, 
    int nEscapement, 
    int nOrientation,  
    int nWeight, 
    int bItalic, 
    int bUnderline, 
    int bStrikeOut, 
    PIMAGE pimg);
void cege_settextjustify(int horiz, int vert, PIMAGE pimg);
int  cege_textheight(const char *textstring, PIMAGE pimg);
int  cege_textwidth(const char *textstring, PIMAGE pimg);


/* 图像处理相关函数 */
PIMAGE cege_newimage(int width, int height);
void   cege_delimage(PIMAGE pImg); 
void   cege_getimage_from_pimage(
    PIMAGE pDstImg, 
    const PIMAGE pSrcImg, 
    int srcX, 
    int srcY, 
    int srcWidth, 
    int srcHeight
);
void cege_getimage(
    PIMAGE pDstImg,       // 保存图像的 IMAGE 对象指针
    const char *pImgFile,     // 图片文件名
    int zoomWidth,    // 设定图像缩放至的宽度（0 表示默认宽度，不缩放）
    int zoomHeight);    // 设定图像缩放至的高度（0 表示默认高度，不缩放）
int cege_imagefilter_blurring(
    PIMAGE imgdest, 
    int intensity, 
    int alpha,         
    int nXOriginDest, 
    int nYOriginDest, 
    int nWidthDest, 
    int nHeightDest);
void cege_putimage(
    PIMAGE pDstImg, 
    int dstX, 
    int dstY, 
    int dstWidth, 
    int dstHeight,
    PIMAGE pSrcImg, 
    int srcX, 
    int srcY, 
    int srcWidth, 
    int srcHeight, 
    DWORD dwRop); 
int cege_putimage_alphablend(
    PIMAGE imgdest, 
    PIMAGE imgsrc, 
    int nXOriginDest, 
    int nYOriginDest, 
    unsigned char alpha,
    int nXOriginSrc, 
    int nYOriginSrc, 
    int nWidthSrc, 
    int nHeightSrc);
int cege_putimage_transparent(
    PIMAGE imgdest, 
    PIMAGE imgsrc, 
    int nXOriginDest, 
    int nYOriginDest, 
    color_t crTransparent,
    int nXOriginSrc, 
    int nYOriginSrc, 
    int nWidthSrc, 
    int nHeightSrc);
int cege_putimage_alphatransparent(
    PIMAGE imgdest, 
    PIMAGE imgsrc, 
    int nXOriginDest, 
    int nYOriginDest, 
    color_t crTransparent, 
    unsigned char alpha,
    int nXOriginSrc, 
    int nYOriginSrc, 
    int nWidthSrc, 
    int nHeightSrc);


/*  键盘鼠标输入函数 */
int cege_getch(void);
key_msg   cege_getkey(void);
mouse_msg cege_getmouse(void);
int  cege_kbhit(void);
int  cege_kbmsg(void);
int  cege_keystate(int key);
void cege_flushmouse(void);
int  cege_mousemsg(void);
int  cege_mousepos(int *x, int *y);
int  cege_showmouse(int bShow);


/* 时间函数 */
void   cege_api_sleep(long dwMilliseconds);
void   cege_delay(long Milliseconds);
void   cege_delay_ms(long Milliseconds);
void   cege_delay_fps(double fps);
void   cege_delay_jfps(double fps);
double cege_fclock(void);

/* 数学函数 */


/* 随机函数 */
unsigned int cege_random(unsigned int n);
double cege_randomf(void);
void   cege_randomize(void);

/* 其他函数 */
float cege_getfps(void);
int   cege_inputbox_getline(const char *title, const char *text, char *buf, int len);


/* 音乐播放 */
#define MUSIC_ERROR  0xFFFFFFFF

MUSIC cege_MUSIC_New(void);
void  cege_MUSIC_Delete(MUSIC music);
int   cege_MUSIC_IsOpen(MUSIC music);
int   cege_MUSIC_OpenFile(MUSIC music, const char *filepath);
int   cege_MUSIC_Play(MUSIC music, int dwFrom, int dwTo);
int   cege_MUSIC_Pause(MUSIC music);
int   cege_MUSIC_Seek(MUSIC music, int dwTo);
int   cege_MUSIC_SetVolume(MUSIC music, float value);
int   cege_MUSIC_Close(MUSIC music);
int   cege_MUSIC_Stop(MUSIC music);
unsigned long cege_MUSIC_GetPosition(MUSIC music);
unsigned long cege_MUSIC_GetLength(MUSIC music);


#ifdef __cplusplus   
}       /* extern "C" { */
#endif  

#if  defined(_MSC_VER) && !defined(__CEGE_EGE__)
#pragma comment(lib, "cege.lib")
#endif

#ifndef __CEGE_EGE__
#if defined(_MSC_VER) && (defined(HIDE_CONSOLE) || !defined(SHOW_CONSOLE))
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif
#endif  /* !__CEGE_EGE__ */

#endif  /* !__CEGE_H__ */
