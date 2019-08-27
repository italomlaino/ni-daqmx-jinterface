package com.model.util;

public class Constants {

	// TerminalConfigType
	public static final int DAQmx_Val_Cfg_Default = -1;
	public static final int DAQmx_Val_RSE = 10083;
	public static final int DAQmx_Val_NRSE = 10078;
	public static final int DAQmx_Val_Diff = 10106;
	public static final int DAQmx_Val_PseudoDiff = 12529;

	// TaskActionType
	public static final int DAQmx_Val_Task_Start = 0;
	public static final int DAQmx_Val_Task_Stop = 1;
	public static final int DAQmx_Val_Task_Verify = 2;
	public static final int DAQmx_Val_Task_Commit = 3;
	public static final int DAQmx_Val_Task_Reserve = 4;
	public static final int DAQmx_Val_Task_Unreserve = 5;
	public static final int DAQmx_Val_Task_Abort = 6;

	// ActiveEdgeType
	public static final int DAQmx_Val_Rising = 10280;
	public static final int DAQmx_Val_Falling = 10171;

	// SampleModeType
	public static final int DAQmx_Val_FiniteSamps = 10178;
	public static final int DAQmx_Val_ContSamps = 10123;
	public static final int DAQmx_Val_HWTimedSinglePoint = 12522;

	// FillModeType
	public static final boolean DAQmx_Val_GroupByChannel = false;
	public static final boolean DAQmx_Val_GroupByScanNumber = true;

	// ExcitationSourceType
	public static final int DAQmx_Val_None = 10230;
	public static final int DAQmx_Val_Internal = 10200;
	public static final int DAQmx_Val_External = 10167;

	// ShuntResistorLocType
	public static final int DAQmx_Val_Default = -1;
	// public static final int DAQmx_Val_Internal = 10200;
	// public static final int DAQmx_Val_External = 10167;

	// BridgeConfigType
	public static final int DAQmx_Val_FullBridge = 10182;
	public static final int DAQmx_Val_HalfBridge = 10187;
	public static final int DAQmx_Val_QuarterBridge = 10270;
	public static final int DAQmx_Val_NoBridge = 10228;

	// VoltageUnitType
	public static final int DAQmx_Val_Volts = 10348;
	public static final int DAQmx_Val_FromCustomScale = 10065;

	// CurrentUnitType
	public static final int DAQmx_Val_Amps = 10342;
	// public static final int DAQmx_Val_FromCustomScale = 10065;

	// ElectricalUnitType
	public static final int DAQmx_Val_VoltsPerVolt = 15896;
	public static final int DAQmx_Val_mVoltsPerVolt = 15897;

	// TorqueUnitType
	public static final int DAQmx_Val_NewtonMeters = 15881;
	public static final int DAQmx_Val_InchOunces = 15882;
	public static final int DAQmx_Val_InchPounds = 15883;
	public static final int DAQmx_Val_FootPounds = 15884;
	// public static final int DAQmx_Val_FromCustomScale = 10065;

	// PhysicalUnitType
	// public static final int DAQmx_Val_NewtonMeters = 15881;
	// public static final int DAQmx_Val_InchOunces = 15882;
	// public static final int DAQmx_Val_InchPounds = 15883;
	// public static final int DAQmx_Val_FootPounds = 15884;

	// VelocityUnitType
	public static final int DAQmx_Val_MetersPerSecond = 15959;
	public static final int DAQmx_Val_InchesPerSecond = 15960;
	// public static final int DAQmx_Val_FromCustomScale = 10065;

	// VelocitySensivityUnitType
	public static final int DAQmx_Val_MillivoltsPerMillimeterPerSecond = 15963;
	public static final int DAQmx_Val_MillivoltsPerInchPerSecond = 15964;

}