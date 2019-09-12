/* graphics.h
 * CEGE图形库的标头
 *
 * 这个头文件尽量兼容了原有的EGE同名函数的常用重载
 * 对于大部分函数，最后一个IMAGE参数默认为NULL（即屏幕）
 * 提供常用函数的简单版本
 * 这里面的所有函数宏都对应一个以cege_开头的同名函数
 * 具体信息参见 cege.h
 *
 *  V1.2
 *  Ma Xiaobo  2018-12
 */

#ifndef __GRAPHICS_CEGE_H__
#define __GRAPHICS_CEGE_H__

#include "cege.h"

/* 兼容部分EGE 
 * 不建议使用以下的宏来使用CEGE，这些宏容易和其他函数冲突
 * 如果要禁止它们，请在包含此头文件之前定义宏 CEGE_NO_EGE
 */
#ifndef CEGE_NO_EGE 

#define true  1
#define false 0

#define cleardevice()                          cege_cleardevice(SCREEN)
#define clearviewport()                        cege_clearviewport(SCREEN)
#define closegraph()                           cege_closegraph()
#define gettarget()                            cege_cgettarget()
#define getviewport(pleft, ptop, pright, pbottom, pclip)  cege_getviewport(pleft, ptop, pright, pbottom, pclip, SCREEN)
#define initgraph(w, h)                        cege_initgraph(w, h, 0)
#define is_run()                               cege_is_run()
#define setcaption(caption)                    cege_setcaption(caption)
#define setinitmode(mode, x, y)                cege_setinitmode(mode, x, y)
#define setrendermode(mode)                    cege_setrendermode(mode)
#define settarget(pbuf)                        cege_settarget(pbuf)

#define window_getviewport(pleft, ptop, pright, pbottom)  cege_window_getviewport(pleft, ptop, pright, pbottom)
#define window_setviewport(left, top, right, bottom)      cege_window_setviewport(left, top, right, bottom)

#define arc(x, y, strangle, endangle)          cege_arc(x, y, stangle, endangle, radius, SCREEN)
#define bar(left, top, right, bottom)          cege_bar(left, top, right, bottom, SCREEN)
#define bar3d(left, top, right, bottom, depth) cege_bar3d(left, top, right, bottom, depth, topflag, SCREEN)
#define circle(x, y, radius)                   cege_circle(x, y, radius, SCREEN);
#define drawbezier(numpoints, polypoints)      cege_drawbezier(numpoints, polypoints, SCREEN)
#define drawlines(numliness, polypoints)       cege_drawlines(numliness, polypoints, SCREEN)
#define drawpoly(numliness, polypoints)        cege_drawpoly(numliness, polypoints, SCREEN)
#define ellipse(x, y, stangle, endangle, xradius, yradius)  cege_ellipse(x, y, stangle, endangle, xradius, yradius, SCREEN)
#define fillpoly(numpoints, polypoints)        cege_fillpoly(numpoints, polypoints, SCREEN)
#define floodfill(x, y, border)                cege_floodfill(x, y, border, SCREEN)
#define floodfillsurface(x, y, areacolor)      cege_floodfillsurface(x, y, areacolor, SCREEN)
#define getheight()                            cege_getheight(SCREEN)
#define cgetpixel(x, y)                        cege_cgetpixel(x, y, SCREEN)
#define getwidth()                             cege_getwidth(SCREEN)
#define getx()                                 cege_getx(SCREEN)
#define gety()                                 cege_gety(SCREEN)
#define line(x1, y1, x2, y2)                   cege_line(x1, y1, x2, y2, SCREEN)
#define cege_linerel(dx, dy)                   cege_linerel(dx, dy, SCREEN)
#define lineto(x, y)                           cege_lineto(x, y, SCREEN)
#define moverel(dx, dy)                        cege_moverel(dx, dy, SCREEN)
#define moveto(x, y)                           cege_moveto(x, y, SCREEN)
#define pieslice(x, y, stangle, endangle, radius)  cege_pieslice(x, y, stangle, endangle, radius, SCREEN)
#define putpixel(x, y, color)                  cege_putpixel(x, y, color, SCREEN)
#define putpixels(nPoint, pPoints)             cege_putpixels(nPoint, pPoints, SCREEN)
#define rectangle(left, top, right, bottom)    cege_rectangle(left, top, right, bottom, SCREEN)
#define sector(x, y, stangle, endangle, xradius, yradius)   cege_sector(x, y, stangle, endangle, xradius, yradius, SCREEN)
#define setlinestyle(linestyle, upattern, thickness)        cege_setlinestyle(linestyle, upattern, thickness, SCREEN)
#define setlinewidth(thickness)                cege_setlinewidth(thickness, SCREEN)
#define setwritemode(mode)                     cege_setwritemode(int mode, SCREEN)

#define ege_enable_aa(enable)                    cege_ege_enable_aa(enable, SCRE)
#define ege_line(x1, y1, x2, y2)                 cege_ege_line(x1, y1, x2, y2, SCREEN);
#define ege_drawpoly(numpoints, polypoints)      cege_ege_drawpoly(numpoints, polypoints, SCREEN)
#define ege_drawcurve(numpoints, polypoints)     cege_ege_drawcurve(numpoints, polypoints, SCREEN)
#define ege_rectangle(x, y, w, h)                cege_ege_rectangle(x, y, w, h, SCREEN)
#define ege_ellipse(x, y, w, h)                  cege_ege_ellipse(x, y, w, h, SCREEN)
#define ege_pie(x, y, w, h, stangle, sweepAngle) cege_ege_pie(x, y, w, h, stangle, sweepAngle, SCREEN)
#define ege_arc(x, y, w, h, stangle, sweepAngle) cege_ege_arc(x, y, w, h, stangle, sweepAngle, SCREEN)
#define ege_bezier(numpoints, polypoints)        cege_ege_bezier(numpoints, polypoints, SCREEN)
#define ege_fillpoly(numpoints, polypoints)      cege_ege_fillpoly(numpoints, polypoints, SCREEN)
#define ege_fillrect(x, y, w, h)                 cege_ege_fillrect(x, y, w, h, SCREEN)
#define ege_fillellipse(x, y, w, h)              cege_ege_fillellipse(x, y, w, h, SCREEN)
#define ege_fillpie(x, y, w, h, stangle, sweepAngle) cege_ege_fillpie(x, y, w, h, stangle, sweepAngle, SCREEN)
#define ege_setpattern_none()                    cege_ege_setpattern_none(SCREEN)
#define ege_setpattern_lineargradient(x1, y1, c1, x2, y2, c2)   cege_ege_setpattern_lineargradient(x1, y1, c1, x2, y2, c2, SCREEN)
#define ege_setpattern_pathgradient(center, centercolor, count, points, colcount, pointscolor)      cege_ege_setpattern_pathgradient(center, centercolor, count, points, colcount, pointscolor, SCREEN)
#define ege_setpattern_ellipsegradient(center, centercolor, x, y, w, h, color)      cege_ege_setpattern_ellipsegradient(center, centercolor, x, y, w, h, color, SCREEN)
#define ege_setpattern_texture()               cege_ege_setpattern_texture(srcimg, x, y, w, h, SCREEN)
#define ege_setalpha(alpha)                    cege_ege_setalpha(alpha, SCREEN)
#define ege_gentexture(gen)                    cege_ege_gentexture(gen, SCREEN)
#define ege_puttexture(srcimg, dest, src)      cege_ege_puttexture(srcimg, dest, src, SCREEN)

#define getbkcolor()                           cege_getbkcolor(SCREEN)
#define getcolor()                             cege_getcolor(SCREEN)
#define getfillcolor()                         cege_getfillcolor(SCREEN)
#define hsl2rgb(H, S, L)                       cege_hsl2rgb(H, S, L)
#define hsv2rgb(H, S, V)                       cege_hsv2rgb(H, S, V)
#define rgb2gray(rgb)                          cege_rgb2gray(rgb)
#define rgb2hsl(rgb, H, S, L)                  cege_rgb2hsl(rgb, H, S, L)
#define rgb2hsv(rgb, H, S, V)                  cege_rgb2hsv(rgb, H, S, V)
#define setbkcolor(color)                      cege_setbkcolor(color, SCREEN)
#define setbkcolor_f(color)                    cege_setbkcolor_f(color, SCREEN)
#define setbkmode(iBkMode)                     cege_setbkmode(iBkMode, SCREEN)
#define setcolor(color)                        cege_setcolor(color, SCREEN)
#define setfillcolor(color)                    cege_setfillcolor(color, SCREEN)
#define setfontbkcolor(color)                  cege_setfontbkcolor(color, SCREEN)

#define RGBtoGRAY   rgb2gray
#define RGBtoHSL    rgb2hsl
#define RGBtoHSV    rgb2hsv
#define HSLtoRGB    hsl2rgb
#define HSVtoRGB    hsv2rgb

#define getfont(font)                          cege_getfont(font, SCREEN);
#define outtext(textstring)                    cege_outtext(textstring, SCREEN)
#define outtextrect(x, y, w, h, textstring)    cege_outtextrect(x, y, w, h, textstring, SCREEN)
#define outtextxy(x, y, textstring)            cege_outtextxy(x, y, textstring, SCREEN)
//#define cege_rectprintf(x, y, w, h, SCREEN, textstring, ...)  cege_rectprintf(x, y, w, h, SCREEN, textstring)
#define setfont(nHeight, nWidth, lpszFace)     cege_setfont(nHeight, nWidth, lpszFace, SCREEN)
#define settextjustify(horiz, vert)            cege_settextjustify(horiz, vert, SCREEN)
#define textheight(textstring)                 cege_textheight(textstring, SCREEN)
#define textwidth(textstring)                  cege_textwidth(textstring, SCREEN)

#define getimage(pDstImg, pImgFile)            cege_getimage(pDstImg, pImgFile, 0, 0)
#define putimage(dstX, dstY, pSrcImg)          cege_putimage(SCREEN, dstX, dstY, 0, 0, pSrcImg, 0, 0, 0, 0, SRCCOPY);
#define newimage()                             cege_newimage(0, 0)
#define delimage(pImg)                         cege_delimage(pImg)
/* 未完 */

#define getch()                     cege_getch()
#define getkey()                    cege_getkey()
#define getmouse()                  cege_getmouse()
#define kbhit()                     cege_kbhit()
#define flushmouse()                cege_flushmouse()
#define keystate(key)               cege_keystate(key)
#define mousemsg()                  cege_mousemsg()
#define mousepos(x, y)              cege_mousepos(x, y)
#define showmouse(bShow)            cege_showmouse(int bShow)

#define api_sleep(dwMilliseconds)   cege_api_sleep(dwMilliseconds)
#define delay(dwMilliseconds)       cege_delay(Milliseconds)
#define delay_ms(dwMilliseconds)    cege_delay_ms(Milliseconds)
#define delay_fps(fps)              cege_delay_fps(fps)
#define delay_jfps(fps)             cege_delay_jfps(fps)
#define fclock()                    cege_fclock()

#define random(n)                   cege_random(n)
#define randomf()                   cege_randomf()
#define randomize()                 cege_randomize()

#define getfps()                    cege_getfps()
#define inputbox_getline(title, text, buf, len)     cege_inputbox_getline(title, text, buf, len)

#endif  /* !CEGE_NO_EGE */

#endif  /* !__GRAPHICS_CEGE_H__ */
