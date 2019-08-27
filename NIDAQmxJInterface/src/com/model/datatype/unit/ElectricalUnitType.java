package com.model.datatype.unit;

import com.model.util.Constants;

public enum ElectricalUnitType {
	VoltsPerVolt(Constants.DAQmx_Val_VoltsPerVolt), MilivoltsPerVolt(
			Constants.DAQmx_Val_mVoltsPerVolt);

	private int code;

	private ElectricalUnitType(int code) {
		this.code = code;
	}

	public int getCode() {
		return code;
	}
}
