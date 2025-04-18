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

#ifndef ACTUALMAINWINDOW_H
#define ACTUALMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QMdiArea;
QT_END_NAMESPACE

class MainWindow;
class DataGraph;
class IdIqGraph;

class ActualMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ActualMainWindow(QWidget* parent = nullptr);

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    QMdiArea*   m_mdiArea;
    MainWindow* m_paramWindow = nullptr;
    DataGraph*  m_motorGraph = nullptr;
    DataGraph*  m_simulationGraph = nullptr;
    DataGraph*  m_controllerGraph = nullptr;
    DataGraph*  m_debugGraph = nullptr;
    DataGraph*  m_voltageGraph = nullptr;
    IdIqGraph*  m_idigGraph = nullptr;
    DataGraph*  m_powerGraph = nullptr;
};

#endif // ACTUALMAINWINDOW_H
