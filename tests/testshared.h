/** ---------------------------------------------------------------------------
 * -*- c++ -*-
 * @file: testshared.h
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#pragma once

#define OPENGL_TEST_MAIN(LOGLEVEL)                                             \
    int main(int argc, char **argv)                                            \
    {                                                                          \
        yLogger.setLevel(LOGLEVEL);                                            \
        ::testing::InitGoogleTest(&argc, argv);                                \
        ::yage::init();                                                        \
        ::yage::Window x;                                                      \
        x.create("Window", 800, 600);                                          \
        auto ret = RUN_ALL_TESTS();                                            \
        ::yage::quit();                                                        \
        return ret;                                                            \
    }

#define TEST_MAIN(LOGLEVEL)                                                    \
    int main(int argc, char **argv)                                            \
    {                                                                          \
        yLogger.setLevel(LOGLEVEL);                                            \
        testing::InitGoogleTest(&argc, argv);                                  \
        return RUN_ALL_TESTS();                                                \
    }
