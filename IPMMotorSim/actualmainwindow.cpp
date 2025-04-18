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
#include "datagraph.h"
#include "idiqgraph.h"

ActualMainWindow::ActualMainWindow(QWidget* parent)
: QMainWindow(parent), m_mdiArea(new QMdiArea)
{
    QMenu*   fileMenu = new QMenu(tr("&File"), this);
    QAction* quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);
    menuBar()->addMenu(fileMenu);

    connect(quitAction, &QAction::triggered, this, &ActualMainWindow::close);

    m_mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(m_mdiArea);
    setWindowTitle(tr("OpenInverter IPM Motor Simulator"));

    m_motorGraph = new DataGraph("motor");
    m_simulationGraph = new DataGraph("sim", this);
    m_controllerGraph = new DataGraph("cont", this);
    m_debugGraph = new DataGraph("debug", this);
    m_voltageGraph = new DataGraph("voltage", this);
    m_idigGraph = new IdIqGraph("idig", this);
    m_powerGraph = new DataGraph("power", this);
    m_paramWindow = new MainWindow(
        m_motorGraph,
        m_simulationGraph,
        m_controllerGraph,
        m_debugGraph,
        m_voltageGraph,
        m_idigGraph,
        m_powerGraph);

    m_mdiArea->addSubWindow(m_paramWindow);
    m_mdiArea->addSubWindow(m_motorGraph);
    m_mdiArea->addSubWindow(m_simulationGraph);
    m_mdiArea->addSubWindow(m_controllerGraph);
    m_mdiArea->addSubWindow(m_debugGraph);
    m_mdiArea->addSubWindow(m_voltageGraph);
    m_mdiArea->addSubWindow(m_idigGraph);
    m_mdiArea->addSubWindow(m_powerGraph);
}

void ActualMainWindow::closeEvent([[maybe_unused]] QCloseEvent* event)
{
    m_mdiArea->closeAllSubWindows();
}