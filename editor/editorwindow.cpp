/* ----------------------------------------------------------------------------
 * /home/yannherklotz/Github/YAGE/editor/editorwindow.cpp
 *
 * Copyright (c) 2017 Yann Herklotz Grave <ymherklotz@gmail.com>
 * MIT License, see LICENSE file for more details.
 * ----------------------------------------------------------------------------
 */

#include "editorwindow.h"
#include "ui_editorwindow.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::on_openGLWidget_destroyed()
{
}
