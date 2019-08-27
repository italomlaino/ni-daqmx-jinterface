#include <jni.h>
#ifndef NIDAQMXJWRAPPERNATIVE_H_
#define NIDAQMXJWRAPPERNATIVE_H_

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_addGlobalChansToTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring channelNames);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_clearTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_configureLogging(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring filePath, jint loggingMode,
		jstring groupName, jint operation);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTask(JNIEnv *env, jclass jc,
		jstring taskName);
JNIEXPORT jboolean JNICALL
Java_com_wrapper_NIDAQmxJWrapper_isTaskDone(JNIEnv *env, jclass jc,
		jlong ptaskHandle);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_loadTask(JNIEnv *env, jclass jc,
		jstring taskName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_startTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_startNewFile(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring filePath);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_stopTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_waitUntilTaskDone(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeToWait);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerDoneEvent(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong options,
		DAQmxDoneEventCallbackPtr callbackFunction, void *callbackData);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerEveryNSamplesEvent(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jint everyNsamplesEventType,
		jlong nSamples, jlong options,
		DAQmxEveryNSamplesEventCallbackPtr callbackFunction, void *callbackData);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerSignalEvent(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint signalID, jlong options,
		DAQmxSignalEventCallbackPtr callbackFunction, void *callbackData);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskChannel(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskDevice(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_taskControl(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint action);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIAccelChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIBridgeChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAICurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble extShuntResistorVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAICurrentRMSChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble extShuntResistorVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgePolynomialChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray forwardCoeffs, jdoubleArray reverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray electricalVals, jint electricalUnits,
		jdoubleArray physicalVals, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgeTwoPointLinChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceIEPEChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIFreqVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble thresholdLevel, jdouble hysteresis,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIMicrophoneChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jint units,
		jdouble micSensitivity, jdouble maxSndPressLevel,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgePolynomialChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray forwardCoeffs, jdoubleArray reverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray electricalVals, jint electricalUnits,
		jdoubleArray physicalVals, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgeTwoPointLinChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIResistanceChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIRosetteStrainGageChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint rosetteType, jdouble gageOrientation, jintArray rosetteMeasTypes,
		jlong numRosetteMeasTypes, jint strainConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble gageFactor,
		jdouble nominalGageResistance, jdouble poissonRatio,
		jdouble leadWireResistance);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIRTDChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint rtdType, jint resistanceConfig,
		jint currentExcitSource, jdouble currentExcitVal, jdouble r0);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIStrainGageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint strainConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble gageFactor,
		jdouble initialBridgeVoltage, jdouble nominalGageResistance,
		jdouble poissonRatio, jdouble leadWireResistance,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITempBuiltInSensorChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint units);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmcplChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint thermocoupleType, jint cjcSource, jdouble cjcVal,
		jstring cjcChannel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmstrChanIex(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jdouble a, jdouble b, jdouble c);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmstrChanVex(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble a, jdouble b, jdouble c, jdouble r1);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgePolynomialChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray forwardCoeffs, jdoubleArray reverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray electricalVals, jint electricalUnits,
		jdoubleArray physicalVals, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgeTwoPointLinChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVelocityIEPEChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageRMSChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageChanWithExcit(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jboolean useExcitForScaling,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosEddyCurrProxProbeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosLVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosRVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIAccelChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint currentExcitSource,
		jdouble currentExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAICurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble externalShuntResistorValue, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIBridgeChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIForceBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIForceIEPEChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint currentExcitSource,
		jdouble currentExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIMicrophoneChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jint units,
		jdouble maxSndPressLevel, jint currentExcitSource,
		jdouble currentExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPressureBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIResistanceChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIRTDChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIStrainGageChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble initialBridgeVoltage, jdouble leadWireResistance,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmcplChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint cjcSource, jdouble cjcVal, jstring cjcChannel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmstrChanIex(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmstrChanVex(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble r1);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAITorqueBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIVoltageChanWithExcit(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint voltageExcitSource,
		jdouble voltageExcitVal, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPosLVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPosRVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOCurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOFuncGenChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jint type, jdouble frequency,
		jdouble amplitude, jdouble offset);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring physicalChannel,
		jstring nameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createDIChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring lines, jstring nameToAssignToLines,
		jint lineGrouping);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createDOChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring lines, jstring nameToAssignToLines,
		jint lineGrouping);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCICountEdgesChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jint edge, jlong initialCount, jint countDirection);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIFreqChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint edge, jint measMethod,
		jdouble measTime, jlong divisor, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPeriodChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint edge, jint measMethod,
		jdouble measTime, jlong divisor, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jstring sourceTerminal, jdouble minVal, jdouble maxVal);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseWidthChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint startingEdge,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCISemiPeriodChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCITwoEdgeSepChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint firstEdge,
		jint secondEdge, jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCILinEncoderChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jint decodingType, jboolean ZidxEnable, jdouble ZidxVal, jint ZidxPhase,
		jint units, jdouble distPerPulse, jdouble initialPos,
		jstring customScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIAngEncoderChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jint decodingType, jboolean ZidxEnable, jdouble ZidxVal, jint ZidxPhase,
		jint units, jlong pulsesPerRev, jdouble initialAngle,
		jstring customScaleName);
JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIGPSTimestampChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring counter,
		jstring nameToAssignToChannel, jint units, jint gpsSyncMethod,
		jstring custScaleName);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jint units, jint idleState, jdouble initialDelay, jdouble freq,
		jdouble dutyCycle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jstring sourceTerminal, jint idleState, jint initialDelay,
		jint lowTicks, jint highTicks);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring counter, jstring nameToAssignToChannel,
		jint units, jint idleState, jdouble initialDelay, jdouble lowTime,
		jdouble highTime);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgBurstHandshakingTimingExportClock(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jint sampleMode,
		jstring sampsPerChan, jdouble sampleClkRate, jstring sampleClkOutpTerm,
		jint sampleClkPulsePolarity, jint pauseWhen, jint readyEventActiveLevel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgBurstHandshakingTimingImportClock(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jint sampleMode,
		jstring sampsPerChan, jdouble sampleClkRate, jstring sampleClkSrc,
		jint sampleClkActiveEdge, jint pauseWhen, jint readyEventActiveLevel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgChangeDetectionTiming(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring risingEdgeChan,
		jstring fallingEdgeChan, jint sampleMode, jstring sampsPerChan);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgHandshakingTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint sampleMode, jstring sampsPerChanToAcquire);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgImplicitTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint sampleMode, jstring sampsPerChanToAcquire);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgPipelinedSampClkTiming(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring source, jdouble rate,
		jint activeEdge, jint sampleMode, jstring samplesPerChannel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgSampClkTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring source, jdouble rate, jint activeEdge,
		jint sampleMode, jlong sampsPerChan);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgEdgeStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerSlope,
		jdouble triggerLevel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgWindowStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerWhen,
		jdouble windowTop, jdouble windowBottom);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerEdge);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigPatternStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jstring triggerPattern,
		jint triggerWhen);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgEdgeRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerSlope,
		jdouble triggerLevel, jlong pretriggerSamples);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgWindowRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerWhen,
		jdouble windowTop, jdouble windowBottom, jlong pretriggerSamples);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerEdge,
		jlong pretriggerSamples);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigPatternRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jstring triggerPattern,
		jint triggerWhen, jlong pretriggerSamples);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeAdvTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring triggerSource, jint triggerEdge);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableAdvTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_sendSoftwareTrigger(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint triggerID);
JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readAnalogF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode);
JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readAnalogScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jshortArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryI16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps);
JNIEXPORT jintArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryI32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps);
JNIEXPORT jlongArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps);
JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jlong arraySizeInSamps);
JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jlong arraySizeInSamps);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrFreqScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTicksScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps);
JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTimeScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jbooleanArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalLines(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInBytes);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout);
JNIEXPORT jbooleanArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU8(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jarray readArray, jlong arraySizeInSamps,
		jint *sampsPerChanRead, jboolean *reserved);
JNIEXPORT jlongArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlongArray readArray, jlong arraySizeInSamps);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskReadChannel(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeAnalogF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray writeArray);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeAnalogScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jdouble value);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeBinaryI16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jshortArray writeArray);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeBinaryU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jarray writeArray);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray frequency,
		jdoubleArray dutyCycle);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrFreqScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout,
		jdouble frequency, jdouble dutyCycle);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jlongArray highTicks,
		jlongArray lowTicks);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTicksScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jlong highTicks,
		jlong lowTicks);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray highTime,
		jdoubleArray lowTime);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTimeScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout,
		jdouble highTime, jdouble lowTime);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalLines(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jbooleanArray writeArray);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jlong value);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU8(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jbooleanArray writeArray);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jarray writeArray);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jlongArray writeArray);

//JNIEXPORT jint JNICALL Java_com_wrapper_NIDAQmxJWrapper_writeRaw(
//		JNIEnv *env, jclass jc, jlong ptaskHandle, jint numSamps,
//		jboolean autoStart, jdouble timeout, void *writeArray,
//		jint *sampsPerChanWritten, jboolean *reserved) {
//}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_exportSignal(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint signalID, jarray outputTerminal);
JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_calculateReversePolyCoeff(JNIEnv *env,
		jclass jc, jdoubleArray forwardCoeffs, jlong numForwardCoeffsIn,
		jdouble minValX, jdouble maxValX, jint numPointsToCompute,
		jint reversePolyOrder);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createLinScale(JNIEnv *env, jclass jc,
		jstring name, jdouble slope, jdouble yIntercept, jint preScaledUnits,
		jstring scaledUnits);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createMapScale(JNIEnv *env, jclass jc,
		jstring name, jdouble prescaledMin, jdouble prescaledMax,
		jdouble scaledMin, jdouble scaledMax, jint preScaledUnits,
		jstring scaledUnits);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createPolynomialScale(JNIEnv *env, jclass jc,
		jstring name, jdouble forwardCoeffs, jlong numForwardCoeffsIn,
		jdouble reverseCoeffs, jlong numReverseCoeffsIn, jint preScaledUnits,
		jstring scaledUnits);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTableScale(JNIEnv *env, jclass jc,
		jstring name, jdouble prescaledVals, jlong numPrescaledValsIn,
		jdouble scaledVals, jlong numScaledValsIn, jint preScaledUnits,
		jstring scaledUnits);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgInputBuffer(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong numSampsPerChan);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgOutputBuffer(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong numSampsPerChan);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getErrorString(JNIEnv *env, jclass jc,
		jint errorCode);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getExtendedErrorInfo(JNIEnv *env, jclass jc);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskName(JNIEnv *env, jclass jc,
		jlong pTask);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskChannels(JNIEnv *env, jclass jc,
		jlong pTask);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskNumChans(JNIEnv *env, jclass jc,
		jlong pTask);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskDevices(JNIEnv *env, jclass jc,
		jlong pTask);
JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskNumDevices(JNIEnv *env, jclass jc,
		jlong pTask);
JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getChanType(JNIEnv *env, jclass jc,
		jlong pTask, jstring jChannel);
JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getAIMin(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_setAIMin(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel, jdouble value);
JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getAIMax(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel);

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_setAIMax(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel, jdouble value);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getSysScales(JNIEnv *env, jclass jc);
JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getSysTasks(JNIEnv *env, jclass jc);
#endif
