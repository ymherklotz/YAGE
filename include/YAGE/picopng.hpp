/* ----------------------------------------------------------------------------
 * picopng.hpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com> -- MIT License
 * See file LICENSE for more details
 * ----------------------------------------------------------------------------
 */

#include <vector>
#include <cstdlib>

namespace yage
{

extern int decodePNG(std::vector<unsigned char> &out_image,
					 unsigned long &image_width,
					 unsigned long &image_height,
					 const unsigned char *in_png,
					 size_t in_size,
					 bool convert_to_rgba32 = true);

} // yage
