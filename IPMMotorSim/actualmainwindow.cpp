/*
 * This file is part of the IPMMotorSim project
 *
 * Copyright (C) 2025 David J. Fiddes <D.J@fiddes.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtWidgets>

#include "actualmainwindow.h"
#include "mainwindow.h"

ActualMainWindow::ActualMainWindow(QWidget* parent)
: QMainWindow(parent), m_mdiArea(new QMdiArea), m_paramWindow(new MainWindow)
{
    QMenu*   fileMenu = new QMenu(tr("&File"), this);
    QAction* quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);
    menuBar()->addMenu(fileMenu);

    connect(quitAction, &QAction::triggered, this, &ActualMainWindow::close);

    m_mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(m_mdiArea);
    setWindowTitle(tr("OpenInverter IPM Motor Simulator"));

    m_mdiArea->addSubWindow(m_paramWindow);
}

void ActualMainWindow::closeEvent([[maybe_unused]] QCloseEvent* event)
{
    m_mdiArea->closeAllSubWindows();
}