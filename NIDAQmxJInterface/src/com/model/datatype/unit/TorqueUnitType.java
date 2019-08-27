package com.model.datatype.unit;

import com.model.util.Constants;

public enum TorqueUnitType {
	NewtonMeters(Constants.DAQmx_Val_NewtonMeters), InchOunces(
			Constants.DAQmx_Val_InchOunces), InchPounds(
			Constants.DAQmx_Val_InchPounds), FootPounds(
			Constants.DAQmx_Val_FootPounds), FromCustomScale(
			Constants.DAQmx_Val_FromCustomScale);

	private int code;

	private TorqueUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
