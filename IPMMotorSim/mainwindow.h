/*
 * This file is part of the IPMMotorSim project
 *
 * Copyright (C) 2022 Pete9008 <openinverter.org>
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datagraph.h"
#include "idiqgraph.h"
#include "motormodel.h"

#include <fstream>
#include <memory>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void runFor(int num_steps);

    void logStart();
    void logSimRunParameters( int num_steps);
    void logSimResults(
        const QList<QPointF>& listIa,
        const QList<QPointF>& listIb,
        const QList<QPointF>& listIc,
        const QList<QPointF>& listIq,
        const QList<QPointF>& listId,
        const QList<QPointF>& listMFreq,
        const QList<QPointF>& listMPos,
        const QList<QPointF>& listContMPos,
        const QList<QPointF>& listCVa,
        const QList<QPointF>& listCVb,
        const QList<QPointF>& listCVc,
        const QList<QPointF>& listCVq,
        const QList<QPointF>& listCVd,
        const QList<QPointF>& listCIq,
        const QList<QPointF>& listCId,
        const QList<QPointF>& listCifw,
        const QList<QPointF>& listVVd,
        const QList<QPointF>& listVVq,
        const QList<QPointF>& listVVq_bemf,
        const QList<QPointF>& listVVq_dueto_id,
        const QList<QPointF>& listVVd_dueto_iq,
        const QList<QPointF>& listVVq_dueto_Rq,
        const QList<QPointF>& listVVd_dueto_Rd,
        const QList<QPointF>& listVVLd,
        const QList<QPointF>& listVVLq,
        const QList<QPointF>& listIdIq,
        const QList<QPointF>& listPower,
        const QList<QPointF>& listTorque,
        const QList<QPointF>& listElecPower,
        const QList<QPointF>& listEfficiency);
    void logStop();

    std::ofstream m_log;

    std::unique_ptr<DataGraph> motorGraph;
    std::unique_ptr<DataGraph> simulationGraph;
    std::unique_ptr<DataGraph> controllerGraph;
    std::unique_ptr<DataGraph> debugGraph;
    std::unique_ptr<DataGraph> voltageGraph;
    std::unique_ptr<IdIqGraph> idigGraph;
    std::unique_ptr<DataGraph> powerGraph;
    std::unique_ptr<MotorModel> motor;

    double m_time;
    uint32_t m_old_time;
    uint32_t m_old_ms_time;
    double m_oldVa;
    double m_oldVb;
    double m_oldVc;

    double m_timestep;
    double m_Vdc;

    double m_runTime;
    int m_lastTorqueDemand;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_vehicleWeight_editingFinished();

    void on_pbRunFor_clicked();

    void on_pbStep_clicked();

    void on_wheelSize_editingFinished();

    void on_gearRatio_editingFinished();

    void on_Vdc_editingFinished();

    void on_Lq_editingFinished();

    void on_Ld_editingFinished();

    void on_FluxLinkage_editingFinished();

    void on_LoopFreq_editingFinished();

    void on_pbRunFor10s_clicked();

    void on_pbRunFor1s_clicked();

    void on_pbRunFor100ms_clicked();

    void on_pbRunFor10ms_clicked();

    void on_pbRestart_clicked();

    void on_Rs_editingFinished();

    void on_Poles_editingFinished();

    void on_torqueDemand_editingFinished();

    void on_throttleCurrent_editingFinished();

    void on_opMode_editingFinished();

    void on_direction_editingFinished();

    void on_IqManual_editingFinished();

    void on_IdManual_editingFinished();

    void on_CurrentKp_editingFinished();

    void on_CurrentKi_editingFinished();

    void on_SyncAdv_editingFinished();

    void on_LqMinusLd_editingFinished();

    void on_SyncDelay_editingFinished();

    void on_FreqMax_editingFinished();

    void on_SamplingPoint_editingFinished();

    void on_pbTransient_clicked();

    void on_SyncOfs_editingFinished();

    void on_pbAccelCoast_clicked();

    void on_cb_OpPoint_toggled(bool checked);

    void on_cb_Simulation_toggled(bool checked);

    void on_cb_ContVolt_toggled(bool checked);

    void on_cb_ContCurr_toggled(bool checked);

    void on_cb_MotVolt_toggled(bool checked);

    void on_cb_MotCurr_toggled(bool checked);

    void on_cb_PowTorqTime_toggled(bool checked);

    void on_rb_Speed_toggled(bool checked);

    void on_RoadGradient_editingFinished();

    void on_runTime_editingFinished();

    void on_VLimMargin_editingFinished();

    void on_VLimFlt_editingFinished();

    void on_FWCurrMax_editingFinished();

    void on_rb_OP_Amps_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *bar);
};

#endif // MAINWINDOW_H
