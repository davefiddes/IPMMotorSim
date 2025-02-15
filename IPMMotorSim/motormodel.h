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

#ifndef MOTORMODEL_H
#define MOTORMODEL_H

#include <QtMath>

class MotorModel
{
public:
    MotorModel(double wheelSize,double ratio,double roadGradient,double mass,double Lq,double Ld,double Rs,double poles,double fluxLink,double timestep, double syncDelay, double sampPoint);
    void Step(double Va, double Vb, double Vc);
    void Restart();
    void setWheelSize(double val) {m_WheelSize = val;}
    void setGboxRatio(double val) {m_Ratio = val;}
    void setVehicleMass(double val) {m_Mass = val;}
    void setLq(double val) {m_Lq = val;}
    void setLd(double val) {m_Ld = val;}
    void setRs(double val) {m_Rs = val;}
    void setPoles(double val) {m_Poles = val;}
    [[nodiscard]] double getPoles() const {return m_Poles;}
    void setFluxLinkage(double val) {m_FluxLink = val;}
    void setSyncDelay(double val) {m_syncdelay = val;}
    void setTimestep(double val) {m_Timestep = val;}
    void setPosition(double val) {m_Position = (val * m_Poles);}
    void setSamplingPoint(double val) {m_samplingPoint = val;}
    void setRoadGradient(double val) {m_RoadGradient = val;}
    [[nodiscard]] double getMotorPosition() const;
    [[nodiscard]] double getElecPosition() const;
    [[nodiscard]] double getMotorFreq() const {return m_Frequency;}
    [[nodiscard]] bool getMotorDirection() const {return (m_Speed>=0);}
    [[nodiscard]] double getIa() const {return m_Ia;} //gets current at end of period, ideal controller sampling point
    [[nodiscard]] double getIb() const {return m_Ib;}
    [[nodiscard]] double getIc() const {return m_Ic;}
    [[nodiscard]] double getIaSamp() const {return m_IaSamp;} //gets current at samplingPoint into period, real controller sampling point
    [[nodiscard]] double getIbSamp() const {return m_IbSamp;}
    [[nodiscard]] double getIcSamp() const {return m_IcSamp;}
    [[nodiscard]] double getIq() const {return m_Iq;} //model output
    [[nodiscard]] double getId() const {return m_Id;}
    [[nodiscard]] double getVd() const {return m_Vd;}
    [[nodiscard]] double getVq() const {return m_Vq;}
    [[nodiscard]] double getVq_bemf() const {return m_Vq_bemf;}
    [[nodiscard]] double getVq_dueto_id() const {return m_Vq_dueto_id;}
    [[nodiscard]] double getVd_dueto_iq() const {return m_Vd_dueto_iq;}
    [[nodiscard]] double getVq_dueto_Rq() const {return m_Vq_dueto_Rq;}
    [[nodiscard]] double getVd_dueto_Rd() const {return m_Vd_dueto_Rd;}
    [[nodiscard]] double getVLd() const {return m_VLd;}
    [[nodiscard]] double getVLq() const {return m_VLq;}
    [[nodiscard]] double getPower() const {return m_Power;}
    [[nodiscard]] double getTorque() const {return m_Torque;}


private:
    double m_WheelSize;
    double m_Ratio;
    double m_RoadGradient;
    double m_Mass;
    double m_Lq;
    double m_Ld;
    double m_Rs;
    double m_Poles;
    double m_FluxLink; //Hz
    double m_syncdelay;
    double m_samplingPoint; //sampling position as fraction of period, 0=start, 1=end

    double m_Position{}; //degrees
    double m_Frequency{}; // Hz motor speed (NOT electrical)
    double m_Timestep{};
    double m_Ia{};
    double m_Ib{};
    double m_Ic{};
    double m_IaSamp{};
    double m_IbSamp{};
    double m_IcSamp{};
    double m_Id{};
    double m_Iq{};
    double m_Speed{}; // m/s
    double m_Power{};
    double m_Torque{}; //motor torque

    double m_Vd{};
    double m_Vq{};
    double m_Vq_bemf{};
    double m_Vq_dueto_id{};
    double m_Vd_dueto_iq{};
    double m_Vq_dueto_Rq{};
    double m_Vd_dueto_Rd{};
    double m_VLd{};
    double m_VLq{};
};

#endif // MOTORMODEL_H
