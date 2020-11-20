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
#include <cstdlib>
#include <iostream>

#include "image.cc"

using std::clog;
using std::endl;

using ceng391::Image;

int main(int argc, char** argv)
{
        Image *img = new Image(200, 100,4);

        clog << "Created new image of size " << img->w()
             << "x" << img->h() << " with " << img->n_ch() << endl;

        img->set_zero();
        img->set_rect(50, 50, 10, 30, 255);

        img->write_pnm("Q1_RGB_Image");

        Image *image_rgba = new Image(200, 100,4); //new image for  rgba to grayscale
        image_rgba->set_zero();
        image_rgba->set_rect(50, 50, 10, 30, 255);
        //image_rgba->save_as_pnm("grayImage");
        image_rgba->to_grayscale(); // calls to grayscale method.

        Image *img_gray = new Image(200, 100,1); // new image for graysale to  rgba
        img_gray->set_zero();
        img_gray->set_rect(50, 50, 10, 30, 255);
        //img_gray->save_as_pnm("grayImage");
        img_gray->to_rgba(); // calls to rgba method.
    


        delete img;
        delete image_rgba;
        delete img_gray;

        return EXIT_SUCCESS;
}
