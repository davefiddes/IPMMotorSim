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

#include <QMessageBox>
#include <QtWidgets>

#include "actualmainwindow.h"
#include "datagraph.h"
#include "idiqgraph.h"
#include "mainwindow.h"

using namespace std::chrono;

ActualMainWindow::ActualMainWindow(QWidget* parent)
: QMainWindow(parent), m_mdiArea(new QMdiArea)
{
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

    createMenuAndActions();
}

void ActualMainWindow::closeEvent([[maybe_unused]] QCloseEvent* event)
{
    m_mdiArea->closeAllSubWindows();
}

void ActualMainWindow::createMenuAndActions()
{
    QMenu*   fileMenu = new QMenu(tr("&File"), this);
    QAction* quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);
    menuBar()->addMenu(fileMenu);

    connect(quitAction, &QAction::triggered, this, &ActualMainWindow::close);

    QMenu*   simulationMenu = new QMenu(tr("&Simulation"), this);
    QAction* runForAction = simulationMenu->addAction(tr("Run for..."));
    connect(runForAction, &QAction::triggered, this, &ActualMainWindow::runFor);

    QAction* run10sAction = simulationMenu->addAction(tr("Run 10s"));
    connect(run10sAction, &QAction::triggered, this, [this] {
        runForDuration(10s);
    });

    QAction* run1sAction = simulationMenu->addAction(tr("Run 1s"));
    connect(
        run1sAction, &QAction::triggered, this, [this] { runForDuration(1s); });

    QAction* run100msAction = simulationMenu->addAction(tr("Run 100ms"));
    connect(run100msAction, &QAction::triggered, this, [this] {
        runForDuration(100ms);
    });

    QAction* run10msAction = simulationMenu->addAction(tr("Run 10ms"));
    connect(run10msAction, &QAction::triggered, this, [this] {
        runForDuration(10ms);
    });

    QAction* runstepAction = simulationMenu->addAction(tr("&Single Step"));
    connect(
        runstepAction,
        &QAction::triggered,
        this,
        &ActualMainWindow::runSingleStep);

    QAction* transientAction = simulationMenu->addAction(tr("&Transient"));
    connect(
        transientAction,
        &QAction::triggered,
        this,
        &ActualMainWindow::runTransient);

    QAction* accelCoastAction = simulationMenu->addAction(tr("&Accel/Coast"));
    connect(
        accelCoastAction,
        &QAction::triggered,
        this,
        &ActualMainWindow::runAccelCoast);

    QAction* restartAction = simulationMenu->addAction(tr("&Restart"));
    connect(
        restartAction,
        &QAction::triggered,
        this,
        &ActualMainWindow::runRestart);

    menuBar()->addMenu(simulationMenu);
}

void ActualMainWindow::runFor()
{
    bool   ok{};
    double duration = QInputDialog::getDouble(
        this,
        tr("Run for..."),
        tr("Duration [s]:"),
        5.0,
        0,
        100,
        3,
        &ok,
        Qt::WindowFlags(),
        1);

    if (ok)
    {
        m_paramWindow->runForDuration(MainWindow::RunDuration(duration));
    }
}

void ActualMainWindow::runForDuration(std::chrono::milliseconds duration)
{
    m_paramWindow->runForDuration(duration);
}

void ActualMainWindow::runSingleStep()
{
    m_paramWindow->runSingleStep();
}

void ActualMainWindow::runTransient()
{
    m_paramWindow->runTransient();
}

void ActualMainWindow::runAccelCoast()
{
    m_paramWindow->runAccelCoast();
}

void ActualMainWindow::runRestart()
{
    m_paramWindow->runRestart();
}