// // Ramazan Arslan 250201023
// Written by Mustafa Ozuysal
// Contact <mustafaozuysal@iyte.edu.tr> for comments and bug reports
// ------------------------------
// Copyright (c) 2020, Mustafa Ozuysal
// All rights reserved.
// ------------------------------
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holders nor the
//       names of his/its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
// ------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ------------------------------
#include "image.hpp"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using std::cerr;
using std::clog;
using std::endl;
using std::exit;
using std::ios;
using std::ofstream;
using std::string;


namespace ceng391 {

Image::Image(int width, int height, int n_channels, int step)
        : m_width(width), m_height(height), m_n_channels(n_channels)
{
        if (step < width * n_channels)
                step = width * n_channels;
        m_step = step;
        m_data = new uchar[m_height * m_step];
}

Image::~Image()
{
        // clog << "Deleting image" << endl;
        delete [] m_data;
}

Image *Image::new_gray(int width, int height)
{
        return new Image(width, height, 1);
}

void Image::set_rect(int tlx, int tly, int width, int height, uchar value)
{
        if (tlx < 0) {
                width += tlx;
                tlx = 0;
        }

        if (tly < 0) {
                height += tly;
                tly = 0;
        }

         if (m_n_channels != 1) {
                for (int y = tly; y < tly + height; ++y) {
                        if (y >= m_height)
                                break;
                        uchar *row = m_data + y * m_step;
                        for (int x = tlx*m_n_channels ; x < (tlx + width)*m_n_channels; x+= m_n_channels) {
                                if (x >= m_width*m_n_channels) //When I create an rgba image with 4 channels,
                                        break;//makes the assignments with an extra 1 for loop so that the other 3 channels are not empty.
                                for (int c = 0; c < m_n_channels; ++c) {
                                row[x+c] = value;
                                }
                        
                        }
                        
                }
         }


         else{

                for (int y = tly; y < tly + height; ++y) {
                        if (y >= m_height)
                                break;
                        uchar *row = m_data + y * m_step;
                        for (int x = tlx; x < tlx + width ; ++x) {
                                if (x >= m_width)
                                        break;
                                row[x] = value;
                        }
                }
        }
         
        
}


void Image::write_pnm(const std::string &filename) //creates files and renders pixel by pixel
{
        if (m_n_channels != 1) {
                const string magic_head = "P6"; // P6 for rgba image
                ofstream fout;
                string extended_name = filename + ".ppm"; // ppm for rgba image
                fout.open(extended_name.c_str(), ios::out | ios::binary);
                fout << magic_head << "\n";
                fout << m_width << " " << m_height << " 255\n";
                for (int y = 0; y < m_height; ++y) {
                        const uchar *row_data = this->data(y);
                        uchar *row_datam = new uchar[m_width*3]; //creates new pointer for multichannel (r g b)
                        int index =0;
                        for (int aa =0; aa < m_width*m_n_channels ; ++aa){
                                if((aa+1) % 4 != 0){ //condition to exclude alpha value
                                        row_datam[index] = row_data[aa]; //If it is not alpha, it makes an assignment.
                                        index++;
                                }
                        }
                        fout.write(reinterpret_cast<const char*>(row_datam), (m_n_channels-1)*m_width*sizeof(uchar));//writes ımage
                }
                fout.close();
        }
        else{
                const string magic_head = "P5";
                ofstream fout;
                string extended_name = filename + ".pgm";
                fout.open(extended_name.c_str(), ios::out | ios::binary);
                fout << magic_head << "\n";
                fout << m_width << " " << m_height << " 255\n";
                for (int y = 0; y < m_height; ++y) {
                        const uchar *row_data = this->data(y);
                        fout.write(reinterpret_cast<const char*>(row_data), m_width*sizeof(uchar));
                }
                fout.close();
        }

}
void Image::to_grayscale(){ // converts rgba to grayscale

        Image *image_gray = Image::new_gray(200, 100); // creates new grayscale image
        uchar *temp = image_gray->data(); //gets the address of the new ımage
        uchar *rgba = this->data(); //gets the address of the calling image
        
        int i =0; //Creates the grayscale image by multiplying the values ​​of the multichannel image by the necessary coefficients.
        for(int a = 0; a<m_n_channels*m_width*m_height; a+=m_n_channels){ // r*0.3 + g*0.59 + b*0.11
                temp[i] = (rgba[a]*0.3)+(rgba[a+1]*0.59)+(rgba[a+2]*0.11);
                i++;
        }
        image_gray->write_pnm("Q3_RgbaToGray_Image"); // creates ımage
     
}
void Image::to_rgba(){ // converts grayscale to rgba

        Image *image_rgb = new Image(m_width,m_height,4); //creates new rgba image

        uchar *temp = image_rgb->data(); //gets the address of the new ımage
        uchar *gray = this->data(); //gets the address of the calling image
        
        for(int a = 0; a < (m_width*m_height) ; ++a){ //Creates rgba image according to the values ​​of grayscale image.
                temp[(a*4)] = gray[a]; //4 channel of rgba image matces grayscale image's 1 channel values . 
                temp[(a*4)+1] = gray[a];  
                temp[(a*4)+2] = gray[a];  
                temp[(a*4)+3] = gray[a];  
            
        }
        image_rgb->write_pnm("Q3_GrayToRgb_Image");// creates ımage
     
}

}
