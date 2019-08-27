package com.model.datatype.unit;

import com.model.util.Constants;

public enum CurrentUnitType {
	FromCustomScale(Constants.DAQmx_Val_FromCustomScale), Amps(
			Constants.DAQmx_Val_Amps);

	private int code;

	private CurrentUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
