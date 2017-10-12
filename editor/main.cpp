/* ----------------------------------------------------------------------------
 * /home/yannherklotz/Github/YAGE/editor/main.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "editorwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EditorWindow w;
    w.show();

    return a.exec();
}
