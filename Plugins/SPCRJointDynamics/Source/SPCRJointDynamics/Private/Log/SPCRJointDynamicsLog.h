//======================================================================================
//  Copyright (c) 2019 SPARK CREATIVE Inc.
//  All rights reserved.
//======================================================================================
#pragma once
//======================================================================================
//
//======================================================================================
#include "Engine.h"

//======================================================================================
//
//======================================================================================
/** Logカテゴリの定義 (UE4の仕様) */
DECLARE_LOG_CATEGORY_EXTERN(LogSPCRJointDynamics, Warning, All);

/** Logのユーティリティの定義  */
#define SPCRJOINTDYNAMICS_VERYVERBOSE(Format, ...) UE_LOG(LogSPCRJointDynamics, VeryVerbose, TEXT("[SPCRJointDynamics][VERYVERBOSE]") Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_VERBOSE(Format, ...)     UE_LOG(LogSPCRJointDynamics, Verbose,     TEXT("[SPCRJointDynamics][VERBOSE]")     Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_LOG(Format, ...)         UE_LOG(LogSPCRJointDynamics, Log,         TEXT("[SPCRJointDynamics][LOG]")         Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_WARNING(Format, ...)     UE_LOG(LogSPCRJointDynamics, Warning,     TEXT("[SPCRJointDynamics][WARNING]")     Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_ERROR(Format, ...)       UE_LOG(LogSPCRJointDynamics, Error,       TEXT("[SPCRJointDynamics][ERROR]")       Format, ##__VA_ARGS__)

#define SPCRJOINTDYNAMICS_CVERYVERBOSE(Condition,Format, ...) UE_CLOG(Condition,LogSPCRJointDynamics, VeryVerbose, TEXT("[SPCRJointDynamics][VERYVERBOSE]") Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_CVERBOSE(Condition,Format, ...)     UE_CLOG(Condition,LogSPCRJointDynamics, Verbose,     TEXT("[SPCRJointDynamics][VERBOSE]")     Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_CLOG(Condition,Format, ...)         UE_CLOG(Condition,LogSPCRJointDynamics, Log,         TEXT("[SPCRJointDynamics][LOG]")         Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_CWARNING(Condition,Format, ...)     UE_CLOG(Condition,LogSPCRJointDynamics, Warning,     TEXT("[SPCRJointDynamics][WARNING]")     Format, ##__VA_ARGS__)
#define SPCRJOINTDYNAMICS_CERROR(Condition,Format, ...)       UE_CLOG(Condition,LogSPCRJointDynamics, Error,       TEXT("[SPCRJointDynamics][ERROR]") 

//======================================================================================
// EOF
//======================================================================================
