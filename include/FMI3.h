#ifndef FMI3_H
#define FMI3_H

/*****************************************************************
 *  Copyright (c) Dassault Systemes. All rights reserved.        *
 *  This file is part of FMIKit. See LICENSE.txt in the project  *
 *  root for license information.                                *
 *****************************************************************/

#include "FMI.h"

//enum {
//	FMI3Float64Type,
//	FMI3Int32Type,
//	FMI3BooleanType,
//	FMI3StringType
//} FMI3VariableType;

/***************************************************
Types for Common Functions
****************************************************/

/* Inquire version numbers and setting logging status */
const char* FMI3GetVersion(FMIInstance *instance);

fmi3Status FMI3SetDebugLogging(FMIInstance *instance,
	fmi3Boolean loggingOn,
	size_t nCategories,
	const fmi3String categories[]);

/* Creation and destruction of FMU instances and setting debug status */
fmi3Status FMI3InstantiateModelExchange(
	FMIInstance               *instance,
	fmi3String                 instantiationToken,
	fmi3String                 resourceLocation,
	fmi3Boolean                visible,
	fmi3Boolean                loggingOn);

fmi3Status FMI3InstantiateCoSimulation(
	FMIInstance                   *instance,
	fmi3String                     instantiationToken,
	fmi3String                     resourceLocation,
	fmi3Boolean                    visible,
	fmi3Boolean                    loggingOn,
	fmi3Boolean                    eventModeUsed,
	const fmi3ValueReference       requiredIntermediateVariables[],
	size_t                         nRequiredIntermediateVariables,
	fmi3CallbackIntermediateUpdate intermediateUpdate);

fmi3Status FMI3InstantiateScheduledExecution(
	FMIInstance                   *instance,
	fmi3String                     instantiationToken,
	fmi3String                     resourceLocation,
	fmi3Boolean                    visible,
	fmi3Boolean                    loggingOn,
	const fmi3ValueReference       requiredIntermediateVariables[],
	size_t                         nRequiredIntermediateVariables,
	fmi3CallbackIntermediateUpdate intermediateUpdate,
	fmi3CallbackLockPreemption     lockPreemption,
	fmi3CallbackUnlockPreemption   unlockPreemption);

fmi3Status FMI3FreeInstance(FMIInstance *instance);

/* Enter and exit initialization mode, enter event mode, terminate and reset */
fmi3Status FMI3EnterInitializationMode(FMIInstance *instance,
	fmi3Boolean toleranceDefined,
	fmi3Float64 tolerance,
	fmi3Float64 startTime,
	fmi3Boolean stopTimeDefined,
	fmi3Float64 stopTime);

fmi3Status FMI3ExitInitializationMode(FMIInstance *instance);

fmi3Status FMI3EnterEventMode(FMIInstance *instance,
	fmi3Boolean stepEvent,
	const fmi3Int32 rootsFound[],
	size_t nEventIndicators,
	fmi3Boolean timeEvent);

fmi3Status FMI3Terminate(FMIInstance *instance);

fmi3Status FMI3Reset(FMIInstance *instance);

/* Getting and setting variable values */
fmi3Status FMI3GetFloat32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Float32 values[],
	size_t nValues);

fmi3Status FMI3GetFloat64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Float64 values[],
	size_t nValues);

fmi3Status FMI3GetInt8(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Int8 values[],
	size_t nValues);

fmi3Status FMI3GetUInt8(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3UInt8 values[],
	size_t nValues);

fmi3Status FMI3GetInt16(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Int16 values[],
	size_t nValues);

fmi3Status FMI3GetUInt16(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3UInt16 values[],
	size_t nValues);

fmi3Status FMI3GetInt32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Int32 values[],
	size_t nValues);

fmi3Status FMI3GetUInt32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3UInt32 values[],
	size_t nValues);

fmi3Status FMI3GetInt64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Int64 values[],
	size_t nValues);

fmi3Status FMI3GetUInt64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3UInt64 values[],
	size_t nValues);

fmi3Status FMI3GetBoolean(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Boolean values[],
	size_t nValues);

fmi3Status FMI3GetString(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3String values[],
	size_t nValues);

fmi3Status FMI3GetBinary(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	size_t sizes[],
	fmi3Binary values[],
	size_t nValues);

fmi3Status FMI3SetFloat32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Float32 values[],
	size_t nValues);

fmi3Status FMI3SetFloat64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Float64 values[],
	size_t nValues);

fmi3Status FMI3SetInt8(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Int8 values[],
	size_t nValues);

fmi3Status FMI3SetUInt8(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3UInt8 values[],
	size_t nValues);

fmi3Status FMI3SetInt16(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Int16 values[],
	size_t nValues);

fmi3Status FMI3SetUInt16(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3UInt16 values[],
	size_t nValues);

fmi3Status FMI3SetInt32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Int32 values[],
	size_t nValues);

fmi3Status FMI3SetUInt32(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3UInt32 values[],
	size_t nValues);

fmi3Status FMI3SetInt64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Int64 values[],
	size_t nValues);

fmi3Status FMI3SetUInt64(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3UInt64 values[],
	size_t nValues);

fmi3Status FMI3SetBoolean(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Boolean values[],
	size_t nValues);

fmi3Status FMI3SetString(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3String values[],
	size_t nValues);

fmi3Status FMI3SetBinary(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const size_t sizes[],
	const fmi3Binary values[],
	size_t nValues);

/* Getting Variable Dependency Information */
fmi3Status FMI3GetNumberOfVariableDependencies(FMIInstance *instance,
	fmi3ValueReference valueReference,
	size_t* nDependencies);

fmi3Status FMI3GetVariableDependencies(FMIInstance *instance,
	fmi3ValueReference dependent,
	size_t elementIndicesOfDependent[],
	fmi3ValueReference independents[],
	size_t elementIndicesOfIndependents[],
	fmi3DependencyKind dependencyKinds[],
	size_t nDependencies);

/* Getting and setting the internal FMU state */
fmi3Status FMI3GetFMUState(FMIInstance *instance, fmi3FMUState* FMUState);

fmi3Status FMI3SetFMUState(FMIInstance *instance, fmi3FMUState  FMUState);

fmi3Status FMI3FreeFMUState(FMIInstance *instance, fmi3FMUState* FMUState);

fmi3Status FMI3SerializedFMUStateSize(FMIInstance *instance,
	fmi3FMUState  FMUState,
	size_t* size);

fmi3Status FMI3SerializeFMUState(FMIInstance *instance,
	fmi3FMUState  FMUState,
	fmi3Byte serializedState[],
	size_t size);

fmi3Status FMI3DeSerializeFMUState(FMIInstance *instance,
	const fmi3Byte serializedState[],
	size_t size,
	fmi3FMUState* FMUState);

/* Getting partial derivatives */
fmi3Status FMI3GetDirectionalDerivative(FMIInstance *instance,
	const fmi3ValueReference unknowns[],
	size_t nUnknowns,
	const fmi3ValueReference knowns[],
	size_t nKnowns,
	const fmi3Float64 seed[],
	size_t nSeed,
	fmi3Float64 sensitivity[],
	size_t nSensitivity);

fmi3Status FMI3GetAdjointDerivative(FMIInstance *instance,
	const fmi3ValueReference unknowns[],
	size_t nUnknowns,
	const fmi3ValueReference knowns[],
	size_t nKnowns,
	const fmi3Float64 seed[],
	size_t nSeed,
	fmi3Float64 sensitivity[],
	size_t nSensitivity);

/* Entering and exiting the Configuration or Reconfiguration Mode */
fmi3Status FMI3EnterConfigurationMode(FMIInstance *instance);

fmi3Status FMI3ExitConfigurationMode(FMIInstance *instance);

/* Clock related functions */
fmi3Status FMI3GetClock(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Clock values[],
	size_t nValues);

fmi3Status FMI3SetClock(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Clock values[],
	const fmi3Boolean subactive[],
	size_t nValues);

fmi3Status FMI3GetIntervalDecimal(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3Float64 interval[],
	size_t nValues);

fmi3Status FMI3GetIntervalFraction(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	fmi3UInt64 intervalCounter[],
	fmi3UInt64 resolution[],
	size_t nValues);

fmi3Status FMI3SetIntervalDecimal(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Float64 interval[],
	size_t nValues);

fmi3Status FMI3SetIntervalFraction(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3UInt64 intervalCounter[],
	const fmi3UInt64 resolution[],
	size_t nValues);

fmi3Status FMI3UpdateDiscreteStates(FMIInstance *instance,
	fmi3Boolean *discreteStatesNeedUpdate,
	fmi3Boolean *terminateSimulation,
	fmi3Boolean *nominalsOfContinuousStatesChanged,
	fmi3Boolean *valuesOfContinuousStatesChanged,
	fmi3Boolean *nextEventTimeDefined,
	fmi3Float64 *nextEventTime);

/***************************************************
Types for Functions for Model Exchange
****************************************************/

fmi3Status FMI3EnterContinuousTimeMode(FMIInstance *instance);

fmi3Status FMI3CompletedIntegratorStep(FMIInstance *instance,
	fmi3Boolean noSetFMUStatePriorToCurrentPoint,
	fmi3Boolean* enterEventMode,
	fmi3Boolean* terminateSimulation);

/* Providing independent variables and re-initialization of caching */
fmi3Status FMI3SetTime(FMIInstance *instance, fmi3Float64 time);

fmi3Status FMI3SetContinuousStates(FMIInstance *instance,
	const fmi3Float64 continuousStates[],
	size_t nContinuousStates);

/* Evaluation of the model equations */
fmi3Status FMI3GetDerivatives(FMIInstance *instance,
	fmi3Float64 derivatives[],
	size_t nContinuousStates);

fmi3Status FMI3GetEventIndicators(FMIInstance *instance,
	fmi3Float64 eventIndicators[],
	size_t nEventIndicators);

fmi3Status FMI3GetContinuousStates(FMIInstance *instance,
	fmi3Float64 continuousStates[],
	size_t nContinuousStates);

fmi3Status FMI3GetNominalsOfContinuousStates(FMIInstance *instance,
	fmi3Float64 nominals[],
	size_t nContinuousStates);

fmi3Status FMI3GetNumberOfEventIndicators(FMIInstance *instance,
	size_t* nEventIndicators);

fmi3Status FMI3GetNumberOfContinuousStates(FMIInstance *instance,
	size_t* nContinuousStates);

/***************************************************
Types for Functions for Co-Simulation
****************************************************/

/* Simulating the FMU */

fmi3Status FMI3EnterStepMode(FMIInstance *instance);

fmi3Status FMI3GetOutputDerivatives(FMIInstance *instance,
	const fmi3ValueReference valueReferences[],
	size_t nValueReferences,
	const fmi3Int32 orders[],
	fmi3Float64 values[],
	size_t nValues);

fmi3Status FMI3DoStep(FMIInstance *instance,
	fmi3Float64 currentCommunicationPoint,
	fmi3Float64 communicationStepSize,
	fmi3Boolean noSetFMUStatePriorToCurrentPoint,
	fmi3Boolean* eventEncountered,
	fmi3Boolean* clocksAboutToTick,
	fmi3Boolean* terminate,
	fmi3Boolean* earlyReturn,
	fmi3Float64* lastSuccessfulTime);

fmi3Status FMI3ActivateModelPartition(FMIInstance *instance,
	fmi3ValueReference clockReference,
	size_t clockElementIndex,
	fmi3Float64 activationTime);

#endif // FMI3_H
