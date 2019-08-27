package com.wrapper;

public class NIDAQmxJWrapper {

	public static final String LIBRARY_NAME = "NIDAQmxJWrapperNative";

	static {
		System.loadLibrary(LIBRARY_NAME);
	}

	// ****************************** Task ******************************
	public native static void clearTask(long pTask)
			throws NIDAQmxJWrapperException;

	public native static long createTask(String name)
			throws NIDAQmxJWrapperException;

	public native static boolean isTaskDone(long pTask)
			throws NIDAQmxJWrapperException;

	public native static void startTask(long pTask)
			throws NIDAQmxJWrapperException;

	public native static void stopTask(long pTask)
			throws NIDAQmxJWrapperException;

	// ************* Events **********

	// ************* Advanced ********

	public native static void taskControl(long pTask, int action)
			throws NIDAQmxJWrapperException;

	// ************* Properties ********

	public native static String getTaskName(long pTask)
			throws NIDAQmxJWrapperException;

	public native static String getTaskChannels(long pTask)
			throws NIDAQmxJWrapperException;

	public native static long getTaskNumChans(long pTask)
			throws NIDAQmxJWrapperException;

	public native static String getTaskDevices(long pTask)
			throws NIDAQmxJWrapperException;

	public native static long getTaskNumDevices(long pTask)
			throws NIDAQmxJWrapperException;

	// **************** Channel Configuration/Control ********************

	// ******** Create Analog Input Channels ********

	public native static void createAIVoltageChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			int terminalConfig, double minVal, double maxVal, int units,
			String customScaleName) throws NIDAQmxJWrapperException;

	public native static void createAICurrentChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			int terminalConfig, double minVal, double maxVal, int units,
			int shuntResistorLoc, double extShuntResistorVal,
			String customScaleName) throws NIDAQmxJWrapperException;

	public native static void createAICurrentRMSChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			int terminalConfig, double minVal, double maxVal, int units,
			int shuntResistorLoc, double extShuntResistorVal,
			String customScaleName) throws NIDAQmxJWrapperException;

	public native static void createAITorqueBridgePolynomialChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			double minVal, double maxVal, int units, int bridgeConfig,
			int voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double[] forwardCoeffs,
			double[] reverseCoeffs, int electricalUnits, int physicalUnits,
			String customScaleName) throws NIDAQmxJWrapperException;

	public native static void createAITorqueBridgeTableChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			double minVal, double maxVal, int units, int bridgeConfig,
			int voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double[] electricalVals,
			int electricalUnits, double[] physicalVals, int physicalUnits,
			String customScaleName) throws NIDAQmxJWrapperException;

	public native static void createAITorqueBridgeTwoPointLinChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			double minVal, double maxVal, int units, int bridgeConfig,
			int voltageExcitSource, double voltageExcitVal,
			double nominalBridgeResistance, double firstElectricalVal,
			double secondElectricalVal, int electricalUnits,
			double firstPhysicalVal, double secondPhysicalVal,
			int physicalUnits, String customScaleName)
			throws NIDAQmxJWrapperException;

	public native static void createAIVelocityIEPEChan(long pTask,
			String physicalChannel, String nameToAssignToChannel,
			int terminalConfig, double minVal, double maxVal, int units,
			double sensitivity, int sensitivityUnits, int currentExcitSource,
			double currentExcitVal, String customScaleName)
			throws NIDAQmxJWrapperException;

	// *** Position ***

	// ******** Create TEDS Analog Input Channels ********

	// *** Position ***

	// ******** Create Analog Output Channels ********

	// ******** Create Digital Input Channels ********

	// ******** Create Digital Output Channels ********

	// ******** Create Counter Input Channels ********

	// *** Position ***

	// *** Timestamp ***

	// ******** Create Counter Output Channels ********

	// ******** Properties ***********

	public native static int getChanType(long pTask, String channel)
			throws NIDAQmxJWrapperException;

	public native static double getAIMin(long pTask, String channel)
			throws NIDAQmxJWrapperException;

	public native static void setAIMin(long pTask, String channel, double value)
			throws NIDAQmxJWrapperException;

	public native static double getAIMax(long pTask, String channel)
			throws NIDAQmxJWrapperException;

	public native static void setAIMax(long pTask, String channel, double value)
			throws NIDAQmxJWrapperException;

	// ***************************** Timing *****************************
	public native static void cfgSampClkTiming(long pTask, String source,
			double rate, int activeEdge, int sampleMode, long sampsPerChan)
			throws NIDAQmxJWrapperException;

	// ************************ Read Functions ***************************
	public native static double[] readAnalogF64(long pTask,
			int numSampsPerChan, double timeout, boolean fillMode)
			throws NIDAQmxJWrapperException;

	// ******** Advanced ********

	// ***************************** Write Functions
	// ****************************

	// ******** Advanced ********

	// ***************************** Export HW Signals
	// **************************

	// ***************************** Scale Configuration
	// ************************

	// ******************* Internal Buffer Configuration
	// ************************

	// ******************* Advanced Functions ************************

	// ****************************** System Configuration
	// **********************

	public native static String getSysScales();

	public native static String getSysTasks();

	// ************************** Error Handling ************************
	public native static String getErrorString(int errorCode)
			throws NIDAQmxJWrapperException;

	public native static String getExtendedErrorInfo()
			throws NIDAQmxJWrapperException;
}
