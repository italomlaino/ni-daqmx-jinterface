package com.model.datatype.unit;

import com.model.util.Constants;

public enum VelocitySensivityUnitType {
	MillivoltsPerMillimeterPerSecond(
			Constants.DAQmx_Val_MillivoltsPerMillimeterPerSecond), MillivoltsPerInchPerSecond(
			Constants.DAQmx_Val_MillivoltsPerInchPerSecond);

	private int code;

	private VelocitySensivityUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
