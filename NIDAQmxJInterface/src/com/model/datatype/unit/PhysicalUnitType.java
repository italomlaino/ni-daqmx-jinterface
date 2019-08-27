package com.model.datatype.unit;

import com.model.util.Constants;

public enum PhysicalUnitType {
	NewtonMeters(Constants.DAQmx_Val_NewtonMeters), InchOunces(
			Constants.DAQmx_Val_InchOunces), InchPounds(
			Constants.DAQmx_Val_InchPounds), FootPounds(
			Constants.DAQmx_Val_FootPounds);

	private int code;

	private PhysicalUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
