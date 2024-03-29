package com.model.datatype.unit;

import com.model.util.Constants;

public enum VelocityUnitType {

	MetersPerSecond(Constants.DAQmx_Val_MetersPerSecond), InchesPerSecond(
			Constants.DAQmx_Val_InchesPerSecond), FromCustomScale(
			Constants.DAQmx_Val_FromCustomScale);

	private int code;

	private VelocityUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
