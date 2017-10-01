/**
 *  @filename   :   epd4in2.h
 *  @brief      :   Header file for Dual-color e-paper library epd4in2.cpp
 *  @author     :   Yehui from Waveshare
 *  
 *  Copyright (C) Waveshare     August 10 2017
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef EPDLIB_H
#define EPDLIB_H

// Display resolution
#define EPD_WIDTH       400
#define EPD_HEIGHT      300

#define EPD_PLL_50HZ	0x3C
#define EPD_PLL_67HZ	0x3B
#define EPD_PLL_100HZ	0x3A
#define EPD_PLL_150HZ	0x29
#define EPD_PLL_200HZ	0x39

extern const unsigned char lut_vcom0[];
extern const unsigned char lut_ww[];
extern const unsigned char lut_bw[];
extern const unsigned char lut_bb[];
extern const unsigned char lut_wb[];

class Epd {
public:
    unsigned int width;
    unsigned int height;

    Epd(int cs_pin, int dc_pin, int busy_pin, int rst_pin);
    ~Epd();
    int  Init(unsigned char frame_rate = EPD_PLL_50HZ, unsigned int spi_speed = 2000000);
    void WaitUntilIdle(void);
    void Reset(void);
    void SetPartialWindow(const unsigned char* frame_buffer, int x, int y, int w, int l);
    void SetPartialWindowBlack(const unsigned char* buffer_black, int x, int y, int w, int l);
    void SetPartialWindowRed(const unsigned char* buffer_red, int x, int y, int w, int l);
    void DisplayFrame(const unsigned char* frame_buffer);
    void DisplayFrame(void);
    void ClearFrame(void);
    void Sleep(void);

private:
    void SendCommand(unsigned char command);
    void SendData(unsigned char data);
    void SpiTransfer(unsigned char data);
    void SetLut(void);

    unsigned int reset_pin;
    unsigned int dc_pin;
    unsigned int cs_pin;
    unsigned int busy_pin;
};

#endif /* EPDLIB_H */

/* END OF FILE */
