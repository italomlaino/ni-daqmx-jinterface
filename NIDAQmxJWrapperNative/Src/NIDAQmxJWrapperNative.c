#define STRICT

#include <stdlib.h>
#include <NIDAQmx.h>

#include "NIDAQmxJWrapperNative.h"
#include "Util.h"

// FIXME Convert all uInt64 (unsigned long) to BigInteger
JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_addGlobalChansToTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jchannelNames) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;
	const char* channelNames = NULL;

	channelNames = getStringUTFChars(env, jchannelNames, NULL);

	code = DAQmxAddGlobalChansToTask(taskHandle, channelNames);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_clearTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxClearTask(taskHandle);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_configureLogging(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jfilePath, jint loggingMode,
		jstring jgroupName, jint operation) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;
	const char *filePath = NULL;
	const char *groupName = NULL;

	filePath = getStringUTFChars(env, jfilePath, NULL);
	groupName = getStringUTFChars(env, jgroupName, NULL);

	code = DAQmxConfigureLogging(taskHandle, filePath, loggingMode, groupName,
			operation);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTask(JNIEnv *env, jclass jc,
		jstring jtaskName) {
	int32 code;
	const char *taskName = NULL;
	TaskHandle taskHandle = NULL;

	taskName = getStringUTFChars(env, jtaskName, NULL);

	code = DAQmxCreateTask(taskName, &taskHandle);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return 0;
	}

	(*env)->ReleaseStringUTFChars(env, jtaskName, taskName);

	return (jlong) (intptr_t) taskHandle;
}

JNIEXPORT jboolean JNICALL
Java_com_wrapper_NIDAQmxJWrapper_isTaskDone(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {

	int32 code;
	bool32 done;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxIsTaskDone(taskHandle, &done);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return 0;
	}

	return (jboolean) done;
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_loadTask(JNIEnv *env, jclass jc,
		jstring jtaskName) {
	int32 code;
	const char *taskName = NULL;
	TaskHandle taskHandle;

	taskName = getStringUTFChars(env, jtaskName, NULL);

	code = DAQmxLoadTask(taskName, &taskHandle);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return 0;
	}

	return (jlong) (intptr_t) taskHandle;
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_startTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {

	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxStartTask(taskHandle);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_startNewFile(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jfilePath) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;
	const char *filePath = NULL;

	filePath = getStringUTFChars(env, jfilePath, NULL);

	code = DAQmxStartNewFile(taskHandle, filePath);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_stopTask(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxStopTask(taskHandle);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_waitUntilTaskDone(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeToWait) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxWaitUntilTaskDone(taskHandle, timeToWait);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerDoneEvent(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong options,
		DAQmxDoneEventCallbackPtr callbackFunction, void *callbackData) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerEveryNSamplesEvent(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jint everyNsamplesEventType,
		jlong nSamples, jlong options,
		DAQmxEveryNSamplesEventCallbackPtr callbackFunction, void *callbackData) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_registerSignalEvent(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint signalID, jlong options,
		DAQmxSignalEventCallbackPtr callbackFunction, void *callbackData) {
	// TODO
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskChannel(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index) {
	int32 code;
	int32 bufferSize;
	char *buffer = NULL;
	jstring jbuffer = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	bufferSize = DAQmxGetNthTaskChannel(taskHandle, index, NULL, 0);

	if (bufferSize != 0) {

		buffer = (char) malloc(bufferSize);

		code = DAQmxGetNthTaskChannel(taskHandle, index, buffer, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jbuffer = (*env)->NewStringUTF(env, buffer);
	}

	return jbuffer;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskDevice(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index) {
	int32 code;
	int32 bufferSize;
	char *buffer = NULL;
	jstring jbuffer = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	bufferSize = DAQmxGetNthTaskDevice(taskHandle, index, NULL, 0);

	if (bufferSize != 0) {

		buffer = (char) malloc(bufferSize);

		code = DAQmxGetNthTaskDevice(taskHandle, index, buffer, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jbuffer = (*env)->NewStringUTF(env, buffer);
	}

	return jbuffer;
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_taskControl(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint action) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxTaskControl(taskHandle, action);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}

}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIAccelChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIAccelChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			sensitivity, sensitivityUnits, currentExcitSource, currentExcitVal,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIBridgeChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jstring jcustomScaleName) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIBridgeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAICurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble extShuntResistorVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAICurrentChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			shuntResistorLoc, extShuntResistorVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAICurrentRMSChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble extShuntResistorVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAICurrentRMSChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			shuntResistorLoc, extShuntResistorVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgePolynomialChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jforwardCoeffs, jdoubleArray jreverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *forwardCoeffs = NULL;
	float64 *reverseCoeffs = NULL;
	jlong numForwardCoeffs;
	jlong numReverseCoeffs;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jforwardCoeffs != NULL) {
		forwardCoeffs = (*env)->GetDoubleArrayElements(env, jforwardCoeffs,
				NULL);
	}
	numForwardCoeffs = (*env)->GetArrayLength(env, jforwardCoeffs);

	if (jreverseCoeffs != NULL) {
		reverseCoeffs = (*env)->GetDoubleArrayElements(env, jreverseCoeffs,
				NULL);
	}
	numReverseCoeffs = (*env)->GetArrayLength(env, jreverseCoeffs);

	code = DAQmxCreateAIForceBridgePolynomialChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			forwardCoeffs, (uInt32) numForwardCoeffs, reverseCoeffs,
			(uInt32) numReverseCoeffs, electricalUnits, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);
	(*env)->ReleaseDoubleArrayElements(env, jforwardCoeffs, forwardCoeffs, 0);
	(*env)->ReleaseDoubleArrayElements(env, jreverseCoeffs, reverseCoeffs, 0);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jelectricalVals, jint electricalUnits,
		jdoubleArray jphysicalVals, jint physicalUnits,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *electricalVals = NULL;
	float64 *physicalVals = NULL;
	jlong numElectricalVals;
	jlong numPhysicalVals;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jelectricalVals != NULL) {
		electricalVals = (*env)->GetDoubleArrayElements(env, jelectricalVals,
				NULL);
	}
	numElectricalVals = (*env)->GetArrayLength(env, jelectricalVals);

	if (jphysicalVals != NULL) {
		physicalVals = (*env)->GetDoubleArrayElements(env, jphysicalVals, NULL);
	}
	numPhysicalVals = (*env)->GetArrayLength(env, jphysicalVals);

	code = DAQmxCreateAIForceBridgeTableChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			electricalVals, (uInt32) numElectricalVals, electricalVals,
			(uInt32) numPhysicalVals, electricalUnits, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceBridgeTwoPointLinChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIForceBridgeTwoPointLinChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			firstElectricalVal, secondElectricalVal, electricalUnits,
			firstPhysicalVal, secondPhysicalVal, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIForceIEPEChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIForceIEPEChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			sensitivity, sensitivityUnits, currentExcitSource, currentExcitVal,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIFreqVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble thresholdLevel, jdouble hysteresis,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIFreqVoltageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, thresholdLevel,
			hysteresis, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIMicrophoneChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jint units,
		jdouble micSensitivity, jdouble maxSndPressLevel,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIMicrophoneChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, units, micSensitivity,
			maxSndPressLevel, currentExcitSource, currentExcitVal,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgePolynomialChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jforwardCoeffs, jdoubleArray jreverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *forwardCoeffs = NULL;
	float64 *reverseCoeffs = NULL;
	jlong numForwardCoeffs;
	jlong numReverseCoeffs;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jforwardCoeffs != NULL) {
		forwardCoeffs = (*env)->GetDoubleArrayElements(env, jforwardCoeffs,
				NULL);
	}
	numForwardCoeffs = (*env)->GetArrayLength(env, jforwardCoeffs);

	if (jreverseCoeffs != NULL) {
		reverseCoeffs = (*env)->GetDoubleArrayElements(env, jreverseCoeffs,
				NULL);
	}
	numReverseCoeffs = (*env)->GetArrayLength(env, jreverseCoeffs);

	code = DAQmxCreateAIPressureBridgePolynomialChan(taskHandle,
			physicalChannel, nameToAssignToChannel, minVal, maxVal, units,
			bridgeConfig, voltageExcitSource, voltageExcitVal,
			nominalBridgeResistance, forwardCoeffs, (uInt32) numForwardCoeffs,
			reverseCoeffs, (uInt32) numReverseCoeffs, electricalUnits,
			physicalUnits, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);
	(*env)->ReleaseDoubleArrayElements(env, jforwardCoeffs, forwardCoeffs, 0);
	(*env)->ReleaseDoubleArrayElements(env, jreverseCoeffs, reverseCoeffs, 0);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jelectricalVals, jint electricalUnits,
		jdoubleArray jphysicalVals, jint physicalUnits,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *electricalVals = NULL;
	float64 *physicalVals = NULL;
	jlong numElectricalVals;
	jlong numPhysicalVals;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jelectricalVals != NULL) {
		electricalVals = (*env)->GetDoubleArrayElements(env, jelectricalVals,
				NULL);
	}
	numElectricalVals = (*env)->GetArrayLength(env, jelectricalVals);

	if (jphysicalVals != NULL) {
		physicalVals = (*env)->GetDoubleArrayElements(env, jphysicalVals, NULL);
	}
	numPhysicalVals = (*env)->GetArrayLength(env, jphysicalVals);

	code = DAQmxCreateAIPressureBridgeTableChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			electricalVals, (uInt32) numElectricalVals, electricalVals,
			(uInt32) numPhysicalVals, electricalUnits, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPressureBridgeTwoPointLinChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIPressureBridgeTwoPointLinChan(taskHandle,
			physicalChannel, nameToAssignToChannel, minVal, maxVal, units,
			bridgeConfig, voltageExcitSource, voltageExcitVal,
			nominalBridgeResistance, firstElectricalVal, secondElectricalVal,
			electricalUnits, firstPhysicalVal, secondPhysicalVal, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIResistanceChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIResistanceChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			currentExcitSource, currentExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIRosetteStrainGageChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint rosetteType, jdouble gageOrientation, jintArray jrosetteMeasTypes,
		jlong numRosetteMeasTypes, jint strainConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble gageFactor,
		jdouble nominalGageResistance, jdouble poissonRatio,
		jdouble leadWireResistance) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIRTDChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint rtdType, jint resistanceConfig,
		jint currentExcitSource, jdouble currentExcitVal, jdouble r0) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateAIRTDChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, rtdType,
			resistanceConfig, currentExcitSource, currentExcitVal, r0);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIStrainGageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint strainConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble gageFactor,
		jdouble initialBridgeVoltage, jdouble nominalGageResistance,
		jdouble poissonRatio, jdouble leadWireResistance,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIStrainGageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, strainConfig,
			voltageExcitSource, voltageExcitVal, gageFactor,
			initialBridgeVoltage, nominalGageResistance, poissonRatio,
			leadWireResistance, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITempBuiltInSensorChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint units) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateAITempBuiltInSensorChan(taskHandle, physicalChannel,
			nameToAssignToChannel, units);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmcplChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint thermocoupleType, jint cjcSource, jdouble cjcVal,
		jstring jcjcChannel) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *cjcChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	cjcChannel = getStringUTFChars(env, jcjcChannel, NULL);

	code = DAQmxCreateAIThrmcplChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, thermocoupleType,
			cjcSource, cjcVal, cjcChannel);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcjcChannel, cjcChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmstrChanIex(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jdouble a, jdouble b, jdouble c) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateAIThrmstrChanIex(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			currentExcitSource, currentExcitVal, a, b, c);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIThrmstrChanVex(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble a, jdouble b, jdouble c, jdouble r1) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateAIThrmstrChanVex(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			voltageExcitSource, voltageExcitVal, a, b, c, r1);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgePolynomialChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jforwardCoeffs, jdoubleArray jreverseCoeffs,
		jint electricalUnits, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *forwardCoeffs = NULL;
	float64 *reverseCoeffs = NULL;
	jlong numForwardCoeffs;
	jlong numReverseCoeffs;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jforwardCoeffs != NULL) {
		forwardCoeffs = (*env)->GetDoubleArrayElements(env, jforwardCoeffs,
				NULL);
	}
	numForwardCoeffs = (*env)->GetArrayLength(env, jforwardCoeffs);

	if (jreverseCoeffs != NULL) {
		reverseCoeffs = (*env)->GetDoubleArrayElements(env, jreverseCoeffs,
				NULL);
	}
	numReverseCoeffs = (*env)->GetArrayLength(env, jreverseCoeffs);

	code = DAQmxCreateAITorqueBridgePolynomialChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			forwardCoeffs, (uInt32) numForwardCoeffs, reverseCoeffs,
			(uInt32) numReverseCoeffs, electricalUnits, physicalUnits,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);
	(*env)->ReleaseDoubleArrayElements(env, jforwardCoeffs, forwardCoeffs, 0);
	(*env)->ReleaseDoubleArrayElements(env, jreverseCoeffs, reverseCoeffs, 0);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}

}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgeTableChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdoubleArray jelectricalVals, jint electricalUnits,
		jdoubleArray jphysicalVals, jint physicalUnits,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	float64 *electricalVals = NULL;
	float64 *physicalVals = NULL;
	jlong numElectricalVals;
	jlong numPhysicalVals;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	if (jelectricalVals != NULL) {
		electricalVals = (*env)->GetDoubleArrayElements(env, jelectricalVals,
				NULL);
	}
	numElectricalVals = (*env)->GetArrayLength(env, jelectricalVals);

	if (jphysicalVals != NULL) {
		physicalVals = (*env)->GetDoubleArrayElements(env, jphysicalVals, NULL);
	}
	numPhysicalVals = (*env)->GetArrayLength(env, jphysicalVals);

	code = DAQmxCreateAITorqueBridgeTableChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			electricalVals, (uInt32) numElectricalVals, electricalVals,
			(uInt32) numPhysicalVals, electricalUnits, physicalUnits,
			customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAITorqueBridgeTwoPointLinChan(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble nominalBridgeResistance,
		jdouble firstElectricalVal, jdouble secondElectricalVal,
		jint electricalUnits, jdouble firstPhysicalVal,
		jdouble secondPhysicalVal, jint physicalUnits, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAITorqueBridgeTwoPointLinChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, bridgeConfig,
			voltageExcitSource, voltageExcitVal, nominalBridgeResistance,
			firstElectricalVal, secondElectricalVal, electricalUnits,
			firstPhysicalVal, secondPhysicalVal, physicalUnits,
			customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVelocityIEPEChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jdouble sensitivity, jint sensitivityUnits,
		jint currentExcitSource, jdouble currentExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIVelocityIEPEChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			sensitivity, sensitivityUnits, currentExcitSource, currentExcitVal,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIVoltageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageRMSChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIVoltageRMSChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIVoltageChanWithExcit(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint bridgeConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jboolean useExcitForScaling,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIVoltageChanWithExcit(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			bridgeConfig, voltageExcitSource, voltageExcitVal,
			useExcitForScaling, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosEddyCurrProxProbeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIPosEddyCurrProxProbeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, sensitivity,
			sensitivityUnits, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosLVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIPosLVDTChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, sensitivity,
			sensitivityUnits, voltageExcitSource, voltageExcitVal,
			voltageExcitFreq, ACExcitWireMode, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAIPosRVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jdouble sensitivity, jint sensitivityUnits,
		jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAIPosRVDTChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, sensitivity,
			sensitivityUnits, voltageExcitSource, voltageExcitVal,
			voltageExcitFreq, ACExcitWireMode, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIAccelChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint currentExcitSource,
		jdouble currentExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIAccelChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			currentExcitSource, currentExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAICurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint shuntResistorLoc,
		jdouble externalShuntResistorValue, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAICurrentChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			shuntResistorLoc, externalShuntResistorValue, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIBridgeChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIBridgeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIForceBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIForceBridgeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIForceIEPEChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint currentExcitSource,
		jdouble currentExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIForceIEPEChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			currentExcitSource, currentExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIMicrophoneChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jint units,
		jdouble maxSndPressLevel, jint currentExcitSource,
		jdouble currentExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIMicrophoneChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, units, maxSndPressLevel,
			currentExcitSource, currentExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPressureBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIPressureBridgeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIResistanceChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIResistanceChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			currentExcitSource, currentExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIRTDChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateTEDSAIRTDChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			currentExcitSource, currentExcitVal);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIStrainGageChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble initialBridgeVoltage, jdouble leadWireResistance,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIStrainGageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, initialBridgeVoltage, leadWireResistance,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmcplChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint cjcSource, jdouble cjcVal, jstring jcjcChannel) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *cjcChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	cjcChannel = getStringUTFChars(env, jcjcChannel, NULL);

	code = DAQmxCreateTEDSAIThrmcplChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, cjcSource, cjcVal,
			cjcChannel);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcjcChannel, cjcChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmstrChanIex(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint currentExcitSource,
		jdouble currentExcitVal) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateTEDSAIThrmstrChanIex(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			currentExcitSource, currentExcitVal);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIThrmstrChanVex(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint resistanceConfig, jint voltageExcitSource,
		jdouble voltageExcitVal, jdouble r1) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateTEDSAIThrmstrChanVex(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, resistanceConfig,
			voltageExcitSource, voltageExcitVal, r1);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAITorqueBridgeChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAITorqueBridgeChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIVoltageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIVoltageChanWithExcit(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint terminalConfig, jdouble minVal,
		jdouble maxVal, jint units, jint voltageExcitSource,
		jdouble voltageExcitVal, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIVoltageChanWithExcit(taskHandle, physicalChannel,
			nameToAssignToChannel, terminalConfig, minVal, maxVal, units,
			voltageExcitSource, voltageExcitVal, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPosLVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIPosLVDTChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, voltageExcitFreq, ACExcitWireMode,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTEDSAIPosRVDTChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jint voltageExcitSource, jdouble voltageExcitVal,
		jdouble voltageExcitFreq, jint ACExcitWireMode,
		jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateTEDSAIPosRVDTChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, voltageExcitSource,
			voltageExcitVal, voltageExcitFreq, ACExcitWireMode,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOCurrentChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAOCurrentChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOFuncGenChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jint type, jdouble frequency,
		jdouble amplitude, jdouble offset) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateAOFuncGenChan(taskHandle, physicalChannel,
			nameToAssignToChannel, type, frequency, amplitude, offset);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createAOVoltageChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jphysicalChannel,
		jstring jnameToAssignToChannel, jdouble minVal, jdouble maxVal,
		jint units, jstring jcustomScaleName) {
	int32 code;
	const char *physicalChannel = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	physicalChannel = getStringUTFChars(env, jphysicalChannel, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateAOVoltageChan(taskHandle, physicalChannel,
			nameToAssignToChannel, minVal, maxVal, units, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jphysicalChannel, physicalChannel);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createDIChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jlines, jstring jnameToAssignToLines,
		jint lineGrouping) {
	int32 code;
	const char *lines = NULL;
	const char *nameToAssignToLines = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	lines = getStringUTFChars(env, jlines, NULL);
	nameToAssignToLines = getStringUTFChars(env, jnameToAssignToLines, NULL);

	code = DAQmxCreateDIChan(taskHandle, lines, nameToAssignToLines,
			lineGrouping);

	(*env)->ReleaseStringUTFChars(env, jlines, lines);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToLines,
			nameToAssignToLines);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createDOChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jlines, jstring jnameToAssignToLines,
		jint lineGrouping) {
	int32 code;
	const char *lines = NULL;
	const char *nameToAssignToLines = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	lines = getStringUTFChars(env, jlines, NULL);
	nameToAssignToLines = getStringUTFChars(env, jnameToAssignToLines, NULL);

	code = DAQmxCreateDOChan(taskHandle, lines, nameToAssignToLines,
			lineGrouping);

	(*env)->ReleaseStringUTFChars(env, jlines, lines);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToLines,
			nameToAssignToLines);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCICountEdgesChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jint edge, jlong initialCount, jint countDirection) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateCICountEdgesChan(taskHandle, counter,
			nameToAssignToChannel, edge, initialCount, countDirection);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIFreqChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint edge, jint measMethod,
		jdouble measTime, jlong divisor, jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCIFreqChan(taskHandle, counter, nameToAssignToChannel,
			minVal, maxVal, units, edge, measMethod, measTime, divisor,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPeriodChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint edge, jint measMethod,
		jdouble measTime, jlong divisor, jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCIPeriodChan(taskHandle, counter, nameToAssignToChannel,
			minVal, maxVal, units, edge, measMethod, measTime, divisor,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateCIPulseChanFreq(taskHandle, counter,
			nameToAssignToChannel, minVal, maxVal, units);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jstring jsourceTerminal, jdouble minVal, jdouble maxVal) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *sourceTerminal = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	sourceTerminal = getStringUTFChars(env, jsourceTerminal, NULL);

	code = DAQmxCreateCIPulseChanTicks(taskHandle, counter,
			nameToAssignToChannel, sourceTerminal, minVal, maxVal);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jsourceTerminal, sourceTerminal);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseChanTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateCIPulseChanTime(taskHandle, counter,
			nameToAssignToChannel, minVal, maxVal, units);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIPulseWidthChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint startingEdge,
		jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCIPulseWidthChan(taskHandle, counter,
			nameToAssignToChannel, minVal, maxVal, units, startingEdge,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCISemiPeriodChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCISemiPeriodChan(taskHandle, counter,
			nameToAssignToChannel, minVal, maxVal, units, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCITwoEdgeSepChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jdouble minVal, jdouble maxVal, jint units, jint firstEdge,
		jint secondEdge, jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCITwoEdgeSepChan(taskHandle, counter,
			nameToAssignToChannel, minVal, maxVal, units, firstEdge, secondEdge,
			customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCILinEncoderChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jint decodingType, jboolean ZidxEnable, jdouble ZidxVal, jint ZidxPhase,
		jint units, jdouble distPerPulse, jdouble initialPos,
		jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCILinEncoderChan(taskHandle, counter,
			nameToAssignToChannel, decodingType, ZidxEnable, ZidxVal, ZidxPhase,
			units, distPerPulse, initialPos, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIAngEncoderChan(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jint decodingType, jboolean ZidxEnable, jdouble ZidxVal, jint ZidxPhase,
		jint units, jlong pulsesPerRev, jdouble initialAngle,
		jstring jcustomScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *customScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	customScaleName = getStringUTFChars(env, jcustomScaleName, NULL);

	code = DAQmxCreateCIAngEncoderChan(taskHandle, counter,
			nameToAssignToChannel, decodingType, ZidxEnable, ZidxVal, ZidxPhase,
			units, pulsesPerRev, initialAngle, customScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustomScaleName, customScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}
JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCIGPSTimestampChan(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jcounter,
		jstring jnameToAssignToChannel, jint units, jint gpsSyncMethod,
		jstring jcustScaleName) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *custScaleName = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	custScaleName = getStringUTFChars(env, jcustScaleName, NULL);

	code = DAQmxCreateCIGPSTimestampChan(taskHandle, counter,
			nameToAssignToChannel, units, gpsSyncMethod, custScaleName);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jcustScaleName, custScaleName);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jint units, jint idleState, jdouble initialDelay, jdouble freq,
		jdouble dutyCycle) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateCOPulseChanFreq(taskHandle, counter,
			nameToAssignToChannel, units, idleState, initialDelay, freq,
			dutyCycle);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jstring jsourceTerminal, jint idleState, jint initialDelay,
		jint lowTicks, jint highTicks) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;
	const char *sourceTerminal = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);
	sourceTerminal = getStringUTFChars(env, jsourceTerminal, sourceTerminal);

	code = DAQmxCreateCOPulseChanTicks(taskHandle, counter,
			nameToAssignToChannel, sourceTerminal, idleState, initialDelay,
			lowTicks, highTicks);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);
	(*env)->ReleaseStringUTFChars(env, jsourceTerminal, sourceTerminal);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createCOPulseChanTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jcounter, jstring jnameToAssignToChannel,
		jint units, jint idleState, jdouble initialDelay, jdouble lowTime,
		jdouble highTime) {
	int32 code;
	const char *counter = NULL;
	const char *nameToAssignToChannel = NULL;

	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	counter = getStringUTFChars(env, jcounter, NULL);
	nameToAssignToChannel = getStringUTFChars(env, jnameToAssignToChannel,
			NULL);

	code = DAQmxCreateCOPulseChanTime(taskHandle, counter,
			nameToAssignToChannel, units, idleState, initialDelay, lowTime,
			highTime);

	(*env)->ReleaseStringUTFChars(env, jcounter, counter);
	(*env)->ReleaseStringUTFChars(env, jnameToAssignToChannel,
			nameToAssignToChannel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgBurstHandshakingTimingExportClock(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jint sampleMode,
		jstring jsampsPerChan, jdouble sampleClkRate,
		jstring jsampleClkOutpTerm, jint sampleClkPulsePolarity, jint pauseWhen,
		jint readyEventActiveLevel) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgBurstHandshakingTimingImportClock(
		JNIEnv *env, jclass jc, jlong ptaskHandle, jint sampleMode,
		jstring jsampsPerChan, jdouble sampleClkRate, jstring jsampleClkSrc,
		jint sampleClkActiveEdge, jint pauseWhen, jint readyEventActiveLevel) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgChangeDetectionTiming(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jrisingEdgeChan,
		jstring jfallingEdgeChan, jint sampleMode, jstring jsampsPerChan) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgHandshakingTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint sampleMode, jstring jsampsPerChanToAcquire) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgImplicitTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint sampleMode, jstring jsampsPerChanToAcquire) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgPipelinedSampClkTiming(JNIEnv *env,
		jclass jc, jlong ptaskHandle, jstring jsource, jdouble rate,
		jint activeEdge, jint sampleMode, jstring jsamplesPerChannel) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgSampClkTiming(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jsource, jdouble rate, jint activeEdge,
		jint sampleMode, jlong sampsPerChan) {
	int32 code;
	const char *source = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	source = getStringUTFChars(env, jsource, NULL);

	code = DAQmxCfgSampClkTiming(taskHandle, source, rate, activeEdge,
			sampleMode, sampsPerChan);

	(*env)->ReleaseStringUTFChars(env, jsource, source);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgEdgeStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerSlope,
		jdouble triggerLevel) {
	int32 code;
	const char *triggerSource = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	triggerSource = getStringUTFChars(env, jtriggerSource, NULL);

	code = DAQmxCfgAnlgEdgeStartTrig(taskHandle, triggerSource, triggerSlope,
			triggerLevel);

	(*env)->ReleaseStringUTFChars(env, jtriggerSource, triggerSource);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgWindowStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerWhen,
		jdouble windowTop, jdouble windowBottom) {
	int32 code;
	const char *triggerSource = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	triggerSource = getStringUTFChars(env, jtriggerSource, NULL);

	code = DAQmxCfgAnlgWindowStartTrig(taskHandle, triggerSource, triggerWhen,
			windowTop, windowBottom);

	(*env)->ReleaseStringUTFChars(env, jtriggerSource, triggerSource);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerEdge) {
	int32 code;
	const char *triggerSource = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	triggerSource = getStringUTFChars(env, jtriggerSource, NULL);

	code = DAQmxCfgDigEdgeStartTrig(taskHandle, triggerSource, triggerEdge);

	(*env)->ReleaseStringUTFChars(env, jtriggerSource, triggerSource);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigPatternStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jstring jtriggerPattern,
		jint triggerWhen) {
	int32 code;
	const char *triggerSource = NULL;
	const char *triggerPattern = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	triggerSource = getStringUTFChars(env, jtriggerSource, NULL);
	triggerPattern = getStringUTFChars(env, jtriggerPattern, NULL);

	code = DAQmxCfgDigPatternStartTrig(taskHandle, triggerSource,
			triggerPattern, triggerWhen);

	(*env)->ReleaseStringUTFChars(env, jtriggerSource, triggerSource);
	(*env)->ReleaseStringUTFChars(env, jtriggerPattern, triggerPattern);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableStartTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxDisableStartTrig(taskHandle);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgEdgeRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerSlope,
		jdouble triggerLevel, jlong pretriggerSamples) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgAnlgWindowRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerWhen,
		jdouble windowTop, jdouble windowBottom, jlong pretriggerSamples) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerEdge,
		jlong pretriggerSamples) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigPatternRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jstring jtriggerPattern,
		jint triggerWhen, jlong pretriggerSamples) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableRefTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxDisableRefTrig(taskHandle);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgDigEdgeAdvTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jstring jtriggerSource, jint triggerEdge) {
	int32 code;
	const char *triggerSource = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	triggerSource = getStringUTFChars(env, jtriggerSource, NULL);

	code = DAQmxCfgDigEdgeAdvTrig(taskHandle, triggerSource, triggerEdge);

	(*env)->ReleaseStringUTFChars(env, jtriggerSource, triggerSource);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_disableAdvTrig(JNIEnv *env, jclass jc,
		jlong ptaskHandle) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxDisableAdvTrig(taskHandle);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_sendSoftwareTrigger(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint triggerID) {
	int32 code;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxSendSoftwareTrigger(taskHandle, triggerID);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readAnalogF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode) {
	int32 code;
	uInt32 size;
	uInt32 nChannels;
	float64 *data = NULL;
	jdoubleArray array = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxGetTaskNumChans(taskHandle, &nChannels);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return NULL;
	}

	size = numSampsPerChan * nChannels;
	data = (float64 *) malloc((size_t) (sizeof(float64) * size));

	code = DAQmxReadAnalogF64(taskHandle, numSampsPerChan, timeout,
			(bool32) fillMode, data, size, NULL, NULL);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return NULL;
	}

	array = (*env)->NewDoubleArray(env, size);
	(*env)->SetDoubleArrayRegion(env, array, 0, size, data);

	return array;
}

JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readAnalogScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	int32 code;
	jdouble value;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxReadAnalogScalarF64(taskHandle, timeout, &value, NULL);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return 0;
	}

	return value;
}

JNIEXPORT jshortArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryI16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jintArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryI32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jlongArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readBinaryU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	int32 code;
	jdouble value;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxReadCounterScalarF64(taskHandle, timeout, &value, NULL);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return 0;
	}

	return value;
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	int32 code;
	jlong value;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) ptaskHandle;

	code = DAQmxReadCounterScalarU32(taskHandle, timeout, &value, NULL);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return NULL;
	}

	return value;
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCounterU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrFreqScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTicksScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean interleaved, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jarray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readCtrTimeScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	// TODO
}

JNIEXPORT jbooleanArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalLines(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInBytes) {
	// TODO
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jdouble timeout) {
	// TODO
}

JNIEXPORT jbooleanArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU8(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jarray jreadArray, jlong arraySizeInSamps,
		jint *sampsPerChanRead, jboolean *reserved) {
	// TODO
}

JNIEXPORT jlongArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_readDigitalU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jdouble timeout,
		jboolean fillMode, jlongArray jreadArray, jlong arraySizeInSamps) {
	// TODO
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getNthTaskReadChannel(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong index) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeAnalogF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray jwriteArray) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeAnalogScalarF64(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jdouble value) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeBinaryI16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jshortArray jwriteArray) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeBinaryU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jarray jwriteArray) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrFreq(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray jfrequency,
		jdoubleArray jdutyCycle) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrFreqScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout,
		jdouble frequency, jdouble dutyCycle) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTicks(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jlongArray jhighTicks,
		jlongArray jlowTicks) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTicksScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jlong highTicks,
		jlong lowTicks) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTime(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jdoubleArray jhighTime,
		jdoubleArray jlowTime) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeCtrTimeScalar(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout,
		jdouble highTime, jdouble lowTime) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalLines(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jbooleanArray jwriteArray) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalScalarU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jboolean autoStart, jdouble timeout, jlong value) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU8(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jbooleanArray jwriteArray) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU16(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jarray jwriteArray) {
	// TODO
}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_writeDigitalU32(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint numSampsPerChan, jboolean autoStart,
		jdouble timeout, jboolean dataLayout, jlongArray jwriteArray) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_exportSignal(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jint signalID, jarray joutputTerminal) {
	// TODO
}

JNIEXPORT jdoubleArray JNICALL
Java_com_wrapper_NIDAQmxJWrapper_calculateReversePolyCoeff(JNIEnv *env,
		jclass jc, jdoubleArray jforwardCoeffs, jlong numForwardCoeffsIn,
		jdouble minValX, jdouble maxValX, jint numPointsToCompute,
		jint reversePolyOrder) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createLinScale(JNIEnv *env, jclass jc,
		jstring jname, jdouble slope, jdouble yIntercept, jint preScaledUnits,
		jstring jscaledUnits) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createMapScale(JNIEnv *env, jclass jc,
		jstring jname, jdouble prescaledMin, jdouble prescaledMax,
		jdouble scaledMin, jdouble scaledMax, jint preScaledUnits,
		jstring jscaledUnits) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createPolynomialScale(JNIEnv *env, jclass jc,
		jstring jname, jdouble forwardCoeffs, jlong numForwardCoeffsIn,
		jdouble reverseCoeffs, jlong numReverseCoeffsIn, jint preScaledUnits,
		jstring jscaledUnits) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_createTableScale(JNIEnv *env, jclass jc,
		jstring jname, jdouble prescaledVals, jlong numPrescaledValsIn,
		jdouble scaledVals, jlong numScaledValsIn, jint preScaledUnits,
		jstring jscaledUnits) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgInputBuffer(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong numSampsPerChan) {
	// TODO
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_cfgOutputBuffer(JNIEnv *env, jclass jc,
		jlong ptaskHandle, jlong numSampsPerChan) {
	// TODO
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getErrorString(JNIEnv *env, jclass jc,
		jint errorCode) {
	int32 code;
	int32 bufferSize;
	char *error = NULL;
	jstring jerror = NULL;

	bufferSize = DAQmxGetErrorString(errorCode, NULL, 0);

	if (bufferSize != 0) {

		error = (char *) malloc(bufferSize);

		code = DAQmxGetErrorString(errorCode, error, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
		}

		jerror = (*env)->NewStringUTF(env, error);
	}

	return jerror;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getExtendedErrorInfo(JNIEnv *env, jclass jc) {
	int32 code;
	int32 bufferSize;
	char *error = NULL;
	jstring jerror = NULL;

	bufferSize = DAQmxGetExtendedErrorInfo(NULL, 0);

	if (bufferSize != 0) {

		error = (char *) malloc(bufferSize);

		code = DAQmxGetExtendedErrorInfo(error, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
		}

		jerror = (*env)->NewStringUTF(env, error);
	}

	return jerror;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskName(JNIEnv *env, jclass jc,
		jlong pTask) {
	int32 code;
	int32 bufferSize;
	char *name = NULL;
	jstring jname = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	bufferSize = DAQmxGetTaskName(taskHandle, NULL, 0);

	if (bufferSize > 0) {

		name = (char *) malloc(bufferSize);

		code = DAQmxGetTaskName(taskHandle, name, bufferSize);
		if (code > 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jname = (*env)->NewStringUTF(env, name);
	}

	return jname;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskChannels(JNIEnv *env, jclass jc,
		jlong pTask) {
	int32 code;
	int32 bufferSize;
	char *data = NULL;
	jstring jdata = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	bufferSize = DAQmxGetTaskChannels(taskHandle, NULL, 0);

	if (bufferSize > 0) {

		data = (char *) malloc(bufferSize);

		code = DAQmxGetTaskChannels(taskHandle, data, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jdata = (*env)->NewStringUTF(env, data);
	}

	return jdata;
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskNumChans(JNIEnv *env, jclass jc,
		jlong pTask) {
	int32 code;
	uInt32 length;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	code = DAQmxGetTaskNumChans(taskHandle, &length);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return -1;
	}

	return (jlong) length;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskDevices(JNIEnv *env, jclass jc,
		jlong pTask) {
	int32 code;
	int32 bufferSize;
	char *data = NULL;
	jstring jdata = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	bufferSize = DAQmxGetTaskDevices(taskHandle, NULL, 0);

	if (bufferSize > 0) {
		data = (char *) malloc(bufferSize);

		code = DAQmxGetTaskDevices(taskHandle, data, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jdata = (*env)->NewStringUTF(env, data);
	}

	return jdata;
}

JNIEXPORT jlong JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getTaskNumDevices(JNIEnv *env, jclass jc,
		jlong pTask) {
	int32 code;
	uInt32 length;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	code = DAQmxGetTaskNumDevices(taskHandle, &length);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return -1;
	}

	return (jlong) length;

}

JNIEXPORT jint JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getChanType(JNIEnv *env, jclass jc,
		jlong pTask, jstring jChannel) {
	int32 code;
	int32 type;
	const char *channel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	channel = getStringUTFChars(env, jChannel, NULL);

	code = DAQmxGetChanType(taskHandle, channel, &type);
	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return -1;
	}

	(*env)->ReleaseStringUTFChars(env, jChannel, channel);

	return type;
}

JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getAIMin(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel) {
	int32 code;
	float64 min;
	const char *channel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	channel = getStringUTFChars(env, jchannel, NULL);

	code = DAQmxGetAIMin(taskHandle, channel, &min);

	(*env)->ReleaseStringUTFChars(env, jchannel, channel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return -1;
	}

	return (jdouble) min;
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_setAIMin(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel, jdouble value) {
	int32 code;
	const char *channel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	channel = getStringUTFChars(env, jchannel, NULL);

	code = DAQmxSetAIMin(taskHandle, channel, value);

	(*env)->ReleaseStringUTFChars(env, jchannel, channel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT jdouble JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getAIMax(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel) {
	int32 code;
	float64 max;
	const char *channel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	channel = getStringUTFChars(env, jchannel, NULL);

	code = DAQmxGetAIMax(taskHandle, channel, &max);

	(*env)->ReleaseStringUTFChars(env, jchannel, channel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return -1;
	}

	return (jdouble) max;
}

JNIEXPORT void JNICALL
Java_com_wrapper_NIDAQmxJWrapper_setAIMax(JNIEnv *env, jclass jc, jlong pTask,
		jstring jchannel, jdouble value) {
	int32 code;
	const char *channel = NULL;
	TaskHandle taskHandle = (TaskHandle) (intptr_t) pTask;

	channel = getStringUTFChars(env, jchannel, NULL);

	code = DAQmxSetAIMax(taskHandle, channel, value);

	(*env)->ReleaseStringUTFChars(env, jchannel, channel);

	if (code < 0) {
		throwNIDAQmxJWrapperException(env, code);
		return;
	}
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getSysScales(JNIEnv *env, jclass jc) {
	int32 code;
	int32 bufferSize;
	char *data = NULL;
	jstring jdata = NULL;

	bufferSize = DAQmxGetSysScales(NULL, 0);

	if (bufferSize > 0) {

		data = (char *) malloc(bufferSize);

		code = DAQmxGetSysScales(data, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jdata = (*env)->NewStringUTF(env, data);
	}

	return jdata;
}

JNIEXPORT jstring JNICALL
Java_com_wrapper_NIDAQmxJWrapper_getSysTasks(JNIEnv *env, jclass jc) {
	int32 code;
	int32 bufferSize;
	char *data = NULL;
	jstring jdata = NULL;

	bufferSize = DAQmxGetSysTasks(NULL, 0);

	if (bufferSize > 0) {

		data = (char *) malloc(bufferSize);

		code = DAQmxGetSysTasks(data, bufferSize);
		if (code < 0) {
			throwNIDAQmxJWrapperException(env, code);
			return NULL;
		}

		jdata = (*env)->NewStringUTF(env, data);
	}

	return jdata;
}