#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nHuman.h"

// Declarations
class cHumanActId;

// Type aliases from DWARF
using u32 = unsigned int;

class cHumanActId
{
public:
    struct ACT_ID_TBL;
public:
    struct ACT_ID_TBL
    {
    public:
        u32 mActNo;  // offset: 0x0
        nHuman::HM_SKILL_LV mMaxLv;  // offset: 0x4
    };
public:
    static u32 getCustomSkillActNo(nHuman::CUSTOM_SKILL_ENUM id, nHuman::JOB_ENUM job);
    static nHuman::HM_SKILL_LV getCustomSkillLvMax(nHuman::CUSTOM_SKILL_ENUM id, nHuman::JOB_ENUM job);
    static nHuman::CUSTOM_SKILL_ENUM getCustomSkillId(u32 actNo, nHuman::JOB_ENUM job);
    static u32 getNormalSkillActNo(nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::JOB_ENUM job);
    static nHuman::HM_SKILL_LV getNormalSkillLvMax(nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::JOB_ENUM job);
    static nHuman::GROW_NORMAL_SKILL_ENUM getNormalSkillId(u32 actNo, nHuman::JOB_ENUM job);
private:
    static const ACT_ID_TBL* getActIdJobTbl(nHuman::JOB_ENUM job);
    static const ACT_ID_TBL* getNormalActIdJobTbl(nHuman::JOB_ENUM job);
private:
    static const ACT_ID_TBL mActId_Job01Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job02Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job03Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job04Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job05Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job06Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job07Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job08Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job09Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job10Cs_Tbl[20];
    static const ACT_ID_TBL mActId_Job01_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job02_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job03_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job04_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job05_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job06_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job07_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job08_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job09_NomalGlow_Tbl[10];
    static const ACT_ID_TBL mActId_Job10_NomalGlow_Tbl[10];
};
