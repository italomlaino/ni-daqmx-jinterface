package com.model.datatype.unit;

import com.model.util.Constants;

public enum VoltageUnitType {

	FromCustomScale(Constants.DAQmx_Val_FromCustomScale), Volts(
			Constants.DAQmx_Val_Volts);

	private int code;

	private VoltageUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
